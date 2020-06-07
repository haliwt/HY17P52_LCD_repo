/**************************************************************************************************|
|* Copyright 2018 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17P Series                                                                 *|
|**************************************************************************************************/

/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__
//// PT1 //
#if defined(USE_HY17P58_2M) || defined(USE_HY17P58_4M) || defined(USE_HY17P58_8M)
#define P58_PT10                      2                                    //PT1.0 for P58 
#define P58_PT10_MSK                 (1 << P58_PT10)
#define P58_PT10_H                   (1 << P58_PT10)
#define P58_PT10_L                   (0 << P58_PT10)
#define P58_PT11                      2                                    //PT1.1 for P58 
#define P58_PT11_MSK                 (1 << P58_PT11)
#define P58_PT11_H                   (1 << P58_PT11)
#define P58_PT11_L                   (0 << P58_PT11)
#else  /* HY17P52 */ //FOR other serials
#define PT10                      0
#define PT10_MSK                 (1 << PT10)
#define PT10_H                   (1 << PT10)
#define PT10_L                   (0 << PT10)

#define PT11                      1
#define PT11_MSK                 (1 << PT11)
#define PT11_H                   (1 << PT11)
#define PT11_L                   (0 << PT11)
#endif

#if defined(USE_HY17P48_2M) || defined(USE_HY17P48_4M) || defined(USE_HY17P48_8M)
#define P48_PT12                      2                                  //PT1.2 for P48 
#define P48_PT12_MSK                 (1 << P48_PT12)
#define P48_PT12_H                   (1 << P48_PT12)
#define P48_PT12_L                   (0 << P48_PT12)
#else /* HY17P52 */   //FOR other serials
#define PT12        
#define PT12_MSK                 (1 << PT12)
#define PT12_H                   (1 << PT12)
#define PT12_L                   (0 << PT12)
#endif
/************************************************
 * 
 * FOR other serials
 * 
 ***********************************************/
#define PT13                      3
#define PT13_MSK                 (1 << PT13)
#define PT13_H                   (1 << PT13)
#define PT13_L                   (0 << PT13)

#define PT14                      4
#define PT14_MSK                 (1 << PT14)
#define PT14_H                   (1 << PT14)
#define PT14_L                   (0 << PT14)

#define PT15                      5
#define PT15_MSK                 (1 << PT15)
#define PT15_H                   (1 << PT15)
#define PT15_L                   (0 << PT15)

#define PT16                      6
#define PT16_MSK                 (1 << PT16)
#define PT16_H                   (1 << PT16)
#define PT16_L                   (0 << PT16)

#define PT17                      7
#define PT17_MSK                 (1 << PT17)
#define PT17_H                   (1 << PT17)
#define PT17_L                   (0 << PT17)

//// TRISC1 Direction Register Inpurt OR Output //
#define TC10                      0               /*PT1.0  TC1.0*/
#define TC10_MSK                 (1 << TC10)
#define TC10_H                   (1 << TC10)
#define TC10_L                   (0 << TC10)

#define TC11                      1
#define TC11_MSK                 (1 << TC11)
#define TC11_H                   (1 << TC11)
#define TC11_L                   (0 << TC11)

#define TC12                      2
#define TC12_MSK                 (1 << TC12)
#define TC12_H                   (1 << TC12)
#define TC12_L                   (0 << TC12)

#define TC13                      3
#define TC13_MSK                 (1 << TC13)
#define TC13_H                   (1 << TC13)
#define TC13_L                   (0 << TC13)

#define TC14                      4
#define TC14_MSK                 (1 << TC14)
#define TC14_H                   (1 << TC14)
#define TC14_L                   (0 << TC14)

#define TC15                      5
#define TC15_MSK                 (1 << TC15)
#define TC15_H                   (1 << TC15)
#define TC15_L                   (0 << TC15)
#define TC16                      6
#define TC16_MSK                 (1 << TC16)
#define TC16_H                   (1 << TC16)
#define TC16_L                   (0 << TC16)
#define TC17                      7
#define TC17_MSK                 (1 << TC17)
#define TC17_H                   (1 << TC17)
#define TC17_L                   (0 << TC17)

//// PT1PU //
#define PU10                      0
#define PU10_MSK                 (1 << PU10)
#define PU10_H                   (1 << PU10)
#define PU10_L                   (0 << PU10)

#define PU11                      1
#define PU11_MSK                 (1 << PU11)
#define PU11_H                   (1 << PU11)
#define PU11_L                   (0 << PU11)

#define PU12                      2
#define PU12_MSK                 (1 << PU12)
#define PU12_H                   (1 << PU12)
#define PU12_L                   (0 << PU12)

#define PU13                      3
#define PU13_MSK                 (1 << PU13)
#define PU13_H                   (1 << PU13)
#define PU13_L                   (0 << PU13)
#define PU14                      4
#define PU14_MSK                 (1 << PU14)
#define PU14_H                   (1 << PU14)
#define PU14_L                   (0 << PU14)
#define PU15                      5
#define PU15_MSK                 (1 << PU15)
#define PU15_H                   (1 << PU15)
#define PU15_L                   (0 << PU15)
#define PU16                      6
#define PU16_MSK                 (1 << PU16)
#define PU16_H                   (1 << PU16)
#define PU16_L                   (0 << PU16)
#define PU17                      7
#define PU17_MSK                 (1 << PU17)
#define PU17_H                   (1 << PU17)
#define PU17_L                   (0 << PU17)

//// PT1DA //
#define DA10                      0
#define DA10_MSK                 (1 << DA10)
#define DA10_H                   (1 << DA10)
#define DA10_L                   (0 << DA10)

#define DA11                      1
#define DA11_MSK                 (1 << DA11)
#define DA11_H                   (1 << DA11)
#define DA11_L                   (0 << DA11)

#define DA12                      2
#define DA12_MSK                 (1 << DA12)
#define DA12_H                   (1 << DA12)
#define DA12_L                   (0 << DA12)

#define DA13                      3
#define DA13_MSK                 (1 << DA13)
#define DA13_H                   (1 << DA13)
#define DA13_L                   (0 << DA13)

#define DA14                      4
#define DA14_MSK                 (1 << DA14)
#define DA14_H                   (1 << DA14)
#define DA14_L                   (0 << DA14)

#define DA15                      5
#define DA15_MSK                 (1 << DA15)
#define DA15_H                   (1 << DA15)
#define DA15_L                   (0 << DA15)
#define DA16                      6
#define DA16_MSK                 (1 << DA16)
#define DA16_H                   (1 << DA16)
#define DA16_L                   (0 << DA16)
#define DA17                      7
#define DA17_MSK                 (1 << DA17)
#define DA17_H                   (1 << DA17)
#define DA17_L                   (0 << DA17)

//// PT2 //
#define PT20                      0
#define PT20_MSK                 (1 << PT20)
#define PT20_H                   (1 << PT20)
#define PT20_L                   (0 << PT20)
#define PT21                      1
#define PT21_MSK                 (1 << PT21)
#define PT21_H                   (1 << PT21)
#define PT21_L                   (0 << PT21)
#define PT22                      2
#define PT22_MSK                 (1 << PT22)
#define PT22_H                   (1 << PT22)
#define PT22_L                   (0 << PT22)
#define PT23                      3
#define PT23_MSK                 (1 << PT23)
#define PT23_H                   (1 << PT23)
#define PT23_L                   (0 << PT23)
#define PT24                      4
#define PT24_MSK                 (1 << PT24)
#define PT24_H                   (1 << PT24)
#define PT24_L                   (0 << PT24)
#define PT25                      5
#define PT25_MSK                 (1 << PT25)
#define PT25_H                   (1 << PT25)
#define PT25_L                   (0 << PT25)
#define PT26                      6
#define PT26_MSK                 (1 << PT26)
#define PT26_H                   (1 << PT26)
#define PT26_L                   (0 << PT26)
#define PT27                      7
#define PT27_MSK                 (1 << PT27)
#define PT27_H                   (1 << PT27)
#define PT27_L                   (0 << PT27)

//// TRISC2 //
#define TC20                      0
#define TC20_MSK                 (1 << TC20)
#define TC20_H                   (1 << TC20)
#define TC20_L                   (0 << TC20)
#define TC21                      1
#define TC21_MSK                 (1 << TC21)
#define TC21_H                   (1 << TC21)
#define TC21_L                   (0 << TC21)
#define TC22                      2
#define TC22_MSK                 (1 << TC22)
#define TC22_H                   (1 << TC22)
#define TC22_L                   (0 << TC22)
#define TC23                      3
#define TC23_MSK                 (1 << TC23)
#define TC23_H                   (1 << TC23)
#define TC23_L                   (0 << TC23)
#define TC24                      4
#define TC24_MSK                 (1 << TC24)
#define TC24_H                   (1 << TC24)
#define TC24_L                   (0 << TC24)
#define TC25                      5
#define TC25_MSK                 (1 << TC25)
#define TC25_H                   (1 << TC25)
#define TC25_L                   (0 << TC25)
#define TC26                      6
#define TC26_MSK                 (1 << TC26)
#define TC26_H                   (1 << TC26)
#define TC26_L                   (0 << TC26)
#define TC27                      7
#define TC27_MSK                 (1 << TC27)
#define TC27_H                   (1 << TC27)
#define TC27_L                   (0 << TC27)

//// PT2PU //
#define PU20                      0
#define PU20_MSK                 (1 << PU20)
#define PU20_H                   (1 << PU20)
#define PU20_L                   (0 << PU20)
#define PU21                      1
#define PU21_MSK                 (1 << PU21)
#define PU21_H                   (1 << PU21)
#define PU21_L                   (0 << PU21)
#define PU22                      2
#define PU22_MSK                 (1 << PU22)
#define PU22_H                   (1 << PU22)
#define PU22_L                   (0 << PU22)
#define PU23                      3
#define PU23_MSK                 (1 << PU23)
#define PU23_H                   (1 << PU23)
#define PU23_L                   (0 << PU23)
#define PU24                      4
#define PU24_MSK                 (1 << PU24)
#define PU24_H                   (1 << PU24)
#define PU24_L                   (0 << PU24)
#define PU25                      5
#define PU25_MSK                 (1 << PU25)
#define PU25_H                   (1 << PU25)
#define PU25_L                   (0 << PU25)
#define PU26                      6
#define PU26_MSK                 (1 << PU26)
#define PU26_H                   (1 << PU26)
#define PU26_L                   (0 << PU26)
#define PU27                      7
#define PU27_MSK                 (1 << PU27)
#define PU27_H                   (1 << PU27)
#define PU27_L                   (0 << PU27)

//// PT2DA //
#define DA20                      0
#define DA20_MSK                 (1 << DA20)
#define DA20_H                   (1 << DA20)
#define DA20_L                   (0 << DA20)
#define DA21                      1
#define DA21_MSK                 (1 << DA21)
#define DA21_H                   (1 << DA21)
#define DA21_L                   (0 << DA21)
#define DA22                      2
#define DA22_MSK                 (1 << DA22)
#define DA22_H                   (1 << DA22)
#define DA22_L                   (0 << DA22)
#define DA23                      3
#define DA23_MSK                 (1 << DA23)
#define DA23_H                   (1 << DA23)
#define DA23_L                   (0 << DA23)
#define DA24                      4
#define DA24_MSK                 (1 << DA24)
#define DA24_H                   (1 << DA24)
#define DA24_L                   (0 << DA24)
#define DA25                      5
#define DA25_MSK                 (1 << DA25)
#define DA25_H                   (1 << DA25)
#define DA25_L                   (0 << DA25)
#define DA26                      6
#define DA26_MSK                 (1 << DA26)
#define DA26_H                   (1 << DA26)
#define DA26_L                   (0 << DA26)
#define DA27                      7
#define DA27_MSK                 (1 << DA27)
#define DA27_H                   (1 << DA27)
#define DA27_L                   (0 << DA27)

/*PT1M1 output model selection */
#define INTEG0                    0       /* HY17P52 */
#define INTEG0_MSK               (3 << INTEG0) 
#define INTEG0_LEV               (3 << INTEG0)
//#define INTEG0_LEV             (2 << INTEG0)
#define INTEG0_EDGERISE          (1 << INTEG0)
#define INTEG0_EDGEFALL          (0 << INTEG0)

#define INTEG1                    2      /* HY17P52 */
#define INTEG1_MSK               (3 << INTEG1)
#define INTEG1_LEV               (3 << INTEG1)
//#define INTEG1_LEV             (2 << INTEG1)
#define INTEG1_EDGERISE          (1 << INTEG1)
#define INTEG1_EDGEFALL          (0 << INTEG1)

#define INTEG2                    2
#define INTEG2_MSK               (1 << INTEG2)
#define INTEG2_EDGERISE          (1 << INTEG2)
#define INTEG2_EDGEFALL          (0 << INTEG2)

#define INTEG3                    3
#define INTEG3_MSK               (1 << INTEG3)
#define INTEG3_EDGERISE          (1 << INTEG3)
#define INTEG3_EDGEFALL          (0 << INTEG3)

#define INTEG4                    4
#define INTEG4_MSK               (1 << INTEG4)
#define INTEG4_EDGERISE          (1 << INTEG4)
#define INTEG4_EDGEFALL          (0 << INTEG4)

#define INTEG5                    5
#define INTEG5_MSK               (1 << INTEG5)
#define INTEG5_EDGERISE          (1 << INTEG5)
#define INTEG5_EDGEFALL          (0 << INTEG5)

#define INTEG6                    6
#define INTEG6_MSK               (1 << INTEG6)
#define INTEG6_EDGERISE          (1 << INTEG6)
#define INTEG6_EDGEFALL          (0 << INTEG6)

#define INTEG7                    7
#define INTEG7_MSK               (1 << INTEG7)
#define INTEG7_EDGERISE          (1 << INTEG7)
#define INTEG7_EDGEFALL          (0 << INTEG7)

#define INTEG20                    0
#define INTEG20_MSK               (1 << INTEG20)
#define INTEG20_EDGERISE          (1 << INTEG20)
#define INTEG20_EDGEFALL          (0 << INTEG20)

#define INTEG21                    1
#define INTEG21_MSK               (1 << INTEG21)
#define INTEG21_EDGERISE          (1 << INTEG21)
#define INTEG21_EDGEFALL          (0 << INTEG21)

#define INTEG22                    2
#define INTEG22_MSK               (1 << INTEG22)
#define INTEG22_EDGERISE          (1 << INTEG22)
#define INTEG22_EDGEFALL          (0 << INTEG22)

#define INTEG23                    3
#define INTEG23_MSK               (1 << INTEG23)
#define INTEG23_EDGERISE          (1 << INTEG23)
#define INTEG23_EDGEFALL          (0 << INTEG23)
/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
// Peripherals/GPIO Multiplexing Config for Peripherals were placed in each peripheral module
// individually GPIO Config were declared/defined below
#if 1
#define GPIO_DIR_PT1xOutputMode(BitSet)           (TRISC1 |= (1 << BitSet)) //output "1"
#define GPIO_DIR_PT1xInputMode(BitSet)            (TRISC1 &= ~(1 << BitSet)) //input "0"
#define GPIO_PT1SETPU(BitSet)                	(PT1PU |= (1 << BitSet))    //Port setup PULL UP
#define GPIO_PT1CLRPU(BitSet)                	(PT1PU &= ~(1 << BitSet))
#define GPIO_PT1SETDA(BitSet)                	(PT1DA |= (1 << BitSet))
#define GPIO_PT1CLRDA(BitSet)                	(PT1DA &= ~(1 << BitSet))
#define GPIO_PT1GET(BitSet)                  	(PT1 & (1 <<BitSet))
#define GPIO_PT1SET(BitSet)                  	(PT1 |= (1 << BitSet))   /*setup = 1*/
#define GPIO_PT1CLR(BitSet)                  	(PT1 &= ~(1 << BitSet))  /*clear = 0*/
#endif 
#if 0
#define GPIO_INTEG0Sel(EG0Sel)               (PT1M1 = ((PT1M1 & (~INTEG0_MSK)) | EG0Sel))
#define GPIO_INTEG1Sel(EG1Sel)               (PT1M1 = ((PT1M1 & (~INTEG1_MSK)) | EG1Sel))
#define GPIO_PM12Sel(PM12Sel)                (PT1INT = ((PT1INT & (~INTEG2_MSK )) | PM12Sel))
#define GPIO_PM13Sel(PM13Sel)                (PT1INT = ((PT1INT & (~INTEG3_MSK )) | PM13Sel))
#define GPIO_PM14Sel(PM14Sel)                (PT1INT = ((PT1INT & (~INTEG4_MSK )) | PM14Sel))
#define GPIO_PM15Sel(PM15Sel)                (PT1INT = ((PT1INT & (~INTEG5_MSK )) | PM15Sel))
#define GPIO_PM16Sel(PM16Sel)                (PT1INT = ((PT1INT & (~INTEG6_MSK )) | PM16Sel))
#define GPIO_PM17Sel(PM17Sel)                (PT1INT = ((PT1INT & (~INTEG7_MSK )) | PM17Sel))
#define GPIO_PM20Sel(PM20Sel)                (PT2INT = ((PT2INT & (~INTEG20_MSK )) | PM20Sel))
#define GPIO_PM21Sel(PM21Sel)                (PT2INT = ((PT2INT & (~INTEG21_MSK )) | PM21Sel))
#define GPIO_PM22Sel(PM22Sel)                (PT2INT = ((PT2INT & (~INTEG22_MSK )) | PM22Sel))
#define GPIO_PM23Sel(PM23Sel)                (PT2INT = ((PT2INT & (~INTEG23_MSK )) | PM23Sel))

#define GPIO_PT2OutputMode(BitSet)           (TRISC2 |= (1 << BitSet))
#define GPIO_PT2InputMode(BitSet)            (TRISC2 &= ~(1 << BitSet))
#define GPIO_PT2SETPU(BitSet)                (PT2PU |= (1 << BitSet))
#define GPIO_PT2CLRPU(BitSet)                (PT2PU &= ~(1 << BitSet))
#define GPIO_PT2SETDA(BitSet)                (PT2DA |= (1 << BitSet))
#define GPIO_PT2CLRDA(BitSet)                (PT2DA &= ~(1 << BitSet))
#define GPIO_PT2GET(BitSet)                  (PT2 & (1 <<BitSet))
#define GPIO_PT2SET(BitSet)                  (PT2 |= (1 << BitSet))
#define GPIO_PT2CLR(BitSet)                  (PT2 &= ~(1 << BitSet))

#define GPIO_PT1SETPUAll()                   (PT1PU = 0xff)
#define GPIO_PT2SETPUAll()                   (PT2PU = 0xff)


// PT1.x // x=0~6
#define GPIO_PT1OutputMode(BitSet)           (TRISC1 |= BitSet)
#define GPIO_PT1OutputHigh(BitSet)           (PT1 |= BitSet)
#define GPIO_PT1OutputLow(BitSet)            (PT1 &= ~BitSet)    // Valid only when PT is Output mode

#define GPIO_PT1InputMode(BitSet)            (TRISC1 &= ~ BitSet) //PORT direction input or output 
//#define GPIO_INTERRUPT_PT1InputEnable(BitSet)          (PT1M1 |= BitSet)  /* HY17P52 isnot register*/
//#define GPIO_INTERRUPT_P1InputDisable(BitSet)          (PT1MI &= ~BitSet) /* HY17P52 isnot register*/
#define GPIO_PT1SETPU(BitSet)                (PT1PU |= BitSet)
#define GPIO_PT1CLRPU(BitSet)                (PT1PU &= ~ BitSet)
#define GPIO_PT1SETPUAll()                   (PT1PU = 0xff)

#define GPIO_PT1SETDA(BitSet)                (PT1DA |= BitSet)
#define GPIO_PT1CLRDA(BitSet)                (PT1DA &= ~ BitSet)

#define GPIO_PT1GET(BitSet)                  (PT1 & BitSet)
#define GPIO_PT1SET(BitSet)                  (PT1 |=  BitSet)
#define GPIO_PT1CLR(BitSet)                  (PT1 &= ~BitSet)
#endif 
// PT1.7 
#define GPIO_PT17_INPUT()                           (TRISC1=(TRISC1&(~TC15_MSK))| TC17_L ) //PT1.7
#define	GPIO_PT17_OUTUT()							(TRISC1=(TRISC1&(~TC17_MSK ))| TC17_H )
#define	GPIO_PT17_HIGH()							(PT1=(PT1&(~PT17_MSK))|PT17_H)
#define	GPIO_PT17_LOW()								(PT1=(PT1&(~PT17_MSK))|PT17_L)


#define	GPIO_PT15_HIGH()				(PT1=(PT1&(~PT15_MSK))|PT15_H)
#define	GPIO_PT15_LOW()					(PT1=(PT1&(~PT15_MSK))|PT15_L)

#define	GPIO_PT16_HIGH()				(PT1=(PT1&(~PT16_MSK))|PT16_H)
#define	GPIO_PT16_LOW()					(PT1=(PT1&(~PT16_MSK))|PT16_L)


#define	GPIO_PT15_DIR_INPUT()				(TRISC1=(TRISC1&(~TC15_MSK))| TC15_L )
#define	GPIO_PT15_DIR_OUTUT()				(TRISC1=(TRISC1&(~TC15_MSK ))| TC15_H )
#define	GPIO_DIR_PT1xInput(bitset)		(TRISC1 &= ~(0x01<<(bitset)))//((PT1>>PT15)&0x1)
#define GPIO_READ_PT15()				((PT1 & (0x01 << PT15)) >> PT15)//((PT1|<<PT15)&0x1)

#define	GPIO_PT16_INPUT()				(TRISC1=(TRISC1&(~TC16_MSK))| TC16_L )
#define	GPIO_PT16_OUTUT()				(TRISC1=(TRISC1&(~TC16_MSK ))| TC16_H )

#define	GPIO_DIR_PT10_INPUT()					(TRISC1=(TRISC1&(~TC10_MSK))| TC10_L )
#define	GPIO_DIR_PT10_OUTUT()				   (TRISC1=(TRISC1&(~TC10_MSK ))| TC10_H )
#define	GPIO_READ_PT10()			    		((PT1>>PT10)&0x1)    //PT10 = 0


//#define INTEG10		0
	#define INTEG10_MASK			(3<<INTEG10)
	#define	INTEG10_FALL_EDGE		(0<<INTEG10)
	#define	INTEG10_RICE_EDGE		(1<<INTEG10)
	#define	INTEG10_HIG_LOW			 (2<<INTEG10)

#define	GPIO_PT10_INTTrig(uinteg)	(PT1M1=(PT1M1&(~INTEG10_MASK))| uinteg)
	
#define	GPIO_PT10_INT(uinteg)	(PT1M1=(PT1M1&(~INTEG0_MSK))| uinteg)





#endif 