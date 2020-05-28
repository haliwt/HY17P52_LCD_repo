#define   seg_kgf    0x01
#define   seg_bar    0x02
#define   seg_psi    0x04
#define   seg_MPa    0x08

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
   unsigned char save_mode;
   unsigned char uint_set_mode;
   unsigned char plus_uint;
   unsigned char unit_plus;
   unsigned char measure_mode;
   unsigned char zero_point_mode;
   unsigned char error_mode;
   unsigned char key_flag;
   unsigned int second_5_over;
   unsigned int second_3_over;
  
   unsigned char  plus_revise_flag;
   unsigned char  minus_revise_flag;
  
   unsigned char  Presskey_flag;
   unsigned char  Pressure_sign ;
  // unsigned char  NegativePressure_plus;

   int m_offset_value;
   int p_offset_value;
    


};

extern struct _adc_works_ adS; 

/*----------------------------------------------------------------------------*/
/* Function PROTOTYPES                                                        */
/*----------------------------------------------------------------------------*/
unsigned char HY17P52WR3(unsigned char Addr,unsigned char DataH,unsigned char DataL);
void HY17P52WR3Delay(char ms);


void ClearLCD(void);
void DisplayHycon(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayUnit(void);
void EEPROM_WriteWord(void);
void Delay(unsigned int ms);
void GPIO_Iint(void) ;
