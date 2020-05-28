
#define TableNumber 115
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
   unsigned char  NegativePressure_plus;

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


