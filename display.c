#define  USE_HY17P52_2M
#include <SFRType.h>
#include "lcdTable.h"
#include <LCD.h>
#include "display.h"
struct _adc_works_ adS;  

//unsigned char n,count,*LCDAddr,LCDData;

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
  LCD_WriteData(&LCD1,Char_H);
  LCD_WriteData(&LCD2,Char_Y);
  LCD_WriteData(&LCD3,Char_C);   /*HY17P52 com3 */
  LCD_WriteData(&LCD4,Char_O);
  LCD_WriteData(&LCD5,Char_N);
  LCD_WriteData(&LCD6,0x00);
}
/***************************************************************************
  *
  *Function Name:Index_Subsection()
  *Function : serch table be responds psi volue,voltage transition psi
  *
  *                                                        
****************************************************************************/
void Index_Subsection(long Sub)
{
    if(Sub >=6505 && Sub<= 6509){
      switch(Sub){
            case 6505 :
                  Sub = 146;
                  break;
            case 6506 :
                 Sub = 146;
                 break;
            case 6507 :
                 Sub = 145;
                 break;
            case 6508 :
                 Sub = 144;
                 break;
            case 6509 :
                Sub = 144;
                break;
          }   
      }
      if(Sub >=6510 && Sub<= 6521){
       switch(Sub){
             case 6521:
                  Sub = 131;
                  break;
            case 6520:
                 Sub = 132;
                 break;
            case 6519 :
                  Sub = 130;
                  break;
            case 6518:
                 Sub = 134;
                 break;
            case 6517 :
                 Sub = 135;
                 break;
            case 6516 :
                 Sub = 135;
                 break;
            case 6515 :
                 Sub = 138;
                 break;
            case 6514 :
                Sub = 139;
                break;
          }    

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

  if((Num<0)||(Num>0x80000000))
  {
    Num=~Num;
    Num++;
    MINUS=1;
  }
  else
  {
    MINUS=0;
  }

  LCDAddr=&LCD5;
 // LCDAddr = &LCD4;  /*HY17P52 for LCD FTP1625SX01*/
   for(count=0;count<6;count++) /* has 6 register for "LCD0 ~LCD5" */
  {
    LCDData=seg[Num%10]; 
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/10 ;
    LCDAddr--;
  }
  if(MINUS==1)//if(adS.S_Plus==1)//if(MINUS==1)
      LCD_WriteData(&LCD6,S_Minus);// LCD_WriteData(&LCD0,S_Minus);
  else
      LCD_WriteData(&LCD6,0);//LCD_WriteData(&LCD0,0);
}

/*---------------------------------------------------------------------------*/
/* LCD DISPLAY Hexadecimal                                                   */
/*---------------------------------------------------------------------------*/
void DisplayHex(unsigned int Num)
{
  unsigned char count,*LCDAddr,LCDData;

 // LCDAddr=&LCD5;
  LCDAddr = &LCD4; /*HY17P52 for LCD FTP1625SX01*/
  for(count=0;count<6;count++)
  {
    LCDData=seg[Num%0x10];
    LCD_WriteData(LCDAddr,LCDData);
    Num=Num/0x10 ;
    LCDAddr--;
  }
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