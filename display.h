
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
   unsigned char extend_t;   /*measure mode */
   unsigned long ADC_value;  

   int m_offset_value;
   int p_offset_value;
   
   unsigned char  delta_v;
   unsigned char  theta_v;
  
   unsigned char Presskey_flag;
   unsigned char Positive_sign ;
   unsigned char Negative_sign;
   int plus_Error_value;
   int  minus_Error_value;

   unsigned char Error_Positive_flag;



};

extern struct _adc_works_ adS; 



void ClearLCD(void);
void DisplayHycon(void);
// long Index_Subsection(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayUnit(void);


