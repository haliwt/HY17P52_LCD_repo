#define  USE_HY17P52_2M

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <SFRType.h>
#include <INT.h>
#include <CLK.h>
#include <PWR.h>
#include <ADC_52.h>
#include <GPIO.h>
#include <LCD.h>
#include <TMR_52.h>
#include "display.h"
/*----------------------------------------------------------------------------*/
/* DEFINITIONS                                                                */
/*----------------------------------------------------------------------------*/

#define abs(value)            ((value) >0 ? (value) : (-value) )

#define PSITokgf(kgf)       (0.145 * (kgf))
#define BARTokgf(kgf)   	(2.1 * (kgf))
#define MPATokgf(kgf)	 	(0.1 * (kgf))

#define STD_VALUE           65000
/*----------------------------------------------------------------------------*/
/* Global CONSTANTS                                                           */
/*----------------------------------------------------------------------------*/
static  int index_offset ;
unsigned char Flag;
long	ADC;

unsigned long Second_real_3=0;
unsigned long firstSecond=0;
unsigned char getLastSecond =0 ;


volatile typedef union _MCUSTATUS
{
  char  _byte;
  struct
  {
    unsigned b_ADCdone:1;
    unsigned b_TMAdone:1;
    unsigned b_TMBdone:1;
    unsigned b_TMCdone:1;
    unsigned b_Ext0done:1;
    unsigned b_Ext1done:1;
    unsigned b_UART_TxDone:1;
    unsigned b_UART_RxDone:1;
  };
} MCUSTATUS;

MCUSTATUS  MCUSTATUSbits;
#if 1
const unsigned int table_Getkgf_100_90[]={
	6500,6501,6502,6503,6504,6505,6506,6507,6508,6509,6510,6511,6812
};
#endif 
const unsigned int display_Unitkgf_100_90[]={
    100,990,980,970,960,950,940,930,920,910,910,900,900
};
/******************************************************/
unsigned int table_Getkgf_90_80[]={ 
	6513,6514,6515,6516,6517,6518,6519,6520,6521,6522,5623,6524
};
unsigned int table_Getkgf_80_70[]={ 
	6525,6526,6527,6528,6529,6530,6531,6532,6533,6534,5635,6536
};
unsigned int table_Getkgf_70_60[]={ 
	6537,6538,6539,6540,6541,6542,6543,6544,6545,6546,5647,6548
};
unsigned int table_Getkgf_60_50[]={ 6540, 6120 };
unsigned int table_Getkgf_50_40[]={ 6120, 5320 };
unsigned int table_Getkgf_40_30[]={ 5321, 4481 };
unsigned int table_Getkgf_30_20[]={ 4480, 3668};
unsigned int table_Getkgf_20_10[]={ 3667, 2847};
unsigned int table_Getkgf_10_0[]= { 2846, 2010 };
/*minus kfg value array m --minus */
unsigned int m_table_Getkgf_100_90[]={6270,5435};
unsigned int m_table_Getkgf_90_80[]={5436,4615};
unsigned int m_table_Getkgf_80_70[]={4617,3784};
unsigned int m_table_Getkgf_70_60[]={3785,2948};
unsigned int m_table_Getkgf_60_50[]={2949,2123};
unsigned int m_table_Getkgf_50_40[]={2124,1307};
unsigned int m_table_Getkgf_40_30[]={1308,469};
unsigned int m_table_Getkgf_30_20[]={470,375};
unsigned int m_table_Getkgf_20_10[]={376,1156};
unsigned int m_table_Getkgf_10_0[]={1157,1997};
unsigned char Flag;
/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
unsigned char HY17P52WR3(unsigned char Addr,unsigned char DataH,unsigned char DataL);
void HY17P52WR3Delay(char ms);

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void PGAandADCAccuracyMode(void);
void AccuracyModeADCOFF(void);
void ADCAccuracyMode(void);
void Delay(unsigned int ms);
void ShowADC (void);
void DisplayNum(long Num);
void GPIO_Init(void);
long Index_Subsection(void);
/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
    unsigned int read_t,read_h,n; 
    int LCDDisplay;
   //CLK Setting
	//CLK_CPUCKSelect(CPUS_DHSCK) ;
	//CLK Setting
	CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
	CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
 	//GPIO Setting
	GPIO_PT15_OUTUT();  // SETTING PT4.4 OUTPUT
    GPIO_PT16_OUTUT();  // SETTING PT4.3 OUTPUT
    GPIO_PT17_OUTUT();	
	GPIO_PT10_INPUT();

//VDDA Setting
	PWR_BGREnable();
	PWR_LDOPLEnable();
	PWR_LDOEnable();
	PWR_LDOSel(LDOC_2V4);
//ADC Setting
	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);


	PGAandADCAccuracyMode();
	//ADCAccuracyMode();
	//AccuracyModeADCOFF();


//LCD Setting
	//LCDCN1 = 0xc8 ;
	LCD_Enable();
	LCD_ChargePumpSelect(LCDV_3V0);
	LCD_OutBufferEnable();
	LCD_ChargePumpClk(SELPCLK_14KHZ);
	//LCDCN2 = 0x00;
	LCD_DisplayOn();

 	//LCDCN3 = 0x00;
	LCD_PT60Mode(LCD);   //COM0
	LCD_PT61Mode(LCD);	 //COM1
	LCD_PT62Mode(LCD);   //COM2
	LCD_PT63Mode(LCD);   //COM3

	TMA1_CLKSelect(TMAS1_DMSCK); //freq = DMS_CK = 3.686Mhz/256 = 0.014398MHz      0.014398Mhz / 2= 7.2KHz
    TMA1_CLKDiv(DTMA1_TMA1CKDIV2); // fdiv = 7.2KHz ,T = 0.138ms
    TMA1_CompSet(255);    //TMA1C cycle=10*TMA1R cycle 8bit = 255
    TA1IE_Enable();

    TA1IF_ClearFlag();

    TMA1_ClearTMA1();    //Clear TMA count
    TMA1Enable();
   
	ADIF_ClearFlag();
	ADIE_Enable();
	GIE_Enable();
    
	while(1)
	{
	    
		
		if(GPIO_READ_PT10())
		{
		  
		  adS.key_flag=adS.key_flag ^ 0x01; /* check process  ISR()__inptrrupt reference */

		 if(adS.second_5_over >= 1){ /*unit set mode*/
			
			 if(GPIO_READ_PT10()){
	     
				adS.second_5_over =0;
				adS.uint_set_mode =1;
				adS.zero_point_mode =0;
				adS.measure_mode =1;
				DisplayUnit();
				Delay(20000);
				Delay(20000);

				    //BIE Read   
					BIEARL=0;                                //addr=0
					BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
					while((BIECN& 0x01)==1);   
					read_t = BIEDRL;
					read_h = BIEDRH;
					if(read_h == 0x00){
							GPIO_PT16_HIGH();
								
							Delay(20000);
							GPIO_PT16_LOW(); 
							Delay(20000);
							GPIO_PT16_HIGH();
							Delay(20000);
							GPIO_PT16_LOW(); 
								//BIE Write
							HY17P52WR3(0,0xAA,0x11);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
							if(Flag== 1)
							{
								while(1);    //fail
							}
					}
					if(read_t == 0x11){

							GPIO_PT15_HIGH();
								
							Delay(20000);
							GPIO_PT15_LOW(); 
							Delay(20000);
							GPIO_PT15_HIGH();
							Delay(20000);
							GPIO_PT15_LOW(); 

					}
				
			
			
				GPIO_PT15_HIGH();	
				Delay(10000);
				Delay(10000);
				Delay(10000);
				switch(adS.plus_uint){
					case psi: 
					     adS.plus_uint++;
						 adS.u_plus = psi;
					    break;
					case bar:
						adS.plus_uint++;
						 adS.u_plus = bar;
					     break;
					case kgf:
						adS.plus_uint++;
						adS.u_plus = kgf;
					     break;
				    case mpa:
					     adS.plus_uint=0;
						 adS.u_plus = mpa;
					     break;
				}
			
			}
		 }
		 if(adS.second_3_over >=1 && adS.second_5_over < 1 && adS.uint_set_mode !=1){ /* zero point mode*/

			   if(GPIO_READ_PT10()){
				
				adS.zero_point_mode =1;
				adS.uint_set_mode = 0;
				adS.measure_mode =1;
			    adS.second_3_over=0;
				//display LCD "2Er"
			     Display2Er();
                 Delay(20000);
                
			}
		 }
		 
		}
		else{
		   	GPIO_PT16_LOW();
		   	GPIO_PT15_LOW();
		   
		   if(adS.measure_mode == 0){ /* measure mode */
		         
				if(MCUSTATUSbits.b_ADCdone==1)
				{
					MCUSTATUSbits.b_ADCdone=0;
					
					ADC=ADC>>6;
					adS.ADC_DAT = ADC * 0.1;
					#if 1
					n = Index_Subsection(); /* judge ADC value region*/
			
					DisplayNum(n);
					if(n <0){
                       LCDDisplay = 12345; 

					}
					else{
                       LCDDisplay = display_Unitkgf_100_90[n];
					}
					#endif 
					//DisplayNum(LCDDisplay);
					GPIO_PT16_HIGH();
		            adS.key_flag =0;
		        	Delay(20000);
		           	GPIO_PT16_LOW(); 

			    }
	   		}
		   if(adS.zero_point_mode == 1){ /*zero point mode */

			   adS.zero_point_mode =0;
			   adS.measure_mode=0;
			   ADC=ADC>>6;
			   adS.m_offset_value = ADC - STD_VALUE;

			}
		   if(adS.second_3_over >=1){ /* over 3 seconds don't press key return measure_mode*/
		   	   adS.measure_mode = 0;
		   	   adS.uint_set_mode=0;
			   adS.key_flag =0;

			}
			if(adS.uint_set_mode ==1){

				switch(adS.u_plus){
					case psi:
						
					break;
					case bar:
					break;
					case kgf:
					break;
					case mpa:
					break;
					default :
					break;

				}

			}
		
		}

    }
}

/***************************************************************************
  *
  *Function Name:Index_Subsection()
  *Function : serch table be responds psi volue,voltage transition psi
  *
  *                                                        
****************************************************************************/
long Index_Subsection()
{
    
     int i =13;
    adS.ADC_DAT = 6510;
    //adS.ADC_DAT = adS.ADC_DAT * 0.1;
	 if(adS.ADC_DAT > 6549 && adS.ADC_DAT < 6500) {
        adS.ADC_DAT = 66666;
     return adS.ADC_DAT;
   }
	 if(adS.ADC_DAT >=6500){
       
		  //  adS.ADC_DAT= adS.ADC_DAT + adS.m_offset_value ;
      
        while(i--){
          
           if(table_Getkgf_100_90[i] == (unsigned int)adS.ADC_DAT) {
                   
                return i;
           }
         
        };
     }
	 return -1;

}

/*----------------------------------------------------------------------------*/
/*          LCD Show ADC                                                        */
/*----------------------------------------------------------------------------*/
void ShowADC (void)
{
	//Index_Subsection(ADC); /* judge ADC value region*/
	DisplayNum(ADC);
	
}
/*----------------------------------------------------------------------------*/
/* Software Delay Subroutines                                                 */
/*----------------------------------------------------------------------------*/
void Delay(unsigned int ms)
{
  for(;ms>0;ms--)
    __asm__("NOP");
}
/*----------------------------------------------------------------------------*/
/* Interrupt Service Routines                                                 */
/*----------------------------------------------------------------------------*/
void ISR(void) __interrupt
{

	if(ADIF_IsFlag())
	{
		ADIF_ClearFlag();
		ADC=ADC_GetData();
		MCUSTATUSbits.b_ADCdone=1;
	}
	if(TA1IF_IsFlag())  //PT1.0  Timer A1 interrupt flag 
	{
		firstSecond++ ;
		Second_real_3 ++;
		if(adS.key_flag ==1||adS.key_flag==0) {
			adS.second_5_over = 0;
			firstSecond=0 ;
			adS.second_3_over =0;
			Second_real_3 =0;
			adS.key_flag =2;
			
		}
		if(Second_real_3 ==5600){
		    Second_real_3 =0;
			adS.second_3_over ++ ;
		}
		if(firstSecond ==9300) // 5 second
	    {
	        firstSecond=0;
		    getLastSecond ++ ;
			adS.second_5_over ++ ;
			if(getLastSecond == 12){ //60 sec
				getLastSecond =0;
				GPIO_PT16_HIGH();	
			    Delay(10000);
				GPIO_PT15_HIGH();	
			    Delay(10000);
			    Delay(10000);
			}	
	      
	       GPIO_PT16_LOW()	;	
	    }
	 
		TA1IF_ClearFlag();
	}
}

/*----------------------------------------------------------------------------*/
/* End Of File                                                                */
/*----------------------------------------------------------------------------*/
