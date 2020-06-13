
/****************************************************************************
	*
	*This is soft to hight pressure to 500 kpa (72.5psi)
	*
	*
	*
******************************************************************************/
#define  USE_HY17P52_2M

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <SFRType.h>
#include <INT.h>
#include <CLK.h>
#include <PWR.h>
#include <RST.h>
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


#define abs(value)          ((value) >0 ? (value) : (-value) )

#define kgfTOpsi(kgf)       (0.1450 * (kgf))
#define kgfTObar(kgf)   	  (1.0 * (kgf))
#define kgfTOmpa(kgf)	 	    (0.1 * (kgf))

#define STD_VALUE                 105000//WT.EDIT 2020-06-03 //10400//10440//10400

#define STD_NEGATIVE_VOLTAGE      69620//6962 WT.EDIT 2020-06-03
#define DEGUG     				0

#define TEST                    1
#define SAVEPOWER               1
#define NEGAIVE_PRESSURE        0
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
//void SetupUnit_Mode(void);
void SetupSaveUnit_ID(unsigned char id);
void PositivePressureWorks_Mode(void);
void NegativePressureWorks_Mode(void);
void SetupUnitSelection(void);
void SetupZeroPointSelection(void);
void ProcessWorksPrecondition(void);
unsigned char EEPROM_ReadUnitData_Address0(void);
//void DisplaySelectionUintPoint(void);
void ProcessRunsFlag(void);
void LowVoltageBlink(void);
/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
  //  static unsigned int delayTimes =0;
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


    if(GPIO_READ_PT10()==0 && firstPower !=0)
		{

              //  adS.key_flag=adS.key_flag ^ 0x01; /* check process  ISR()__inptrrupt reference */
              adS.key_flag =2;

              if(adS.delayTimes_5s >= 12000 && adS.access_id_5s!=1 ){ /*unit set mode*/

                if(GPIO_READ_PT10()==0){
                
                  adS.access_id_3s=1;
                  SetupUnitSelection();
                }

              }

              if(adS.delayTimes_3s >=5000&& adS.access_id_3s !=1){ /* zero point mode*/

                if(GPIO_READ_PT10()==0){
                     SetupZeroPointSelection();
                    }
              }
              if(adS.delayDisplay >= 1200 ){/* Wake up screen display wake up sleep*/

                  if(GPIO_READ_PT10()==0){

                      if(adS.zeroTo60times==1){
                            Delay(1000);
                  	   	    if(GPIO_READ_PT10()==0){
                      	   	    LCD_DisplayOn();
                                adS.getSaveTimes=0;
                                adS.LowVoltage_flag=0;
                                SYS_WAKEUP() ; //WT.EDTI 2020-06-13 
                                }
                        }else if(adS.zeroTo60times==2){
                            Delay(1000);
                  	   	    if(GPIO_READ_PT10()==0){
                      	   	    LCD_DisplayOn();
                                adS.getSaveTimes=0;
                                adS.LowVoltage_flag=0;
                                SYS_WAKEUP() ;//WT.EDTI 2020-06-13 
                                }

                        }
                        else if(adS.workstation_flag ==1){
                            Delay(1000);
                             if(GPIO_READ_PT10()==0){
                                adS.zeroTo60times=2;
                                adS.LowVoltage_flag=0;
                                SYS_WAKEUP() ;//WT.EDTI 2020-06-13 
                             }
                        }

                  }
              }
    }// GPIO_READ_PT10()=0 END
  	else{
          if(adS.testMode == 0){ /* measure mode */
              firstPower =1;
              ProcessRunsFlag();

    			   if(adS.reload_ADCInterrupt ==1){
        				adS.reload_ADCInterrupt ++ ;
        				ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
        				ADIF_ClearFlag();
        				ADIE_Enable();
        				GIE_Enable();
    			    }
    			   if(MCUSTATUSbits.b_ADCdone==1){
      					MCUSTATUSbits.b_ADCdone=0;

      					ProcessWorksPrecondition();
                if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/

                    PositivePressureWorks_Mode();
                  }
                #if NEGATIVE_PRESSURE
                if(adS.Pressure_sign ==1){ /*Input Negative pressure mode*/

      						   NegativePressureWorks_Mode();
                   }
               #endif 
              }
          }
  	      if(adS.zeroPoint_Mode ==1){

  				   SetupZeroPoint_Mode();
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
	*Function Name: void ProcessRunFlag(void)
	*Input Reference : NO
	*Return Reference :NO
	*
******************************************************************************/
void ProcessRunsFlag(void)
{
	  adS.zeroPoint_Mode=0;
    adS.key_flag =0;
    adS.unit_setMode=0;
    adS.delayTimes_3s=0;
    adS.delayTimes_5s=0;
    adS.access_id_5s=0;
    adS.access_id_3s=0;
    adS.delayDisplay =0;

}
/******************************************************************************
	*
	*Function Name: EEPROM_ReadData(void);
	*Input Reference : converter unit value,This is kgf value
	*Return Reference :NO
	*
******************************************************************************/
unsigned char EEPROM_ReadUnitData_Address0(void)
{
     unsigned char unitID = kgf; //WT.EDIT 2020-06-09 EDIT cancel "static"
     BIEARL=0;                                //addr=0
	   BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	   while((BIECN& 0x01)==1);
     adS.eepromRead_UnitHigh_bit= BIEDRH;
	   unitID=BIEDRL;
     return unitID;
}
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
        unsigned char uid=0; 

    uid = EEPROM_ReadUnitData_Address0();
    if(adS.eepromRead_UnitHigh_bit == 0xAA)
       adS.eepromRead_UnitLow_bit  = uid;
    else adS.eepromRead_UnitLow_bit = kgf;
    
    switch(adS.eepromRead_UnitLow_bit){

      case psi:
         LCD_WriteData(&LCD4, seg_psi) ;
         DisplayPointP3();
         return kgfTOpsi(data);

      break;

      case bar:
        LCD_WriteData(&LCD4, seg_bar) ;
        DisplayPointP1();
        return	kgfTObar(data);
      break;

      case kgf:
        LCD_WriteData(&LCD4, seg_kgf) ;
        DisplayPointP3();
         return data;
      break;

      case mpa:
       LCD_WriteData(&LCD4, seg_mpa) ;
       DisplayPointP1();
      return kgfTOmpa(data);
      break;

      default :
           
      break;




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
  *Function : delected Low Voltage value
  *
  *
  *
***************************************************************************/
unsigned char LowVoltageDetect_2V4(void)
{
    unsigned char flag;
    LVD_VolSelect(VLDX_20);
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
  *Function Name : void LowVoltageBlink(void)
  *Input Regerence : No
  *Return Reference :NO
  *
*******************************************************************************/
void LowVoltageBlink(void)
{
  if(adS.LowVoltage_flag==1){

  LCD_DisplayOff();
  adS.zeroTo60times=1;

  }
  else{

    DisplayBAT();
    Delay(10000);
    LCD_DisplayOff();
    Delay(5000);
    LCD_DisplayOn();
    Delay(5000);
    LCD_DisplayOff();

    adS.LowVoltage_flag=1;
    LCD_DisplayOff();
    adS.zeroTo60times=1;
  }
}
/*****************************************************************************
  *
  *Function Name : unsigned char LowVoltageDisplay(void)
  *Function : detected low voltage is 3V
  *Input Regerence : No
  *Return Reference :NO
  *
*******************************************************************************/
void LowVoltageDisplay(void)
{
  unsigned char LVD_2V4_flag=0 ;
  unsigned char LVD_3V_flag =0;
	LVD_3V_flag = LowVoltageDetect_3V();
	if(LVD_3V_flag==0){ /* battery capacity is full*/
      DisplayBatteryCapacityFull();
	}
	else{
	       LVD_2V4_flag = LowVoltageDetect_2V4();
	       if(LVD_2V4_flag == 0){
	       			DisplayBatteryCapacityHalf();
	       }
	       else{
                DispalyBatteryCapacityLow();
    	       	  #ifndef TEST
                  LowVoltageBlink();
                #endif
              }
      }
}
/****************************************************************************
  *
  *Function Name : unsigned char LowVoltageDisplay(void)
  *Function :setup zero point basie
  *Input Reference :NO
  *Return Reference : NO
  *
******************************************************************************/
void SetupZeroPoint_Mode(void)
{
    long  minusOffset_Value;
    long  plusOffset_Value;
    adS.zeroPoint_Mode =0;
		adS.testMode=0;
		adS.reload_ADCInterrupt = 1;
		ProcessWorksPrecondition();
    adS.access_id_5s= 1;

    #if NEGATIVE_PRESSURE 
  		if(adS.Pressure_sign ==1){ /* Negative revise data "-"  */
            minusOffset_Value = abs(ADC)  - STD_NEGATIVE_VOLTAGE ; //delta value

            minusOffset_Value=abs(minusOffset_Value);
            minusOffset_Value=(unsigned char)minusOffset_Value;

            //BIE Read
            BIEARL=2;                                //addr=1
            BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
            while((BIECN& 0x01)==1);
            adS.minus_revise_flag = BIEDRH;

            if(adS.minus_revise_flag==0x22 && GPIO_READ_PT15() !=0){

                adS.delayTimes_5s=0;
              }
            else{

                //write delta data in eeprom negative pressure "-"
                HY17P52WR3(2,0x22,minusOffset_Value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                if(Flag== 1){
                //  GPIO_PT16_HIGH();
                  while(1);    //fail
                }
                      adS.delayTimes_5s=0;
            }
        }
    #endif
		{ /* Positive revise data for "+*/
              adS.Pressure_sign =0;
              //ADC = ADC * 0.1; //WT.EDIT 2020-06-03 modify
              plusOffset_Value= abs(ADC) -STD_VALUE  ;
              plusOffset_Value =(unsigned char)abs(plusOffset_Value);

              BIEARL=1;                       //addr=1
              BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
              while((BIECN& 0x01)==1);
              adS.plus_revise_flag =BIEDRH ;

              if(adS.plus_revise_flag==0x11 && GPIO_READ_PT15() !=0 ){

                adS.delayTimes_5s=0;
              }
              else{
                  HY17P52WR3(1,0x11,plusOffset_Value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                  if(Flag== 1){
                      //GPIO_PT16_HIGH();
                      while(1);    //fail
                  }

                  adS.delayTimes_5s=0;
              }
    }
}
/**************************************************************
	*
	*Function Name: SetupUnit_Mode(void)
	*Function : setup unit and save
	*
	*
***************************************************************/
void SetupSaveUnit_ID( unsigned char id)
{
	 //BIE Write
	HY17P52WR3(0,0xAA,id);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
	if(Flag== 1)
	{
	//	GPIO_PT16_HIGH();
		while(1);    //fail
	}


}
/**********************************************************************
  *
  *Function Name :void SetupUnitAndZeroPoint_Mode(void)
  *Function : setup selection which unit
  *Input Reference: NO
  *Return Reference : NO
  *
***********************************************************************/
void SetupUnitSelection(void)
{
  unsigned char unit_s= kgf;
  adS.delayTimes_5s =0;
  adS.unit_setMode =1;
  adS.zeroPoint_Mode =0;
  adS.testMode =1;
  adS.access_id_5s=0;
  DisplayUnit();

  switch(unit_s){
  case psi:
     LCD_WriteData(&LCD4,seg_psi);
     adS.unitChoose = psi;
     adS.delayTimes_5s=9000;
     if(GPIO_READ_PT10()==0){
       unit_s++; 
     }else adS.unitChoose = psi;
       SetupSaveUnit_ID(adS.unitChoose);
      break;
  case bar:
     adS.unitChoose = bar;
     LCD_WriteData(&LCD4,seg_bar);
     adS.delayTimes_5s=9000;
      if(GPIO_READ_PT10()==0){
       unit_s++; 
     }else adS.unitChoose = bar;
        SetupSaveUnit_ID(adS.unitChoose);
       break;
  case kgf:
    adS.unitChoose = kgf;
    LCD_WriteData(&LCD4,seg_kgf);
     adS.delayTimes_5s=9000;
      if(GPIO_READ_PT10()==0){
       unit_s++; 
     }else adS.unitChoose = kgf;
       SetupSaveUnit_ID(adS.unitChoose);
       break;
  case mpa:
     adS.unitChoose = mpa;
     LCD_WriteData(&LCD4,seg_mpa);
      adS.delayTimes_5s=9000;
     if(GPIO_READ_PT10()==0){
         unit_s = psi;
     }else adS.unitChoose = mpa;
      SetupSaveUnit_ID(adS.unitChoose);
    break;
  default :
     break;
 
  }

}
/**********************************************************************
	*
	*Function Name :SetupZeroPointSelection
	*Funciton: positive pressure works preconditon
	*
	*
	*
***********************************************************************/
void ProcessWorksPrecondition(void)
{
	  ADC=ADC>>6;
    #if NEGATIVE_PRESSURE 
	  if((ADC<0)||(ADC>0x80000000))
			{

				adS.Pressure_sign =1;
				//LCD_WriteData(&LCD0,0X08);// "-"minus sign bit

			}
   
			else
			{
				if(ADC < 17000){
				     adS.Pressure_sign =1;
					 adS.negativeInPositive_flag=1;
				}
				else
				adS.Pressure_sign =0;
			}
    #endif 


}
/**********************************************************************
	*
	*Function Name :void PositivePressureWorks_Mode(void)
	*Funciton: positive pressure measure
	*
	*
	*
***********************************************************************/
void PositivePressureWorks_Mode(void)
{
    long delta,eta;
    long LCDDisplay;
    unsigned long initialize_ADC ;
    unsigned char readInitial_flag=0;
    adS.Pressure_sign =0;
   // eta = ADC * 0.1 ;  //WT.EDIT 2020-06-12 CAECEL
    adS.getSaveTimes++;
   
     

        //BIE Read
		    BIEARL=1;                        //addr=1
		    BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
		    while((BIECN& 0x01)==1);
		    adS.plus_revise_flag =BIEDRH ;
		    adS.eepromRead_PositiveDeltaLow_bit=BIEDRL;

		    		//if(adS.eepromRead_PositiveDeltaLow_bit+ (ADC * 0.01) >= STD_VALUE){
		    if(adS.eepromRead_PositiveDeltaLow_bit + eta >= STD_VALUE){
              eta = ADC * 0.1 ; //end number don't cance
		    			delta =eta - adS.eepromRead_PositiveDeltaLow_bit ;

		    	}
		    else{
              eta = ADC * 0.1 ;
		    			delta =eta  + adS.eepromRead_PositiveDeltaLow_bit ;

		    }

		    if(adS.plus_revise_flag == 0x11){


            
		    		if((ADC < 27800) || (ADC < initialize_ADC) ){

                if(readInitial_flag==0 && readInitial_flag!= 0x33 ){
              
                    //BIE Read
                    BIEARL=3;                                //addr=3
                    BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
                    while((BIECN& 0x01)==1);
                    readInitial_flag =BIEDRH ;
                    initialize_ADC=BIEDRL;
                    initialize_ADC =initialize_ADC * 1000;
              }

  		    			UnitConverter(0);
  		    			DisplayNum(0);
  		    		  LowVoltageDisplay();
  		    		  DisplaySignPlus();
  		          Delay(20000);

                adS.getSaveTimes++;
                adS.workstation_flag =0;

            }
		    		else {
		    				 adS.workstation_flag =1;
		    				//eta = delta * 0.1;
		    				//  LCDDisplay= 0.0115 *eta- 20.12; //WT.EDIT 2020-0603 MODIFY y = 0.0115x - 20.12
		    				LCDDisplay= 0.115 *delta- 220; //WT.EDIT 2020-06-03 //y = 0.0115x - 20.392

		    				if(LCDDisplay >=1070){
                       // DisplayHHH();
                    LCDDisplay=UnitConverter(LCDDisplay);
                    DisplayNum(LCDDisplay);
                    LowVoltageDisplay();
                    Delay(20000);
                    adS.getSaveTimes++;
                }
		    				else if(LCDDisplay <1060 && LCDDisplay >=1000){

  		    					LCDDisplay=UnitConverter(LCDDisplay);

  	                if(adS.eepromRead_UnitLow_bit==psi)DisplayNum(LCDDisplay);
  	                else if(adS.eepromRead_UnitLow_bit==mpa)DisplayNum(LCDDisplay);
  	                else
  	                DisplayNum4Bytes(LCDDisplay);
  		    					LowVoltageDisplay();
  		    					DisplaySignPlus();
  		    				//	DisplaySelectionUintPoint();
  		    					Delay(20000);
  		    					adS.getSaveTimes++;


		    			   }
		    			   else{

		    			   	  if(LCDDisplay < 100 ){
  		    						LCDDisplay=UnitConverter(LCDDisplay);

  		    						if(adS.eepromRead_UnitLow_bit==mpa)DisplayNumOneByte(LCDDisplay);
  		    						else
  		    						DisplayNum2Bit(LCDDisplay);
  		    						LowVoltageDisplay();
  		    						DisplaySignPlus();
  		    						Delay(20000);
  		    						adS.getSaveTimes++;
                    }
		    			   	  else{
                          LCDDisplay=UnitConverter(LCDDisplay);

                          DisplayNum(LCDDisplay);
                          LowVoltageDisplay();
                          DisplaySignPlus();
                          Delay(20000);
                          adS.getSaveTimes++;
                        }
                      }
		            }
		            #if 1
		                if(adS.getSaveTimes>225){
		                    if(adS.zeroTo60times ==2){
		                        adS.zeroTo60times =0 ;
		                        adS.getSaveTimes=0;
		                    }
		                    else{
		                            LCD_DisplayOff();
		                            adS.zeroTo60times=1;
                                #if SAVEPOWER
                                  Sleep();
                                #endif
		                    }
		                }
		            #endif

		    }
		    #if 1
		    if(adS.plus_revise_flag !=0x11){

		    		   if(initialize_ADC != 0x33){
                     initialize_ADC =(unsigned int) (ADC * 0.001);
                      //write delta data in eeprom negative pressure "-"
                     HY17P52WR3(3,0x33,initialize_ADC); //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                     if(Flag== 1){
                      //  GPIO_PT16_HIGH();
                      while(1);    //fail
                    }
              }
                ADC=UnitConverter(ADC);
					      DisplayNum(ADC);
		    		    LowVoltageDisplay();
		    		    DisplaySignPlus();
		    
			}
		    #endif

}
/**********************************************************************
	*
	*Function Name :void NegativePressureWorks_Mode(void)
	*
	*
	*
	*
***********************************************************************/
#if NEGATIVE_PRESSURE
void NegativePressureWorks_Mode(void)
{
		long theta;
		long LCDDisplay ; //"-"
	    adS.Pressure_sign=1;

	  if(adS.negativeInPositive_flag==1){
            adS.negativeInPositive_flag=0;

            theta = ADC * 0.1;

            LCDDisplay= 200.84 - (0.115 * theta)   ;   //y = -0.0116x + 20.084//y = -0.0115x + 20.194

            if(theta >=1600 && theta < 1750){

                UnitConverter(0);
                DisplayNum(0);
                Delay(20000);
                adS.getSaveTimes++;
                adS.workstation_flag =0;
            }
            else {
                adS.workstation_flag =1;
                LCDDisplay=UnitConverter(LCDDisplay);
                DisplayNum(LCDDisplay);
                LowVoltageDisplay();
                DisplaySignMinus();
              //  DisplaySelectionUintPoint();
                Delay(20000);
                adS.getSaveTimes++;
            }
        }
		else if(ADC < 0){
                adS.workstation_flag =1;
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

			 	   LCDDisplay= (0.115 * theta) + 180;        //y = 0.0115x + 20.253

				  if( LCDDisplay >= 1050 ){

                    UnitConverter(0);
                    LowVoltageDisplay();
                    DisplayLLL();//"-"
                    Delay(20000);
                    adS.getSaveTimes++;
				}
				else if(LCDDisplay <1050 && LCDDisplay >=1000){

          LCDDisplay=UnitConverter(LCDDisplay);
					if(adS.eepromRead_UnitLow_bit==psi)DisplayNum(LCDDisplay);
					else if(adS.eepromRead_UnitLow_bit==mpa)DisplayNum(LCDDisplay);
				    else
					DisplayNum4Bytes(LCDDisplay);

					LowVoltageDisplay();
					DisplaySignMinus();
					//DisplaySelectionUintPoint();

					Delay(20000);
          adS.getSaveTimes++;
				}
				else{

					LCDDisplay=UnitConverter(LCDDisplay);

					DisplayNum(LCDDisplay);
					LowVoltageDisplay();
					DisplaySignMinus();
				   // DisplaySelectionUintPoint();
					Delay(20000);
          adS.getSaveTimes++;
				}


			}
	}
    if(adS.getSaveTimes>60){
        if(adS.zeroTo60times ==2){
            adS.zeroTo60times =0 ;
            adS.getSaveTimes=0;
        }
        else{
                LCD_DisplayOff();
                adS.zeroTo60times=1;
        }
    }

}
#endif 

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
	adS.delayTimes_3s=0;
	//display LCD "2Er"
	Display2Er();
	

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
    #if 1
		adS.delayTimes_3s ++;
		adS.delayTimes_5s++;
		adS.delayDisplay++ ;
	//	adS.getSaveTimes=0;
	    //adS.zeroTo60times=1;
		if(adS.key_flag ==1||adS.key_flag==0) {
			adS.delayTimes_5s = 0;

			adS.delayTimes_3s =0;
		    adS.delayDisplay =0;
			adS.key_flag =2;
			GPIO_PT15_HIGH();


		}
	  #endif


	}


	#endif
}

/*----------------------------------------------------------------------------*/
/* End Of File                                                                */
/*----------------------------------------------------------------------------*/
