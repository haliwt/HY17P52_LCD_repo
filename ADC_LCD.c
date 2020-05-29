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

#define STD_VALUE                 6524

#define STD_NEGATIVE_VOLTAGE      6346//6344//6343

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

void ShowADC (void);
void DisplayNum(long Num);
void GPIO_Init(void);
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
		
		//  adS.key_flag=adS.key_flag ^ 0x01; /* check process  ISR()__inptrrupt reference */
		    
			
		 if(adS.second_5_over >= 10000){ /*unit set mode*/
			
			 if(GPIO_READ_PT10()){
	          
			    adS.second_5_over=9000;
				adS.second_5_over =0;
				adS.uint_set_mode =1;
				//adS.zero_point_mode =0;
				adS.measure_mode =1;
				DisplayUnit();
			//	Delay(10000);
				adS.second_3_over=0;
				
			     switch(adS.plus_uint){
					case psi: 
					     adS.plus_uint++;
						 adS.unit_plus = psi;
						 LCD_WriteData(&LCD4,seg_psi);
						  adS.second_5_over=9000;
					    break;
					case bar:
						adS.plus_uint++;
						 adS.unit_plus = bar;
						  LCD_WriteData(&LCD4,seg_bar);
						  adS.second_5_over=9000;
					     break;
					case kgf:
						adS.plus_uint++;
						adS.unit_plus = kgf;
						 LCD_WriteData(&LCD4,seg_kgf);
						  adS.second_5_over=9000;
					     break;
				    case mpa:
					     adS.plus_uint=0;
						 adS.unit_plus = mpa;
						  LCD_WriteData(&LCD4,seg_mpa);
						   adS.second_5_over=9000;
					     break;
				}
			
			}
		 }
		 if(adS.second_3_over >=5000){ /* zero point mode*/

			   if(GPIO_READ_PT10()){
				 adS.zero_point_mode = 1;
				//adS.uint_set_mode = 0;
				adS.measure_mode =1;
			    adS.second_3_over=0;
				//display LCD "2Er"
			     Display2Er();
                // Delay(20000);
				 
                
			}
		 }
		 
		}
		else{
		   	
		   
		   if(adS.measure_mode == 0){ /* measure mode */
		       	adS.zero_point_mode=0;
				adS.key_flag =0;
				adS.uint_set_mode=0;
				
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
						if( ADC < 1600 && ADC >=0 ) {
							adS.Pressure_sign =1;
						
						}
				        else{
						       adS.Pressure_sign =0;
						      
						}
					}
				   
				
				if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/

				         n = ADC ;
				         LCDDisplay= (0.1 * n)-364 ;  //y = 0.0175x - 36.495  //= 0.0175x - 36.495 
		           
	                  
		                 if(adS.plus_revise_flag ==1){
		                 if(n<2000)DisplayNum(ADC);
					   
						 else if( (LCDDisplay *10) < 2875){
							    LCDDisplay= 0.125 *n- 202.86; //y = 0.0125x - 20.286
						        DisplayNum(LCDDisplay);

									Delay(20000);
				
						 }
						 else {
							
						        if(adS.p_offset_value >=0) //WT.EDIT 2020-05-28
							    n =abs(ADC)- abs(adS.p_offset_value);
							    else  n =abs(ADC) + abs(adS.p_offset_value);
							    LCDDisplay= 56193  - (8.47 * n) ;//y=-0.846x + 5619.3
							     
								DisplayNum( LCDDisplay);
								Delay(20000);
									
								}
									
							}
							else
							{
								DisplayNum(ADC);
								Delay(20000);

							}
						}
										
				}//end else 
			    else { /*Input Negative pressure mode*/
						adS.Pressure_sign =1;
						delta  = ADC ;
                        
					    theta= abs(ADC) - adS.m_offset_value;  
					   if(adS.minus_revise_flag==1){

					   	 
					
						//LCDDisplay= 0.12*theta + 255;//LCDDisplay= 0.012*p + 24.76;
					   	   if(delta >=0 ){
					   	   	 LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
							 DisplayNum( LCDDisplay);
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
									DisplayNum( LCDDisplay);
									Delay(20000);
								
						    }
						}
					
									
						else{
							ADC = abs(ADC);
							DisplayNum(ADC);
							Delay(20000);
						}
					}
		     }
		    
		   if(adS.zero_point_mode == 1){ /*zero point mode */
     
				adS.zero_point_mode =0;
			     adS.measure_mode=0;
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
					DisplayNum( adS.p_offset_value);
					Delay(20000);
				}
			
			}
		   #if 0
		   if(adS.second_3_over >=1){ /* over 3 seconds don't press key return measure_mode*/
		   	   adS.measure_mode = 0;
		   	   adS.uint_set_mode=0;
			   adS.key_flag =0;
			   adS.second_3_over =0;

			}
		   #endif 
			if(adS.uint_set_mode ==1){

				adS.uint_set_mode =0 ;
				adS.measure_mode = 0;
		
				switch(adS.unit_plus){
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
	#if 1
	if(TA1IF_IsFlag())  //PT1.0  Timer A1 interrupt flag 
	{
		TA1IF_ClearFlag();
		adS.second_3_over ++;
		adS.second_5_over++;
	 #if 1
		if(adS.key_flag ==1||adS.key_flag==0) {
			adS.second_5_over = 0;
		
			adS.second_3_over =0;
		
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
