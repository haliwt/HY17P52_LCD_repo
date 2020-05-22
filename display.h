
#define TableNumber 115
enum unit_t{psi,bar,kgf,mpa};
struct _adc_works_
{
   unsigned char save_mode;
   unsigned char uint_set_mode;
   unsigned char measure_mode;
   unsigned char zero_point_mode;
   unsigned char error_mode;
   unsigned char key_flag;
   unsigned char second_5_over;
   unsigned char second_3_over;
   unsigned char extend_t;   /*measure mode */
   unsigned long ADC_value;  
   unsigned char unit_plus ;
   unsigned char  plus_uint ;
   int m_offset_value;
   int p_offset_value;
   long p_InitADC_DAT;
   long m_InitADC_DAT;
   long BasisVoltage;
   unsigned char p_InitADC_flag;
   unsigned char m_InitADC_flag;
   unsigned char  delta_v;
   unsigned char  Negative_delta_flag;
   unsigned char Presskey_flag;
   unsigned char Positive_sign ;
   unsigned char Negative_sign;
   unsigned char plus_Error_value;
   unsigned char minus_Error_value;
   long Negative_delta_value;


};

extern struct _adc_works_ adS; 



void ClearLCD(void);
void DisplayHycon(void);
// long Index_Subsection(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayUnit(void);
void Negative_Pressure_Arithmetic(void);





