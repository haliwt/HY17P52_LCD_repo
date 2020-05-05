/**************************************************************************************************|
|* Copyright 2019 Hycon Technology,                                                       *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17M Series                                                                 *|
|**************************************************************************************************/

#include <INT.h>           // Interrupt Config for ADC
#include <CLK.h>           // CLK Cpnfig for ADC

/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
// AD1CN0 //
// Bit-field Struc Test for SDCC
#define ENAD1                     7
#define ENAD1_MSK                (1 << ENAD1)
#define ENAD1_ENABLE             (1 << ENAD1)
#define ENAD1_DISABLE            (0 << ENAD1)

#define FilterN                   5
#define FilterN_MSK              (3 << FilterN) 
#define FilterN_512              (3 << FilterN)
#define FilterN_256              (2 << FilterN)
#define FilterN_128              (1 << FilterN)
#define FilterN_64               (0 << FilterN)

#define OSR                       1
#define OSR_MSK                  (15 << OSR) 
//#define OSR_65536                (11 << OSR)
#define OSR_64                   (10 << OSR)
#define OSR_128                  ( 9 << OSR)
#define OSR_256                  ( 8 << OSR)
#define OSR_512                  ( 7 << OSR)
#define OSR_1024                 ( 6 << OSR)
#define OSR_2048                 ( 5 << OSR)
#define OSR_4096                 ( 4 << OSR)
#define OSR_8192                 ( 3 << OSR)
#define OSR_16384                ( 2 << OSR)
#define OSR_32768                ( 1 << OSR)
#define OSR_65536                ( 0 << OSR)

#define CMFR                      0
#define CMFR_MSK                 (1 << CMFR)
#define CMFR_ENABLE              (1 << CMFR)
#define CMFR_DISABLE             (0 << CMFR)

// AD1CN1 //
#define ENBRCH                     7
#define ENBRCH_MSK                (1 << ENBRCH)
#define ENBRCH_ENABLE             (1 << ENBRCH)
#define ENBRCH_DISABLE            (0 << ENBRCH)

#define VREGN                     5
#define VREGN_MSK                (1 << VREGN)
#define VREGN_DIV2               (1 << VREGN)
#define VREGN_DIV1               (0 << VREGN)

#define ADGN                      0
#define ADGN_MSK                 (7 << ADGN)
#define ADGN_RSVD                (7 << ADGN)
#define ADGN_16                  (6 << ADGN)
#define ADGN_8                   (5 << ADGN)
#define ADGN_4                   (4 << ADGN)
#define ADGN_2                   (3 << ADGN)
#define ADGN_1                   (2 << ADGN)
#define ADGN_1DIV2               (1 << ADGN)
#define ADGN_1DIV4               (0 << ADGN)


// AD1CN2 //
#define SELVIN								4
#define SELVIN_MSK					(1 << SELVIN)
#define SELVIN_1V2					  (1 << SELVIN)
#define SELVIN_VDDADIV2			(0 << SELVIN)

#define DCSET                     0
#define DCSET_MSK                (15 << DCSET)
#define DCSET_N7DIV8             (15 << DCSET)
#define DCSET_N6DIV8             (14 << DCSET)
#define DCSET_N5DIV8             (13 << DCSET)
#define DCSET_N4DIV8             (12 << DCSET)
#define DCSET_N3DIV8             (11 << DCSET)
#define DCSET_N2DIV8             (10 << DCSET)
#define DCSET_N1DIV8             ( 9 << DCSET)
#define DCSET_N0                 ( 8 << DCSET)
#define DCSET_P7DIV8             ( 7 << DCSET)
#define DCSET_P6DIV8             ( 6 << DCSET)
#define DCSET_P5DIV8             ( 5 << DCSET)
#define DCSET_P4DIV8             ( 4 << DCSET)
#define DCSET_P3DIV8             ( 3 << DCSET)
#define DCSET_P2DIV8             ( 2 << DCSET)
#define DCSET_P1DIV8             ( 1 << DCSET)
#define DCSET_P0                 ( 0 << DCSET)


// AD1CN3 //

#define INP                       4
#define INP_MSK                  (15 << INP)
#define INP_DAOI                 (15 << INP)
#define INP_VSS                  (14 << INP)
#define INP_TS1                  (13 << INP)
#define INP_TS0                  (12 << INP)
#define INP_REFOI                (11 << INP)
#define INP_VDDA                 (10 << INP)
#define INP_OPOI                 ( 9 << INP)
#define INP_AI14                 ( 8 << INP)
#define INP_AI12                 ( 7 << INP)
#define INP_AI10                 ( 6 << INP)
#define INP_AI8                  ( 5 << INP)
#define INP_AI6             		 ( 4 << INP)
#define INP_AI4                  ( 3 << INP)
#define INP_AI2                  ( 2 << INP)
#define INP_AI1                  ( 1 << INP)
#define INP_AI0                  ( 0 << INP)

#define INN                       0
#define INN_MSK                  (15 << INN)
#define INN_DAOI                 (15 << INN)
#define INN_VSS                  (14 << INN)
#define INN_TS1                  (13 << INN)
#define INN_TS0                  (12 << INN)
#define INN_REFOI                (11 << INN)
#define INN_VDDA                 (10 << INN)
#define INN_OPOI                 ( 9 << INN)
#define INN_VDDDIV10             ( 8 << INN)
#define INN_AI13                 ( 7 << INN)
#define INN_AI11                 ( 6 << INN)
#define INN_AI9                  ( 5 << INN)
#define INN_AI7                  ( 4 << INN)
#define INN_AI5                  ( 3 << INN)
#define INN_AI2                  ( 2 << INN)
#define INN_AI1                  ( 1 << INN)
#define INN_AI0                  ( 0 << INN)

// AD1CN4 //
#define VRH                       6
#define VRH_MSK                  (3 << VRH)
#define VRH_REFOI                (3 << VRH)
#define VRH_AI10                 (2 << VRH)
#define VRH_AI0                  (1 << VRH)
#define VRH_VDDA                 (0 << VRH)

#define VRL                       4
#define VRL_MSK                  (3 << VRL)
#define VRL_REFOI                  (3 << VRL)
#define VRL_AI4                  (2 << VRL)
#define VRL_AI2                  (1 << VRL)
#define VRL_VSS               (0 << VRL)

#define INX                       2
#define INX_MSK                  (3 << INX)
#define INX_CROSS                (3 << INX)
#define INX_INP                  (2 << INX)
#define INX_INN                  (1 << INX)
#define INX_NORMAL               (0 << INX)

#define VRIS                      1
#define VRIS_MSK                 (1 << VRIS)
#define VRIS_SHORT               (1 << VRIS)
#define VRIS_NORMAL              (0 << VRIS)

#define INIS                      0
#define INIS_MSK                 (1 << INIS)
#define INIS_SHORT               (1 << INIS)
#define INIS_NORMAL              (0 << INIS)

// AD1CN5 //
#define ENACM                     7
#define ENACM_MSK                (1 << ENACM)
#define ENACM_ENABLE             (1 << ENACM)
#define ENACM_DISABLE            (0 << ENACM)

#define VCMS                      5
#define VCMS_MSK                 (1 << VCMS)
#define VCMS_REFOint                 (1 << VCMS)
#define VCMS_ACMint           (0 << VCMS)

#define LDOPL                     4
#define LDOPL_MSK                (1 << LDOPL)
#define LDOPL_ENABLE             (1 << LDOPL)
#define LDOPL_DISABLE            (0 << LDOPL)
         
#define TPSCP                     2          
#define TPSCP_MSK                (1 << TPSCP)
#define TPSCP_ENABLE             (1 << TPSCP)
#define TPSCP_DISABLE            (0 << TPSCP)
           
#define ENTPS                     1
#define ENTPS_MSK                (1 << ENTPS)
#define ENTPS_ENABLE             (1 << ENTPS)
#define ENTPS_DISABLE            (0 << ENTPS)

#define TPSCH                     0
#define TPSCH_MSK                (1 << TPSCH)
#define TPSCH_REVERSE            (1 << TPSCH)
#define TPSCH_NORMAL             (0 << TPSCH)

// CSFCN1 //
#define ENINXCH                   5
#define ENINXCH_MSK              (1 << ENINXCH)
#define ENINXCH_ENABLE           (1 << ENINXCH)
#define ENINXCH_DISABLE          (0 << ENINXCH)

// LVDCN //
#define DAFM                      7
#define DAFM_MSK                 (1 << DAFM)
#define DAFM_CHOPPER             (1 << DAFM)
#define DAFM_NORMAL              (0 << DAFM)

#define ENCH                      6
#define ENCH_MSK                 (1 << ENCH)
#define ENCH_ENABLE              (1 << ENCH)
#define ENCH_DISABLE             (0 << ENCH)

// TMA1CN //
#define CHP_CKS                   0
#define CHP_CKS_MSK              (3 << CHP_CKS)
#define CHP_CKS_DIV4             (3 << CHP_CKS)
#define CHP_CKS_DIV8             (2 << CHP_CKS)
#define CHP_CKS_DIV16            (1 << CHP_CKS)
#define CHP_CKS_DIV64            (0 << CHP_CKS)

// FILTER //
#define PreSpect                  6
#define PreSpect_MSK             (3 << PreSpect)
#define PreSpect_9TO6            (3 << PreSpect)
#define PreSpect_10TO7           (2 << PreSpect)
#define PreSpect_11TO8           (1 << PreSpect)
#define PreSpect_12TO9           (0 << PreSpect)

#define FreBit                    5
#define FreBit_MSK               (1 << PreBit)
#define FreBit_4BITS             (1 << PreBit)
#define FreBit_3BOTS             (0 << PreBit)

#define ENSpect                   4
#define ENSpect_MSK              (1 << ENSpect)
#define ENSpect_ENABLE           (1 << ENSpect)
#define ENSpect_DISABLE          (0 << ENSpect)

#define FiltThr                   1
#define FiltThr_MSK              (3 << FiltThr)
#define FiltThr_1024             (3 << FiltThr)
#define FiltThr_512              (2 << FiltThr)
#define FiltThr_256              (1 << FiltThr)
#define FiltThr_128              (0 << FiltThr)

#define ENFilter                  0
#define ENFilter_MSK             (1 << ENFilter)
#define ENFilter_ENABLE          (1 << ENFilter)
#define ENFilter_DISABLE         (0 << ENFilter)

// MCCN1 //
#define VRSEL                      6
#define VRSEL_MSK                 (1 << VRSEL)
#define VRSEL_REFOint              (1 << VRSEL)
#define VRSEL_ACMint             (0 << VRSEL)


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
//#define AD1CN0_SET(AD1CN0Sel)       (AD1CN0 |= (1<<AD1CN0Sel))
//#define AD1CN0_CLR(AD1CN0Sel)       (AD1CN0 &= ~(1<<AD1CN0Sel))
//#define AD1CN1_SET(AD1CN0Sel)       (AD1CN1 |= (1<<AD1CN0Sel))
//#define AD1CN1_CLR(AD1CN0Sel)       (AD1CN1 &= ~(1<<AD1CN0Sel))
//#define AD1CN2_SET(AD1CN0Sel)       (AD1CN2 |= (1<<AD1CN0Sel))
//#define AD1CN2_CLR(AD1CN0Sel)       (AD1CN1 &= ~(1<<AD1CN0Sel))
//#define AD1CN3_SET(AD1CN0Sel)       (AD1CN3 |= (1<<AD1CN0Sel))
//#define AD1CN3_CLR(AD1CN0Sel)       (AD1CN3 &= ~(1<<AD1CN0Sel))
//#define AD1CN4_SET(AD1CN0Sel)       (AD1CN4 |= (1<<AD1CN0Sel))
//#define AD1CN4_CLR(AD1CN0Sel)       (AD1CN4 &= ~(1<<AD1CN0Sel))
//#define AD1CN5_SET(AD1CN0Sel)       (AD1CN5 |= (1<<AD1CN0Sel))
//#define AD1CN5_CLR(AD1CN0Sel)       (AD1CN5 &= ~(1<<AD1CN0Sel))


#define ADC_INT_Enable()                (INTE0 |= ADCIE_ENABLE)
#define ADC_INT_Disable()               (INTE0 &= (~ADCIE_MSK))
#define ADC_INT_IsFlag()                (INTF0 & ADCIF_SET)
#define ADC_INT_ClearFlag()             (INTF0 &= (~ADCIF_MSK))

#define AD1CN0_SET(AD1CN0Sel)           (AD1CN0 |= (1<<AD1CN0Sel))
#define AD1CN0_CLR(AD1CN0Sel)           (AD1CN0 &= ~(1<<AD1CN0Sel))
#define ADC_Enable()                    (AD1CN0 |= ENAD1_ENABLE)
#define ADC_Disable()                   (AD1CN0 &= (~ENAD1_MSK))
#define ADC_CMFREnable()                (AD1CN0 |= CMFR_ENABLE)
#define ADC_CMFRDisable()               (AD1CN0 &= (~CMFR_MSK))
#define ADC_OSRSelect(OSRSel)           (AD1CN0 = (AD1CN0 & (~OSR_MSK)) | OSRSel)

#define AD1CN1_SET(AD1CN1Sel)             (AD1CN1 |= (1<<AD1CN1Sel))
#define AD1CN1_CLR(AD1CN1Sel)             (AD1CN1 &= ~(1<<AD1CN1Sel))
#define ADC_VREGNEnable()                        (AD1CN1 |= VREGN_DIV2)
#define ADC_VREGNDisable()                       (AD1CN1 &= VREGN_DIV1)
#define ADC_VRXSelect(VRXSel)                  (AD1CN1 = ((AD1CN1 & (~VREGN_MSK)) | VRXSel))
#define ADC_GainSelect(adgn,vregn)      (AD1CN1  = (AD1CN1  & (~(ADGN_MSK | VREGN_MSK)))|(adgn | vregn) )

#define AD1CN2_SET(AD1CN2Sel)           (AD1CN2 |= (1<<AD1CN2Sel))
#define AD1CN2_CLR(AD1CN2Sel)           (AD1CN2 &= ~(1<<AD1CN2Sel))
#define ADC_DCSETSelect(dcset)          (AD1CN2 = ((AD1CN2 & (~DCSET_MSK)) | dcset))
#define ADC_ACMBufSelect(SELVINSel)	(AD1CN2 = ((AD1CN2 & (~SELVIN_MSK)) | SELVINSel))

#define AD1CN3_SET(AD1CN3Sel)           (AD1CN3 |= (1<<AD1CN3Sel))
#define AD1CN3_CLR(AD1CN3Sel)           (AD1CN3 &= ~(1<<AD1CN3Sel))
#define ADC_VINSelect(inp,inn)          (AD1CN3 = ((AD1CN3 & (~(INP_MSK | INN_MSK))) | (inp | inn)))

#define AD1CN4_SET(AD1CN4Sel)           (AD1CN4 |= (1<<AD1CN4Sel))
#define AD1CN4_CLR(AD1CN4Sel)           (AD1CN4 &= ~(1<<AD1CN4Sel))
#define ADC_VRINSelect(vrh,vrl)         (AD1CN4 = ((AD1CN4 & (~(VRH_MSK | VRL_MSK))) | (vrh | vrl)))
#define ADC_INXSelect(INXSel)           (AD1CN4 = ((AD1CN4 & (~INX_MSK)) | INXSel))
#define ADC_VRIS_Short()                (AD1CN4 |= VRIS_SHORT )
#define ADC_VRIS_Normal()               (AD1CN4 &= (~VRIS_MSK) )
#define ADC_INIS_Short()                (AD1CN4 |= INIS_SHORT )
#define ADC_INIS_Normal()               (AD1CN4 &= (~INIS_MSK))

#define AD1CN5_SET(AD1CN5Sel)           (AD1CN5 |= (1<<AD1CN5Sel))
#define AD1CN5_CLR(AD1CN5Sel)           (AD1CN5 &= ~(1<<AD1CN5Sel))
#define ADC_ENACMEnable()               (AD1CN5 |= ENACM_ENABLE)
#define ADC_ENACMDisable()              (AD1CN5 &=(~ENACM_MSK))
#define ADC_VCMSSelect(vcms)           (AD1CN5 = ((AD1CN5 & (~VCMS_MSK)) | vcms))
#define ADC_LDOPLEnable()               (AD1CN5 |= LDOPL_ENABLE)
#define ADC_LDOPLDisable()              (AD1CN5 &= (~LDOPL_MSK))
//#define PWR_LDOPLEnable()               (AD1CN5 |= LDOPL_ENABLE)
//#define PWR_LDOPLDisable()              (AD1CN5 &= (~LDOPL_MSK))
#define ADC_TPSCPEnable()               (AD1CN5 |= TPSCP_ENABLE)
#define ADC_TPSCPDisable()              (AD1CN5 &= (~TPSCP_MSK))
#define ADC_ENTPSEnable()               (AD1CN5 |= ENTPS_ENABLE)
#define ADC_ENTPSDisable()              (AD1CN5 &= (~ENTPS_MSK))
#define ADC_TPSCHEnable()               (AD1CN5 |= TPSCH_ENABLE)
#define ADC_TPSCHDisable()              (AD1CN5 &= (~TPSCH_MSK))
#define ADC_TPSSelect(TPSSel)           (AD1CN5 = ((AD1CN5 & (~TPSCH_MSK)) | TPSSel))

#define CSFCN1_SET(CSFCN1Sel)           (CSFCN1 |= (1<<CSFCN1Sel))
#define CSFCN1_CLR(CSFCN1Sel)           (CSFCN1 &= ~(1<<CSFCN1Sel))
#define ADC_ENINXCH_Enable()            (CSFCN1 |= ENINXCH_ENABLE)
#define ADC_ENINXCH_Disable()           (CSFCN1 &= (~ENINXCH_MSK))

#define LVDCN_SET(LVDCNSel)             (LVDCN |= (1<<LVDCNSel))
#define LVDCN_CLR(LVDCNSel)             (LVDCN &= ~(1<<LVDCNSel))
#define ADC_DAFM_CHOPPER()              (LVDCN |= DAFM_CHOPPER)
#define ADC_DAFM_NORMAL()               (LVDCN &=(~DAFM_MSK))
#define ADC_ENCH_Enable()               (LVDCN |= ENCH_ENABLE)
#define ADC_ENCH_Disable()              (LVDCN &=(~ENCH_MSK))

#define TMA1CN_SET(TMA1CNSel)           (TMA1CN |= (1<<TMA1CNSel))
#define TMA1CN_CLR(TMA1CNSel)           (TMA1CN &= ~(1<<TMA1CNSel))
#define ADC_CHPCKSSelect(CHPCKS_Sel)    (TMA1CN = ((TMA1CN & (~CHP_CKS_MSK)) | CHPCKS_Sel))

#define FILTER_SET(FILTERSel)           (FILTER |= (1<<FILTERSel))
#define FILTER_CLR(FILTERSel)           (FILTER &= ~(1<<FILTERSel))
#define ADC_PreSpectSelect(PreSpectSel) (FILTER = ((FILTER & (~PreSpect_MSK)) | PreSpectSel))
#define ADC_PreBitSelect(PreBitSel)     (FILTER = ((FILTER & (~PreBit_MSK)) | PreBitSel))
#define ADC_ENSpect_Enable()            (FILTER |= ENSpect_ENABLE)
#define ADC_ENSpect_Disable()           (FILTER &= (~ENSpect_MSK))
#define ADC_FiltThrSelect(FiltThrSel)   (FILTER = ((FILTER & (~FiltThr_MSK)) | FiltThrSel))
#define ADC_ENFilter_Enable()           (FILTER |= ENFilter_ENABLE)
#define ADC_ENFilter_Disable()          (FILTER &= (~ENFilter_MSK))

//REFO voltage buffer select
#define ADC_VRSEL_REFOint()                 (MCCN1 |= VRSEL_REFOint)
#define ADC_VRSEL_ACMint()                  (MCCN1 &= (~VRSEL_MSK))

/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/

void ADC_Open(unsigned char cks,        //Prescaler of SD18 peripheral operating frequency
              unsigned char inh,        //SI+ input signal selector
              unsigned char inl,        //SI- input signal selector
              unsigned char vrh,        //VR+ voltage signal selector
              unsigned char vrl,        //VR- voltage signal selector
              unsigned char adgn,       //AD amplification adjuster
              unsigned char vrgn,       //VR amplification adjuster
              unsigned char dcset,      //SI+/- bias adjuster
              unsigned char osr,       //SD18 over-sampling rate divider
              unsigned char vcms) ; //VCMS signal selector

long ADC_GetData(void);
void ADC_SDRVEnable(void);
void ADC_SDRVDisable(void);