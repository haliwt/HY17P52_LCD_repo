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
//#define  TPSTEST
/*
#define ADGN                      0
#define ADGN_MSK                 (7 << ADGN)
//FOR ICE
#define ADGN_RSVD              (7 << ADGN)
#define ADGN_16                    (6 << ADGN)
#define ADGN_4                      (4 << ADGN)
#define ADGN_1                      (2 << ADGN)
//FOR BODY
#define ADGN_RSVD        (7 << ADGN)
#define ADGN_16              (6 << ADGN)
#define ADGN_1                (5 << ADGN)
#define ADGN_4                (4 << ADGN)
*/
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
typedef struct _adc_wrks_
{
   unsigned char save_mode;
   unsigned char uint_set_mode;
   unsigned char measure_mode;
   unsigned char zero_point_mode;
   unsigned char error_mode;
   unsigned char key_flag;
   unsigned char second_5_over;
   unsigned char second_3_over;
   unsigned char extend_t;   /*measure mode */
   
}adc_works_t;
adc_works_t adS; 


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
		  
		  adS.key_flag=adS.key_flag ^ 0x01;

		 if(adS.second_5_over >= 1){ /*unit set mode*/
			   adS.key_flag = 0;
			 if(GPIO_READ_PT10()){
				adS.second_5_over =0;
				adS.uint_set_mode =1;
				adS.zero_point_mode =0;
				adS.measure_mode =1;
				adS.key_flag = 0;
				DisplayUnit();
				Delay(20000);
				GPIO_PT15_HIGH();	
				Delay(10000);
				Delay(10000);
				Delay(10000);
			}
		 }
		 if(adS.second_3_over >=1 && adS.second_5_over < 1){ /* zero point mode*/

			
			   if(GPIO_READ_PT10()){
				adS.second_3_over =0;
				adS.zero_point_mode =1;
				adS.uint_set_mode = 0;
				adS.measure_mode =1;
				GPIO_PT16_HIGH();	
				Delay(20000);  // 1/4 period 20000/4 = 50000 = 500ms
				GPIO_PT16_HIGH();	
				Delay(20000);
				GPIO_PT16_LOW();	
				Delay(20000);
				GPIO_PT16_HIGH();	
				Delay(20000);
				GPIO_PT16_LOW();
				Delay(20000);
				GPIO_PT16_HIGH();
			}
		 }
			
		}
		else{
		   	GPIO_PT16_LOW();
		   	GPIO_PT15_LOW();
		   	adS.key_flag = 0;
		   	if(adS.second_3_over>1){
			adS.second_3_over =0;
			adS.measure_mode = 0;

		   }
		   if(adS.measure_mode == 0){ /* measure mode */
				if(MCUSTATUSbits.b_ADCdone==1)
				{
					MCUSTATUSbits.b_ADCdone=0;
					ADC=ADC>>4;
					ShowADC();
		            Delay(20000);
			    }
	   		}
		   if(adS.zero_point_mode == 1){ /*zero point mode */

			   adS.zero_point_mode =0;
			   adS.measure_mode=0;
			   //display LCD "2Er"
			     Display2Er();
                 Delay(20000);
                 Delay(20000);
                 Delay(20000);
                 Delay(20000);
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
		    Second_real_3 =0;
			adS.key_flag =2;
		}
		if(Second_real_3 ==5600) // 3 second
	    {
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
