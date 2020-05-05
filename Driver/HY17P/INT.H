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
// INTE0 //
#define GIE                        7
#define GIE_MSK                   (1 << GIE)
#define GIE_ENABLE                (1 << GIE)
#define GIE_DISABLE               (0 << GIE)

#define TA1CIE                     6
#define TA1CIE_MSK                (1 << TA1CIE)
#define TA1CIE_ENABLE             (1 << TA1CIE)
#define TA1CIE_DISABLE            (0 << TA1CIE)

#define ADIE                       5
#define ADIE_MSK                  (1 << ADIE)
#define ADIE_ENABLE               (1 << ADIE)
#define ADIE_DISABLE              (0 << ADIE)

#define WDTIE                      4
#define WDTIE_MSK                 (1 << WDTIE)
#define WDTIE_ENABLE              (1 << WDTIE)
#define WDTIE_DISABLE             (0 << WDTIE)

#define TB1IE                      3
#define TB1IE_MSK                 (1 << TB1IE)
#define TB1IE_ENABLE              (1 << TB1IE)
#define TB1IE_DISABLE             (0 << TB1IE)

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
//
//// INTE2 //
#define TA2IE                      7
#define TA2IE_MSK                 (1 << TA2IE)
#define TA2IE_ENABLE              (1 << TA2IE)
#define TA2IE_DISABLE             (0 << TA2IE)

#define TA2CIE                     6
#define TA2CIE_MSK                (1 << TA2CIE)
#define TA2CIE_ENABLE             (1 << TA2CIE)
#define TA2CIE_DISABLE            (0 << TA2CIE)

#define TX2IE                      3
#define TX2IE_MSK                 (1 << TX2IE)
#define TX2IE_ENABLE              (1 << TX2IE)
#define TX2IE_DISABLE             (0 << TX2IE)

#define RC2IE                      2
#define RC2IE_MSK                 (1 << RC2IE)
#define RC2IE_ENABLE              (1 << RC2IE)
#define RC2IE_DISABLE             (0 << RC2IE)

#define BOR2IE                     0
#define BOR2IE_MSK                (1 << BOR2IE)
#define BOR2IE_ENABLE             (1 << BOR2IE)
#define BOR2IE_DISABLE            (0 << BOR2IE)

// INTE3 //
#define I2C2IE                      0
#define I2C2IE_MSK                 (1 << I2C2IE)
#define I2C2IE_ENABLE              (1 << I2C2IE)
#define I2C2IE_DISABLE             (0 << I2C2IE)

#define I2CER2IE                    1
#define I2CER2IE_MSK               (1 << I2CER2IE)
#define I2CER2IE_ENABLE            (1 << I2CER2IE)
#define I2CER2IE_DISABLE           (0 << I2CER2IE)

// INTF0 //
#define TA1CIF                     6
#define TA1CIF_MSK                (1 << TA1CIF)
#define TA1CIF_SET                (1 << TA1CIF)

#define ADIF                       5
#define ADIF_MSK                  (1 << ADIF)
#define ADIF_SET                  (1 << ADIF)

#define WDTIF                      4
#define WDTIF_MSK                 (1 << WDTIF)
#define WDTIF_SET                 (1 << WDTIF)

#define TB1IF                      3
#define TB1IF_MSK                 (1 << TB1IF)
#define TB1IF_SET                 (1 << TB1IF)

#define E1IF                       1
#define E1IF_MSK                  (1 << E1IF)
#define E1IF_SET                  (1 << E1IF)

#define E0IF                       0
#define E0IF_MSK                  (1 << E0IF)
#define E0IF_SET                  (1 << E0IF)

// INTF1 //
#define TA1IF                      7
#define TA1IF_MSK                  (1 << TA1IF)
#define TA1IF_SET                  (1 << TA1IF)


#define SPIIF                      6
#define SPIIF_MSK                  (1 << SPIIF)
#define SPIIF_SET                  (1 << SPIIF)

#define TXIF                       5
#define TXIF_MSK                   (1 << ITXIF)
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
#define E3IF_MSK                   (1 << IE3IF)
#define E3IF_SET                   (1 << E3IF)

#define E2IF                       0
#define E2IF_MSK                   (1 << IE2IF)
#define E2IF_SET                   (1 << E2IF)

// INTF2 //
#define TA2IF                      7
#define TA2IF_MSK                  (1 << TA2IF)
#define TA2IF_SET                  (1 << TA2IF)

#define TA2CIF                     6
#define TA2CIF_MSK                (1 << TA2CIF)
#define TA2CIF_SET                (1 << TA2CIF)

#define TX2IF                      3
#define TX2IF_MSK                  (1 << ITX2IF)
#define TX2IF_SET                  (1 << TX2IF)

#define RC2IF                      2
#define RC2IF_MSK                  (1 << IRC2IF)
#define RC2IF_SET                  (1 << RC2IF)

#define BOR2IF                     0
#define BOR2IF_MSK                 (1 << BOR2IF)
#define BOR2IF_SET                 (1 << BOR2IF)

// INTF3 //
#define I2C2IF                      0
#define I2C2IF_MSK                  (1 << I2C2IF)
#define I2C2IF_SET                  (1 << I2C2IF)

#define I2CER2IF                    1
#define I2CER2IF_MSK                (1 << I2CER2IF)
#define I2CER2IF_SET                (1 << I2CER2IF)

// PT1INTE //

#define INTE17                       7
#define INTE17_MSK                  (1 << INTE17)
#define INTE17_ENABLE               (1 << INTE17)
#define INTE17_DISABLE              (0 << INTE17)

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

#define INTF17                       7
#define INTF17_MSK                  (1 << INTF17)
#define INTF17_ENABLE               (1 << INTF17)
#define INTF17_DISABLE              (0 << INTF17)

#define INTF16                       6
#define INTF16_MSK                  (1 << INTF16)
#define INTF16_ENABLE               (1 << INTF16)
#define INTF16_DISABLE              (0 << INTF16)

#define INTF15                       5
#define INTF15_MSK                  (1 << INTF15)
#define INTF15_ENABLE               (1 << INTF15)
#define INTF15_DISABLE              (0 << INTF15)

#define INTF14                       4
#define INTF14_MSK                  (1 << INTF14)
#define INTF14_ENABLE               (1 << INTF14)
#define INTF14_DISABLE              (0 << INTF14)

// PT2INTE //

#define INTE23                       3
#define INTE23_MSK                  (1 << INTE23)
#define INTE23_ENABLE               (1 << INTE23)
#define INTE23_DISABLE              (0 << INTE23)

#define INTE22                       2
#define INTE22_MSK                  (1 << INTE22)
#define INTE22_ENABLE               (1 << INTE22)
#define INTE22_DISABLE              (0 << INTE22)

#define INTE21                       1
#define INTE21_MSK                  (1 << INTE21)
#define INTE21_ENABLE               (1 << INTE21)
#define INTE21_DISABLE              (0 << INTE21)

#define INTE20                       0
#define INTE20_MSK                  (1 << INTE20)
#define INTE20_ENABLE               (1 << INTE20)
#define INTE20_DISABLE              (0 << INTE20)


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define INTE0_SET(INTE0Sel)         (INTE0 |= (1<<INTE0Sel))
#define INTE0_CLR(INTE0Sel)         (INTE0 &= ~(1<<INTE0Sel))
#define INTE1_SET(INTE0Sel)         (INTE1 |= (1<<INTE0Sel))
#define INTE1_CLR(INTE0Sel)         (INTE1 &= ~(1<<INTE0Sel))
#define INTE2_SET(INTE0Sel)         (INTE2 |= (1<<INTE0Sel))
#define INTE2_CLR(INTE0Sel)         (INTE2 &= ~(1<<INTE0Sel))



#define GIE_Enable()                (INTE0 |= GIE_ENABLE)
#define GIE_Disable()               (INTE0 &= (~GIE_MSK))



#define TA1CIE_Enable()             (INTE0 |= TA1CIE_ENABLE)
#define TA1CIE_Disable()            (INTE0 &= (~TA1CIE_MSK))
#define TA1CIF_IsFlag()             (INTF0 & TA1CIF_SET)
#define TA1CIF_ClearFlag()          (INTF0 &= (~TA1CIF_MSK))

#define TA2CIE_Enable()             (INTE2 |= TA2CIE_ENABLE)
#define TA2CIE_Disable()            (INTE2 &= (~TA2CIE_MSK))
#define TA2CIF_IsFlag()             (INTF2 & TA2CIF_SET)
#define TA2CIF_ClearFlag()          (INTF2 &= (~TA2CIF_MSK))

#define ADIE_Enable()               (INTE0 |= ADIE_ENABLE)
#define ADIE_Disable()              (INTE0 &= (~ADIE_MSK))
#define ADIF_IsFlag()               (INTF0 & ADIF_SET)
#define ADIF_ClearFlag()            (INTF0 &= (~ADIF_MSK))

#define WDTIE_Enable()              (INTE0 |= WDTIE_ENABLE)
#define WDTIE_Disable()             (INTE0 &= (~WDTIE_MSK))
#define WDTIF_IsFlag()              (INTF0 & WDTIF_SET)
#define WDTIF_ClearFlag()           (INTF0 &= (~WDTIF_MSK))

#define TB1IE_Enable()              (INTE0 |= TB1IE_ENABLE)
#define TB1IE_Disable()             (INTE0 &= (~TB1IE_MSK))
#define TB1IF_IsFlag()              (INTF0 & TB1IF_SET)
#define TB1IF_ClearFlag()           (INTF0 &= (~TB1IF_MSK))

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

#define TA2IE_Enable()              (INTE2 |= TA2IE_ENABLE)
#define TA2IE_Disable()             (INTE2 &= (~TA2IE_MSK))
#define TA2IF_IsFlag()              (INTF2 & TA2IF_SET)
#define TA2IF_ClearFlag()           (INTF2 &= (~TA2IF_MSK))

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

#define I2CER2IE_Enable()            (INTE3 |= I2CER2IE_ENABLE)
#define I2CER2IE_Disable()           (INTE3 &= (~I2CER2IE_MSK))
#define I2CER2IF_IsFlag()            (INTF3 & I2CER2IF_SET)
#define I2CER2IF_ClearFlag()         (INTF3 &= (~I2CER2IF_MSK))

#define I2CIE_Enable()              (INTE1 |= I2CIE_ENABLE)
#define I2CIE_Disable()             (INTE1 &= (~I2CIE_MSK))
#define I2CIF_IsFlag()              (INTF1 & I2CIF_SET)
#define I2CIF_ClearFlag()           (INTF1 &= (~I2CIF_MSK))

#define I2C2IE_Enable()              (INTE3 |= I2C2IE_ENABLE)
#define I2C2IE_Disable()             (INTE3 &= (~I2C2IE_MSK))
#define I2C2IF_IsFlag()              (INTF3 & I2C2IF_SET)
#define I2C2IF_ClearFlag()           (INTF3 &= (~I2C2IF_MSK))

#define E3IE_Enable()               (INTE1 |= E3IE_ENABLE)
#define E3IE_Disable()              (INTE1 &= (~E3IE_MSK))
#define E3IF_IsFlag()               (INTF1 & E3IF_SET)
#define E3IF_ClearFlag()            (INTF1 &= (~E3IF_MSK))

#define E2IE_Enable()               (INTE1 |= E2IE_ENABLE)
#define E2IE_Disable()              (INTE1 &= (~E2IE_MSK))
#define E2IF_IsFlag()               (INTF1 & E2IF_SET)
#define E2IF_ClearFlag()            (INTF1 &= (~E2IF_MSK))

#define TX2IE_Enable()              (INTE2 |= TX2IE_ENABLE)
#define TX2IE_Disable()             (INTE2 &= (~TX2IE_MSK))
#define TX2IF_IsFlag()              (INTF2 & TX2IF_SET)
#define TX2IF_ClearFlag()           (INTF2 &= (~TX2IF_MSK))

#define RC2IE_Enable()              (INTE2 |= RC2IE_ENABLE)
#define RC2IE_Disable()             (INTE2 &= (~RC2IE_MSK))
#define RC2IF_IsFlag()              (INTF2 & RC2IF_SET)
#define RC2IF_ClearFlag()           (INTF2 &= (~RC2IF_MSK))

#define BOR2IE_Enable()             (INTE2 |= BOR2IE_ENABLE)
#define BOR2IE_Disable()            (INTE2 &= (~BOR2IE_MSK))
#define BOR2IF_IsFlag()             (INTF2 & BOR2IF_SET)
#define BOR2IF_ClearFlag()          (INTF2 &= (~BOR2IF_MSK))

#define INTE17_Enable()             (PT1INTE |= INTE17_ENABLE)
#define INTE17_Disable()            (PT1INTE &= (~INTE17_MSK))
#define INTF17_IsFlag()             (PT1INTF & INTF17_SET)
#define INTF17_ClearFlag()          (PT1INTF &= (~INTF17_MSK))

#define INTE16_Enable()             (PT1INTE |= INTE16_ENABLE)
#define INTE16_Disable()            (PT1INTE &= (~INTE16_MSK))
#define INTF16_IsFlag()             (PT1INTF & INTF16_SET)
#define INTF16_ClearFlag()          (PT1INTF &= (~INTF16_MSK))

#define INTE15_Enable()             (PT1INTE |= INTE15_ENABLE)
#define INTE15_Disable()            (PT1INTE &= (~INTE15_MSK))
#define INTF15_IsFlag()             (PT1INTF & INTF15_SET)
#define INTF15_ClearFlag()          (PT1INTF &= (~INTF15_MSK))

#define INTE14_Enable()             (PT1INTE |= INTE14_ENABLE)
#define INTE14_Disable()            (PT1INTE &= (~INTE14_MSK))
#define INTF14_IsFlag()             (PT1INTF & INTF14_SET)
#define INTF14_ClearFlag()          (PT1INTF &= (~INTF14_MSK))

#define INTE23_Enable()             (PT2INTE |= INTE23_ENABLE)
#define INTE23_Disable()            (PT2INTE &= (~INTE23_MSK))
#define INTF23_IsFlag()             (PT2INTF & INTF23_SET)
#define INTF23_ClearFlag()          (PT2INTF &= (~INTF23_MSK))

#define INTE22_Enable()             (PT2INTE |= INTE22_ENABLE)
#define INTE22_Disable()            (PT2INTE &= (~INTE22_MSK))
#define INTF22_IsFlag()             (PT2INTF & INTF22_SET)
#define INTF22_ClearFlag()          (PT2INTF &= (~INTF22_MSK))

#define INTE21_Enable()             (PT2INTE |= INTE21_ENABLE)
#define INTE21_Disable()            (PT2INTE &= (~INTE21_MSK))
#define INTF21_IsFlag()             (PT2INTF & INTF21_SET)
#define INTF21_ClearFlag()          (PT2INTF &= (~INTF21_MSK))

#define INTE20_Enable()             (PT2INTE |= INTE20_ENABLE)
#define INTE20_Disable()            (PT2INTE &= (~INTE20_MSK))
#define INTF20_IsFlag()             (PT2INTF & INTF20_SET)
#define INTF20_ClearFlag()          (PT2INTF &= (~INTF20_MSK))
/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
