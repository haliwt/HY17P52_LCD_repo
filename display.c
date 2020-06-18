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
  GPIO_DIR_PT1xInput(PT15);
  GPIO_DIR_PT10_INPUT() ;
  GPIO_PT1SETPU(PT15);
  GPIO_PT1SETPU(PT10);  
  GPIO_PT1SETPU(PT16);
  GPIO_PT16_OUTUT();  
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
  
  LCDAddr = &LCD1;//LCDAddr=&LCD3;
  for(count=0;count<3;count++)
  {
    LCDData=seg[Num%10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/10 ;
    LCDAddr++;
  }
 // LCD_WriteData(&LCD0,highest_bit_NotOne) ;  //WT.EDIT 2020-06-05
}
/*---------------------------------------------------------------------------
  *
  * Function Name:DisplayNum(long Num)
  * Function :LCD display 
  * Input Reference: need display number
  *
  *
*---------------------------------------------------------------------------*/
void DisplayNum4Bytes( long Num)
{
  unsigned char count;
  unsigned char *LCDAddr,LCDData;

  
  LCDAddr = &LCD1;
  for(count=0;count<4;count++)
  {
        
           LCDData=seg[Num%10];
          if(count == 3){
                  if(Num %10 !=0)
                    LCD_WriteData(&LCD0,highest_bit_One) ; 
                  else 
                    LCD_WriteData(&LCD0,highest_bit_NotOne) ; 
                  count =5;
            }
            else{
             
              LCD_WriteData(LCDAddr,LCDData);
              Num=Num/10 ;
              LCDAddr++;

            }
  }
 // LCD_WriteData(&LCD0,highestPlus) ; //WT.EDIT 2020-06-05
}
/*---------------------------------------------------------------------------
/*---------------------------------------------------------------------------
  *
  * Function Name:DisplayNum(long Num)
  * Function :LCD display 
  * Input Reference: need display number
  *
  *
*---------------------------------------------------------------------------*/
void DisplayNum2Bit(int Num)
{
  unsigned char count;
  unsigned char *LCDAddr,LCDData;
  
  LCDAddr=&LCD2;
  for(count=2;count<4;count++)
  {
    LCDData=seg[Num%10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/10 ;
    LCDAddr--;
  }
  LCD_WriteData(&LCD3,seg_lcd3_mask);
 }
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayNumOneByte(int number);
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayNumOneByte(int Num)
{
  
  unsigned char count;
  unsigned char *LCDAddr,LCDData;
  
LCDAddr = &LCD1;//LCDAddr=&LCD3;
for(count=0;count<3;count++)
{
    if(LCDAddr != &LCD1){
      LCDData=seg[0];
      LCD_WriteData(LCDAddr,LCDData);
    }
    LCDData=seg[Num%10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/10 ;
    LCDAddr++;
  }
  
}
/*---------------------------------------------------------------------------*/
/* LCD DISPLAY Hexadecimal                                                   */
/*---------------------------------------------------------------------------*/
#if 0
void DisplayHex(unsigned int Num)
{
  unsigned char count,*LCDAddr,LCDData;

  LCDAddr=&LCD5;
  for(count=0;count<6;count++)
  {
    LCDData=seg[Num%0x10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/0x10 ;
    LCDAddr--;
  } 
 
}
#endif 
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
  *Function Name :void Display2Er(void)
  *Function :LCD display "2Er"
  *
  *
******************************************************************************/
void Display2ErP3(void)
{
  LCD_WriteData(&LCD0,0x00);
  LCD_WriteData(&LCD3,Char_2);
  LCD_WriteData(&LCD2,Char_E);
  LCD_WriteData(&LCD1,Char_R);   
  LCD_WriteData(&LCD2,POINT_P3);  

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
  LCD_WriteData(&LCD0, symbol_battery_full);
}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayBatteryCapacityFull(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayBatteryCapacityHalf(void)
{
  LCD_WriteData(&LCD0, symbol_battery_half);
 
}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayBatteryCapacityFull(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DispalyBatteryCapacityLow(void)
{
  LCD_WriteData(&LCD0,symbol_battery_low);
 
}

/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayPointP3(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayPointP3(void)
{
  LCD_WriteData(&LCD2,POINT_P3);  

}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayPointP2(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayPointP2(void)
{
  LCD_WriteData(&LCD3,POINT_P2);  

}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplayPointP1(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayPointP1(void)
{
  LCD_WriteData(&LCD0,POINT_P1);  

}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplaySignMinus(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplaySignMinus(void)
{

  LCD_WriteData(&LCD0,symbol_minus);  

}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplaySignPlus(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplaySignPlus(void)
{
     LCD_WriteData(&LCD0,symbol_plus);                
}
/*----------------------------------------------------------------------------
  *
  *Function Name : void DisplaySignPlus(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
void DisplayHighestByte_One(void)
{
   LCD_WriteData(&LCD0,highest_bit_One);       

}

          

