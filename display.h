
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
   unsigned char u_plus ;
   unsigned char  plus_uint ;
   int m_offset_value;
   int p_offset_value;

};

extern struct _adc_works_ adS; 
#if 0
unsigned int pressTable[TableNumber ] = {
 1123,1684,1703,1986
,2227,2258,2548,2816,2824,3383,3392,3665,3934,4002
,4210,4496,4503,4570,4632,4712,4766,4778,4836,4896
,4993,5054,5058,5107,5165,5285,5326,5385,5442,5496
,5606,5633,5700,5766,5840,5888,5896,5943,6001,6050
,6120,6203,6208,6250,6265,6284,6314,6316,6336,6355
,6359,6361,6362,6363,6365,6405,6465,6500,6500,6505
,6506,6507,6508,6509,6510,6511,6512,6513,6514,6515
,6516,6517,6518,6519,6520,6521,6522,6523,6524,6525
,6526,6527,6528,6529,6530,6531,6532,6533,6534,6535
,6536,6537,6538,6539,6540,6541,6542,6543,6544,6545
,6546,6547,6548,6549,6550,6551,6552,6553,6554,6555

};
#endif 

void ClearLCD(void);
void DisplayHycon(void);
void Index_Subsection(long sub);
void DisplayNum(long Num);
void DisplayHex(unsigned int Num);
void Display2Er(void);
void DisplayUnit(void);


