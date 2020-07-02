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
void UnitConverter(void);
unsigned char LowVoltageDetect_3V(void);
unsigned char LowVoltageDetect_2V4(void);
void LowVoltageDisplay(void);
void SetupZeroPoint_Mode(void);
void SetupUnit_Mode(void);
void SetupSaveUnit_ID(unsigned char id);

void PositivePressureWorks_Mode(void);
void SetupUnitSelection(void);
void SetupZeroPointSelection(void);
void ProcessWorksPrecondition(void);
unsigned char EEPROM_ReadUnitData_Address0(void);

void ProcessRunsFlag(void);
void LowVoltageBlink(void);
void DisplaySelectionUintPoint(void);
void PowerOnToChange(void);
void ZeroPointReset_Function(void);
/*----------------------------------------------------------------------------*/
/* DEFINITIONS                                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global CONSTANTS                                                           */
/*----------------------------------------------------------------------------*/
unsigned char ADCData,ADCData1,ADCData2;
unsigned char Flag;
long	ADC;
float FS30_Display,MapZeroPint;

volatile typedef union _MCUSTATUS
{
  char  _byte;
  struct
  {
    unsigned b_ADCdone:1;
    //unsigned b_TMAdone:1;
    //unsigned b_TMBdone:1;
    //unsigned b_TMCdone:1;
    //unsigned b_Ext0done:1;
    //unsigned b_Ext1done:1;
    //unsigned b_UART_TxDone:1;
    //unsigned b_UART_RxDone:1;
  };
} MCUSTATUS;

MCUSTATUS  MCUSTATUSbits;

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void PGAandADCAccuracyMode(void);
void AccuracyModeADCOFF(void);
void ADCAccuracyMode(void);

/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
 unsigned char onpower =0 ;
 adS.Main_testMode =0;
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
      if(GPIO_PT1GET(PT10)==0 && onpower !=0)
		  {
              Delay(1000);
           
             if(adS.unit_2 == 0){

                  if(GPIO_PT1GET(PT10)==0 ){

                         if(adS.zeroTo60times==1){
                                  SYS_WAKEUP() ; //WT.EDTI 2020-06-13
                                  LCD_DisplayOn();
                                  adS.getSaveTimes=0;
                                  adS.LowVoltage_flag=0;
                                  
                          }
                          if(adS.workstation_flag ==1){
                            
                                  adS.zeroTo120s=1;
                                  SYS_WAKEUP() ; //WT.EDTI 2020-06-13
                                  LCD_DisplayOn();
                                  adS.LowVoltage_flag=0;
                            }

                    }
                
                 Delay(50000);
                 Delay(50000);


                  // if(adS.delayTimes_3s >=3000&& adS.access_id_3s !=1){ /* zero point mode*/
               if(GPIO_PT1GET(PT10)==0 && adS.access_id_3s!=1){


                       SetupZeroPointSelection();
                      
                }
                Delay(50000);
                Delay(50000);
                if(GPIO_PT1GET(PT10)==0 && adS.access_id_5s!=1){

                  adS.unit_2 =1;
                  adS.access_id_3s=1;

                  SetupUnitSelection();
                }
            }
            else{
                Delay(50000);
                if(GPIO_PT1GET(PT10)==0){

                  adS.unit_2 =1;
                  adS.access_id_3s=1;
                  SetupUnitSelection();

                }
           }
        }
        else{

          if(adS.Main_testMode == 0){
              if(onpower ==0){

                  onpower=1;
                  PowerOnToChange();
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
          
        
                   PositivePressureWorks_Mode();
               
               
          
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
  *Function Name: PowerOnToChange(void)
  *Input Reference : NO
  *Return Reference :NO
  *
******************************************************************************/
void PowerOnToChange(void)
{
    SYS_WAKEUP() ; //WT.EDTI 2020-06-13
    LCD_DisplayOn();
     //BIE Read
    BIEARL=1;                        //addr=1
    BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
    while((BIECN& 0x01)==1);
    adS.Sign =BIEDRH ;
    if((GPIO_PT1GET(PT15)==0)||adS.Sign ==0){
      adS.TheSecondWriteTimes =1;
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
    adS.setMode =0;

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

  //*pt = adS.unitChoose;
 // adS.reload_ADCInterrupt = 1;

   //BIE Write
  HY17P52WR3(0,0x00,0x00);  //addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
  if(Flag== 1)
  {
    while(1);    //fail
  }
  SetupSaveUnit_ID(adS.unitChoose);


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
  adS.Main_unit_setMode =1;
  adS.access_id_5s=0;
  adS.reload_ADCInterrupt = 1;
  adS.setMode =1;
  DisplayUnit();
  Delay(10000);
  adS.plus_uint++;
  if(adS.plus_uint >4)adS.plus_uint=1;

  switch(adS.plus_uint){
  case psi: //1
     adS.unitChoose = psi;
     LCD_WriteData(&LCD4,seg_psi);
     DisplayPointP3(); //
  break;
  case bar: //2
     adS.unitChoose = bar;
     LCD_WriteData(&LCD4,seg_bar);
      DisplayPointP2();   //
    break;
  case kgf://3
     
    adS.unitChoose = kgf;
    LCD_WriteData(&LCD4,seg_kgf);
     DisplayNoPoint();
  break;
  case mpa://4
     adS.unitChoose = mpa;
     LCD_WriteData(&LCD4,seg_mpa);
     DisplayPointP1();
  break;
  }
 // SetupSaveUnit_ID(adS.unitChoose);//WT.EDIT 2020-06-29
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
    //WT.EDIT 2020-06-09 EDIT cancel "static"
     unsigned char unitId;
     BIEARL=0;                                //addr=0
     BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
     while((BIECN& 0x01)==1);
    adS.eepromRead_UnitHigh_bit= BIEDRH;
    unitId = BIEDRL;
    return unitId;

}

/******************************************************************************
  *
  *Function Name:DisplaySelectionUintPoint(void)
  *Function : be save unit value
  *Input Ref:NO
  *Return Ref:NO
  * 
******************************************************************************/
void DisplaySelectionUintPoint(void)
{

  if(adS.eepromRead_UnitLow_bit==psi || adS.unitChoose ==psi ){
        LCD_WriteData(&LCD4, seg_psi) ;
        DisplayPointP3(); //
  }
  else if(adS.eepromRead_UnitLow_bit==bar || adS.unitChoose==bar ){
         LCD_WriteData(&LCD4, seg_bar) ;
         DisplayPointP2();   //
  }
  else if(adS.eepromRead_UnitLow_bit==kgf || adS.unitChoose==kgf){
        LCD_WriteData(&LCD4, seg_kgf) ;
        DisplayNoPoint();
  }
  else if(adS.eepromRead_UnitLow_bit==mpa || adS.unitChoose==mpa){
        LCD_WriteData(&LCD4, seg_mpa) ;
         DisplayPointP1();
  }
  else if(adS.eepromRead_UnitHigh_bit !=0xAA && adS.initialize!=3){
          LCD_WriteData(&LCD4, seg_kgf) ;
          DisplayNoPoint();
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
    LVD_PWRSelect(PWRS_VDD); //WT.EDIT

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
    LVD_PWRSelect(PWRS_VDD);//WT.EDIT 2020-06-29
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
  

  adS.zeroTo60times=2;

  }
  else {

    adS.LowVoltage_flag=1;
    adS.zeroTo60times=2;

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
    Delay(20000);
    LCD_DisplayOff();
    Idle()   ; //Sleep();

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
  *Function: setup the zero point of value
  *Inpute Ref: NO
  *Return Ref: NO
  *
***********************************************************************/
void SetupZeroPointSelection(void)
{
  adS.Main_zeroPoint_Mode = 1;
  adS.Main_unit_setMode = 0;
  adS.Main_testMode =1;
  adS.zeroTo120s =1;
  adS.setMode =1;

  Display2Er();
  LCD_DisplayOn();
  adS.zeroTo120s =1;
    adS.setMode =1;
}
/**********************************************************************
  *
  *Function Name :SetupZeroPointSelection
  *Function: setup the zero point of value
  *Inpute Ref: NO
  *Return Ref: NO
  *
***********************************************************************/
void ZeroPointReset_Function(void)
{
  
readData:   if(MCUSTATUSbits.b_ADCdone==1){
          adS.workstation_flag =1;
          MCUSTATUSbits.b_ADCdone=0;
          ADC = ADC >>6;
          if(adS.Sign == 0x11){ 

            FS30_Display  =   0.0343 * ADC  - adS.factor ;

          }
          else if(adS.Sign == 0x22)  //adS.factor = - adS.factor;
          FS30_Display  =   0.0343 * ADC  + adS.factor ;
    }


  if(FS30_Display >301){
     
      adS.dError = 1;
      DisplayErr();
      Delay(20000);
     adS.access_id_3s=0;
     adS.Main_zeroPoint_Mode =1;
     goto readData;
  }
  else if(FS30_Display<=300){
         adS.MapZero = 1;
         adS.dError =0;
         MapZeroPint=FS30_Display ;
         
         DisplayNum4Bytes(0);
         LowVoltageDisplay();
         DisplaySelectionUintPoint();
         Delay(20000);
         adS.Main_zeroPoint_Mode =0;
         adS.Main_testMode=0;

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
    int signflag,a1;
    int index ,data[2],hex;
    float temp ;
    float prevalue;
    adS.Main_zeroPoint_Mode =0;
		adS.Main_testMode=0;
    adS.Main_unit_setMode = 0;
    adS.zeroTo120s =1;
    adS.setMode =1;
    LCD_DisplayOn();

     if(adS.WriteEepromTimes  < 5 && adS.TheSecondWriteTimes==1){
         if(MCUSTATUSbits.b_ADCdone==1){
            adS.access_id_5s= 1;
            adS.initialize=3; //flag 
              MCUSTATUSbits.b_ADCdone=0;
              adS.reload_ADCInterrupt = 1;
              
              ADC =ADC >>6;
                      
                        prevalue = 0.0343 * ADC; 
                        temp =prevalue - 400 +0.5  ;


                        if(temp>=0)signflag=1;
                        else signflag =0;

                        temp = abs(temp);

                       while(temp!=0) {
            							a1=temp;
            					 		temp=temp/16;
          					  		data[index]=a1%16;
          					  		 index++;
          					    }
                          hex =data[1] << 4 | data[0];
                       // adS.factor =prevalue - 400 + 0.5 ;
                        #if 1
                         LCD_DisplayOn();
                        if(signflag==1){
                            GPIO_PT16_LOW();
                            HY17P52WR3(1,0x11,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }
                              LCD_DisplayOn();
                           DisplayNum4Bytes(temp);
                  
                            Delay(20000);

                       }
                       else{
                             GPIO_PT16_HIGH();
                            temp = abs(temp);
                            HY17P52WR3(1,0x22,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                               
                               while(1);    //fail
                            }
                               LCD_DisplayOn();
                             DisplayNum4Bytes(temp);
                  
                            Delay(20000);


                       }
                     #endif 
                        adS.WriteEepromTimes++;
                        adS.setMode =0;   
          
        }
    }
    else{
      adS.Main_zeroPoint_Mode =1;
      adS.Main_testMode=1;
      ZeroPointReset_Function();
      if(adS.dError == 1){
          DisplayErr();
      }
      else{
            adS.access_id_5s= 0;
            Display2ErP3();
            adS.setMode =0;          
            Delay(20000);
      }

    }
}
/**********************************************************************
	*
	*Function Name :void PositivePressureWorks_Mode(void)
	*Funciton: positive pressure measure
	*Input Ref: NO
	*Return Ref:NO
	*
***********************************************************************/
void PositivePressureWorks_Mode(void)
{
     float  lamda,thelta;
    
     

    adS.unit_2 =0;
    adS.eepromRead_UnitLow_bit=EEPROM_ReadUnitData_Address0();
    adS.getSaveTimes++;
#if 1 //BIE Read
        BIEARL=1;                        //addr=1
        BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
        while((BIECN& 0x01)==1);
        adS.Sign =BIEDRH ;
        adS.factor=BIEDRL;
#endif 
   
    if(MCUSTATUSbits.b_ADCdone==1){
               adS.workstation_flag =1;
               MCUSTATUSbits.b_ADCdone=0;
                ADC = ADC >>6;
                if(adS.Sign == 0x11){ 

                   lamda  =   0.0343 * ADC  - adS.factor ;
                   
               
                  }
                else if(adS.Sign == 0x22)  //adS.factor = - adS.factor;
                    lamda  =   0.0343 * ADC  + adS.factor ;
             
              
               if(adS.initialize==0)
                {
                    adS.CorrectionValue[0] =ADC;
                    thelta = adS.CorrectionValue[0];
                    adS.initialize++;
                }
                else if(adS.initialize == 1 || adS.initialize ==2){
                    if(adS.initialize == 1){
                        adS.CorrectionValue[0]  =ADC;
                        thelta = adS.CorrectionValue[0];
                        adS.initialize++ ;
                     }
                     else{

                           lamda  =   0.0343 * ADC  - 12 ;
                           thelta = lamda ;
                           adS.getSaveTimes++;
                           if(adS.Sign == 0x11 || adS.Sign == 0x22)adS.initialize++;
                          }
                }
                else{
                      
                         if(ADC<=(adS.CorrectionValue[0] + 5)){

                              thelta =0;
                              adS.workstation_flag =0;
                              adS.getSaveTimes++;
                              adS.workstation_flag =0;
                          }
                          else if(lamda >=1004){
                               DisplayHHH();
                               Delay(20000);
                          }
                          else{
                                  
                                  FS30_Display = lamda;
                                 
                                  if(adS.MapZero == 1){

                                     thelta = lamda - MapZeroPint ;
                                     if(thelta<=0) thelta =0;

                                  }
                                  else{
                                       thelta = lamda  ;
                                  }
                                  if(thelta <= 0x03) thelta = 0;
                                  adS.getSaveTimes++;
                                  adS.workstation_flag =1;
                           }
                
                    }
                    if(adS.eepromRead_UnitLow_bit==psi || adS.unitChoose ==psi ) thelta= kgfTOpsi(thelta)  ;//WT.EDIT IC75 but psi
                     DisplayNum4Bytes(thelta);
                     LowVoltageDisplay();
                     DisplaySelectionUintPoint();
                     Delay(20000);
                     Delay(20000);
                     adS.getSaveTimes++;
                     if(adS.workstation_flag==1){
                           if(adS.zeroTo120s==1){

                              adS.BeSureflag =1;
                           }
                     }
                    
                     
                    
        }
      if(adS.getSaveTimes>98 && adS.setMode == 0){
                         if(adS.zeroTo120s ==1 && adS.BeSureflag ==1 ){
                              adS.zeroTo60times =0 ;
                              adS.getSaveTimes=0;
                              adS.zeroTo120s=0;
                              adS.BeSureflag =0;
                              LCD_DisplayOn();
                          }
                          else if(adS.zeroTo120s==0){
                                 LCD_DisplayOff();
                                adS.zeroTo60times=1;
                                adS.zeroTo120s = 0;
                                #if SAVEPOWER
                                Idle()   ; //Sleep();
                                Sleep();
                               
                                #endif
                          }
                          
          }
          
}
/*----------------------------------------------------------------------------*/
/* Subroutine Function                                                        */
/*----------------------------------------------------------------------------*/

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
