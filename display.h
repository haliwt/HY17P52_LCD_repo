
#ifndef __DISPLAY_H__
#define __DISPLAY_H__


//
#define   seg_p      0x01
/* unit sign */
#define   seg_kgf    0x01
#define   seg_bar    0x02
#define   seg_psi    0x04
#define   seg_mpa    0x08
/* vector sign*/
#define   symbol_c      0x02
#define   symbol_b      0x04
#define   symbol_g      0x08
/*battery sign symbol */
#define   symbol_t1     0x10     //battery value t1
#define   symbol_t3     0x20
#define   symbol_t2     0x40
#define   symbol_t0     0x80   //battery outline


#define   symbol_full   4
#define   symbol_battery_full     (LCD0 |=(0x0f<< symbol_full ))

#define   symbol_half  4
#define   symbol_battery_half  (LCD0 |=(0x0d << symbol_half ))

#define   symbol_low   4
#define   symbol_battery_low    (LCD0 |=(0x09 << symbol_low))

#define   symbol_minus_bit        3
#define   symbol_minus           (LCD0 |=(0x01 << symbol_minus_bit))
#define   symbol_plus            (LCD0 &= ~(0x01 << symbol_minus_bit))


#define  POINTP3             0
#define  POINT_P3       (LCD2 |=(0x01<<POINTP3))

#define  POINTP2            0
#define  POINT_P2       (LCD3 |=(0x01<<POINTP2))

#define  POINTP1           0
#define  POINT_P1       (LCD0 |=(0x01<<POINTP1))

#define seg_lcd3_data   0
#define seg_lcd3_mask   (LCD3 &= (0x01<<seg_lcd3_data))

#define highestbit              0
#define highest_bit_One         (LCD0 |=(0x06<< highestbit))
#define highest_bit_NotOne      (LCD0 &=~(0x06<< highestbit))

#define NOPOINT                 0
#define NOPOINT_P1             (LCD0 &= ~(0x01 << NOPOINT ))
#define NOPOINT_P2             (LCD3 &= ~(0x01 << NOPOINT ))
#define NOPOINT_P3             (LCD2 &= ~(0x01 << NOPOINT ))





enum unit_t{psi=1,bar,kgf,mpa};

struct _adc_works_
{
   unsigned char save_mode: 1;
   unsigned char Main_unit_setMode:1;
   unsigned char noMeasureSet:1;
  
   unsigned char Main_testMode:1;
   unsigned char Main_zeroPoint_Mode:1;
   unsigned char error_mod:1;

   unsigned char negativeInPositive_flag: 1;
   unsigned char zeroTo60times : 2;
   unsigned char initialize:2;

    

   unsigned char  access_id_3s : 1;
   unsigned char  access_id_5s : 1;
   unsigned char  workstation_flag:1;
   unsigned char  LowVoltage_flag : 1;
   unsigned char  initialVoltage :1;
   unsigned char  setMode : 1;
   unsigned char  BeSureflag:1;
   unsigned char  getSaveflag:1; 
   
   unsigned char  LVD_2V4_flag : 1;
   unsigned char  TheSecondWriteTimes:1;
   unsigned char  MapZero:1;
   unsigned char  dError:1;
   unsigned char  checkValue_2:1;
   unsigned char  checkValue_1:1;
   unsigned char  EEr_flag:2;
   unsigned char  reload_ADCInterrupt :2;

 
   unsigned char  Sign;
   unsigned char  unit_2;
   unsigned char  plus_uint;
   unsigned char  zeroTo120s ;

   unsigned char  WriteEepromTimes ;

   unsigned char unitChoose;
   unsigned char  tmes120svalue;
   unsigned int   delayTimes_5s;
   unsigned int   delayTimes_3s;
   unsigned int   delayDisplay ;
   unsigned int   getSaveTimes ;
   

   int   CheckValue[3];
   int   CorrectionValue[3];
   float  factor;
   float  coefficient;
   float   set2ErData;
   

};

extern struct _adc_works_ adS;

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
void ClearLCD(void);
void DisplayHycon(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayErr(void);
void Display2ErP3(void);

void DisplayUnit(void);
void DisplayHHH(void);
void DisplayLLL(void);
void DisplayBAT(void);
void Delay(unsigned int ms);
void GPIO_Iint(void) ;


void DisplayBatteryCapacityFull(void);
void DisplayBatteryCapacityHalf(void);
void DispalyBatteryCapacityLow(void);

void DisplayPointP3(void);
void DisplayPointP2(void);
void DisplayPointP1(void);
void DisplaySignMinus(void);
void DisplaySignPlus(void);
void DisplayNum2Bit(int  num);
void DisplayHighestByte_One(void);
void DisplayNum4Bytes(long number);
void DisplayZero(void);
void DisplayNoPoint(void);


void ClearLCD(void);
void DisplayHycon(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);





#endif
