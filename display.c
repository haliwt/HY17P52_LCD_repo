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
  //LCD_WriteData(&LCD0,highestPlus) ; //WT.EDIT 2020-06-05
}
/*---------------------------------------------------------------------------
  *
  * Function Name:DisplayNum(long Num)
  * Function :LCD display 
  * Input Reference: need display number
  *
  *
*---------------------------------------------------------------------------*/
void DisplayNum4Bytes( int Num)
{
  unsigned char count,count2;
  unsigned char *LCDAddr,LCDData;

#if 0
        LCDAddr=&LCD0;
  
      if(LCDAddr != &LCD0){

         for(count2=0;count2<3;count2++)
          {
            LCDData=seg[Num%10];
            LCD_WriteData(LCDAddr,LCDData);
            Num=Num/10 ;
            LCDAddr++;
          }

      }
      else if(LCDAddr == &LCD0){
          LCDData=seg[Num%10];
          LCD_WriteData(LCDAddr,highestByte);
          Num=Num/10 ;
          LCDAddr++;
     
        }
 #endif  
  #if 1
  LCDAddr=&LCD0;
  for(count=0;count<4;count++)
  {
       if(LCDAddr == &LCD0) LCD_WriteData(&LCD0,highestByte) ; 
       
      else {
          LCDData=seg[Num%10];
          LCD_WriteData(LCDAddr,LCDData);
          Num=Num/10 ;
         }
        
         LCDAddr++;
     
    }
#endif 
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
  *Function Name : void DisplayBatteryCapacityFull(void)
  * 
  *                                               
----------------------------------------------------------------------------*/
int DecimalToHex(int number)
{
   int n,a1,count=0;//count 用于角标的计数，j 控制 for 循环
  //int a[100];
  int hex;
  int a[2];
  a[0]=0;
  a[1]=0;
 
 while(number!=0) {
    a1=number;
    number=number/16;
      a[count]=a1%16;
      count++;
    }
  
  
#if 1

  hex =a[1] << 4 | a[0];

 // printf("hex = %#x\r\n",hex);

#endif
  return hex ;

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
   LCD_WriteData(&LCD0,highestByte);       

}
