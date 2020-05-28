#define  USE_HY17P52_2M
#include <SFRType.h>
#include "lcdTable.h"
#include <LCD.h>
#include "display.h"
#include <GPIO.h>
struct _adc_works_ adS; 



void GPIO_Iint(void) 
{
  //GPIO Setting
  GPIO_PT15_OUTUT();  // SETTING PT4.4 OUTPUT
    GPIO_PT16_OUTUT();  // SETTING PT4.3 OUTPUT
 //   GPIO_PT17_OUTUT();  
  GPIO_PT10_INPUT();
}

/************************************************************
 * 
 * unsigned char n,count,*LCDAddr,LCDData;
 * 
 * 
 ************************************************************/
void ClearLCD(void)
{
	unsigned char count;
  	FSR0=&LCD0;
  	for(count=6;count>0;count--)
    	POINC0=0;
}


/***************************************************************************
  *
  *Display char "HYCon"
  *
  *                                                        
****************************************************************************/
void DisplayHycon(void)
{
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD1,Char_L);
  LCD_WriteData(&LCD2,Char_L);
  LCD_WriteData(&LCD3,Char_L);   /*HY17P52 com3 */
  LCD_WriteData(&LCD4,Char_L);
  LCD_WriteData(&LCD5,Char_L);
  LCD_WriteData(&LCD6,0x00);
}

/***************************************************************************
  *
  *Function Name:Index_Subsection()
  *Function : serch table be responds psi volue,voltage transition psi
  *
  *                                                        
****************************************************************************/
void EEPROM_WriteWord(void)
{
        unsigned char Flag;
        unsigned int read_t,read_h;
   
        
          //BIE Read   
          BIEARL=0;                                //addr=0
          BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
          while((BIECN& 0x01)==1);   
          read_t = BIEDRL;
          read_h = BIEDRH;
          if(read_h == 0x00){
              GPIO_PT16_HIGH();
                

            
                //BIE Write
              HY17P52WR3(0,0xAA,0x11);  //addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
              if(Flag== 1)
              {
                while(1);    //fail
              }
          }
          if(read_t == 0x11){

              GPIO_PT15_HIGH();
                
              
               

          }

}
/*---------------------------------------------------------------------------
	*
	* Function Name:DisplayNum(long Num)
	* Function :LCD display 
	* Input Reference: need display number
	*
	*
*---------------------------------------------------------------------------*/
void DisplayNum(long Num)
{
  unsigned char count,MINUS;
  unsigned char *LCDAddr,LCDData;
  
  LCDAddr=&LCD3;
  for(count=1;count<4;count++)
  {
    LCDData=seg[Num%10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/10 ;
    LCDAddr--;
  }
  
  if(adS.Pressure_sign==1)
    LCD_WriteData(&LCD0,0X08);
  else
  LCD_WriteData(&LCD0,0);
  LCD_WriteData(&LCD0,symbol_t0);

 
 
}

/*---------------------------------------------------------------------------*/
/* LCD DISPLAY Hexadecimal                                                   */
/*---------------------------------------------------------------------------*/
void DisplayHex(unsigned int Num)
{
  unsigned char count,*LCDAddr,LCDData;


  LCDAddr = &LCD3; 
  for(count=1;count<4;count++)
  {
    LCDData=seg[Num%0x10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/0x10 ;
    LCDAddr--;
  }
   
  if(adS.Pressure_sign==1)
    LCD_WriteData(&LCD0,0X08);
  else
  LCD_WriteData(&LCD0,0);
  LCD_WriteData(&LCD4,symbol_t0);
}
/*****************************************************************************
  *
  *Function Name :void Display2Er(void)
  *Function :LCD display "2Er"
  *
  *
******************************************************************************/
void Display2Er(void)
{
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD1,Char_2);
  LCD_WriteData(&LCD2,Char_E);
  LCD_WriteData(&LCD3,Char_R);   
 

}
/*****************************************************************************
  *
  *Function Name :void DisplayUnit(void)
  *Function :LCD display "Uni"
  *
  *
******************************************************************************/
void DisplayUnit(void)
{
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD1,Char_CAP_U);
  LCD_WriteData(&LCD2,Char_N);
  LCD_WriteData(&LCD3,Char_I); 
}
/*----------------------------------------------------------------------------*/
/* Software Delay Subroutines                                                 */
/*----------------------------------------------------------------------------*/
void Delay(unsigned int ms)
{
  for(;ms>0;ms--)
    __asm__("NOP");
}