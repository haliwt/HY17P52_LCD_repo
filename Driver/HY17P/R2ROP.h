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
//  OP1CN0  //
#define OP1OS                        1
#define OP1OS_MSK                   (7 << OP1OS)
//#define OP1OS_AI8                (7 << OP1OS)
//#define OP1OS_                      (6 << OP1OS)
#define OP1OS_AI4                     (5 << OP1OS)
#define OP1OS_AI11                   (4 << OP1OS)                     
#define OP1OS_AI8                     (3 << OP1OS)
#define OP1OS_AI7                     (2 << OP1OS)
#define OP1OS_AI13                   (1 << OP1OS)
#define OP1OS_OFF                   (0 << OP1OS)  

#define ENOP1                        0
#define ENOP1_MSK                   (1 << ENOP1)
#define ENOP1_ENABLE                   (1 << ENOP1)   
#define ENOP1_DISABLE                   (0 << ENOP1)

//  OP1NET  //
#define OP1PS                        4
#define OP1PS_MSK                        (7 << OP1PS)
#define OP1PS_AI5                           (7 << OP1PS)
#define OP1PS_AI4                           (6 << OP1PS)
#define OP1PS_AI8                           (5 << OP1PS)
#define OP1PS_AI13                         (4 << OP1PS)
#define OP1PS_AI7                           (3 << OP1PS)
#define OP1PS_V12_1                      (2 << OP1PS)
#define OP1PS_DACO                      (1 << OP1PS)
#define OP1PS_LPF_fbp                   (0 << OP1PS)

#define OP1NS                        0
#define OP1NS_MSK                     (7 << OP1NS)
//#define OP1NS_                   (7 << OP1NS)
#define OP1NS_AI13                      (6 << OP1NS)
#define OP1NS_AI10                      (5 << OP1NS)
#define OP1NS_AI12                      (4 << OP1NS)
#define OP1NS_AI9                        (3 << OP1NS)
#define OP1NS_AI16                      (2 << OP1NS)
#define OP1NS_V12_1                   (1 << OP1NS)
#define OP1NS_OP1O                   (0 << OP1NS)

//  OP2CN0  //
#define OP2OS                        1
#define OP2OS_MSK                          (3 << OP2OS)                   
#define OP2OS_AI11                           (3 << OP2OS)
#define OP2OS_Vg_peak                    (2 << OP2OS)
#define OP2OS_AI4                             (1 << OP2OS)
#define OP2OS_OFF                           (0 << OP2OS)  

#define ENOP2                        0
#define ENOP2_MSK                   (1 << ENOP2)
#define ENOP2_ENABLE                   (1 << ENOP2)   
#define ENOP2_DISABLE                   (0 << ENOP2)

//  OP2NET  //
#define OP2PS                        4
#define OP2PS_MSK                         (15 << OP2PS)
//#define OP2PS_                                 (15 << OP2PS)
//#define OP2PS_                                 (14 << OP2PS)
//#define OP2PS_                                 (13 << OP2PS)
//#define OP2PS_                                 (12 << OP2PS)
#define OP2PS_AI11VSS                  (11 << OP2PS)
#define OP2PS_AI8AI10                    (10 << OP2PS)
#define OP2PS_AI10                          (9 << OP2PS)
#define OP2PS_AI8                            (8 << OP2PS)
#define OP2PS_OP1O                       (7 << OP2PS)
#define OP2PS_AI7                            (6 << OP2PS)
#define OP2PS_AI6                            (5 << OP2PS)
#define OP2PS_AI5                            (4 << OP2PS)
#define OP2PS_AI4                            (3 << OP2PS)
#define OP2PS_AI11                          (2 << OP2PS)
#define OP2PS_REFO                       (1 << OP2PS)
#define OP2PS_DACO                       (0 << OP2PS)

#define OP2NS                        0
#define OP2NS_MSK                     (7 << OP2NS)
#define OP2NS_AI4                        (7 << OP2NS)
#define OP2NS_AI6                        (6 << OP2NS)
#define OP2NS_AI5                        (5 << OP2NS)
#define OP2NS_AI8AI10                 (4 << OP2NS)
#define OP2NS_AI10                      (3 << OP2NS)
#define OP2NS_AI8                        (2 << OP2NS)
#define OP2NS_OP2O                   (1 << OP2NS)
#define OP2NS_OP1O                   (0 << OP2NS)

// IQ0  //
#define ENIQ                               0
#define ENIQ_MSK                                (1 <<ENIQ)
#define ENIQ_ENABLE                          (1 <<ENIQ)
#define ENIQ_DISABLE                         (0 <<ENIQ)

//  IQ1  //
#define IQOffset                        3
#define IQOffset_MSK                       (1 << IQOffset)

#define IQMODE                       1
#define IQMODE_MSK                      (1 << IQMODE)   
#define IQMODE_DNRDIV4               (1 << IQMODE)
#define IQMODE_NORMAL               (0 << IQMODE) 

#define IQINV                             0
#define IQINV_MSK                                  (1 << IQINV)
#define IQINV_INVER                                (1 << IQINV)
#define IQINV_NORMAL                            (0 << IQINV)

//  BIACN0  //
#define ENPK                              7
#define ENPK_MSK                                    (1 << ENPK)
#define ENPK_ENABLE                              (1 << ENPK)
#define ENPK_DISABLE                             (0 << ENPK)

#define ENPKS                             6
#define ENPKS_MSK                                    (1 << ENPKS)
#define ENPKS_ENABLE                              (1 << ENPKS)
#define ENPKS_DISABLE                             (0 << ENPKS)

#define ENPKD                             5
#define ENPKD_MSK                                    (1 << ENPKD)
#define ENPKD_ENABLE                              (1 << ENPKD)
#define ENPKD_DISABLE                             (0 << ENPKD)

#define PKRST                             4
#define PKRST_MSK                                     (1 << PKRST)
#define PKRST_NORMAL                              (1 << PKRST)
#define PKRST_RESET                                  (0 << PKRST)

#define ENLPF                             3
#define ENLPF_MSK                                    (1 << ENLPF)
#define ENLPF_ENABLE                              (1 << ENLPF)
#define ENLPF_DISABLE                             (0 << ENLPF)

#define LPFS                               1
#define LPFS_MSK                                     (3 << LPFS_MSK)
//#define LPFS_300k                                (3 << LPFS_MSK)
#define LPFS_300k                                      (2 << LPFS_MSK)
#define LPFS_50k                                        (1 << LPFS_MSK)
#define LPFS_5k                                           (0 << LPFS_MSK)
/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define OP1_Enable()                            (OP1CN0 |= ENOP1_ENABLE)
#define OP1_Disable()                             (OP1CN0 &= (~ENOP1_MSK))
#define OP1_OUTPUTSel(Sel)                     (OP1CN0 = ((OP1CN0 & (~OP1OS_MSK)) | Sel))
#define OP1_INPSel(Sel)                     (OP1NET = ((OP1NET & (~OP1PS_MSK)) | Sel))
#define OP1_INNSel(Sel)                     (OP1NET = ((OP1NET & (~OP1NS_MSK)) | Sel))

#define OP2_Enable()                             (OP2CN0 |= ENOP2_ENABLE)
#define OP2_Disable()                             (OP2CN0 &= (~ENOP2_MSK))
#define OP2_OUTPUTSel(Sel)                     (OP2CN0 = ((OP2CN0 & (~OP2OS_MSK)) | Sel))
#define OP2_INPSel(Sel)                     (OP2NET = ((OP2NET & (~OP2PS_MSK)) | Sel))
#define OP2_INNSel(Sel)                     (OP2NET = ((OP2NET & (~OP2NS_MSK)) | Sel))

#define IQ_Enable()                               (IQ0 |= ENIQ_ENABLE)
#define IQ_Disable()                               (IQ0 &= (~ENIQ_MSK))
#define IQ_OFFSET(Set)                        (IQ1 = ((IQ1 & (~IQOffset_MSK)) | Set))
#define IQ_NormalMode()                       (IQ1 &= (~IQMODE_MSK))
#define IQ_DNRDIV4Mode()                       (IQ1 |= IQMODE_DNRDIV4)
#define IQ_PHASE(Sel)                            (IQ1 = ((IQ1 & (~IQINV_MSK)) | Sel))

#define LPF_Enable()                                          (BIACN0 |= ENPK_ENABLE)
#define LPF_Disable()                                         (BIACN0 &= (~ENPK_MSK))
#define LPF_HighSpeedEnable()                          (BIACN0 |= ENPKS_ENABLE)
#define LPF_HighSpeedDisable()                          (BIACN0 &= (~ENPKS_MSK))
#define LPF_NMOSEnable()                                 (BIACN0 |= ENPKD_ENABLE)
#define LPF_NMOSDisable()                                 (BIACN0 &= (~ENPKD_MSK))
#define LPF_RESET()                                            (BIACN0 &= (~PKRST_MSK))
#define LPF_LPFOutEnable()                                 (BIACN0 |= ENLPF_ENABLE)
#define LPF_LPFOutDisable()                                 (BIACN0 &= (~ENLPF_MSK))
#define LPF_FcSel(Sel)                                       (BIACN0 = ((BIACN0 & (~LPFS_MSK)) | Sel))


