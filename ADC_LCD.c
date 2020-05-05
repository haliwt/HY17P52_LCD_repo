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

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void PGAandADCAccuracyMode(void);
void AccuracyModeADCOFF(void);
void ADCAccuracyMode(void);
void Delay(unsigned int ms);
void ShowADC (void);
void DisplayNum(long Num);
/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
//CLK Setting
	CLK_CPUCKSelect(CPUS_DHSCK) ;
//GPIO Setting
    TRISC1 = 0x00;
    TRISC2 = 0x00;
    PT1 = 0x00;
    PT1DA = 0x00;
	GPIO_PT1SETPUAll();
	GPIO_PT2SETPUAll();

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
//	LCD_DisplayOff();

 	//LCDCN3 = 0x00;
	LCD_PT60Mode(LCD);
	LCD_PT61Mode(LCD);
	LCD_PT62Mode(LCD);
	LCD_PT63Mode(LCD);

	//LCDCN4 = 0x00;
	LCD_PT80Mode(LCD);
	LCD_PT81Mode(LCD);
	LCD_PT82Mode(LCD);
	LCD_PT83Mode(LCD);
	LCD_PT84Mode(LCD);
	LCD_PT85Mode(LCD);
	LCD_PT86Mode(LCD);
	LCD_PT87Mode(LCD);
/*
	//LCDCN6 = 0x00;
	LCD_PT64Mode(LCD);
	LCD_PT65Mode(LCD);
	LCD_PT66Mode(LCD);
	LCD_PT67Mode(LCD);

	//LCDCN7 = 0x00;
	LCD_PT70Mode(LCD);
	LCD_PT71Mode(LCD);
	LCD_PT72Mode(LCD);
	LCD_PT73Mode(LCD);

	//LCDCN8 = 0xff;
	LCD_PT74Mode(LCD);
	LCD_PT75Mode(LCD);
	LCD_PT76Mode(LCD);
	LCD_PT77Mode(LCD);
*/
//TMA Setting
/*
	TMA1_CLKSelect ( TMAS1_DMSCK );
	TMA1_CLKDiv (DTMA1_TMA1CKDIV8);
	TMA1_ClearTMA1();
	TMA1Enable();
*/
	ADIF_ClearFlag();  /* 清除中断标志位 */
	ADIE_Enable();
	GIE_Enable(); //

	while(1)
	{
		if(MCUSTATUSbits.b_ADCdone==1)
		{
			MCUSTATUSbits.b_ADCdone=0;
			ADC=ADC>>6;
			ShowADC();
            Delay(20000);
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
	/*
	if(TA1IF_IsFlag())
	{
		TA1IF_ClearFlag();
		//TMR_RS ();
	}
	*/
}

/*----------------------------------------------------------------------------*/
/* End Of File                                                                */
/*----------------------------------------------------------------------------*/
