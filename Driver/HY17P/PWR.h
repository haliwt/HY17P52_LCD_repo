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
// PWRCN //
#define ENBGR                      7
#define ENBGR_MSK                 (1 << ENBGR)
#define ENBGR_ENABLE              (1 << ENBGR)
#define ENBGR_DISABLE             (0 << ENBGR)

#define LDOC                       4
#define LDOC_MSK                  (7 << LDOC)
#define LDOC_Res                  (7 << LDOC)
#define LDOC_4V5                  (6 << LDOC)
#define LDOC_4V0                  (5 << LDOC)
#define LDOC_3V6                  (4 << LDOC)
#define LDOC_3V3                  (3 << LDOC)
#define LDOC_2V9                  (2 << LDOC)
#define LDOC_2V6                  (1 << LDOC)
#define LDOC_2V4                  (0 << LDOC)

#define LDOM                       2
#define LDOM_MSK                  (3 << LDOM)
#define LDOM_BLOUT                (3 << LDOM)
#define LDOM_HIGH                 (2 << LDOM)
#define LDOM_VDD                  (1 << LDOM)
#define LDOM_DISABLE              (0 << LDOM)

#define ENLDO                      1                
#define ENLDO_MSK                 (1 << ENLDO)
#define ENLDO_ENABLE              (1 << ENLDO)
#define ENLDO_DISABLE             (0 << ENLDO)

#define CSFON                      0                
#define CSFON_MSK                 (1 << CSFON)
#define CSFON_ENABLE              (1 << CSFON)
#define CSFON_DISABLE             (0 << CSFON)

#define PWRS                       5
#define PWRS_MSK                  (1 << PWRS)
#define PWRS_VDD                  (0 << PWRS)
#define PWRS_VLCD                 (1 << PWRS)

#define VLDX                       1
#define VLDX_MSK                  (15 << VLDX)
#define VLDX_PT12                 (15 << VLDX)
#define VLDX_40                   (14 << VLDX)
#define VLDX_36                   (13 << VLDX)
#define VLDX_33                   (12 << VLDX)
#define VLDX_30                   (11 << VLDX)
#define VLDX_29                   (10 << VLDX)
#define VLDX_28                   (9 << VLDX)
#define VLDX_27                   (8 << VLDX)
#define VLDX_26                   (7 << VLDX)
#define VLDX_25                   (6 << VLDX)
#define VLDX_24                   (5 << VLDX)
#define VLDX_23                   (4 << VLDX)
#define VLDX_22                   (3 << VLDX)
#define VLDX_21                   (2 << VLDX)
#define VLDX_20                   (1 << VLDX)
#define VLDX_OFF                  (0 << VLDX)

#define LVDO                       0
#define LVDO_MSK                  (1 << LVDO)

// BIACN0 //  Only For P58
#define ENREFO                  0
#define ENREFO_MSK                (1 << ENREFO)
#define ENREFO_ENABLE             (1 << ENREFO)
#define ENREFO_DISABLE            (0 << ENREFO)


// AD1CN5 //
#define LDOPL                     4
#define LDOPL_MSK                (1 << LDOPL)
#define LDOPL_ENABLE             (1 << LDOPL)
#define LDOPL_DISABLE            (0 << LDOPL)

/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define PWR_BGREnable()                 (PWRCN |= ENBGR_ENABLE)
#define PWR_BGRDisable()                (PWRCN &= (~ENBGR_MSK))
#define PWR_LDOEnable()                 (PWRCN |= ENLDO_ENABLE)
#define PWR_LDODisable()                (PWRCN &= (~ENLDO_MSK))
#define PWR_BRCHEnable()                (AD1CN1 |= ENBRCH_ENABLE)
#define PWR_BRCHDisable()               (AD1CN1 &= (~ENBRCH_MSK))
#define PWR_LDOPLEnable()               (AD1CN5 |= LDOPL_ENABLE)
#define PWR_LDOPLDisable()              (AD1CN5 &= (~LDOPL_MSK))
#define PWR_CSFONEnable()               (PWRCN |= CSFON_ENABLE)
#define PWR_CSFONDisable()              (PWRCN &= (~CSFON_MSK))

#define PWR_LDOSel(LDOVSel)             (PWRCN = ((PWRCN & (~LDOC_MSK)) | LDOVSel))
#define PWR_LDOMode(LDOMode)            (PWRCN = ((PWRCN & (~LDOM_MSK)) | LDOMode))

#define LVD_PWRSelect(Sel)              (LVDCN = ((LVDCN & (~PWRS_MSK)) | Sel))
#define LVD_VolSelect(Sel)              (LVDCN = ((LVDCN & (~VLDX_MSK)) | Sel))
#define LVD_Disable()                   (LVDCN = LVDCN & (~VLDX_MSK))

#define LVD_GetLVDO()                   (LVDCN & LVDO_MSK)

//Only For P58
#define PWR_ENREFOEnable()               (BIACN0 |= ENREFO_ENABLE)
#define PWR_ENREFODisable()              (BIACN0 &= (~ENREFO_MSK))
/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
//void PWR_Open(unsigned char VDDASel,    //VDDA regulated selector
//              unsigned char ACMEn,
//              unsigned char DelayCnt);
