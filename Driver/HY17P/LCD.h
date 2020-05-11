/**************************************************************************************************|
|* Copyright 2016 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY11P Series                                                                 *|
|**************************************************************************************************/
#include <CLK.h>           // CLK Cpnfig for LCD

/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
// LCDCN1 //
#define ENLCP                     7
#define ENLCP_MSK                (1 << ENLCP)
#define ENLCP_ENABLE             (1 << ENLCP)
#define ENLCP_DISABLE            (0 << ENLCP)

#define LCDV                      4
#define LCDV_MSK                 (7 << LCDV)
#define LCDV_2V4                 (7 << LCDV)
#define LCDV_2V6                 (6 << LCDV)
#define LCDV_2V8                 (5 << LCDV)
#define LCDV_3V0                 (4 << LCDV)
#define LCDV_3V3                 (3 << LCDV)
#define LCDV_4V05                (2 << LCDV)
#define LCDV_4V5                 (1 << LCDV)
#define LCDV_5V05                (0 << LCDV)

#define ENLB                      3
#define ENLB_MSK                 (1 << ENLB)
#define ENLB_ENABLE              (1 << ENLB)
#define ENLB_DISABLE             (0 << ENLB)

#define SELPCLK                   2
#define SELPCLK_MSK              (1 << SELPCLK)
#define SELPCLK_7KHZ             (1 << SELPCLK)
#define SELPCLK_14KHZ            (0 << SELPCLK)

// LCDCN2 //
#define LCDBL                     1
#define LCDBL_MSK                (1 << LCDBL)
#define LCDBL_LCDOFF             (1 << LCDBL)
#define LCDBL_LCDON              (0 << LCDBL)

#define LCI                       0
#define LCI_MSK                  (1 << LCDBL)
#define LCI_LCDReverse           (1 << LCDBL)
#define LCI_LCDNormal            (0 << LCDBL)

// LCDCN3 //
#define SCM3                      6
#define SCM3_MSK                 (3 << SCM3)
#define SCM3_LCDCOM              (3 << SCM3)
//#define SCM3_RSV               (2 << SCM3)
//#define SCM3_RSV               (1 << SCM3)
#define SCM3_GPIO                (0 << SCM3)

#define SCM2                      4
#define SCM2_MSK                 (3 << SCM2)
#define SCM2_LCDCOM              (3 << SCM2)
//#define SCM2_RSV               (2 << SCM2)
//#define SCM2_RSV               (1 << SCM2)
#define SCM2_GPIO                (0 << SCM2)

#define SCM1                      2
#define SCM1_MSK                 (3 << SCM1)
#define SCM1_LCDCOM              (3 << SCM1)
//#define SCM1_RSV               (2 << SCM1)
//#define SCM1_RSV               (1 << SCM1)
#define SCM1_GPIO                (0 << SCM1)

#define SCM0                      0
#define SCM0_MSK                 (3 << SCM0)
#define SCM0_LCDCOM              (3 << SCM0)
//#define SCM0_RSV               (2 << SCM0)
//#define SCM0_RSV               (1 << SCM0)
#define SCM0_GPIO                (0 << SCM0)

// LCDCN4 //

#define SSG21                     7
#define SSG21_MSK                (1 << SSG21)
#define SSG21_SEG                (1 << SSG21)
#define SSG21_GPIO               (0 << SSG21)

#define SSG20                     6
#define SSG20_MSK                (1 << SSG20)
#define SSG20_SEG                (1 << SSG20)
#define SSG20_GPIO               (0 << SSG20)

#define SSG19                     5
#define SSG19_MSK                (1 << SSG19)
#define SSG19_SEG                (1 << SSG19)
#define SSG19_GPIO               (0 << SSG19)

#define SSG18                     4
#define SSG18_MSK                (1 << SSG18)
#define SSG18_SEG                (1 << SSG18)
#define SSG18_GPIO               (0 << SSG18)

#define SSG17                     3
#define SSG17_MSK                (1 << SSG17)
#define SSG17_SEG                (1 << SSG17)
#define SSG17_GPIO               (0 << SSG17)

#define SSG16                     2
#define SSG16_MSK                (1 << SSG16)
#define SSG16_SEG                (1 << SSG16)
#define SSG16_GPIO               (0 << SSG16)

#define SSG15                     1
#define SSG15_MSK                (1 << SSG15)
#define SSG15_SEG                (1 << SSG15)
#define SSG15_GPIO               (0 << SSG15)

#define SSG14                     0
#define SSG14_MSK                (1 << SSG14)
#define SSG14_SEG                (1 << SSG14)
#define SSG14_GPIO               (0 << SSG14)
/*
// LCDCN5 //
#define LCDCN5_SSG41                     7
#define LCDCN5_SSG41_MSK                (1 << LCDCN5_SSG41)
#define LCDCN5_SSG41_SEG                (1 << LCDCN5_SSG41)
#define LCDCN5_SSG41_GPIO               (0 << LCDCN5_SSG41)

#define LCDCN5_SSG40                     6
#define LCDCN5_SSG40_MSK                (1 << LCDCN5_SSG40)
#define LCDCN5_SSG40_SEG                (1 << LCDCN5_SSG40)
#define LCDCN5_SSG40_GPIO               (0 << LCDCN5_SSG40)

#define LCDCN5_SSG39                     5
#define LCDCN5_SSG39_MSK                (1 << LCDCN5_SSG39)
#define LCDCN5_SSG39_SEG                (1 << LCDCN5_SSG39)
#define LCDCN5_SSG39_GPIO               (0 << LCDCN5_SSG39)

#define LCDCN5_SSG38                     4
#define LCDCN5_SSG38_MSK                (1 << LCDCN5_SSG38)
#define LCDCN5_SSG38_SEG                (1 << LCDCN5_SSG38)
#define LCDCN5_SSG38_GPIO               (0 << LCDCN5_SSG38)

#define LCDCN5_SSG37                     3
#define LCDCN5_SSG37_MSK                (1 << LCDCN5_SSG37)
#define LCDCN5_SSG37_SEG                (1 << LCDCN5_SSG37)
#define LCDCN5_SSG37_GPIO               (0 << LCDCN5_SSG37)

#define LCDCN5_SSG36                     2
#define LCDCN5_SSG36_MSK                (1 << LCDCN5_SSG36)
#define LCDCN5_SSG36_SEG                (1 << LCDCN5_SSG36)
#define LCDCN5_SSG36_GPIO               (0 << LCDCN5_SSG36)

#define LCDCN5_SSG35                     1
#define LCDCN5_SSG35_MSK                (1 << LCDCN5_SSG35)
#define LCDCN5_SSG35_SEG                (1 << LCDCN5_SSG35)
#define LCDCN5_SSG35_GPIO               (0 << LCDCN5_SSG35)

#define LCDCN5_SSG34                     0
#define LCDCN5_SSG34_MSK                (1 << LCDCN5_SSG34)
#define LCDCN5_SSG34_SEG                (1 << LCDCN5_SSG34)
#define LCDCN5_SSG34_GPIO               (0 << LCDCN5_SSG34)
*/
// LCDCN6 //
#define SSG5                      6
#define SSG5_MSK                 (3 << SSG5)
#define SSG5_LCDSEG              (3 << SSG5)
//#define SSG5_RSV               (2 << SSG5)
//#define SSG5_RSV               (1 << SSG5)
#define SSG5_GPIO                (0 << SSG5)

#define SSG4                      4
#define SSG4_MSK                 (3 << SSG4)
#define SSG4_LCDSEG              (3 << SSG4)
//#define SSG4_RSV               (2 << SSG4)
//#define SSG4_RSV               (1 << SSG4)
#define SSG4_GPIO                (0 << SSG4)

#define SSG3                      2
#define SSG3_MSK                 (3 << SSG3)
#define SSG3_LCDSEG              (3 << SSG3)
//#define SSG3_RSV               (2 << SSG3)
//#define SSG3_RSV               (1 << SSG3)
#define SSG3_GPIO                (0 << SSG3)

#define SSG2                      0
#define SSG2_MSK                 (3 << SSG2)
#define SSG2_LCDSEG              (3 << SSG2)
//#define SSG2_RSV               (2 << SSG2)
//#define SSG2_RSV               (1 << SSG2)
#define SSG2_GPIO                (0 << SSG2)

// LCDCN7 //
#define SSG9                      6
#define SSG9_MSK                 (3 << SSG9)
#define SSG9_LCDSEG              (3 << SSG9)
//#define SSG9_RSV               (2 << SSG9)
//#define SSG9_RSV               (1 << SSG9)
#define SSG9_GPIO                (0 << SSG9)

#define SSG8                      4
#define SSG8_MSK                 (3 << SSG8)
#define SSG8_LCDSEG              (3 << SSG8)
//#define SSG8_RSV               (2 << SSG8)
//#define SSG8_RSV               (1 << SSG8)
#define SSG8_GPIO                (0 << SSG8)

#define SSG7                      2
#define SSG7_MSK                 (3 << SSG7)
#define SSG7_LCDSEG              (3 << SSG7)
//#define SSG7_RSV               (2 << SSG7)
//#define SSG7_RSV               (1 << SSG7)
#define SSG7_GPIO                (0 << SSG7)

#define SSG6                      0
#define SSG6_MSK                 (3 << SSG6)
#define SSG6_LCDSEG              (3 << SSG6)
//#define LCDCN6_SSG6_RSV               (2 << SSG6)
//#define LCDCN6_SSG6_RSV               (1 << SSG6)
#define SSG6_GPIO                (0 << SSG6)

// LCDCN8 //
#define SSG13                      6
#define SSG13_MSK                 (3 << SSG13)
#define SSG13_LCDSEG              (3 << SSG13)
//#define SSG13_RSV               (2 << SSG13)
//#define SSG13_RSV               (1 << SSG13)
#define SSG13_GPIO                (0 << SSG13)

#define SSG12                      4
#define SSG12_MSK                 (3 << SSG12)
#define SSG12_LCDSEG              (3 << SSG12)
//#define SSG12_RSV               (2 << SSG12)
//#define SSG12_RSV               (1 << SSG12)
#define SSG12_GPIO                (0 << SSG12)

#define SSG11                      2
#define SSG11_MSK                 (3 << SSG11)
#define SSG11_LCDSEG              (3 << SSG11)
//#define SSG11_RSV               (2 << SSG11)
//#define SSG11_RSV               (1 << SSG11)
#define SSG11_GPIO                (0 << SSG11)

#define SSG10                      0
#define SSG10_MSK                 (3 << SSG10)
#define SSG10_LCDSEG              (3 << SSG10)
//#define SSG10_RSV               (2 << SSG10)
//#define SSG10_RSV               (1 << SSG10)
#define SSG10_GPIO                (0 << SSG10)
/*
// LCDCN9 //
#define LCDCN9_SSG25                      6
#define LCDCN9_SSG25_MSK                 (3 << LCDCN9_SSG25)
#define LCDCN9_SSG25_LCDSEG              (3 << LCDCN9_SSG25)
//#define LCDCN9_SSG25_RSV               (2 << LCDCN9_SSG25)
//#define LCDCN9_SSG25_RSV               (1 << LCDCN9_SSG25)
#define LCDCN9_SSG25_GPIO                (0 << LCDCN9_SSG25)

#define LCDCN9_SSG24                      4
#define LCDCN9_SSG24_MSK                 (3 << LCDCN9_SSG24)
#define LCDCN9_SSG24_LCDSEG              (3 << LCDCN9_SSG24)
//#define LCDCN9_SSG24_RSV               (2 << LCDCN9_SSG24)
//#define LCDCN9_SSG24_RSV               (1 << LCDCN9_SSG24)
#define LCDCN9_SSG24_GPIO                (0 << LCDCN9_SSG24)

#define LCDCN9_SSG23                      2
#define LCDCN9_SSG23_MSK                 (3 << LCDCN9_SSG23)
#define LCDCN9_SSG23_LCDSEG              (3 << LCDCN9_SSG23)
//#define LCDCN9_SSG23_RSV               (2 << LCDCN9_SSG23)
//#define LCDCN9_SSG23_RSV               (1 << LCDCN9_SSG23)
#define LCDCN9_SSG23_GPIO                (0 << LCDCN9_SSG23)

#define LCDCN9_SSG22                      0
#define LCDCN9_SSG22_MSK                 (3 << LCDCN9_SSG22)
#define LCDCN9_SSG22_LCDSEG              (3 << LCDCN9_SSG22)
//#define LCDCN9_SSG22_RSV               (2 << LCDCN9_SSG22)
//#define LCDCN9_SSG22_RSV               (1 << LCDCN9_SSG22)
#define LCDCN9_SSG22_GPIO                (0 << LCDCN9_SSG22)

// LCDCN10 //
#define LCDCN10_SSG29                      6
#define LCDCN10_SSG29_MSK                 (3 << LCDCN10_SSG29)
#define LCDCN10_SSG29_LCDSEG              (3 << LCDCN10_SSG29)
//#define LCDCN10_SSG29_RSV               (2 << LCDCN10_SSG29)
//#define LCDCN10_SSG29_RSV               (1 << LCDCN10_SSG29)
#define LCDCN10_SSG29_GPIO                (0 << LCDCN10_SSG29)

#define LCDCN10_SSG28                      4
#define LCDCN10_SSG28_MSK                 (3 << LCDCN10_SSG28)
#define LCDCN10_SSG28_LCDSEG              (3 << LCDCN10_SSG28)
//#define LCDCN10_SSG28_RSV               (2 << LCDCN10_SSG28)
//#define LCDCN10_SSG28_RSV               (1 << LCDCN10_SSG28)
#define LCDCN10_SSG28_GPIO                (0 << LCDCN10_SSG28)

#define LCDCN10_SSG27                      2
#define LCDCN10_SSG27_MSK                 (3 << LCDCN10_SSG27)
#define LCDCN10_SSG27_LCDSEG              (3 << LCDCN10_SSG27)
//#define LCDCN10_SSG27_RSV               (2 << LCDCN10_SSG27)
//#define LCDCN10_SSG27_RSV               (1 << LCDCN10_SSG27)
#define LCDCN10_SSG27_GPIO                (0 << LCDCN10_SSG27)

#define LCDCN10_SSG26                      0
#define LCDCN10_SSG26_MSK                 (3 << LCDCN10_SSG26)
#define LCDCN10_SSG26_LCDSEG              (3 << LCDCN10_SSG26)
//#define LCDCN10_SSG26_RSV               (2 << LCDCN10_SSG26)
//#define LCDCN10_SSG26_RSV               (1 << LCDCN10_SSG26)
#define LCDCN10_SSG26_GPIO                (0 << LCDCN10_SSG26)

// LCDCN11 //
#define LCDCN11_SSG33                      6
#define LCDCN11_SSG33_MSK                 (3 << LCDCN11_SSG33)
#define LCDCN11_SSG33_LCDSEG              (3 << LCDCN11_SSG33)
//#define LCDCN11_SSG33_RSV               (2 << LCDCN11_SSG33)
//#define LCDCN11_SSG33_RSV               (1 << LCDCN11_SSG33)
#define LCDCN11_SSG33_GPIO                (0 << LCDCN11_SSG33)

#define LCDCN11_SSG32                      4
#define LCDCN11_SSG32_MSK                 (3 << LCDCN11_SSG32)
#define LCDCN11_SSG32_LCDSEG              (3 << LCDCN11_SSG32)
//#define LCDCN11_SSG32_RSV               (2 << LCDCN11_SSG32)
//#define LCDCN11_SSG32_RSV               (1 << LCDCN11_SSG32)
#define LCDCN11_SSG32_GPIO                (0 << LCDCN11_SSG32)

#define LCDCN11_SSG31                      2
#define LCDCN11_SSG31_MSK                 (3 << LCDCN11_SSG31)
#define LCDCN11_SSG31_LCDSEG              (3 << LCDCN11_SSG31)
//#define LCDCN11_SSG31_RSV               (2 << LCDCN11_SSG31)
//#define LCDCN11_SSG31_RSV               (1 << LCDCN11_SSG31)
#define LCDCN11_SSG31_GPIO                (0 << LCDCN11_SSG31)

#define LCDCN11_SSG30                      0
#define LCDCN11_SSG30_MSK                 (3 << LCDCN11_SSG30)
#define LCDCN11_SSG30_LCDSEG              (3 << LCDCN11_SSG30)
//#define LCDCN11_SSG30_RSV               (2 << LCDCN11_SSG30)
//#define LCDCN11_SSG30_RSV               (1 << LCDCN11_SSG30)
#define LCDCN11_SSG30_GPIO                (0 << LCDCN11_SSG30)
*/
/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define LCD_CLK_ClkSelect(ClkSel)       (OSCCN1 = ((OSCCN1 & (~LCDS_MSK)) | ClkSel))
#define LCD_CLK_DivSelect(DivSel)       (OSCCN2 = ((OSCCN2 & (~DLCD_MSK)) | DivSel))
//涓嬮潰?╁€??糃LK.H 瀹氱京?庝?
//#define CLK_LCDCKSelect(LCDCKSel)         (OSCCN1 = ((OSCCN1 & (~LCDS_MSK)) | LCDCKSel))
//#define CLK_LCDCKDivSelect(LCDCKSel)      (OSCCN2 = ((OSCCN2 & (~DLCD_MSK)) | LCDCKSel))




#define LCD_Enable()                    (LCDCN1 = LCDCN1 | ENLCP_ENABLE)
#define LCD_Disable()                   (LCDCN1 = LCDCN1 & ~(ENLCP_MSK)
#define LCD_ChargePumpSelect(VLCDSel)   (LCDCN1 = ((LCDCN1 & (~LCDV_MSK)) | VLCDSel))
#define LCD_OutBufferEnable()           (LCDCN1 |= ENLB_ENABLE)
#define LCD_OutBufferDisable()          (LCDCN1 &= (~ENLB_MSK))
#define LCD_ChargePumpClk(VLCDCLK)      (LCDCN1 = ((LCDCN1 & (~SELPCLK_MSK)) | VLCDCLK))



#define LCD_DisplayOn()                 (LCDCN2 &= (~LCDBL_MSK))
#define LCD_DisplayOff()                (LCDCN2 |= LCDBL_LCDOFF)

#define LCD                              1
#define IO                               0
#define LCD_PT60Mode(Sel)			    (LCDCN3 =  (LCDCN3 & 0xFC) |  Sel | (Sel<<1))       /*com0*/
#define LCD_PT61Mode(Sel)			    (LCDCN3 =  (LCDCN3 & 0xF3) | (Sel<<2) | (Sel<<3))   /*com1*/
#define LCD_PT62Mode(Sel)			    (LCDCN3 =  (LCDCN3 & 0xCF) | (Sel<<4) | (Sel<<5))   /*com2*/
#define LCD_PT63Mode(Sel)			    (LCDCN3 =  (LCDCN3 & 0x3F) | (Sel<<6) | (Sel<<7))   /*com3*/

#define LCD_PT80Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xFE) | Sel)
#define LCD_PT81Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xFD) | (Sel<<1))
#define LCD_PT82Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xFB) | (Sel<<2))
#define LCD_PT83Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xF7) | (Sel<<3))
#define LCD_PT84Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xEF) | (Sel<<4))
#define LCD_PT85Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xDF) | (Sel<<5))
#define LCD_PT86Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0xBF) | (Sel<<6))
#define LCD_PT87Mode(Sel)				(LCDCN4 =  (LCDCN4 & 0x7F) | (Sel<<7))

#define LCD_PT64Mode(Sel)			    (LCDCN6 =  (LCDCN6 & 0xFC) |  Sel | (Sel<<1))
#define LCD_PT65Mode(Sel)			    (LCDCN6 =  (LCDCN6 & 0xF3) | (Sel<<2) | (Sel<<3))
#define LCD_PT66Mode(Sel)			    (LCDCN6 =  (LCDCN6 & 0xCF) | (Sel<<4) | (Sel<<5))
#define LCD_PT67Mode(Sel)			    (LCDCN6 =  (LCDCN6 & 0x3F) | (Sel<<6) | (Sel<<7))

#define LCD_PT70Mode(Sel)			    (LCDCN7 =  (LCDCN7 & 0xFC) |  Sel | (Sel<<1))
#define LCD_PT71Mode(Sel)			    (LCDCN7 =  (LCDCN7 & 0xF3) | (Sel<<2) | (Sel<<3))
#define LCD_PT72Mode(Sel)			    (LCDCN7 =  (LCDCN7 & 0xCF) | (Sel<<4) | (Sel<<5))
#define LCD_PT73Mode(Sel)			    (LCDCN7 =  (LCDCN7 & 0x3F) | (Sel<<6) | (Sel<<7))
#define LCD_PT74Mode(Sel)			    (LCDCN8 =  (LCDCN8 & 0xFC) |  Sel | (Sel<<1))
#define LCD_PT75Mode(Sel)			    (LCDCN8 =  (LCDCN8 & 0xF3) | (Sel<<2) | (Sel<<3))
#define LCD_PT76Mode(Sel)			    (LCDCN8 =  (LCDCN8 & 0xCF) | (Sel<<4) | (Sel<<5))
#define LCD_PT77Mode(Sel)			    (LCDCN8 =  (LCDCN8 & 0x3F) | (Sel<<6) | (Sel<<7))


#define LCD_WriteData(uAddr,uData)      (*uAddr=uData)
#define LCD_ReadData(uAddr)             (*(uAddr))
/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
//void LCD_Open(unsigned char lcdpr,      //LCD charge pump circuit controller
//              unsigned char ckdiv,      //Prescaler of LCD peripheral operating frequency
//              unsigned char vlcdx,      //Charge pump voltage state select controller
//              unsigned char lcdmx,      //LCD Waveform output controller
//              unsigned char lcdbi);     //LCD waveform bias controller
