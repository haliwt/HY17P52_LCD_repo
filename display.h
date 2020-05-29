#define   seg_kgf    0x01
#define   seg_bar    0x02
#define   seg_psi    0x04
#define   seg_mpa    0x08

#define   symbol_c      0x02
#define   symbol_b      0x04
#define   symbol_g      0x08
#define   symbol_t1     0x10     //battery value t1 
#define   symbol_t3     0x20  
#define   symbol_t2     0x40
#define   symbol_t0     0x80   //battery outline 

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
  
  
   unsigned char  plus_revise_flag:1;
   unsigned char  minus_revise_flag:1;
  
   unsigned char  Presskey_flag:1;
   unsigned char  Pressure_sign :1;
   unsigned char  eepromRead_high_bit ; 
   unsigned char  eepromRead_low_bit ;
   unsigned char  reload_ADCInterrupt :1; 

   
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

void Delay(unsigned int ms);
void GPIO_Iint(void) ;

long Reverse_Data(long number);