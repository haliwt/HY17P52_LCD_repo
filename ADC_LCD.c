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
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
unsigned char HY17P52WR3(unsigned char Addr,unsigned char DataH,unsigned char DataL);
void HY17P52WR3Delay(char ms);


/*----------------------------------------------------------------------------*/
/* DEFINITIONS                                                                */
/*----------------------------------------------------------------------------*/


#define abs(value)            ((value) >0 ? (value) : (-value) )

#define kgfTOpsi(kgf)       (0.145 * (kgf))
#define kgfTObar(kgf)   	(0.01 * (kgf))
#define kgfTOmpa(kgf)	 	(0.1 * (kgf))

#define STD_VALUE                 105000//WT.EDIT 2020-06-03 //10400//10440//10400

#define STD_NEGATIVE_VOLTAGE      69620//6962 WT.EDIT 2020-06-03
#define DEGUG     				0

/*----------------------------------------------------------------------------*/
/* Global CONSTANTS                                                           */
/*----------------------------------------------------------------------------*/

unsigned char Flag;
long	ADC;


volatile typedef union _MCUSTATUS
{
  char  _byte;
  struct
  {
    unsigned b_ADCdone:1;
   // unsigned b_TMAdone:1;
   // unsigned b_TMBdone:1;
  //  unsigned b_TMCdone:1;
  //  unsigned b_Ext0done:1;
  //  unsigned b_Ext1done:1;
  //  unsigned b_UART_TxDone:1;
  //  unsigned b_UART_RxDone:1;
  };
} MCUSTATUS;

MCUSTATUS  MCUSTATUSbits;



/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void PGAandADCAccuracyMode(void);
void AccuracyModeADCOFF(void);
void ADCAccuracyMode(void);
void DisplayNum(long Num);
long UnitConverter(long data);
unsigned char LowVoltageDetect_3V(void);
unsigned char LowVoltageDetect_2V4(void);
void LowVoltageDisplay(void);
void SetupZeroPoint_Mode(void);
void SetupUnit_Mode(void);
void PositivePressureWorks_Mode(void);
void NegativePressureWorks_Mode(void);
void SetupUnitSelection(void);
void SetupZeroPointSelection(void);
void TestWorksPrecondition(void);

/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{

    unsigned char firstPower = 0;
    adS.testMode =0;
	//CLK Setting
	CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
	CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
    GPIO_Iint() ;

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


		if(GPIO_READ_PT10()&& firstPower !=0)
		{

		//  adS.key_flag=adS.key_flag ^ 0x01; /* check process  ISR()__inptrrupt reference */


		 if(adS.delayTimes_5 >= 10000){ /*unit set mode*/

			 if(GPIO_READ_PT10()){

	          	SetupUnitSelection();
			}

		  }

		 if(adS.delayTimes_3 >=5000){ /* zero point mode*/

			   if(GPIO_READ_PT10()){

			   	SetupZeroPointSelection();

				}
		 }
		 if(adS.delayDisplay >= 1000){

		 	 if(GPIO_READ_PT10()){

	          	   adS.zeroTo60times=1;
		          	LCD_DisplayOn();
			 	 }

		 }

		}
		else{


		   if(adS.testMode == 0){ /* measure mode */
		   	    firstPower =1;
		       	adS.zeroPoint_Mode=0;
				adS.key_flag =0;
				adS.unit_setMode=0;
				if(adS.reload_ADCInterrupt ==1){
					adS.reload_ADCInterrupt ++ ;
					ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
					ADIF_ClearFlag();
					ADIE_Enable();
					GIE_Enable();
				}
				if(MCUSTATUSbits.b_ADCdone==1)
				{
					MCUSTATUSbits.b_ADCdone=0;

					TestWorksPrecondition();

				   if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/

				        PositivePressureWorks_Mode();

					}else if(adS.Pressure_sign ==1){ /*Input Negative pressure mode*/

						NegativePressureWorks_Mode();
					}
		        }
		   }
		   if(adS.zeroPoint_Mode ==1){

					SetupZeroPoint_Mode();
			}
		    if(adS.unit_setMode ==1){

				 SetupUnit_Mode();
			}
		}

    }

}
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/******************************************************************************
	*
	*Function Name: long UnitConverter_2V4(long data)
	*Input Reference : converter unit value,This is kgf value
	*Return Reference : NO
	*
	*
******************************************************************************/
long UnitConverter(long data)
{

		BIEARL=0;                                //addr=0
	    BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	    while((BIECN& 0x01)==1);
	    adS.eepromRead_UnitLow_bit=BIEDRL;

     if(adS.eepromRead_UnitLow_bit==0){ /*psi*/

         LCD_WriteData(&LCD4, seg_psi) ;
         return  kgfTOpsi(data) ;
     }
	 else if(adS.eepromRead_UnitLow_bit==1){ /*unit bar*/
     	 LCD_WriteData(&LCD4, seg_bar) ;
     	 return	kgfTObar(data);
	 }
	 else if(adS.eepromRead_UnitLow_bit==2){ /* unit kgf*/

         LCD_WriteData(&LCD4, seg_kgf) ;
         return data;
	 }
	 else if(adS.eepromRead_UnitLow_bit==3){ /*uint mpa*/

	 	 LCD_WriteData(&LCD4, seg_mpa) ;
	 	 return kgfTOmpa(data);
	 }
	 else{
             LCD_WriteData(&LCD4, seg_kgf) ;
             return data;
	 }

}
/******************************************************************************
	*
	*Function Name: long UnitConverter_3V(long data)
	*
	*
	*
******************************************************************************/
unsigned char LowVoltageDetect_3V(void)
{
    unsigned char flag;
    LVD_VolSelect(VLDX_30 );
    LVD_PWRSelect(PWRS_VDD);
    Delay(10);
  if(LVD_GetLVDO())
  {
      flag= 0;    //Higher than detection voltage
  }
  else
  {
      flag= 1;    //Lower than detection voltage
  }
    return flag;
}

/*************************************************************************
  *
  *Function Name : unsigned char LowVoltageDetect
  *
  *
  *
  *
  *
***************************************************************************/
unsigned char LowVoltageDetect_2V4(void)
{
    unsigned char flag;
    LVD_VolSelect(VLDX_24);
    LVD_PWRSelect(PWRS_VDD);
    Delay(10);
  if(LVD_GetLVDO())
  {
      flag= 0;    //Higher than detection voltage
  }
  else
  {
      flag= 1;    //Lower than detection voltage
  }
    return flag;
}
/*****************************************************************************
  *
  *Function Name : unsigned char LowVoltageDisplay(void)
  *
  *
  *
  *
  *
*******************************************************************************/
void LowVoltageDisplay(void)
{

	adS.LVD_3V_flag = LowVoltageDetect_3V();
	if(adS.LVD_3V_flag==0){ /* battery capacity is full*/

	    // LCD_WriteData(&LCD0,symbol_t0);
	     DisplayBatteryCapacityFull();
	}
	else{
	       adS.LVD_2V4_flag = LowVoltageDetect_2V4();
	       if(adS.LVD_2V4_flag == 0){

	       			//LCD_WriteData(&LCD0,symbol_t0);
	       			DisplayBatteryCapacityHalf();
	       }
	       else{
	       	//	LCD_WriteData(&LCD0,symbol_t0);
	       		DispalyBatteryCapacityLow();
	       }
	}

}
/****************************************************************************
  *
  *
  *Function Name : unsigned char LowVoltageDisplay(void)
  *
  *
  *
  *
******************************************************************************/
void SetupZeroPoint_Mode(void)
{
		adS.zeroPoint_Mode =0;
		adS.testMode=0;
		adS.reload_ADCInterrupt = 1;
		TestWorksPrecondition();


		 if(adS.Pressure_sign ==1){
			adS.minusOffset_Value = abs(ADC)  - STD_NEGATIVE_VOLTAGE ; //delta value

			    adS.minusOffset_Value=abs(adS.minusOffset_Value);
				adS.minusOffset_Value=(unsigned char)adS.minusOffset_Value;
			//	adS.minusOffset_Value=DecimalToHex(adS.minusOffset_Value); //WT.EDIT 2020-06-03
			    //write delta data in eeprom negative pressure "-"
				HY17P52WR3(2,0x22,adS.minusOffset_Value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
				if(Flag== 1)
				{
				GPIO_PT16_HIGH();
					while(1);    //fail
				}

		}
		else
		{
			adS.Pressure_sign =0;
			//ADC = ADC * 0.1; //WT.EDIT 2020-06-03 modify
			adS.plusOffset_Value= abs(ADC) -STD_VALUE  ;




				adS.plusOffset_Value =(unsigned char)abs(adS.plusOffset_Value);
			//	adS.plusOffset_Value=DecimalToHex(adS.plusOffset_Value); //WT.EDIT 2020-06-03

				HY17P52WR3(1,0x11,adS.plusOffset_Value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
				if(Flag== 1)
				{
				GPIO_PT16_HIGH();
					while(1);    //fail
				}

	}



}
/**************************************************************
	*
	*Function Name: SetupUnit_Mode(void)
	*
	*
	*
***************************************************************/
void SetupUnit_Mode(void)
	{
	adS.Presskey_flag=0;
	adS.unit_setMode =0 ;
	adS.testMode = 0;
	adS.reload_ADCInterrupt = 1;
    adS.key_flag =0;
  #if DEGUG
	GPIO_PT16_HIGH();
	Delay(20000);
	GPIO_PT16_LOW();
	Delay(20000);
	GPIO_PT16_HIGH();
	Delay(20000);
	GPIO_PT16_LOW();
	#endif

	//BIE Write
	HY17P52WR3(0,0xAA,adS.unitChoose);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
	if(Flag== 1)
	{
		GPIO_PT16_HIGH();
		while(1);    //fail
	}
#if DEGUG
	//BIE Read
	BIEARL=0;                                //addr=0
	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	while((BIECN& 0x01)==1);
	adS.eepromRead_UnitLow_bit=BIEDRL;

	if(adS.eepromRead_UnitLow_bit==0)  LCD_WriteData(&LCD4, seg_psi) ;
	else if(adS.eepromRead_UnitLow_bit==1)LCD_WriteData(&LCD4, seg_bar ) ;
	else if(adS.eepromRead_UnitLow_bit==2)LCD_WriteData(&LCD4, seg_kgf) ;
	else if(adS.eepromRead_UnitLow_bit==3)LCD_WriteData(&LCD4, seg_mpa) ;

#endif

}
/**********************************************************************
	*
	*Function Name :SetupZeroPointSelection
	*
	*
	*
	*
***********************************************************************/
void TestWorksPrecondition(void)
{
	ADC=ADC>>6;

	#if DEGUG
		GPIO_PT16_HIGH();
		Delay(20000);
		GPIO_PT16_LOW();
	#endif
	if((ADC<0)||(ADC>0x80000000))
	{

		adS.Pressure_sign =1;
		//LCD_WriteData(&LCD0,0X08);// "-"minus sign bit

	}
	else
	{
		if(ADC < 17500){
		     adS.Pressure_sign =1;
			 adS.negativeInPositive_flag=1;
		}
		else
		adS.Pressure_sign =0;
	}


}
/**********************************************************************
	*
	*Function Name :void PositivePressureWorks_Mode(void)
	*
	*
	*
	*
***********************************************************************/
void PositivePressureWorks_Mode(void)
{
            long delta,eta;
		 //   unsigned long saveTimes ;
			long LCDDisplay;
			adS.Pressure_sign =0;
		//	static unsigned char i=0;
		   	//BIE Read
			BIEARL=1;                                //addr=1
			BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
			while((BIECN& 0x01)==1);
			adS.plus_revise_flag =BIEDRH ;
			adS.eepromRead_PositiveDeltaLow_bit=BIEDRL;

					if(adS.eepromRead_PositiveDeltaLow_bit+ (ADC * 0.01) >= STD_VALUE){

						delta =abs(ADC) * 0.1 - adS.eepromRead_PositiveDeltaLow_bit ;

					}
					else{

						delta =abs(ADC)* 0.1 + adS.eepromRead_PositiveDeltaLow_bit ;

					}

				if(adS.plus_revise_flag == 0x11){

					if(ADC < 20000 ){
						UnitConverter(0);
						DisplayNum(0);
					    LowVoltageDisplay();
			            Delay(20000);
			          //  saveTimes ++;

						}
						else {   // ADC  >=100000
							eta = delta ;  //WT.EDIT 2020-06-03 MODIYF
							//eta = delta * 0.1;
							//  LCDDisplay= 0.0115 *eta- 20.12; //WT.EDIT 2020-0603 MODIFY y = 0.0115x - 20.12
							LCDDisplay= 0.115 *eta- 217; //WT.EDIT 2020-06-03 //y = 0.0115x - 20.12

							if(LCDDisplay >=1060){
	              					Delay(10000);
								if(LCDDisplay >=1060){
									DisplayHHH();
									LCDDisplay=UnitConverter(LCDDisplay);
									LowVoltageDisplay();
									Delay(20000);
									//saveTimes ++;
								}
							}
							else if(LCDDisplay <1060 && LCDDisplay >=1000){
					
								LCDDisplay=UnitConverter(LCDDisplay);
							    LCDDisplay=Reverse_Data(LCDDisplay);
								DisplayNum(LCDDisplay);
								LowVoltageDisplay();
								Delay(20000);
								//saveTimes ++;
						   }
						   else{

						   	   if(LCDDisplay < 100 ){


                                  LCDDisplay=UnitConverter(LCDDisplay);
							       LCDDisplay=Reverse_Data(LCDDisplay);
						   	   	   DisplayNum2Bit(LCDDisplay);
						   	   	   LowVoltageDisplay();
									DisplayPointP3();
									Delay(20000);
						   	    	
						   	    }
						   	    else{
						   	    LCDDisplay=UnitConverter(LCDDisplay);
							    LCDDisplay=Reverse_Data(LCDDisplay);
								DisplayNum(LCDDisplay);
								LowVoltageDisplay();
								DisplayPointP3();
								Delay(20000);
							    }
								//saveTimes ++;


						   }

				        }
						#if 0
					    if(adS.zeroTo60times ==1){
					    		adS.zeroTo60times =0;
					    		saveTimes =0;
					    		//adS.delayDisplay =0;
					    		i=0;
					    	}
						 else{

						 	   if(saveTimes >65535){
									i++;
									saveTimes =0;
									if(i>=108){
										i=0;
									   LCD_DisplayOff();

									}

							}
						}
					#endif
			}



}
/**********************************************************************
	*
	*Function Name :void NegativePressureWorks_Mode(void)
	*
	*
	*
	*
***********************************************************************/
void NegativePressureWorks_Mode(void)
{
		long theta;
		long LCDDisplay ;
	    adS.Pressure_sign=1;
		if(adS.negativeInPositive_flag==1){
					adS.negativeInPositive_flag=0;
			        theta = ADC * 0.1;

			        LCDDisplay= 20.084 - (0.0116 * theta)   ;       //y = -0.0116x + 20.084

				    if(theta >=1543){

	                    UnitConverter(0);
	                    LCDDisplay = 0;
	                    Delay(20000);

				    }
				    else {

				    	if(theta < 1543 && theta > 880){
						
							LCDDisplay=UnitConverter(LCDDisplay);
							LCDDisplay=Reverse_Data(LCDDisplay);
							DisplayNum2Bit(LCDDisplay);
					    	LowVoltageDisplay();
					    	DisplayPointP3();
							Delay(20000);

				    	}
				    	else{
		                    LCDDisplay=UnitConverter(LCDDisplay);
							LCDDisplay=Reverse_Data(LCDDisplay);
							DisplayNum(LCDDisplay);
					    	LowVoltageDisplay();
					    	DisplayPointP3();
							Delay(20000);
						}

					}


		}
		else{

				//BIE Read

				BIEARL=2;                                //addr=1
				BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
				while((BIECN& 0x01)==1);
				adS.minus_revise_flag = BIEDRH;
				adS.eepromRead_NegativeDeltaLow_bit=BIEDRL; //delat > 0

		        if(adS.eepromRead_NegativeDeltaLow_bit+ ADC * 0.1 >= STD_NEGATIVE_VOLTAGE ){

						theta =abs(ADC)* 0.1 - adS.eepromRead_NegativeDeltaLow_bit ; //delta voltage < 0

				}
				else{

					theta =abs(ADC) * 0.1+ adS.eepromRead_NegativeDeltaLow_bit ;

				}

			if(adS.minus_revise_flag ==0x22)
			{

			 	     LCDDisplay= (0.115 * theta) + 190;        //y = 0.0115x + 20.253

				  if( LCDDisplay > 1090 ){


					LCDDisplay=UnitConverter(LCDDisplay);
					LCDDisplay=Reverse_Data(LCDDisplay);
					LowVoltageDisplay();

				    DisplayLLL();
					Delay(20000);
				}
				else if(LCDDisplay <1090 && LCDDisplay >=1000){


					LCDDisplay=UnitConverter(LCDDisplay);
					LCDDisplay=Reverse_Data(LCDDisplay);

					DisplayNum(LCDDisplay);
					LowVoltageDisplay();
					Delay(20000);
				}
				else{

					LCDDisplay=UnitConverter(LCDDisplay);
					LCDDisplay=Reverse_Data(LCDDisplay);

					DisplayNum(LCDDisplay);
					LowVoltageDisplay();
					DisplayPointP3();
					Delay(20000);
				}


			}
	}
}
/**********************************************************************
	*
	*Function Name :void SetupUnitAndZeroPoint_Mode(void)
	*
	*
	*
	*
***********************************************************************/
void SetupUnitSelection(void)
{
	adS.delayTimes_5=8000;
	adS.delayTimes_5 =0;
	adS.unit_setMode =1;
	adS.zeroPoint_Mode =0;
	adS.testMode =1;
	DisplayUnit();

	adS.delayTimes_3=0;

	switch(adS.plus_uint){
	case psi:
	     adS.plus_uint++;
		 adS.unitChoose = psi;
		 LCD_WriteData(&LCD4,seg_psi);
		adS.delayTimes_5=8000;
	    break;
	case bar:
		 adS.plus_uint++;
		 adS.unitChoose = bar;
		 LCD_WriteData(&LCD4,seg_bar);
		adS.delayTimes_5=8000;
	     break;
	case kgf:
		adS.plus_uint++;
		adS.unitChoose = kgf;
		LCD_WriteData(&LCD4,seg_kgf);
		adS.delayTimes_5=8000;
	     break;
	case mpa:
	     adS.plus_uint=0;
		 adS.unitChoose = mpa;
		 LCD_WriteData(&LCD4,seg_mpa);
		 adS.delayTimes_5=8000;
	     break;
	}

}
/**********************************************************************
	*
	*Function Name :SetupZeroPointSelection
	*
	*
	*
	*
***********************************************************************/
void SetupZeroPointSelection(void)
{
	adS.zeroPoint_Mode = 1;
	adS.unit_setMode = 0;
	adS.testMode =1;
	adS.delayTimes_3=0;
	//display LCD "2Er"
	Display2Er();
	// Delay(20000);

}

/******************************************************************************/
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
	#if 1
	if(TA1IF_IsFlag())  //PT1.0  Timer A1 interrupt flag
	{
		TA1IF_ClearFlag();
		adS.delayTimes_3 ++;
		adS.delayTimes_5++;
		adS.delayDisplay++ ;
	 #if 1
		if(adS.key_flag ==1||adS.key_flag==0) {
			adS.delayTimes_5 = 0;

			adS.delayTimes_3 =0;
		    adS.delayDisplay =0;
			adS.key_flag =2;
		//	GPIO_PT15_HIGH();

		}
	  #endif


	}


	#endif
}

/*----------------------------------------------------------------------------*/
/* End Of File                                                                */
/*----------------------------------------------------------------------------*/
