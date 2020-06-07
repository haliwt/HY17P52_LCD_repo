




enum unit_t{psi,bar,kgf,mpa};

struct _adc_works_
{
   unsigned char save_mode: 1;
   unsigned char unit_setMode:1;
   unsigned char plus_uint;
   unsigned char unitChoose;
   unsigned char testMode:1;
   unsigned char zeroPoint_Mode:1;
   unsigned char error_mod:1;
   unsigned char key_flag;

   unsigned char negativeInPositive_flag: 1;
   unsigned char LVD_2V4_flag : 1;
   unsigned char LVD_3V_flag : 1;
   unsigned char zeroTo60times : 2;

   unsigned char plus_revise_flag;
   unsigned char minus_revise_flag;

   unsigned char Presskey_flag:1;
   unsigned char Pressure_sign :1;
   unsigned char destroyTimes_3 : 1;
   unsigned char destroyTimes_5 : 1;
   unsigned char workstation_flag:1;

   unsigned char eepromRead_PositiveDeltaLow_bit ;

   unsigned char eepromRead_NegativeDeltaLow_bit;

   unsigned char eepromRead_UnithHigh_bit ;
   unsigned char eepromRead_UnitLow_bit ;
   unsigned char reload_ADCInterrupt :1;
   unsigned int delayTimes_5;
   unsigned int delayTimes_3;
   unsigned int delayDisplay ;
   unsigned int getSaveTimes ;


   long minusOffset_Value;
   long plusOffset_Value;

};

extern struct _adc_works_ adS;







void ClearLCD(void);
void DisplayHycon(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayUnit(void);
void DisplayHHH(void);
void DisplayLLL(void);
void DisplayBAT(void);
void Delay(unsigned int ms);
void GPIO_Iint(void) ;
long Reverse_Data(long number);
void DisplayBatteryCapacityFull(void);
void DisplayBatteryCapacityHalf(void);
void DispalyBatteryCapacityLow(void);
int DecimalToHex(int number);
void DisplayPointP3(void);
void DisplayPointP2(void);
void DisplayPointP1(void);
void DisplaySignMinus(void);
void DisplaySignPlus(void);
void DisplayNum2Bit(int num);
void DisplayHighestByte_One(void);
void DisplayNum4Bytes(int number);
void DisplayNumOneByte(int number);
void Timer_Wait(unsigned long times);
