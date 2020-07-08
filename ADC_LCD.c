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

//#define TEST                    1 //MASK has Be save power
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
float MapZeroPint;

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
          			    }
          
        
                   PositivePressureWorks_Mode();
               
               
          
          }
          else if(adS.Main_zeroPoint_Mode ==1 && adS.access_id_3s==0){

  				     SetupZeroPoint_Mode();

  			   } 
         //else if(adS.Main_unit_setMode ==1){
              // SetupUnit_Mode();

         // }
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
	adS.unitChoose=kgf;
    BIEARL=1;                        //addr=1
    BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
    while((BIECN& 0x01)==1);
    adS.Sign =BIEDRH ;
    if((GPIO_PT1GET(PT15)==0)|| (adS.Sign !=0x11 && adS.Sign !=0x22 && adS.Sign != 0x33)){ //WT.EDIT 2020-07-02
        adS.TheSecondWriteTimes =1;
      }else{
		adS.TheSecondWriteTimes =2; //The second power on be changed battery 
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
 // adS.Main_unit_setMode =1;
  adS.Main_zeroPoint_Mode =0;
  adS.Main_testMode =1;
  adS.Main_unit_setMode =1;
  adS.access_id_5s=0;
  adS.reload_ADCInterrupt = 1;
  adS.setMode =1;

 // adS.Main_unit_setMode =0 ;
  adS.Main_testMode = 0;
  DisplayUnit();
  //Delay(10000);
  adS.plus_uint++;
  if(adS.plus_uint >4)adS.plus_uint=1;

  switch(adS.plus_uint){
  case psi: //1
     adS.unitChoose = psi;
     LCD_WriteData(&LCD4,seg_psi);
     DisplayPointP3(); //
     adS.BeSaveFlag ++ ;
	 if(adS.BeSaveFlag >=3)adS.BeSaveFlag = 4;
  break;
  case bar: //2
     adS.unitChoose = bar;
     LCD_WriteData(&LCD4,seg_bar);
      DisplayPointP2();   //
    break;
  case kgf://3
     
    adS.unitChoose = kgf;
    LCD_WriteData(&LCD4,seg_kgf);
     //DisplayNoPoint();
      DisplayPointP2();
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
  *Function Name:DisplaySelectionUintPoint(void)
  *Function : be save unit value
  *Input Ref:NO
  *Return Ref:NO
  * 
******************************************************************************/
void DisplaySelectionUintPoint(void)
{

  if(adS.unitChoose ==psi ){
        LCD_WriteData(&LCD4, seg_psi) ;
        DisplayPointP3(); //
  }
  else if(adS.unitChoose==bar ){
         LCD_WriteData(&LCD4, seg_bar) ;
         DisplayPointP2();   //
  }
  else if(adS.unitChoose==kgf){
        LCD_WriteData(&LCD4, seg_kgf) ;
        //DisplayNoPoint();
        DisplayPointP2();
  }
  else if( adS.unitChoose==mpa){
        LCD_WriteData(&LCD4, seg_mpa) ;
         DisplayPointP1();
  }
  else if( adS.initialize!=3){
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
    LVD_VolSelect(VLDX_21);//LVD_VolSelect(VLDX_24);//WT.EDIT 2020-07-03
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
    Delay(5000);
    LCD_DisplayOff();
    Delay(5000);
    LCD_DisplayOn();
    Delay(5000);
    LCD_DisplayOff();
    Delay(5000);
    LCD_DisplayOn();
    Delay(5000);
    LCD_DisplayOff();
    Delay(5000);
    LCD_DisplayOn();
    Delay(5000);
    LCD_DisplayOff();
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

    DisplayBatteryCapacityFull(); // DisplayBatteryCapacityHalf();
    adS.LVD_2V4_flag = LowVoltageDetect_2V4();
    if(adS.LVD_2V4_flag == 1){

        DisplayBatteryCapacityHalf();
    }
    else{
          LowVoltageBlink();

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
  if(MapZeroPint>=301){
     
      adS.dError = 1;
  }
  else {
         
         adS.dError =0;

         if(adS.EEr_flag ==0){
              
           adS.set2ErData=MapZeroPint;
           adS.EEr_flag ++ ;
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
    int signflag,a1;
    int index=0 ,data[2],hex=0;
    float temp=0 ;
    float prevalue;
    adS.Main_zeroPoint_Mode =0;
    adS.Main_testMode=0;
    adS.Main_unit_setMode = 0;
    adS.zeroTo120s =1;
    adS.setMode =1;
   

     if(adS.BeSaveFlag <=3 && adS.TheSecondWriteTimes == 1){
         if(MCUSTATUSbits.b_ADCdone==1){
            adS.access_id_5s= 1;
            adS.initialize=3; //flag 
            MCUSTATUSbits.b_ADCdone=0;
            adS.reload_ADCInterrupt = 1;
            adS.MapZero =0;
            ADC =ADC >>6;
                      
           prevalue = 0.0344 * ADC ;  //WT.EDIT 20200703

		 if(prevalue >=300 && prevalue <=520){
          
            
                        temp =prevalue - 400   ;

                       
						#if 0
                       while(temp!=0) {
                          a1=temp;
                          temp=temp/16;
                          data[index]=a1%16;
                           index++;
                        }
                          hex =data[1] << 4 | data[0];
                       adS.checkValue_4 =1;
                   
                     #endif 
						 if(temp ==0){

						     
					        hex =0x00;
                            HY17P52WR3(1,0x33,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }

					    }
						 else if(temp > 0){
						 	 hex =temp;
                           
                            HY17P52WR3(1,0x11,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }
                         

                       }
                       else if(temp< 0){
                         
                            temp = abs(temp);
						    hex =temp;
                            HY17P52WR3(1,0x22,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                               
                               while(1);    //fail
                            }
                          

                       }
         }
		
		 if(prevalue >520){
					//adS.checkValue_5 =1;
	                //adS.CheckValue[2]= 550  - prevalue ;
		 			temp = 550  - prevalue ;
					 if(temp ==0){

						     
					        hex =0x00;
                            HY17P52WR3(2,0x33,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }

					    }
						 else if(temp > 0){
						 	 hex =temp;
                           
                            HY17P52WR3(2,0x11,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }
                         

                       }
                       else if(temp< 0){
                         
                            temp = abs(temp);
						    hex =temp;
                            HY17P52WR3(2,0x22,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                               
                               while(1);    //fail
                            }
                          

                       }

		}
		if(prevalue < 300 && prevalue >150 ){
					//adS.checkValue_2 =1;
		             //adS.CheckValue[1]= 200  - prevalue ;
					 temp = 200  - prevalue ;
					 if(temp ==0){

						     
					        hex =0x00;
                            HY17P52WR3(0,0x33,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }

					    }
						 else if(temp > 0){
						 	 hex =temp;
                           
                            HY17P52WR3(0,0x11,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                           
                            while(1);    //fail
                            }
                         

                       }
                       else if(temp< 0){
                         
                            temp = abs(temp);
						    hex =temp;
                            HY17P52WR3(0,0x22,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                            if(Flag== 1)
                            {
                               
                               while(1);    //fail
                            }
                          

                       }
		                                       
		 }
		 else if(prevalue <150 ){
		        
           temp = 100  - prevalue ;
           if(temp ==0){

                 
                  hex =0x00;
                  HY17P52WR3(3,0x33,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                  if(Flag== 1)
                  {
                 
                  while(1);    //fail
                  }

              }
             else if(temp > 0){
                    hex =temp;
                   
                    HY17P52WR3(3,0x11,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                    if(Flag== 1)
                    {
                   
                    while(1);    //fail
                    }
                         

            }
            else if(temp< 0){
                         
                  temp = abs(temp);
                  hex =temp;
                  HY17P52WR3(3,0x22,hex);  //addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
                  if(Flag== 1)
                  {
                     
                     while(1);    //fail
                  }
                          

              }
		      }

				adS.WriteEepromTimes++;
	            adS.setMode =1;  
			 
	   }
     }
    else{
	      adS.Main_zeroPoint_Mode =0;
	      adS.Main_testMode=0;
	      adS.EEr_flag =0;
	      adS.MapZero = 1;
	      Display2ErP3();
	      Delay(20000);
	      adS.setMode =1;   

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
    float  lamda=0,thelta=0,eta=0,zeta=0,rho=0,omega=0;
    unsigned char highp=0,ee200flag=0,ee550flag=0,ee100flag=0;
    float checkValue=0;
    adS.unit_2 =0;
    
    adS.getSaveTimes++;
 //BIE Read
        BIEARL=1;                        //addr=1
        BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
        while((BIECN& 0x01)==1);
        adS.Sign =BIEDRH ;
        adS.factor=BIEDRL;

		BIEARL=0;                        //addr=1
        BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
        while((BIECN& 0x01)==1);
        ee200flag =BIEDRH ;
        zeta=BIEDRL;

		BIEARL=2;                        //addr=1
        BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
        while((BIECN& 0x01)==1);
        ee550flag =BIEDRH ;
        rho=BIEDRL;

    BIEARL=3;                        //addr=1
        BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
        while((BIECN& 0x01)==1);
        ee100flag =BIEDRH ;
        omega=BIEDRL;
   
    if(MCUSTATUSbits.b_ADCdone==1){
               
			   adS.setMode=0;
               MCUSTATUSbits.b_ADCdone=0;
                ADC = ADC >>6;
				if(adS.Sign == 0x33)eta = 0;
                else if(adS.Sign == 0x11) eta = -adS.factor;
                 // lamda  =    0.0344 * ADC  - adS.factor ;// lamda  =   0.0342 * ADC  - adS.factor ; //WT.EDIT 20200703  adS.coefficient
                   
                else if(adS.Sign == 0x22) eta = adS.factor; //adS.factor = - adS.factor;
                 // lamda  =    0.0344 * ADC  + adS.factor ;
                 lamda  =    0.0344 * ADC  + eta ;
              
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
                           thelta = lamda ;
                           adS.getSaveTimes++;
                           if(adS.Sign == 0x11 || adS.Sign == 0x22||adS.Sign==0x33 ){
                                 adS.initialize++;
                            }
                     }
                }
                else{
                      
                   if(ADC<=(adS.CorrectionValue[0] + 100)){

                        thelta =0;
                        adS.workstation_flag =0;
                        adS.getSaveTimes++;
                        adS.workstation_flag =0;
                
                        if(adS.MapZero == 1 && adS.EEr_flag==0){
                            adS.set2ErData=0;
                            adS.MapZero =0;
                        }
                    }
                    else if(lamda >=1005){
                         
                         highp =1;  
                       
                    }
                    else{
                        highp =0;
                                 
                        if(lamda >= 520 &&(ee550flag ==0x33 ||ee550flag ==0x11||ee550flag ==0x22)){
										  	    if(ee550flag==0x33)checkValue=0;
												else if(ee550flag == 0x11)
												       checkValue = rho;
												else if(ee550flag == 0x22)
													   checkValue = - rho;
												lamda = 0.0344 *ADC  + checkValue ;
												 adS.workstation_flag =1;
										        
										  }
										 
										 
										  if(lamda <300 &&(ee200flag==0x33||ee200flag==0x11||ee200flag==0x22)){   

  												if(ee200flag==0x33)checkValue=0;
  												else if(ee200flag == 0x11)
  												       checkValue = zeta;
  												else if(ee200flag == 0x22)
  													   checkValue = - zeta;
                             lamda = 0.0344 *ADC  + checkValue ;
                             adS.workstation_flag =1;
												}
                        if(lamda <= 150 && (ee100flag==0x33||ee100flag==0x11||ee100flag==0x22)){
                            
                              if(ee100flag==0x33)checkValue=0;
                              else if(ee100flag == 0x11)
                                     checkValue = omega;
                              else if(ee100flag == 0x22)
                                   checkValue = - omega;
                          
												  lamda = 0.0344 *ADC  + checkValue ;
												   adS.workstation_flag =1;
										  }
									    if(adS.MapZero == 1 || adS.dError == 1){

                                          MapZeroPint = lamda;
                                         if(adS.EEr_flag ==0 || adS.dError ==1){
                                              ZeroPointReset_Function();
                                             
                                         }
                                         thelta = lamda - adS.set2ErData;
                                         if(thelta<=0) thelta =0;

                                   }
                                    else
                                    {
                                           
                                          thelta = lamda  ;
										  
                                    }
                                      
                                      if(thelta <= 0x06) {
                                        thelta = 0;
                                        adS.workstation_flag =0;
                                      }
                                      else adS.workstation_flag =1;
                                
                                      adS.getSaveTimes++;
                                      
                      }
                        
                    }
                    if(adS.unitChoose ==psi ) thelta= kgfTOpsi(thelta)  ;//WT.EDIT IC75 but psi
                     if(highp==1){
                        if(lamda >=1007)
                          DisplayHHH();
                        else highp =0;
                         adS.getSaveTimes++;
                    }
                    else if( adS.dError ==1){
                          DisplayErr();
						   adS.workstation_flag =0;
                          adS.getSaveTimes++;
                    }
                    else{
                        
                       DisplayNum4Bytes(thelta);
                       LowVoltageDisplay();
                       DisplaySelectionUintPoint();
                       Delay(20000);
                       Delay(10000);
                       adS.getSaveTimes++;
                       if(adS.workstation_flag==1){
                         if(adS.zeroTo120s==1){
                            adS.BeSureflag =1;
							             adS.second120s=80;
                          }
                       }
                     }

                 

					 if(adS.getSaveTimes>(380 - adS.second120s) && adS.setMode == 0){ //WT.EDIT 2020-07-03
                         if(adS.zeroTo120s ==1 && adS.BeSureflag ==1 ){
                              adS.zeroTo60times =0 ;
                              adS.getSaveTimes=0;
                              adS.zeroTo120s=0;
                              adS.BeSureflag =0;
							  adS.second120s=60;
                              
                          }
                          else if(adS.zeroTo120s==0){
                                 LCD_DisplayOff();
                                adS.zeroTo60times=1;
                                adS.zeroTo120s = 0;
                                Idle()   ; //Sleep();
                                Sleep();
                               
                              
                          }
                          
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
