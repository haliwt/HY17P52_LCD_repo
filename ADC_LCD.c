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

#define kgfTOpsi(kgf)       (1.450 * (kgf))
#define kgfTObar(kgf)   	  (1.0 * (kgf))
#define kgfTOmpa(kgf)	 	    (1.0 * (kgf))

#define STD_VALUE                 30465//WT.EDIT 2020-06-03

//#define STD_NEGATIVE_VOLTAGE      69620//6962 WT.EDIT 2020-06-03
#define DEGUG     				0

#define TEST                    1
#define SAVEPOWER               1
#define NEGAIVE_PRESSURE        0
/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void PGAandADCAccuracyMode(void);
void AccuracyModeADCOFF(void);
void ADCAccuracyMode(void);
void DisplayNum(long Num);
unsigned char  UnitConverter(void);
unsigned char LowVoltageDetect_3V(void);
unsigned char LowVoltageDetect_2V4(void);
void LowVoltageDisplay(void);
void SetupZeroPoint_Mode(void);
//void SetupUnit_Mode(void);
void SetupSaveUnit_ID(unsigned char id);
void PositivePressureWorks_Mode(void);
void SetupUnitSelection(void);
void SetupZeroPointSelection(void);
void ProcessWorksPrecondition(void);
void EEPROM_ReadUnitData_Address0(void);

void ProcessRunsFlag(void);
void LowVoltageBlink(void);
void DisplaySelectionUintPoint(void);

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

void ShowADC (void);
void DisplayNum(long Num);
/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
 unsigned char onpower =0 ;
//CLK Setting
	CLK_CPUCKSelect(CPUS_DHSCK) ;
//GPIO Setting
GPIO_Iint();
#if 0
    TRISC1 = 0x00;
    TRISC2 = 0x00;
    PT1 = 0x00;
    PT1DA = 0x00;
	GPIO_PT1SETPUAll();
	GPIO_PT2SETPUAll();
#endif


//VDDA Setting
	PWR_BGREnable();
	PWR_LDOPLEnable();
	PWR_LDOEnable();
	PWR_LDOSel(LDOC_2V4);
//ADC Setting
	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_1, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);


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
	LCD_PT60Mode(LCD);
	LCD_PT61Mode(LCD);
	LCD_PT62Mode(LCD);
	LCD_PT63Mode(LCD);

//TMA Setting
/*
	TMA1_CLKSelect ( TMAS1_DMSCK );
	TMA1_CLKDiv (DTMA1_TMA1CKDIV8);
	TMA1_ClearTMA1();
	TMA1Enable();
*/
	ADIF_ClearFlag();
	ADIE_Enable();
	GIE_Enable();

	while(1)
	{
        if(GPIO_PT1GET(0)==0 && onpower !=0)
		  {


            Delay(1000);
             if(adS.unit_2 == 0){

                  if(GPIO_PT1GET(0)==0){

                         if(adS.zeroTo60times==1){
                                  SYS_WAKEUP() ; //WT.EDTI 2020-06-13
                                  LCD_DisplayOn();
                                  adS.getSaveTimes=0;
                                  
                          }
                          if(adS.workstation_flag ==1){
                            
                                  adS.zeroTo120s=1;
                                  SYS_WAKEUP() ; //WT.EDTI 2020-06-13
                                  LCD_DisplayOn();
                            }

                    }
                
                 Delay(50000);
                 Delay(50000);


                  // if(adS.delayTimes_3s >=3000&& adS.access_id_3s !=1){ /* zero point mode*/
               if(GPIO_PT1GET(0)==0 && adS.access_id_3s!=1){


                       SetupZeroPointSelection();

                }
                Delay(50000);
                Delay(50000);
                if(GPIO_PT1GET(0)==0 && adS.access_id_5s!=1){

                  adS.unit_2 =1;
                  adS.access_id_3s=1;

                  SetupUnitSelection();
                }
            }
            else{
                Delay(30000);
                if(GPIO_PT1GET(0)==0 && adS.access_id_5s!=1){

                  adS.unit_2 =1;
                  adS.access_id_3s=1;
                  SetupUnitSelection();
                }
            }
        }else{

          if(adS.Main_testMode == 0){
              if(onpower ==0){
                  onpower=1;
                  LCD_DisplayOn();
              }
              ProcessRunsFlag();
              if(adS.reload_ADCInterrupt ==1){
              				adS.reload_ADCInterrupt ++ ;
                      //CLK Setting
                      CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
                      CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
                      //VDDA Setting
                      PWR_BGREnable();
                      PWR_LDOPLEnable();
                      PWR_LDOEnable();
                      PWR_LDOSel(LDOC_2V4);
              				ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_1, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
              				ADIF_ClearFlag();
              				ADIE_Enable();
              				GIE_Enable();
                      Delay(1000);
          			    }
          
           // if(MCUSTATUSbits.b_ADCdone==1){
              //  MCUSTATUSbits.b_ADCdone=0;
               // ADC=ADC>>6;
               // ADC =0.0342 *ADC - 9.7;
               // ShowADC();
                   //   Delay(20000);
                   PositivePressureWorks_Mode();
               
               
           // }
          }
          else if(adS.Main_zeroPoint_Mode ==1 && adS.access_id_3s==0){

  				     SetupZeroPoint_Mode();

  			    }
          else if(adS.Main_unit_setMode ==1){
                SetupUnit_Mode();


            }

       
    }
  }
}
/******************************************************************************
	*
	*Function Name: void ProcessRunFlag(void)
	*Input Reference : NO
	*Return Reference :NO
	*
******************************************************************************/
void ProcessRunsFlag(void)
{
	  adS.Main_zeroPoint_Mode=0;
    adS.Main_unit_setMode =0;
    adS.Main_unit_setMode=0;
    adS.delayTimes_3s=0;
    adS.delayTimes_5s=0;
    adS.access_id_5s=0;
    adS.access_id_3s=0;
    adS.delayDisplay =0;
    adS.unit_2 =0;

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
  adS.delayTimes_5s=0;
  adS.Main_unit_setMode =1;
  adS.Main_zeroPoint_Mode =0;
  adS.Main_testMode =1;
  adS.access_id_5s=0;
  adS.reload_ADCInterrupt = 1;
  DisplayUnit();
  adS.plus_uint++;
  if(adS.plus_uint >4)adS.plus_uint=1;


  switch(adS.plus_uint){
  case psi:

     adS.unitChoose = psi;
     LCD_WriteData(&LCD4,seg_psi);
    
         break;
  case bar:

     adS.unitChoose = bar;
     LCD_WriteData(&LCD4,seg_bar);
    

       break;
  case kgf:

    adS.unitChoose = kgf;
    LCD_WriteData(&LCD4,seg_kgf);
    

       break;
  case mpa:

     adS.unitChoose = mpa;
     LCD_WriteData(&LCD4,seg_mpa);
     
     adS.plus_uint=0;
    break;
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
  HY17P52WR3(0,0xAA,id);  //addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
  if(Flag== 1)
  {
  //  GPIO_PT16_HIGH();
    while(1);    //fail
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

  adS.Main_unit_setMode =0 ;
  adS.Main_testMode = 0;
  adS.unit_2 =0;
 // adS.reload_ADCInterrupt = 1;

   //BIE Write
  HY17P52WR3(0,0x00,0x00);  //addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
  if(Flag== 1)
  {
    GPIO_PT16_HIGH();
    while(1);    //fail
  }
  SetupSaveUnit_ID(adS.unitChoose);


}
/******************************************************************************
  *
  *Function Name: EEPROM_ReadData(void);
  *Input Reference : converter unit value,This is kgf value
  *Return Reference :NO
  *
******************************************************************************/
void EEPROM_ReadUnitData_Address0(void)
{
     unsigned char unitID ; //WT.EDIT 2020-06-09 EDIT cancel "static"
     BIEARL=0;                                //addr=0
     BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
     while((BIECN& 0x01)==1);
    adS.eepromRead_UnitHigh_bit= BIEDRH;
    adS.eepromRead_UnitLow_bit =BIEDRL;

}
/******************************************************************************
	*
	*Function Name: long UnitConverter_2V4(long data)
	*Input Reference : converter unit value,This is kgf value
	*Return Reference : NO
	*
	*
******************************************************************************/
unsigned char  UnitConverter(void)
{

  
  EEPROM_ReadUnitData_Address0();
  if(adS.eepromRead_UnitLow_bit==psi){ /*psi*/

         LCD_WriteData(&LCD4, seg_psi) ;
          DisplayPointP3();

        // return  kgfTOpsi(data) ;
        return psi;
     }
   else if(adS.eepromRead_UnitLow_bit==bar){ /*unit bar*/
        LCD_WriteData(&LCD4, seg_bar) ;
         DisplayPointP2();

       return bar;
   }
   else if(adS.eepromRead_UnitLow_bit==kgf){ /* unit kgf*/

         LCD_WriteData(&LCD4, seg_kgf) ;
         DisplayNoPoint();

          return kgf;
   }
   else if(adS.eepromRead_UnitLow_bit==mpa){ /*uint mpa*/

     LCD_WriteData(&LCD4, seg_mpa) ;
      DisplayPointP1();

     return mpa;
   }
   else if(adS.eepromRead_UnitHigh_bit !=0xAA){


          LCD_WriteData(&LCD4, seg_kgf) ;
           DisplayNoPoint();
           return kgf;
      }
}
/******************************************************************************
  *
  *Function Name:DisplaySelectionUintPoint(void)
  *
  *
  *
******************************************************************************/
void DisplaySelectionUintPoint(void)
{

  if(adS.eepromRead_UnitLow_bit==psi){
       
        DisplayPointP3(); //
  }
  else if(adS.eepromRead_UnitLow_bit==bar){
      
         DisplayPointP2();   //
  }
  else if(adS.eepromRead_UnitLow_bit==kgf){
      
        DisplayNoPoint();
  }
  else if(adS.eepromRead_UnitLow_bit==mpa){
      
         DisplayPointP1();
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
    LVD_VolSelect(VLDX_30);
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
  else {

    adS.LowVoltage_flag=1;
    adS.zeroTo60times=1;

    DisplayBAT();
    Delay(20000);
    LCD_DisplayOff();
    Delay(20000);
    LCD_DisplayOn();
    Delay(20000);
    LCD_DisplayOff();
    Delay(20000);
    LCD_DisplayOn();
    Delay(20000);
    LCD_DisplayOff();
    Delay(20000);
    LCD_DisplayOn();
    adS.unit_2=0;


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


      adS.LVD_3V_flag = LowVoltageDetect_3V();
      if(adS.LVD_3V_flag==0){ /* battery capacity is full*/
          DisplayBatteryCapacityFull();
      }
      else{

             DisplayBatteryCapacityHalf();
             adS.LVD_2V4_flag = LowVoltageDetect_2V4();
             if(adS.LVD_2V4_flag == 0){

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
  adS.Main_zeroPoint_Mode = 1;
  adS.Main_unit_setMode = 0;
  adS.Main_testMode =1;
  adS.zeroTo60times=2;
  //display LCD "2Er"
  Display2Er();

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
    long  formula_Value;
    long  plusOffset_Value;
    adS.Main_zeroPoint_Mode =1;
		adS.Main_testMode=0;
    adS.Main_unit_setMode = 0;
    adS.zeroTo60times=2;

    //if(GPIO_PT1GET(0)==1){

     if(adS.WriteEepromTimes <5){
         if(MCUSTATUSbits.b_ADCdone==1){
              MCUSTATUSbits.b_ADCdone=0;
              adS.reload_ADCInterrupt = 1;
              ADC =ADC >>6;
                  adS.access_id_5s= 1;
    		         // formula_Value =  0.0171 *ADC - 23;
                formula_Value= 0.0342 *ADC - 9.7 - 500;//be changed hardware
                  //ADC = ADC * 0.1; //WT.EDIT 2020-06-03 modify
                      plusOffset_Value= formula_Value ;
                        
                          HY17P52WR3(1,0x0,0x0); //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                          if(Flag== 1){

                               while(1);
                          }  //fail
                         if(plusOffset_Value >=0){

                           HY17P52WR3(1,0x11,plusOffset_Value); //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                           GPIO_PT16_HIGH();
                           if(Flag== 1){

                           while(1);    //fail
                            }
                            adS.delayTimes_5s=0;
                            adS.Main_zeroPoint_Mode =0;
                            adS.unit_2 =0;

                          }
                          else{

                               plusOffset_Value  = abs(plusOffset_Value);
                               HY17P52WR3(1,0x22,plusOffset_Value); //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                               GPIO_PT16_HIGH();

                               if(Flag== 1){

                               while(1);    //fail
                                }

                                adS.delayTimes_5s=0;
                                adS.Main_zeroPoint_Mode =0;
                                adS.unit_2 =0;

                           }
                         adS.WriteEepromTimes++ ;


        }
    }


  else {

          Display2ErP3();
          Delay(20000);
          GPIO_PT16_LOW();
          adS.delayTimes_5s=0;
          adS.WriteEepromTimes++ ;
          adS.Main_zeroPoint_Mode =0;
          adS.unit_2 =0;

  }

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
    unsigned char unitId;
    long LCDDisplay,thelta ;
    unsigned long initialize_ADC[1] ;
    adS.unit_2 =0;
    unitId= UnitConverter();
    adS.getSaveTimes++;
   
   
                  BIEARL=1;                        //addr=1
                  BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
                  while((BIECN& 0x01)==1);
                  adS.ReadEepromID1 = BIEDRH ;
                  adS.ReadEepromValue1= BIEDRL;
                  

        if(MCUSTATUSbits.b_ADCdone==1){
               MCUSTATUSbits.b_ADCdone=0;
                ADC = ADC >>6;
                 

                  if(adS.ReadEepromID1== 0x11) {

                              thelta= 0.0342 *ADC - 9.7  - adS.ReadEepromValue1; // y=0.0343x - 11.712
                             if(unitId==psi) thelta= kgfTOpsi(thelta)     ;
                             adS.initialVoltage = 0;
                           
                             
                  }
                  else if(adS.ReadEepromID1==0x22){

                                          //delta = adS.eepromRead_PositiveDeltaLow_bit ;
                                        thelta= 0.0342 *ADC - 9.7  + adS.ReadEepromValue1;
                                        if(unitId==psi) thelta= kgfTOpsi(thelta) ;
                                        adS.initialVoltage = 0;
                                        
                                       

                  }else {
                   
                    adS.initialVoltage = 1;
                    thelta= 0.0342 *ADC - 9.7 ;
                    if(thelta <= 0) thelta =0 ;
                   
                
                  }
               
                     
                     UnitConverter();
                     if(thelta <= 0x02) thelta =0;
                     DisplayNum4Bytes(thelta);
                     LowVoltageDisplay();
                     DisplaySelectionUintPoint();
                     Delay(20000);
                     Delay(20000);
                     adS.getSaveTimes++;
                     if(adS.initialVoltage ==1)adS.workstation_flag =0;
                     else adS.workstation_flag =1;
                    
        }

   
       //if(adS.getSaveTimes>270){
         if(adS.getSaveTimes>135){
                        
                        if(adS.zeroTo120s ==1 ){
                              adS.zeroTo60times =0 ;
                              adS.getSaveTimes=0;
                              adS.zeroTo120s=0;
                              LCD_DisplayOn();
                          }
                          else{
                                 LCD_DisplayOff();
                                adS.zeroTo60times=1;
                                adS.zeroTo120s = 0;
                                #if SAVEPOWER
                                 Idle()   ; //Sleep();
                                #endif

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
