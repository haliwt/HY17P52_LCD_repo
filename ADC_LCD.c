#define  USE_HY17P52_2M

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <SFRType.h>
#include <INT.h>
#include <CLK.h>
#include <PWR.h>
#include <ADC_52.h>
#include <GPIO.h>S
#include <LCD.h>
#include <TMR_52.h>
#include "display.h"
/*----------------------------------------------------------------------------*/
/* DEFINITIONS                                                                */
/*----------------------------------------------------------------------------*/
#define abs(value)            (value >0 ? value : -value )
#define VoltageToPSi(vuint)		(3.75 * (vuint-40000))
#define PSiTobar(psi)   	(14.5 * psi)
#define barTokgf(psi)	 	(14.22 * psi)
#define kgfTokPa(psi)		(0.145 *psi)
#define kPaToMPa(psi)		(145 * psi)
/*----------------------------------------------------------------------------*/
/* Global CONSTANTS                                                           */
/*----------------------------------------------------------------------------*/
unsigned char ADCData,ADCData1,ADCData2;
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


unsigned int pressTable[TableNumber ] = {
 1123,1684,1703,1986
,2227,2258,2548,2816,2824,3383,3392,3665,3934,4002
,4210,4496,4503,4570,4632,4712,4766,4778,4836,4896
,4993,5054,5058,5107,5165,5285,5326,5385,5442,5496
,5606,5633,5700,5766,5840,5888,5896,5943,6001,6050
,6120,6203,6208,6250,6265,6284,6314,6316,6336,6355
,6359,6361,6362,6363,6365,6405,6465,6500,6500,6505
,6506,6507,6508,6509,6510,6511,6512,6513,6514,6515
,6516,6517,6518,6519,6520,6521,6522,6523,6524,6525
,6526,6527,6528,6529,6530,6531,6532,6533,6534,6535
,6536,6537,6538,6539,6540,6541,6542,6543,6544,6545
,6546,6547,6548,6549,6550,6551,6552,6553,6554,6555

};
 

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
/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
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
				GPIO_PT15_HIGH();	
				Delay(10000);
				Delay(10000);
				Delay(10000);
			
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
					ShowADC();
					GPIO_PT16_HIGH();
		            adS.key_flag =0;
		        	Delay(20000);
		           	GPIO_PT16_LOW(); 

			    }
	   		}
		   if(adS.zero_point_mode == 1){ /*zero point mode */

			   adS.zero_point_mode =0;
			   adS.measure_mode=0;
			}
		   if(adS.second_3_over >=1){ /* over 3 seconds don't press key return measure_mode*/
		   	   adS.measure_mode = 0;
		   	   adS.uint_set_mode=0;
			   adS.key_flag =0;
			}
		
		}

    }
}

/*----------------------------------------------------------------------------*/
/* Subroutine Function                                                        */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*          LCD Show ADC                                                        */
/*----------------------------------------------------------------------------*/
void ShowADC (void)
{
	
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
