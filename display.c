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
  unsigned char count;
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
 
}

/*---------------------------------------------------------------------------*/
/* LCD DISPLAY Hexadecimal                                                   */
/*---------------------------------------------------------------------------*/
void DisplayHex(unsigned int Num)
{
  
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
  LCD_WriteData(&LCD3,Char_2);
  LCD_WriteData(&LCD2,Char_E);
  LCD_WriteData(&LCD1,Char_R);   
 

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
  LCD_WriteData(&LCD1,Char_I);
  LCD_WriteData(&LCD2,Char_N);
  LCD_WriteData(&LCD3,Char_CAP_U); 
}
/*----------------------------------------------------------------------------*/
/* Software Delay Subroutines                                                 */
/*----------------------------------------------------------------------------*/
void Delay(unsigned int ms)
{
  for(;ms>0;ms--)
    __asm__("NOP");
}
/*----------------------------------------------------------------------------
  *
  *Function Name :Reverse 
  * 
  *                                               
----------------------------------------------------------------------------*/
long Reverse_Data(long number)
  {
    long tmp=0;
    while(number!=0)
    {
     tmp=(tmp*10 + number%10);
     number=number*0.1;
    }
   if(number<0) return (-tmp);
    else return tmp;
  }
/*----------------------------------------------------------------------------
  *
  *Function Name :void DisplayHHH(void) 
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayHHH(void)
{
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD1,Char_H );
  LCD_WriteData(&LCD2,Char_H );
  LCD_WriteData(&LCD3,Char_H ); 

}
/*----------------------------------------------------------------------------
  *
  *Function Name :DisplayLLL(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayLLL(void)
{
 
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD1,Char_L);
  LCD_WriteData(&LCD2,Char_L);
  LCD_WriteData(&LCD3,Char_L); //the first address &LCD3

}
/*----------------------------------------------------------------------------
  *
  *Function Name :DisplayBAT(void)
  *Function :LCD display "bAt"
  *                                               
----------------------------------------------------------------------------*/
void DisplayBAT(void)
{
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD1,Char_T); //the third address &LCD1
  LCD_WriteData(&LCD2,Char_A);
  LCD_WriteData(&LCD3,Char_B);  //the first address &LCD3

}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayBatteryCapacityFull(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayBatteryCapacityFull(void)
{
  LCD_WriteData(&LCD0,0xff);
}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayBatteryCapacityFull(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayBatteryCapacityHalf(void)
{
  LCD_WriteData(&LCD0,0xd0);
 
}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayBatteryCapacityFull(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DispalyBatteryCapacityLow(void)
{
  LCD_WriteData(&LCD0,0x90);
 
}


