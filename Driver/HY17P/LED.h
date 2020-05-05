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
// CCNT //
#define CCLevel                       0
#define CCLevel_MSK                  (7 << CCLevel)
#define CCLevel_15mA                (7 << CCLevel)
#define CCLevel_13mA                (6 << CCLevel)
#define CCLevel_11mA                (5 << CCLevel)
#define CCLevel_9mA                  (4 << CCLevel)
#define CCLevel_7mA                  (3 << CCLevel)
#define CCLevel_5mA                  (2 << CCLevel)
#define CCLevel_3mA                  (1 << CCLevel)
#define CCLevel_2mA                   (0 << CCLevel)

// ENCCMode //
#define ENCC0                        0
#define ENCC0_MSK                        (1 <<ENCC0)
#define ENCC0_ENABLE                  (1 <<ENCC0)
#define ENCC0_DISABLE                 (0 <<ENCC0)
#define ENCC1                        1
#define ENCC1_MSK                        (1 <<ENCC1)
#define ENCC1_ENABLE                  (1 <<ENCC1)
#define ENCC1_DISABLE                 (0 <<ENCC1)
#define ENCC2                        2
#define ENCC2_MSK                        (1 <<ENCC2)
#define ENCC2_ENABLE                  (1 <<ENCC2)
#define ENCC2_DISABLE                 (0 <<ENCC2)
#define ENCC3                        3
#define ENCC3_MSK                        (1 <<ENCC3)
#define ENCC3_ENABLE                  (1 <<ENCC3)
#define ENCC3_DISABLE                 (0 <<ENCC3)
#define ENCC4                        4
#define ENCC4_MSK                        (1 <<ENCC4)
#define ENCC4_ENABLE                  (1 <<ENCC4)
#define ENCC4_DISABLE                 (0 <<ENCC4)
#define ENCC5                        5
#define ENCC5_MSK                        (1 <<ENCC5)
#define ENCC5_ENABLE                  (1 <<ENCC5)
#define ENCC5_DISABLE                 (0 <<ENCC5)
#define ENCC6                        6
#define ENCC6_MSK                        (1 <<ENCC6)
#define ENCC6_ENABLE                  (1 <<ENCC6)
#define ENCC6_DISABLE                 (0 <<ENCC6)
#define ENCC7                        7
#define ENCC7_MSK                        (1 <<ENCC7)
#define ENCC7_ENABLE                  (1 <<ENCC7)
#define ENCC7_DISABLE                 (0 <<ENCC7)
/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/
#define CCNT_CCLevelSel(Sel)       (CCNT= CCNT & (~CCLevel_MSK) | Sel)

#define ENCC_Enable(BitSet)            (ENCCMode |= 1 << BitSet)
#define ENCC_Disable(BitSet)            (ENCCMode  &= ~(1 << BitSet))

#define ENCC0_Enable()            (ENCCMode |= ENCC0_ENABLE)
#define ENCC0_Disable()            (ENCCMode &= ~(ENCC0_MSK))
#define ENCC1_Enable()            (ENCCMode |= ENCC1_ENABLE)
#define ENCC1_Disable()            (ENCCMode &= ~(ENCC1_MSK))
#define ENCC2_Enable()            (ENCCMode |= ENCC2_ENABLE)
#define ENCC2_Disable()            (ENCCMode &= ~(ENCC2_MSK))
#define ENCC3_Enable()            (ENCCMode |= ENCC3_ENABLE)
#define ENCC3_Disable()            (ENCCMode &= ~(ENCC3_MSK))
#define ENCC4_Enable()            (ENCCMode |= ENCC4_ENABLE)
#define ENCC4_Disable()            (ENCCMode &= ~(ENCC4_MSK))
#define ENCC5_Enable()            (ENCCMode |= ENCC5_ENABLE)
#define ENCC5_Disable()            (ENCCMode &= ~(ENCC5_MSK))
#define ENCC6_Enable()            (ENCCMode |= ENCC6_ENABLE)
#define ENCC6_Disable()            (ENCCMode &= ~(ENCC6_MSK))
#define ENCC7_Enable()            (ENCCMode |= ENCC7_ENABLE)
#define ENCC7_Disable()            (ENCCMode &= ~(ENCC7_MSK))

#define ENCCALL_Enable()           (ENCCMode = 0xff )
#define ENCCALL_Disable()           (ENCCMode = 0x00)
/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void LEDSetting(unsigned char cclevel);
unsigned char GetDisplay(unsigned char show,unsigned char ledx);