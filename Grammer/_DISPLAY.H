




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
   unsigned char resetZeroDisplay;
   unsigned char quitCurrentMode: 1;
   unsigned char LVD_flag : 1;


   unsigned char plus_revise_flag:1;
   unsigned char minus_revise_flag:1;

   unsigned char Presskey_flag:1;
   unsigned char Pressure_sign :1;
   unsigned char eepromRead_high_bit ;
   unsigned char eepromRead_low_bit ;
   unsigned char reload_ADCInterrupt :1;


   int m_offset_value;
   int p_offset_value;



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
void Delay(unsigned int ms);
void GPIO_Iint(void) ;

long Reverse_Data(long number);
nsigned char LowVoltageDetect(void);
