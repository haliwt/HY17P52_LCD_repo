/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17M Series                                                                 *|
|**************************************************************************************************/
#include <INT.h>           // Interrupt Config for GPIO
/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
//// PT1 //
#define PT10                      0
#define PT10_MSK                 (1 << PT10)
#define PT10_H                   (1 << PT10)
#define PT10_L                   (0 << PT10)
#define PT11                      1
#define PT11_MSK                 (1 << PT11)
#define PT11_H                   (1 << PT11)
#define PT11_L                   (0 << PT11)
#define PT12                      2
#define PT12_MSK                 (1 << PT12)
#define PT12_H                   (1 << PT12)
#define PT12_L                   (0 << PT12)
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

//// PT1IN //
#define IN10                      0
#define IN10_MSK                 (1 << IN10)
#define IN10_H                   (1 << IN10)
#define IN10_L                   (0 << IN10)
#define IN11                      1
#define IN11_MSK                 (1 << IN11)
#define IN11_H                   (1 << IN11)
#define IN11_L                   (0 << IN11)
#define IN12                      2
#define IN12_MSK                 (1 << IN12)
#define IN12_H                   (1 << IN12)
#define IN12_L                   (0 << IN12)
#define IN13                      3
#define IN13_MSK                 (1 << IN13)
#define IN13_H                   (1 << IN13)
#define IN13_L                   (0 << IN13)
#define IN14                      4
#define IN14_MSK                 (1 << IN14)
#define IN14_H                   (1 << IN14)
#define IN14_L                   (0 << IN14)
#define IN15                      5
#define IN15_MSK                 (1 << IN15)
#define IN15_H                   (1 << IN15)
#define IN15_L                   (0 << IN15)
#define IN16                      6
#define IN16_MSK                 (1 << IN16)
#define IN16_H                   (1 << IN16)
#define IN16_L                   (0 << IN16)

//// TRISC1 //
#define TC10                      0
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

//// PT2 //
#define PT20                      0
#define PT20_MSK                 (1 << PT20)
#define PT20_H                   (1 << PT20)
#define PT20_L                   (0 << PT20)
#define PT21                      1
#define PT21_MSK                 (1 << PT21)
#define PT21_H                   (1 << PT21)
#define PT21_L                   (0 << PT21)

//// PT2IN //
#define IN20                      0
#define IN20_MSK                 (1 << IN20)
#define IN20_H                   (1 << IN20)
#define IN20_L                   (0 << IN20)
#define IN21                      1
#define IN21_MSK                 (1 << IN21)
#define IN21_H                   (1 << IN21)
#define IN21_L                   (0 << IN21)

//// TRISC2 //
#define TC20                      0
#define TC20_MSK                 (1 << TC20)
#define TC20_H                   (1 << TC20)
#define TC20_L                   (0 << TC20)
#define TC21                      1
#define TC21_MSK                 (1 << TC21)
#define TC21_H                   (1 << TC21)
#define TC21_L                   (0 << TC21)

//// PT2PU //
#define PU20                      0
#define PU20_MSK                 (1 << PU20)
#define PU20_H                   (1 << PU20)
#define PU20_L                   (0 << PU20)
#define PU21                      1
#define PU21_MSK                 (1 << PU21)
#define PU21_H                   (1 << PU21)
#define PU21_L                   (0 << PU21)

//// PT3 //
#define PT30                      0
#define PT30_MSK                 (1 << PT30)
#define PT30_H                   (1 << PT30)
#define PT30_L                   (0 << PT30)
#define PT31                      1
#define PT31_MSK                 (1 << PT31)
#define PT31_H                   (1 << PT31)
#define PT31_L                   (0 << PT31)
#define PT32                      2
#define PT32_MSK                 (1 << PT32)
#define PT32_H                   (1 << PT32)
#define PT32_L                   (0 << PT32)
#define PT33                      3
#define PT33_MSK                 (1 << PT33)
#define PT33_H                   (1 << PT33)
#define PT33_L                   (0 << PT33)
#define PT34                      4
#define PT34_MSK                 (1 << PT34)
#define PT34_H                   (1 << PT34)
#define PT34_L                   (0 << PT34)
#define PT35                      5
#define PT35_MSK                 (1 << PT35)
#define PT35_H                   (1 << PT35)
#define PT35_L                   (0 << PT35)
#define PT36                      6
#define PT36_MSK                 (1 << PT36)
#define PT36_H                   (1 << PT36)
#define PT36_L                   (0 << PT36)
#define PT37                      7
#define PT37_MSK                 (1 << PT37)
#define PT37_H                   (1 << PT37)
#define PT37_L                   (0 << PT37)

//// PT3IN //
#define IN30                      0
#define IN30_MSK                 (1 << IN30)
#define IN30_H                   (1 << IN30)
#define IN30_L                   (0 << IN30)
#define IN31                      1
#define IN31_MSK                 (1 << IN31)
#define IN31_H                   (1 << IN31)
#define IN31_L                   (0 << IN31)
#define IN32                      2
#define IN32_MSK                 (1 << IN32)
#define IN32_H                   (1 << IN32)
#define IN32_L                   (0 << IN32)
#define IN33                      3
#define IN33_MSK                 (1 << IN33)
#define IN33_H                   (1 << IN33)
#define IN33_L                   (0 << IN33)
#define IN34                      4
#define IN34_MSK                 (1 << IN34)
#define IN34_H                   (1 << IN34)
#define IN34_L                   (0 << IN34)
#define IN35                      5
#define IN35_MSK                 (1 << IN35)
#define IN35_H                   (1 << IN35)
#define IN35_L                   (0 << IN35)
#define IN36                      6
#define IN36_MSK                 (1 << IN36)
#define IN36_H                   (1 << IN36)
#define IN36_L                   (0 << IN36)
#define IN37                      7
#define IN37_MSK                 (1 << IN37)
#define IN37_H                   (1 << IN37)
#define IN37_L                   (0 << IN37)

//// TRISC3 //
#define TC30                      0
#define TC30_MSK                 (1 << TC30)
#define TC30_H                   (1 << TC30)
#define TC30_L                   (0 << TC30)
#define TC31                      1
#define TC31_MSK                 (1 << TC31)
#define TC31_H                   (1 << TC31)
#define TC31_L                   (0 << TC31)
#define TC32                      2
#define TC32_MSK                 (1 << TC32)
#define TC32_H                   (1 << TC32)
#define TC32_L                   (0 << TC32)
#define TC33                      3
#define TC33_MSK                 (1 << TC33)
#define TC33_H                   (1 << TC33)
#define TC33_L                   (0 << TC33)
#define TC34                      4
#define TC34_MSK                 (1 << TC34)
#define TC34_H                   (1 << TC34)
#define TC34_L                   (0 << TC34)
#define TC35                      5
#define TC35_MSK                 (1 << TC35)
#define TC35_H                   (1 << TC35)
#define TC35_L                   (0 << TC35)
#define TC36                      6
#define TC36_MSK                 (1 << TC36)
#define TC36_H                   (1 << TC36)
#define TC36_L                   (0 << TC36)
#define TC37                      7
#define TC37_MSK                 (1 << TC37)
#define TC37_H                   (1 << TC37)
#define TC37_L                   (0 << TC37)

//// PT3PU //
#define PU30                      0
#define PU30_MSK                 (1 << PU30)
#define PU30_H                   (1 << PU30)
#define PU30_L                   (0 << PU30)
#define PU31                      1
#define PU31_MSK                 (1 << PU31)
#define PU31_H                   (1 << PU31)
#define PU31_L                   (0 << PU31)
#define PU32                      2
#define PU32_MSK                 (1 << PU32)
#define PU32_H                   (1 << PU32)
#define PU32_L                   (0 << PU32)
#define PU33                      3
#define PU33_MSK                 (1 << PU33)
#define PU33_H                   (1 << PU33)
#define PU33_L                   (0 << PU33)
#define PU34                      4
#define PU34_MSK                 (1 << PU34)
#define PU34_H                   (1 << PU34)
#define PU34_L                   (0 << PU34)
#define PU35                      5
#define PU35_MSK                 (1 << PU35)
#define PU35_H                   (1 << PU35)
#define PU35_L                   (0 << PU35)
#define PU36                      6
#define PU36_MSK                 (1 << PU36)
#define PU36_H                   (1 << PU36)
#define PU36_L                   (0 << PU36)
#define PU37                      7
#define PU37_MSK                 (1 << PU37)
#define PU37_H                   (1 << PU37)
#define PU37_L                   (0 << PU37)

//// PT3DA //
#define DA30                      0
#define DA30_MSK                 (1 << DA30)
#define DA30_H                   (1 << DA30)
#define DA30_L                   (0 << DA30)
#define DA31                      1
#define DA31_MSK                 (1 << DA31)
#define DA31_H                   (1 << DA31)
#define DA31_L                   (0 << DA31)
//#define DA32                      2
//#define DA32_MSK                 (1 << DA32)
//#define DA32_H                   (1 << DA32)
//#define DA32_L                   (0 << DA32)
//#define DA33                      3
//#define DA33_MSK                 (1 << DA33)
//#define DA33_H                   (1 << DA33)
//#define DA33_L                   (0 << DA33)
//#define DA34                      4
//#define DA34_MSK                 (1 << DA34)
//#define DA34_H                   (1 << DA34)
//#define DA34_L                   (0 << DA34)
//#define DA35                      5
//#define DA35_MSK                 (1 << DA35)
//#define DA35_H                   (1 << DA35)
//#define DA35_L                   (0 << DA35)
#define DA36                      6
#define DA36_MSK                 (1 << DA36)
#define DA36_H                   (1 << DA36)
#define DA36_L                   (0 << DA36)
#define DA37                      7
#define DA37_MSK                 (1 << DA37)
#define DA37_H                   (1 << DA37)
#define DA37_L                   (0 << DA37)

//// PT1M1 //
#define INTEG0                    0
#define INTEG0_MSK               (3 << INTEG0)
#define INTEG0_LEV               (3 << INTEG0)
//#define INTEG0_LEV             (2 << INTEG0)
#define INTEG0_EDGERISE          (1 << INTEG0)
#define INTEG0_EDGEFALL          (0 << INTEG0)

#define INTEG1                    2
#define INTEG1_MSK               (3 << INTEG1)
#define INTEG1_LEV               (3 << INTEG1)
//#define INTEG1_LEV             (2 << INTEG1)
#define INTEG1_EDGERISE          (1 << INTEG1)
#define INTEG1_EDGEFALL          (0 << INTEG1)

//// PT1M2 //
#define PM13                      6
#define PM13_MSK                 (3 << PM13)
//#define PM13_LEV               (3 << PM13)
#define PM13_SCL                 (2 << PM13)
#define PM13_PWM0_1              (1 << PM13)
#define PM13_VOHL                (0 << PM13)

#define PM12                      4
#define PM12_MSK                 (1 << PM12)
#define PM12_PWM1                (1 << PM12)
#define PM12_VOHL                (0 << PM12)

#define PM10                      0
#define PM10_MSK                 (1 << PM10)
#define PM10_TBI0_input          (1 << PM10)
#define PM10_VOHL                (0 << PM10)

//// PT1M3 //
#define PM16                      4
#define PM16_MSK                 (1 << PM16)
#define PM16_PWM0                (1 << PM16)
#define PM16_VOHL                (0 << PM16)

#define PM15                      2
#define PM15_MSK                 (3 << PM15)
//#define PM15_                  (3 << PM15)
#define PM15_TX                  (2 << PM15)
#define PM15_BZ                  (1 << PM15)
#define PM15_VOHL                (0 << PM15)

//// PT1INT //
#define INTEG2                    2
#define INTEG2_MSK               (1 << INTE	G2)
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

//// PT2M1 //
#define PM21                      2
#define PM21_MSK                 (3 << PM21)
#define PM21_TBI1_input          (3 << PM21)
#define PM21_BZ_1                (2 << PM21)
#define PM21_SCL_1               (1 << PM21)
#define PM21_VOHL                (0 << PM21)

#define PM20                      0
#define PM20_MSK                 (3 << PM20)
//#define PM20_                  (3 << PM20)
#define PM20_TX_1                (2 << PM20)
#define PM20_PWM1_1              (1 << PM20)
#define PM20_VOHL                (0 << PM20)

//// PT2INT //
#define INTEG20                   0
#define INTEG20_MSK              (1 << INTEG20)
#define INTEG20_EDGERISE         (1 << INTEG20)
#define INTEG20_EDGEFALL         (0 << INTEG20)

#define INTEG21                   1
#define INTEG21_MSK              (1 << INTEG21)
#define INTEG21_EDGERISE         (1 << INTEG21)
#define INTEG21_EDGEFALL         (0 << INTEG21)

//// PT3M1 //
#define PM33                      6
#define PM33_MSK                 (1 << PM33)
#define PM33_PWM1_2              (1 << PM33)
#define PM33_VOHL                (0 << PM33)

#define PM32                      4
#define PM32_MSK                 (3 << PM32)
//#define PM32_                  (3 << PM32)
#define PM32_SCL_3               (2 << PM32)
#define PM32_PWM0_2              (1 << PM32)
#define PM32_VOHL                (0 << PM32)

#define PM30                      0
#define PM30_MSK                 (3 << PM30)
//#define PM30_                  (3 << PM30)
#define PM30_TBI0_1              (2 << PM30)
#define PM30_SCL_2               (1 << PM30)
#define PM30_VOHL                (0 << PM30)

//// PT3M2 //
#define PM36                      4
#define PM36_MSK                 (3 << PM36)
//#define PM36_                  (3 << PM36)
#define PM36_TX_2                (2 << PM36)
#define PM36_TBI1_1              (1 << PM36)
#define PM36_VOHL                (0 << PM36)

#define PM34                      0
#define PM34_MSK                 (3 << PM34)
//#define PM34_                  (3 << PM34)
#define PM34_TX_3                (2 << PM34)
#define PM34_BZ_2                (1 << PM34)
#define PM34_VOHL                (0 << PM34)

//// PT3INT //
#define INTEG30                   0
#define INTEG30_MSK              (1 << INTEG30)
#define INTEG30_EDGERISE         (1 << INTEG30)
#define INTEG30_EDGEFALL         (0 << INTEG30)

#define INTEG31                   1
#define INTEG31_MSK              (1 << INTEG31)
#define INTEG31_EDGERISE         (1 << INTEG31)
#define INTEG31_EDGEFALL         (0 << INTEG31)

#define INTEG32                   2
#define INTEG32_MSK              (1 << INTEG32)
#define INTEG32_EDGERISE         (1 << INTEG32)
#define INTEG32_EDGEFALL         (0 << INTEG32)

#define INTEG33                   3
#define INTEG33_MSK              (1 << INTEG33)
#define INTEG33_EDGERISE         (1 << INTEG33)
#define INTEG33_EDGEFALL         (0 << INTEG33)

#define INTEG34                   4
#define INTEG34_MSK              (1 << INTEG34)
#define INTEG34_EDGERISE         (1 << INTEG34)
#define INTEG34_EDGEFALL         (0 << INTEG34)

#define INTEG35                   5
#define INTEG35_MSK              (1 << INTEG35)
#define INTEG35_EDGERISE         (1 << INTEG35)
#define INTEG35_EDGEFALL         (0 << INTEG35)

#define INTEG36                   6
#define INTEG36_MSK              (1 << INTEG36)
#define INTEG36_EDGERISE         (1 << INTEG36)
#define INTEG36_EDGEFALL         (0 << INTEG36)

#define INTEG37                   7
#define INTEG37_MSK              (1 << INTEG37)
#define INTEG37_EDGERISE         (1 << INTEG37)
#define INTEG37_EDGEFALL         (0 << INTEG37)
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

// PT1.x // x=0~6
#define GPIO_PT1OutputMode(BitSet)           (TRISC1 |= BitSet)
#define GPIO_PT1OutputHigh(BitSet)           (PT1 |= BitSet)
#define GPIO_PT1OutputLow(BitSet)            (PT1 &= ~BitSet)    // Valid only when PT is Output mode

#define GPIO_PT1InputMode(BitSet)            (TRISC1 &= ~ BitSet)
#define GPIO_PT1InputEnable(BitSet)          (PT1IN |= BitSet)
#define GPIO_PT1InputDisable(BitSet)         (PT1IN &= ~BitSet)
#define GPIO_PT1SETPU(BitSet)                (PT1PU |= BitSet)
#define GPIO_PT1CLRPU(BitSet)                (PT1PU &= ~ BitSet)
#define GPIO_PT1SETPUAll()                   (PT1PU = 0xff)

#define GPIO_PT1SETDA(BitSet)                (PT1DA |= BitSet)
#define GPIO_PT1CLRDA(BitSet)                (PT1DA &= ~ BitSet)

#define GPIO_PT1GET(BitSet)                  (PT1 & BitSet)
#define GPIO_PT1SET(BitSet)                  (PT1 |=  BitSet)
#define GPIO_PT1CLR(BitSet)                  (PT1 &= ~BitSet)

#define GPIO_INTEG0Sel(EG0Sel)               (PT1M1 = ((PT1M1 & (~INTEG0_MSK)) | EG0Sel))
#define GPIO_INTEG1Sel(EG1Sel)               (PT1M1 = ((PT1M1 & (~INTEG1_MSK)) | EG1Sel))
#define GPIO_PM10Sel(PM10Sel)                (PT1M2 = ((PT1M2 & (~PM10_MSK )) | PM10Sel))
#define GPIO_PM12Sel(PM12Sel)                (PT1M2 = ((PT1M2 & (~PM12_MSK )) | PM12Sel))
#define GPIO_PM13Sel(PM13Sel)                (PT1M2 = ((PT1M2 & (~PM13_MSK )) | PM13Sel))
#define GPIO_PM15Sel(PM15Sel)                (PT1M3 = ((PT1M3 & (~PM15_MSK )) | PM15Sel))
#define GPIO_PM16Sel(PM16Sel)                (PT1M3 = ((PT1M3 & (~PM16_MSK )) | PM16Sel))

// PT2.x // x=0~1
#define GPIO_PT2OutputMode(BitSet)           (TRISC2 |=BitSet)
#define GPIO_PT2OutputHigh(BitSet)           (PT2 |= BitSet)
#define GPIO_PT2OutputLow(BitSet)            (PT2 &= ~BitSet)    // Valid only when PT is Output mode

#define GPIO_PT2InputMode(BitSet)            (TRISC2 &= ~BitSet)
#define GPIO_PT2InputEnable(BitSet)          (PT2IN |= BitSet)
#define GPIO_PT2InputDisable(BitSet)         (PT2IN &= ~BitSet)
#define GPIO_PT2SETPU(BitSet)                (PT2PU |= BitSet)
#define GPIO_PT2CLRPU(BitSet)                (PT2PU &= ~BitSet)
#define GPIO_PT2SETPUAll()                   (PT2PU = 0xff)

//#define GPIO_PT2SETDA(BitSet)                (PT2DA |=BitSet)
//#define GPIO_PT2CLRDA(BitSet)                (PT2DA &= ~ BitSet)
#define GPIO_PT2GET(BitSet)                  (PT2 & BitSet)
#define GPIO_PT2SET(BitSet)                  (PT2 |= BitSet)
#define GPIO_PT2CLR(BitSet)                  (PT2 &= ~BitSet)

#define GPIO_PM20Sel(PM20Sel)                (PT2M1 = ((PT2M1 & (~PM20_MSK )) | PM20Sel))
#define GPIO_PM21Sel(PM21Sel)                (PT2M1 = ((PT2M1 & (~PM21_MSK )) | PM21Sel))

// PT3.x // x=0~7
#define GPIO_PT3OutputMode(BitSet)           (TRISC3 |= BitSet)
#define GPIO_PT3OutputHigh(BitSet)           (PT3 |= BitSet)
#define GPIO_PT3OutputLow(BitSet)            (PT3 &= ~BitSet)    // Valid only when PT is Output mode

#define GPIO_PT3InputMode(BitSet)            (TRISC3 &= ~BitSet)
#define GPIO_PT3InputEnable(BitSet)          (PT3IN |=  BitSet)
#define GPIO_PT3InputDisable(BitSet)         (PT3IN &= ~BitSet)
#define GPIO_PT3SETPU(BitSet)                (PT3PU |=  BitSet)
#define GPIO_PT3CLRPU(BitSet)                (PT3PU &= ~BitSet)
#define GPIO_PT3SETPUAll()                   (PT3PU = 0xff)

#define GPIO_PT3SETDA(BitSet)                (PT3DA |= BitSet)
#define GPIO_PT3CLRDA(BitSet)                (PT3DA &= ~ BitSet)

#define GPIO_PT3GET(BitSet)                  (PT3 & BitSet)
#define GPIO_PT3SET(BitSet)                  (PT3 |= BitSet)
#define GPIO_PT3CLR(BitSet)                  (PT3 &= ~BitSet)

#define GPIO_PM30Sel(PM30Sel)                (PT3M1 = ((PT3M1 & (~PM30_MSK )) | PM30Sel))
#define GPIO_PM32Sel(PM32Sel)                (PT3M1 = ((PT3M1 & (~PM32_MSK )) | PM32Sel))
#define GPIO_PM33Sel(PM33Sel)                (PT3M1 = ((PT3M1 & (~PM33_MSK )) | PM33Sel))
#define GPIO_PM34Sel(PM34Sel)                (PT3M2 = ((PT3M2 & (~PM34_MSK )) | PM34Sel))
#define GPIO_PM36Sel(PM36Sel)                (PT3M2 = ((PT3M2 & (~PM36_MSK )) | PM36Sel))


//Smoke Detector//
#define GPIO_GetPT1Data(PT1Data)             PT1Data=PT1
#define GPIO_GetPT2Data(PT2Data)             PT2Data=PT2
#define GPIO_GetPT3Data(PT3Data)             PT3Data=PT3

/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void GPIO_OpenPT1Input(unsigned char InputBits,
                       unsigned char PullHighBits);
void GPIO_OpenPT1Output(unsigned char OutputBits,
                       unsigned char OutHighBits);
void GPIO_OpenPT2Input(unsigned char InputBits,
                       unsigned char PullHighBits);
void GPIO_OpenPT2Output(unsigned char OutputBits,
                       unsigned char OutHighBits);
void GPIO_OpenPT3Input(unsigned char InputBits,
                       unsigned char PullHighBits);
void GPIO_OpenPT3Output(unsigned char OutputBits,
                       unsigned char OutHighBits);