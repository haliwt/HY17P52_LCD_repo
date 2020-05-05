/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
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
//  DACCN0  //
#define DANS                        4
#define DANS_MSK                   (7 << DANS)
//#define DANS_                    (7 << DANS)
//#define DANS_                    (6 << DANS)
//#define DANS_                    (5 << DANS)
#define DANS_AI5                      (4 << DANS)
#define DANS_AI3                      (3 << DANS)
#define DANS_OP1O                 (2 << DANS)
#define DANS_REFO                 (1 << DANS)
#define DANS_VSS                    (0 << DANS)

#define DAPS                        0
#define DAPS_MSK                  (15 << DAPS)
//#define DAPS_                    (15 << DAPS)
//#define DAPS_                    (14 << DAPS)
//#define DAPS_                    (13 << DAPS)
//#define DAPS_                    (12 << DAPS)
//#define DAPS_                    (11 << DAPS)
//#define DAPS_                    (10 << DAPS)
//#define DAPS_                     (9 << DAPS)
//#define DAPS_                     (8 << DAPS)
#define DAPS_AI8                     (7 << DAPS)
#define DAPS_AI7                     (6 << DAPS)
#define DAPS_AI6                     (5 << DAPS)
#define DAPS_AI4                     (4 << DAPS)
#define DAPS_AI2                     (3 << DAPS)
#define DAPS_OP1O                 (2 << DAPS)
#define DAPS_REFO                 (1 << DAPS)
#define DAPS_VDDA                 (0 << DAPS)

//  DACCN1  //
#define DALH                          3
#define DALH_MSK                     (1 << DALH)
#define DALH_ENABLE               (1 << DALH)
#define DALH_DISABLE              (0 << DALH)

#define DAOE                         1
#define DAOE_MSK                     (3 << DAOE)
//#define DAOE_                         (3 << DAOE)
#define DAOE_AI9                        (2 << DAOE)
#define DAOE_LPF_IN                  (1 << DAOE)
#define DAOE_DISABLE               (0 << DAOE)

#define ENDA                          0
#define ENDA_MSK                      (1 << ENDA)
#define ENDA_ENABLE                (1 << ENDA)
#define ENDA_DISABLE               (0 << ENDA)

//  DGCON1 //
#define DGRST                         4
#define DGRST_MSK                     (1 << DGRST)
#define DGRST_RESET                 (1 << DGRST)
#define DGRST_NORMAL              (0 << DGRST)

#define DGDIV                               1
#define DGDIV_MSK                               (7 << DGDIV)
#define DGDIV_CLKDIV128                    (7 << DGDIV)
#define DGDIV_CLKDIV64                      (6 << DGDIV)
#define DGDIV_CLKDIV32                      (5 << DGDIV)
#define DGDIV_CLKDIV16                      (4 << DGDIV)
#define DGDIV_CLKDIV8                        (3 << DGDIV)
#define DGDIV_CLKDIV4                        (2 << DGDIV)
#define DGDIV_CLKDIV2                        (1 << DGDIV)
#define DGDIV_CLKDIV1                        (0 << DGDIV)

#define DGEN                          0
#define DGEN_MSK                      (1 << DGEN)
#define DGEN_ENABLE                (1 << DGEN)
#define DGEN_DISABLE               (0 << DGEN)

//  DGCON2  //
#define DGRP                          0
#define DGRP_MSK                 (63 << DGRP)                          


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define DAC_Enable()                (DACCN1 |= ENDA_ENABLE)
#define DAC_Disable()                (DACCN1 &= (~ENDA_MSK))
#define DAC_DALHEnable()                (DACCN1 |= DALH_ENABLE)
#define DAC_DALHDisable()                (DACCN1 &= (~DALH_MSK))
#define DAC_DAOESel(Sel)           (DACCN1 = ((DACCN1 & (~DAOE_MSK)) | Sel))

#define DAC_DAPSSel(Sel)           (DACCN0 = ((DACCN0 & (~DAPS_MSK)) | Sel))
#define DAC_DANSSel(Sel)           (DACCN0 = ((DACCN0 & (~DANS_MSK)) | Sel))

#define DAC_DACBITSet(Set)        (DACCN2 = Set)

#define DAC_CounterReset()           (DGCON1 |= DGRST_RESET)
#define DAC_DGDIVSel(Sel)            (DGCON1 = ((DGCON1 & (~DGDIV_MSK)) | Sel))
#define DAC_DGEnable()                 (DGCON1 |= DGEN_ENABLE)
#define DAC_DGDisable()                 (DGCON1 &= (~DGEN_MSK))

#define DAC_DGRPSet(Set)             (DGCON2 = ((DGCON2 & (~DGRP_MSK)) | Set))

