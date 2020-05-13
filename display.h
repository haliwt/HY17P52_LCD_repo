
typedef struct _adc_wrks_
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
   unsigned char S_Plus ;

}adc_works_t;

extern adc_works_t adS; 

void ClearLCD(void);
void DisplayHycon(void);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayUnit(void);