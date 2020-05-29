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

#define kgfTOpsi(kgf)       (0.145 * (kgf))
#define kgfTObar(kgf)   	(0.01 * (kgf))
#define kgfTOmpa(kgf)	 	(0.1 * (kgf))

#define STD_VALUE                 6524

#define STD_NEGATIVE_VOLTAGE      6346//6344//6343


/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
unsigned char HY17P52WR3(unsigned char Addr,unsigned char DataH,unsigned char DataL);
void HY17P52WR3Delay(char ms);

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
   //unsigned b_TMBdone:1;
  // unsigned b_TMCdone:1;
  //unsigned b_Ext0done:1;
  // unsigned b_Ext1done:1;
  // unsigned b_UART_TxDone:1;
  // unsigned b_UART_RxDone:1;
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
long UnitConverter(long data);
//void NegativePressure_Display(void);
/*----------------------------------------------------------------------------*/
/* Main Function                                                              */
/*----------------------------------------------------------------------------*/

void main(void)
{
   
    float LCDDisplay=0;
	long delta=0,theta=0,n=0;

   //CLK Setting
	//CLK_CPUCKSelect(CPUS_DHSCK) ;
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

	
   
	ADIF_ClearFlag();
	ADIE_Enable();
	GIE_Enable();
    
	while(1)
	{
	    zeroPoint:  
		
		if(GPIO_READ_PT10())
		{
		
		  //  adS.key_flag=adS.key_flag ^ 0x01; /* check process  ISR()__inptrrupt reference */
		      	GIE_Disable();
				
				if(adS.Presskey_flag==0){
					Delay(20000);
					Delay(20000);
					Delay(20000);
					Delay(20000);
					
				    if(adS.resetZeroDisplay==0 ){ /* zero point mode*/

							     adS.resetZeroDisplay++;
							     adS.zeroPoint_Mode =1;
							     adS.unit_setMode =0;
			                     adS.testMode=0;
							     Display2Er();
								 Delay(20000);
								 Delay(10000);
							     goto zeroPoint ;
						}

						        Delay(20000);
								Delay(20000);
								Delay(20000);
								Delay(20000);
								adS.Presskey_flag=1;
								adS.zeroPoint_Mode =0;
							    
					           
					 }
		             else {

				      
				    
				        Delay(20000);	
				        Delay(10000);
				       
				    }

			    	//Delay(5000);	
			     
		       
		            adS.unit_setMode =1;
					adS.zeroPoint_Mode =0;
					adS.testMode =1;
					DisplayUnit();
				 
				
				
			     switch(adS.plus_uint){
					case psi: 
					     adS.plus_uint++;
						 adS.unitChoose = psi;
						// EEPROM_WriteWord(0,0,0x00);
						 
					     GPIO_PT15_HIGH();
						LCD_WriteData(&LCD4,seg_psi);
					     Delay(20000);	
					     Delay(10000);
					    break;
					case bar:
						 adS.plus_uint++;
						 adS.unitChoose = bar;
						 GPIO_PT15_LOW();
						 // EEPROM_WriteWord(0 ,0,0x01);
						  LCD_WriteData(&LCD4,seg_bar);
						  Delay(20000);	
						  Delay(10000);
					     break;
					case kgf:
						adS.plus_uint++;
						adS.unitChoose = kgf;
						 GPIO_PT15_HIGH();
						 //EEPROM_WriteWord(0 ,0,0x03);
						 LCD_WriteData(&LCD4,seg_kgf);
					     Delay(20000);
					     Delay(10000);	
					
					     break;
				    case mpa:
					     adS.plus_uint=0;
						 adS.unitChoose = mpa;
						 GPIO_PT15_LOW();
						 // EEPROM_WriteWord(0 ,0,0x04);
						  LCD_WriteData(&LCD4,seg_mpa);
						  
						 Delay(20000);
						 Delay(10000);	
					     break;
				     }
			 }
		     else{
		   	
		    #if 1  
         
		   if(adS.testMode == 0){ /* measure mode */
		       	adS.zeroPoint_Mode=0;
				adS.unit_setMode=0;
				adS.resetZeroDisplay=0;
				if(adS.reload_ADCInterrupt == 1){
					adS.reload_ADCInterrupt =0;
					ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
					ADIF_ClearFlag();
					ADIE_Enable();
					GIE_Enable();

				}
			
				if(MCUSTATUSbits.b_ADCdone==1)
				{
					MCUSTATUSbits.b_ADCdone=0;
					
					ADC=ADC>>6;
					
					ADC = ADC * 0.1 ;
					
					if((ADC<0)||(ADC>0x80000000))
					{
						
						adS.Pressure_sign =1;
					}
					else
					{
						adS.Pressure_sign =0;
						      
					}
				if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/

				         n = ADC ;
				         LCDDisplay= (0.1 * n)-364 ;  //y = 0.0175x - 36.495  //= 0.0175x - 36.495 
		           
	                  
		                 if(adS.plus_revise_flag ==1){
		                 
		                 if(n<2000)DisplayNum(ADC);
					   
						 else if( (LCDDisplay *10) < 2875){
							    LCDDisplay= 0.125 *n- 202.86; //y = 0.0125x - 20.286
						        LCDDisplay=Reverse_Data(LCDDisplay);
						        LCDDisplay=UnitConverter(LCDDisplay);
						        DisplayNum(LCDDisplay);

								Delay(20000);
				
						 }
						 else {
							
						        if(adS.p_offset_value >=0) //WT.EDIT 2020-05-28
							    n =abs(ADC)- abs(adS.p_offset_value);
							    else  n =abs(ADC) + abs(adS.p_offset_value);
							    LCDDisplay= 56193  - (8.47 * n) ;//y=-0.846x + 5619.3
							    LCDDisplay=Reverse_Data(LCDDisplay);
							    LCDDisplay=UnitConverter(LCDDisplay);
								DisplayNum( LCDDisplay);
								Delay(20000);
									
								}
									
							}
							else
							{
								ADC=Reverse_Data(ADC);
								DisplayNum(ADC);
								Delay(20000);

							}
						}
										
			    else { /*Input Negative pressure mode*/
						adS.Pressure_sign =1;
						delta  = ADC ;
                        
					    theta= abs(ADC) - adS.m_offset_value;  
					   if(adS.minus_revise_flag==1){

					   	    //LCDDisplay= 0.12*theta + 255;//LCDDisplay= 0.012*p + 24.76;
					   	   if(delta >=0 ){
					   	   	 LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
					   	   	 LCDDisplay=Reverse_Data(LCDDisplay);
					   	   	 LCDDisplay=UnitConverter(LCDDisplay);
							 DisplayNum(LCDDisplay);
							 Delay(20000);

					   	   }
					   	   else{
						            #if 0
						     		if(abs(delta)> 6343){
										DisplayHycon();
										Delay(20000);
						     		}
						       
						    		#endif 
									LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
								    LCDDisplay=Reverse_Data(LCDDisplay);
								    LCDDisplay=UnitConverter(LCDDisplay);
									DisplayNum( LCDDisplay);
									Delay(20000);
								
						    }
						}
						else{

							ADC = abs(ADC);
							ADC=Reverse_Data(ADC);
							DisplayNum(ADC);
							Delay(20000);
						}
					}
		        } 
		    }//end ---testMode 
  
		   if(adS.zeroPoint_Mode == 1){ /*zero point mode */
   	        
   	            adS.resetZeroDisplay=0;
				adS.zeroPoint_Mode =0;
			    adS.testMode=0;
				ADC=ADC>>6;
				ADC = ADC * 0.1;
				if((ADC<0)||(ADC>0x80000000))
				{
					
					adS.Pressure_sign =1;
				}
				else
				{
					adS.Pressure_sign =0;
					
				}
		   
			//	adS.Error_Positive_flag++; //cyclic 
		       /* 找误�?*/
				if(adS.Pressure_sign==1){ /*negative pressure "-"*/
					adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1;
					adS.minus_revise_flag=1;
					
				}
				else{ /*positive pressure +*/
					
					
					adS.p_offset_value= abs(STD_VALUE) -abs(ADC) + 1; 
					adS.plus_revise_flag =1;
					adS.p_offset_value=Reverse_Data(adS.p_offset_value);
					DisplayNum( adS.p_offset_value);
					Delay(20000);
				}
			
			}//end ----zeroPointMode
			#endif 
			if(adS.unit_setMode ==1){

			    adS.Presskey_flag=0;
			    adS.unit_setMode =0 ;
				adS.testMode = 0;
				adS.reload_ADCInterrupt = 1;
				adS.resetZeroDisplay=0;
              
			      
			     GPIO_PT16_HIGH();
			     Delay(20000);
			      GPIO_PT16_LOW();
			      Delay(20000);
			      GPIO_PT16_HIGH();
			      Delay(20000);
			      GPIO_PT16_LOW();
				#if 1
				 //BIE Write
							HY17P52WR3(0,0xAA,adS.unitChoose);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
						    if(Flag== 1)
						    {
						       GPIO_PT16_HIGH();
						        while(1);    //fail
						    }
						    	
													    //BIE Read   
								BIEARL=0;                                //addr=0
							    BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
							    while((BIECN& 0x01)==1); 
							    adS.eepromRead_low_bit=BIEDRL;
							 
							  if(adS.eepromRead_low_bit==0)  LCD_WriteData(&LCD4, seg_bar) ; 
							  else if(adS.eepromRead_low_bit==1)LCD_WriteData(&LCD4, seg_kgf) ; 
							  else if(adS.eepromRead_low_bit==2)LCD_WriteData(&LCD4, seg_mpa) ; 
							  else if(adS.eepromRead_low_bit==3)LCD_WriteData(&LCD4, seg_psi) ; 
				#endif 
				
				

			}
		
		}
     
    }

}
/******************************************************************************
	*
	*Function Name: long UnitConverter(long data)
	*
	*
******************************************************************************/
long UnitConverter(long data)
{
     if(adS.eepromRead_low_bit==0){ /*psi*/
        
         return  kgfTOpsi(data) ;
     } 
	 else if(adS.eepromRead_low_bit==1){ /*unit bar*/
     	 
     	 return	kgfTObar(data);
	 }
	 else if(adS.eepromRead_low_bit==2){ /* unit kgf*/
          
         return data;
	 } 
	 else if(adS.eepromRead_low_bit==3){ /*uint mpa*/

	 	 return kgfTOmpa(data);
	 }

}
/*----------------------------------------------------------------------------*/
/* Interrupt Service Routines                                                 */
/*----------------------------------------------------------------------------*/
void ISR(void) __interrupt
{


	#if 1
	if(ADIF_IsFlag()&&(adS.Presskey_flag !=1))
	{
		ADIF_ClearFlag();
		ADC=ADC_GetData();
		MCUSTATUSbits.b_ADCdone=1;
	}
	#endif 
	
}

/*----------------------------------------------------------------------------*/
/* End Of File                                                                */
/*----------------------------------------------------------------------------*/
