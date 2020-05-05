/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17M Series                                                                 *|
|**************************************************************************************************/
 
/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
// INTE0 //
#define GIE                        7
#define GIE_MSK                   (1 << GIE)
#define GIE_ENABLE                (1 << GIE)
#define GIE_DISABLE               (0 << GIE)

#define TA1CIE                     6
#define TA1CIE_MSK                (1 << TA1CIE)
#define TA1CIE_ENABLE             (1 << TA1CIE)
#define TA1CIE_DISABLE            (0 << TA1CIE)

#define ADCIE                       5
#define ADCIE_MSK                  (1 << ADCIE)
#define ADCIE_ENABLE               (1 << ADCIE)
#define ADCIE_DISABLE              (0 << ADCIE)

#define WDTIE                      4
#define WDTIE_MSK                 (1 << WDTIE)
#define WDTIE_ENABLE              (1 << WDTIE)
#define WDTIE_DISABLE             (0 << WDTIE)

#define TMBIE                      3
#define TMBIE_MSK                 (1 << TMBIE)
#define TMBIE_ENABLE              (1 << TMBIE)
#define TMBIE_DISABLE             (0 << TMBIE)

#define E1IE                       1
#define E1IE_MSK                  (1 << E1IE)
#define E1IE_ENABLE               (1 << E1IE)
#define E1IE_DISABLE              (0 << E1IE)

#define E0IE                       0
#define E0IE_MSK                  (1 << E0IE)
#define E0IE_ENABLE               (1 << E0IE)
#define E0IE_DISABLE              (0 << E0IE)

//// INTE1 //
#define TA1IE                      7
#define TA1IE_MSK                 (1 << TA1IE)
#define TA1IE_ENABLE              (1 << TA1IE)
#define TA1IE_DISABLE             (0 << TA1IE)

#define SPIIE                      6
#define SPIIE_MSK                 (1 << SPIIE)
#define SPIIE_ENABLE              (1 << SPIIE)
#define SPIIE_DISABLE             (0 << SPIIE)

#define TXIE                       5
#define TXIE_MSK                  (1 << TXIE)
#define TXIE_ENABLE               (1 << TXIE)
#define TXIE_DISABLE              (0 << TXIE)

#define RCIE                       4
#define RCIE_MSK                  (1 << RCIE)
#define RCIE_ENABLE               (1 << RCIE)
#define RCIE_DISABLE              (0 << RCIE)

#define I2CERIE                    3
#define I2CERIE_MSK               (1 << I2CERIE)
#define I2CERIE_ENABLE            (1 << I2CERIE)
#define I2CERIE_DISABLE           (0 << I2CERIE)

#define I2CIE                      2
#define I2CIE_MSK                 (1 << I2CIE)
#define I2CIE_ENABLE              (1 << I2CIE)
#define I2CIE_DISABLE             (0 << I2CIE)


#define E3IE                       1
#define E3IE_MSK                  (1 << E3IE)
#define E3IE_ENABLE               (1 << E3IE)
#define E3IE_DISABLE              (0 << E3IE)

#define E2IE                       0
#define E2IE_MSK                  (1 << E2IE)
#define E2IE_ENABLE               (1 << E2IE)
#define E2IE_DISABLE              (0 << E2IE)

//// INTE2 //
#define CMPIE                      2
#define CMPIE_MSK                 (1 << CMPIE)
#define CMPIE_ENABLE              (1 << CMPIE)
#define CMPIE_DISABLE             (0 << CMPIE)

#define OPCIE                      1
#define OPCIE_MSK                 (1 << OPCIE)
#define OPCIE_ENABLE              (1 << OPCIE)
#define OPCIE_DISABLE             (0 << OPCIE)

#define BOR2IE                     0
#define BOR2IE_MSK                (1 << BOR2IE)
#define BOR2IE_ENABLE             (1 << BOR2IE)
#define BOR2IE_DISABLE            (0 << BOR2IE)

// INTF0 //
#define TA1CIF                     6
#define TA1CIF_MSK                (1 << TA1CIF)
#define TA1CIF_SET                (1 << TA1CIF)

#define ADCIF                      5
#define ADCIF_MSK                 (1 << ADCIF)
#define ADCIF_SET                 (1 << ADCIF)

#define WDTIF                      4
#define WDTIF_MSK                 (1 << WDTIF)
#define WDTIF_SET                 (1 << WDTIF)

#define TMBIF                      3
#define TMBIF_MSK                 (1 << TMBIF)
#define TMBIF_SET                 (1 << TMBIF)

#define E1IF                       1
#define E1IF_MSK                  (1 << E1IF)
#define E1IF_SET                  (1 << E1IF)

#define E0IF                       0
#define E0IF_MSK                  (1 << E0IF)
#define E0IF_SET                  (1 << E0IF)

// INTF1 //
#define TA1IF                      7
#define TA1IF_MSK                 (1 << TA1IF)
#define TA1IF_SET                 (1 << TA1IF)

#define TXIF                       5
#define TXIF_MSK                   (1 << TXIF)
#define TXIF_SET                   (1 << TXIF)

#define RCIF                       4
#define RCIF_MSK                   (1 << RCIF)
#define RCIF_SET                   (1 << RCIF)

#define I2CERIF                    3
#define I2CERIF_MSK                (1 << I2CERIF)
#define I2CERIF_SET                (1 << I2CERIF)

#define I2CIF                      2
#define I2CIF_MSK                  (1 << I2CIF)
#define I2CIF_SET                  (1 << I2CIF)

#define E3IF                       1
#define E3IF_MSK                   (1 << E3IF)
#define E3IF_SET                   (1 << E3IF)

#define E2IF                       0
#define E2IF_MSK                   (1 << E2IF)
#define E2IF_SET                   (1 << E2IF)

// INTF2 //
#define CMPIF                      2
#define CMPIF_MSK                  (1 << CMPIF)
#define CMPIF_SET                  (1 << CMPIF)

#define OPCIF                      1
#define OPCIF_MSK                  (1 << OPCIF)
#define OPCIF_SET                  (1 << OPCIF)

#define BOR2IF                     0
#define BOR2IF_MSK                 (1 << BOR2IF)
#define BOR2IF_SET                 (1 << BOR2IF)

// PT1M1 //
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

// PT1INT //
#define INTG16                    6
#define INTG16_MSK                     (1 << INTG16)
#define INTG16_EDGERISE          (1 << INTG16)
#define INTG16_EDGEFALL          (0 << INTG16)

#define INTG15                    5
#define INTG15_MSK                     (1 << INTG15)
#define INTG15_EDGERISE          (1 << INTG15)
#define INTG15_EDGEFALL          (0 << INTG15)

#define INTG14                    4
#define INTG14_MSK                     (1 << INTG14)
#define INTG14_EDGERISE          (1 << INTG14)
#define INTG14_EDGEFALL          (0 << INTG14)

#define INTG13                    3
#define INTG13_MSK                     (1 << INTG13)
#define INTG13_EDGERISE          (1 << INTG13)
#define INTG13_EDGEFALL          (0 << INTG13)

#define INTG12                    2
#define INTG12_MSK                     (1 << INTG12)
#define INTG12_EDGERISE          (1 << INTG12)
#define INTG12_EDGEFALL          (0 << INTG12)

// PT1INTE //
#define INTE16                       6
#define INTE16_MSK                  (1 << INTE16)
#define INTE16_ENABLE               (1 << INTE16)
#define INTE16_DISABLE              (0 << INTE16)

#define INTE15                       5
#define INTE15_MSK                  (1 << INTE15)
#define INTE15_ENABLE               (1 << INTE15)
#define INTE15_DISABLE              (0 << INTE15)

#define INTE14                       4
#define INTE14_MSK                  (1 << INTE14)
#define INTE14_ENABLE               (1 << INTE14)
#define INTE14_DISABLE              (0 << INTE14)

// PT1INTF //
#define INTF16                       6
#define INTF16_MSK                  (1 << INTF16)
#define INTF16_SET                  (1 << INTF16)

#define INTF15                       5
#define INTF15_MSK                  (1 << INTF15)
#define INTF15_SET                  (1 << INTF15)

#define INTF14                       4
#define INTF14_MSK                  (1 << INTF14)
#define INTF14_SET                  (1 << INTF14)

// PT2INT //
#define INTG21                       1
#define INTG21_MSK                  (1 << INTG21)
#define INTG21_EDGERISE              (1 << INTG21)
#define INTG21_EDGEFALL              (0 << INTG21)

#define INTG20                       0
#define INTG20_MSK                  (1 << INTG20)
#define INTG20_EDGERISE               (1 << INTG20)
#define INTG20_EDGEFALL              (0 << INTG20)

// PT2INTE //
#define INTE21                       1
#define INTE21_MSK                  (1 << INTE21)
#define INTE21_ENABLE               (1 << INTE21)
#define INTE21_DISABLE              (0 << INTE21)

#define INTE20                       0
#define INTE20_MSK                  (1 << INTE20)
#define INTE20_ENABLE               (1 << INTE20)
#define INTE20_DISABLE              (0 << INTE20)

// PT2INTF //
#define INTF21                       1
#define INTF21_MSK                  (1 << INTF21)
#define INTF21_SET                  (1 << INTF21)

#define INTF20                       0
#define INTF20_MSK                  (1 << INTF20)
#define INTF20_SET                  (1 << INTF20)

// PT3INT //
#define INTG37                    7
#define INTG37_MSK                     (1 << INTG37)
#define INTG37_EDGERISE          (1 << INTG37)
#define INTG37_EDGEFALL          (0 << INTG37)

#define INTG36                    6
#define INTG36_MSK                     (1 << INTG36)
#define INTG36_EDGERISE          (1 << INTG36)
#define INTG36_EDGEFALL          (0 << INTG36)

#define INTG35                    5
#define INTG35_MSK                     (1 << INTG35)
#define INTG35_EDGERISE          (1 << INTG35)
#define INTG35_EDGEFALL          (0 << INTG35)

#define INTG34                    4
#define INTG34_MSK                     (1 << INTG34)
#define INTG34_EDGERISE          (1 << INTG34)
#define INTG34_EDGEFALL          (0 << INTG34)

#define INTG33                    3
#define INTG33_MSK                     (1 << INTG33)
#define INTG33_EDGERISE          (1 << INTG33)
#define INTG33_EDGEFALL          (0 << INTG33)

#define INTG32                    2
#define INTG32_MSK                     (1 << INTG32)
#define INTG32_EDGERISE          (1 << INTG32)
#define INTG32_EDGEFALL          (0 << INTG32)

#define INTG31                    1
#define INTG31_MSK                     (1 << INTG31)
#define INTG31_EDGERISE          (1 << INTG31)
#define INTG31_EDGEFALL          (0 << INTG31)

#define INTG30                    0
#define INTG30_MSK                     (1 << INTG30)
#define INTG30_EDGERISE          (1 << INTG30)
#define INTG30_EDGEFALL          (0 << INTG30)


// PT3INTE //
#define INTE37                       7
#define INTE37_MSK                  (1 << INTE37)
#define INTE37_ENABLE               (1 << INTE37)
#define INTE37_DISABLE              (0 << INTE37)

#define INTE36                       6
#define INTE36_MSK                  (1 << INTE36)
#define INTE36_ENABLE               (1 << INTE36)
#define INTE36_DISABLE              (0 << INTE36)

#define INTE35                       5
#define INTE35_MSK                  (1 << INTE35)
#define INTE35_ENABLE               (1 << INTE35)
#define INTE35_DISABLE              (0 << INTE35)

#define INTE34                       4
#define INTE34_MSK                  (1 << INTE34)
#define INTE34_ENABLE               (1 << INTE34)
#define INTE34_DISABLE              (0 << INTE34)

#define INTE33                       3
#define INTE33_MSK                  (1 << INTE33)
#define INTE33_ENABLE               (1 << INTE33)
#define INTE33_DISABLE              (0 << INTE33)

#define INTE32                       2
#define INTE32_MSK                  (1 << INTE32)
#define INTE32_ENABLE               (1 << INTE32)
#define INTE32_DISABLE              (0 << INTE32)

#define INTE31                       1
#define INTE31_MSK                  (1 << INTE31)
#define INTE31_ENABLE               (1 << INTE31)
#define INTE31_DISABLE              (0 << INTE31)

#define INTE30                       0
#define INTE30_MSK                  (1 << INTE30)
#define INTE30_ENABLE               (1 << INTE30)
#define INTE30_DISABLE              (0 << INTE30)

// PT3INTF //
#define INTF37                       7
#define INTF37_MSK                  (1 << INTF37)
#define INTF37_SET                  (1 << INTF37)

#define INTF36                       6
#define INTF36_MSK                  (1 << INTF36)
#define INTF36_SET                  (1 << INTF36)

#define INTF35                       5
#define INTF35_MSK                  (1 << INTF35)
#define INTF35_SET                  (1 << INTF35)

#define INTF34                       4
#define INTF34_MSK                  (1 << INTF34)
#define INTF34_SET                  (1 << INTF34)

#define INTF33                       3
#define INTF33_MSK                  (1 << INTF33)
#define INTF33_SET                  (1 << INTF33)

#define INTF32                       2
#define INTF32_MSK                  (1 << INTF32)
#define INTF32_SET                  (1 << INTF32)

#define INTF31                       1
#define INTF31_MSK                  (1 << INTF31)
#define INTF31_SET                  (1 << INTF31)

#define INTF30                       0
#define INTF30_MSK                  (1 << INTF30)
#define INTF30_SET                  (1 << INTF30)


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define INTF0_SET(INTF0Sel)         (INTF0 |= (1<<INTF0Sel))
#define INTF0_CLR(INTF0Sel)         (INTF0 &= ~(1<<INTF0Sel))
#define INTF1_SET(INTF0Sel)         (INTF1 |= (1<<INTF0Sel))
#define INTF1_CLR(INTF0Sel)         (INTF1 &= ~(1<<INTF0Sel))
#define INTF2_SET(INTF0Sel)         (INTF2 |= (1<<INTF0Sel))
#define INTF2_CLR(INTF0Sel)         (INTF2 &= ~(1<<INTF0Sel))



#define GIE_Enable()                (INTE0 |= GIE_ENABLE)
#define GIE_Disable()               (INTE0 &= (~GIE_MSK))



#define TA1CIE_Enable()             (INTE0 |= TA1CIE_ENABLE)
#define TA1CIE_Disable()            (INTE0 &= (~TA1CIE_MSK))
#define TA1CIF_IsFlag()             (INTF0 & TA1CIF_SET)
#define TA1CIF_ClearFlag()          (INTF0 &= (~TA1CIF_MSK))

#define ADCIE_Enable()               (INTE0 |= ADCIE_ENABLE)
#define ADCIE_Disable()              (INTE0 &= (~ADCIE_MSK))
#define ADCIF_IsFlag()               (INTF0 & ADCIF_SET)
#define ADCIF_ClearFlag()            (INTF0 &= (~ADCIF_MSK))

#define WDTIE_Enable()              (INTE0 |= WDTIE_ENABLE)
#define WDTIE_Disable()             (INTE0 &= (~WDTIE_MSK))
#define WDTIF_IsFlag()              (INTF0 & WDTIF_SET)
#define WDTIF_ClearFlag()           (INTF0 &= (~WDTIF_MSK))

#define TMBIE_Enable()              (INTE0 |= TMBIE_ENABLE)
#define TMBIE_Disable()             (INTE0 &= (~TMBIE_MSK))
#define TMBIF_IsFlag()              (INTF0 & TMBIF_SET)
#define TMBIF_ClearFlag()           (INTF0 &= (~TMBIF_MSK))

#define E1IE_Enable()               (INTE0 |= E1IE_ENABLE)
#define E1IE_Disable()              (INTE0 &= (~E1IE_MSK))
#define E1IF_IsFlag()               (INTF0 & E1IF_SET)
#define E1IF_ClearFlag()            (INTF0 &= (~E1IF_MSK))

#define E0IE_Enable()               (INTE0 |= E0IE_ENABLE)
#define E0IE_Disable()              (INTE0 &= (~E0IE_MSK))
#define E0IF_IsFlag()               (INTF0 & E0IF_SET)
#define E0IF_ClearFlag()            (INTF0 &= (~E0IF_MSK))

#define TA1IE_Enable()              (INTE1 |= TA1IE_ENABLE)
#define TA1IE_Disable()             (INTE1 &= (~TA1IE_MSK))
#define TA1IF_IsFlag()              (INTF1 & TA1IF_SET)
#define TA1IF_ClearFlag()           (INTF1 &= (~TA1IF_MSK))

#define SPIIE_Enable()              (INTE1 |= SPIIE_ENABLE)
#define SPIIE_Disable()             (INTE1 &= (~SPIIE_MSK))
#define SPIIF_IsFlag()              (INTF1 & SPIIF_SET)
#define SPIIF_ClearFlag()           (INTF1 &= (~SPIIF_MSK))

#define TXIE_Enable()               (INTE1 |= TXIE_ENABLE)
#define TXIE_Disable()              (INTE1 &= (~TXIE_MSK))
#define TXIF_IsFlag()               (INTF1 & TXIF_SET)
#define TXIF_ClearFlag()            (INTF1 &= (~TXIF_MSK))

#define RCIE_Enable()               (INTE1 |= RCIE_ENABLE)
#define RCIE_Disable()              (INTE1 &= (~RCIE_MSK))
#define RCIF_IsFlag()               (INTF1 & RCIF_SET)
#define RCIF_ClearFlag()            (INTF1 &= (~RCIF_MSK))

#define I2CERIE_Enable()            (INTE1 |= I2CERIE_ENABLE)
#define I2CERIE_Disable()           (INTE1 &= (~I2CERIE_MSK))
#define I2CERIF_IsFlag()            (INTF1 & I2CERIF_SET)
#define I2CERIF_ClearFlag()         (INTF1 &= (~I2CERIF_MSK))

#define I2CIE_Enable()              (INTE1 |= I2CIE_ENABLE)
#define I2CIE_Disable()             (INTE1 &= (~I2CIE_MSK))
#define I2CIF_IsFlag()              (INTF1 & I2CIF_SET)
#define I2CIF_ClearFlag()           (INTF1 &= (~I2CIF_MSK))

#define E3IE_Enable()               (INTE1 |= E3IE_ENABLE)
#define E3IE_Disable()              (INTE1 &= (~E3IE_MSK))
#define E3IF_IsFlag()               (INTF1 & E3IF_SET)
#define E3IF_ClearFlag()            (INTF1 &= (~E3IF_MSK))

#define E2IE_Enable()               (INTE1 |= E2IE_ENABLE)
#define E2IE_Disable()              (INTE1 &= (~E2IE_MSK))
#define E2IF_IsFlag()               (INTF1 & E2IF_SET)
#define E2IF_ClearFlag()            (INTF1 &= (~E2IF_MSK))

#define CMPIE_Enable()              (INTE2 |= CMPIE_ENABLE)
#define CMPIE_Disable()             (INTE2 &= (~CMPIE_MSK))
#define CMPIF_IsFlag()              (INTF2 & CMPIF_SET)
#define CMPIF_ClearFlag()           (INTF2 &= (~CMPIF_MSK))

#define OPCIE_Enable()              (INTE2 |= OPCIE_ENABLE)
#define OPCIE_Disable()             (INTE2 &= (~OPCIE_MSK))
#define OPCIF_IsFlag()              (INTF2 & OPCIF_SET)
#define OPCIF_ClearFlag()           (INTF2 &= (~OPCIF_MSK))

#define BOR2IE_Enable()             (INTE2 |= BOR2IE_ENABLE)
#define BOR2IE_Disable()            (INTE2 &= (~BOR2IE_MSK))
#define BOR2IF_IsFlag()             (INTF2 & BOR2IF_SET)
#define BOR2IF_ClearFlag()          (INTF2 &= (~BOR2IF_MSK))

#define INTG16_Edgerise()          (PT1INT |= INTG16_EDGERISE)
#define INTG16_Edgefall()           (PT1INT &= (~INTG16_MSK))
#define INTE16_Enable()             (PT1INTE |= INTE16_ENABLE)
#define INTE16_Disable()            (PT1INTE &= (~INTE16_MSK))
#define INTF16_IsFlag()               (PT1INTF & INTF16_SET)
#define INTF16_ClearFlag()         (PT1INTF &= (~INTF16_MSK))

#define INTG15_Edgerise()          (PT1INT |= INTG15_EDGERISE)
#define INTG15_Edgefall()           (PT1INT &= (~INTG15_MSK))
#define INTE15_Enable()             (PT1INTE |= INTE15_ENABLE)
#define INTE15_Disable()            (PT1INTE &= (~INTE15_MSK))
#define INTF15_IsFlag()             (PT1INTF & INTF15_SET)
#define INTF15_ClearFlag()          (PT1INTF &= (~INTF15_MSK))

#define INTG14_Edgerise()          (PT1INT |= INTG14_EDGERISE)
#define INTG14_Edgefall()           (PT1INT &= (~INTG14_MSK))
#define INTE14_Enable()             (PT1INTE |= INTE14_ENABLE)
#define INTE14_Disable()            (PT1INTE &= (~INTE14_MSK))
#define INTF14_IsFlag()             (PT1INTF & INTF14_SET)
#define INTF14_ClearFlag()          (PT1INTF &= (~INTF14_MSK))

#define INTG13_Edgerise()          (PT1INT |= INTG13_EDGERISE)
#define INTG13_Edgefall()           (PT1INT &= (~INTG13_MSK))

#define INTG12_Edgerise()          (PT1INT |= INTG12_EDGERISE)
#define INTG12_Edgefall()           (PT1INT &= (~INTG12_MSK))

#define INTG21_Edgerise()          (PT2INT |= INTG21_EDGERISE)
#define INTG21_Edgefall()           (PT2INT &= (~INTG21_MSK))
#define INTE21_Enable()             (PT2INTE |= INTE21_ENABLE)
#define INTE21_Disable()            (PT2INTE &= (~INTE21_MSK))
#define INTF21_IsFlag()             (PT2INTF & INTF21_SET)
#define INTF21_ClearFlag()          (PT2INTF &= (~INTF21_MSK))

#define INTG20_Edgerise()          (PT2INT |= INTG20_EDGERISE)
#define INTG20_Edgefall()           (PT2INT &= (~INTG20_MSK))
#define INTE20_Enable()             (PT2INTE |= INTE20_ENABLE)
#define INTE20_Disable()            (PT2INTE &= (~INTE20_MSK))
#define INTF20_IsFlag()             (PT2INTF & INTF20_SET)
#define INTF20_ClearFlag()          (PT2INTF &= (~INTF20_MSK))

#define INTG37_Edgerise()          (PT3INT |= INTG37_EDGERISE)
#define INTG37_Edgefall()           (PT3INT &= (~INTG37_MSK))
#define INTE37_Enable()             (PT3INTE |= INTE37_ENABLE)
#define INTE37_Disable()            (PT3INTE &= (~INTE37_MSK))
#define INTF37_IsFlag()             (PT3INTF & INTF37_SET)
#define INTF37_ClearFlag()          (PT3INTF &= (~INTF37_MSK))

#define INTG36_Edgerise()          (PT3INT |= INTG36_EDGERISE)
#define INTG36_Edgefall()           (PT3INT &= (~INTG36_MSK))
#define INTE36_Enable()             (PT3INTE |= INTE36_ENABLE)
#define INTE36_Disable()            (PT3INTE &= (~INTE36_MSK))
#define INTF36_IsFlag()             (PT3INTF & INTF36_SET)
#define INTF36_ClearFlag()          (PT3INTF &= (~INTF36_MSK))

#define INTG35_Edgerise()          (PT3INT |= INTG35_EDGERISE)
#define INTG35_Edgefall()           (PT3INT &= (~INTG35_MSK))
#define INTE35_Enable()             (PT3INTE |= INTE35_ENABLE)
#define INTE35_Disable()            (PT3INTE &= (~INTE35_MSK))
#define INTF35_IsFlag()             (PT3INTF & INTF35_SET)
#define INTF35_ClearFlag()          (PT3INTF &= (~INTF35_MSK))

#define INTG34_Edgerise()          (PT3INT |= INTG34_EDGERISE)
#define INTG34_Edgefall()           (PT3INT &= (~INTG34_MSK))
#define INTE34_Enable()             (PT3INTE |= INTE34_ENABLE)
#define INTE34_Disable()            (PT3INTE &= (~INTE34_MSK))
#define INTF34_IsFlag()             (PT3INTF & INTF34_SET)
#define INTF34_ClearFlag()          (PT3INTF &= (~INTF34_MSK))

#define INTG33_Edgerise()          (PT3INT |= INTG33_EDGERISE)
#define INTG33_Edgefall()           (PT3INT &= (~INTG33_MSK))
#define INTE33_Enable()             (PT3INTE |= INTE33_ENABLE)
#define INTE33_Disable()            (PT3INTE &= (~INTE33_MSK))
#define INTF33_IsFlag()             (PT3INTF & INTF33_SET)
#define INTF33_ClearFlag()          (PT3INTF &= (~INTF33_MSK))

#define INTG32_Edgerise()          (PT3INT |= INTG32_EDGERISE)
#define INTG32_Edgefall()           (PT3INT &= (~INTG32_MSK))
#define INTE32_Enable()             (PT3INTE |= INTE32_ENABLE)
#define INTE32_Disable()            (PT3INTE &= (~INTE32_MSK))
#define INTF32_IsFlag()             (PT3INTF & INTF32_SET)
#define INTF32_ClearFlag()          (PT3INTF &= (~INTF32_MSK))

#define INTG31_Edgerise()          (PT3INT |= INTG31_EDGERISE)
#define INTG31_Edgefall()           (PT3INT &= (~INTG31_MSK))
#define INTE31_Enable()             (PT3INTE |= INTE31_ENABLE)
#define INTE31_Disable()            (PT3INTE &= (~INTE31_MSK))
#define INTF31_IsFlag()             (PT3INTF & INTF31_SET)
#define INTF31_ClearFlag()          (PT3INTF &= (~INTF31_MSK))

#define INTG30_Edgerise()          (PT3INT |= INTG30_EDGERISE)
#define INTG30_Edgefall()           (PT3INT &= (~INTG30_MSK))
#define INTE30_Enable()             (PT3INTE |= INTE30_ENABLE)
#define INTE30_Disable()            (PT3INTE &= (~INTE30_MSK))
#define INTF30_IsFlag()             (PT3INTF & INTF30_SET)
#define INTF30_ClearFlag()          (PT3INTF &= (~INTF30_MSK))
/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
