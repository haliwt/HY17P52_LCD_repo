
/**************************************************************************************************|
|* Copyright 2018 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17P Series                                                                 *|
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
#define VREGN                     5
#define VREGN_MSK                (1 << VREGN)
#define VREGN_DIV2               (1 << VREGN)
#define VREGN_DIV1               (0 << VREGN)

#define PGAGN                     3
#define PGAGN_MSK                (3 << PGAGN)
#define PGAGN_8                  (3 << PGAGN)
//#define PGAGN_4                  (2 << PGAGN)    
//#define PGAGN_2                  (1 << PGAGN)    
#define PGAGN_1                  (0 << PGAGN) 


  // ADGN defined in main.c  //
#define ADGN                      0
#define ADGN_MSK                 (7 << ADGN)

#if 1
//FOR ICE
#define ADGN_RSVD                 (7 << ADGN)
#define ADGN_16                   (6 << ADGN)
#define ADGN_4                     (4 << ADGN)
#define ADGN_1                     (2 << ADGN)
#endif 

 //WT.EDIT HY17P52 IC
#if 0
//FOR BODY
#define ADGN_RSVD                (7 << ADGN)
#define ADGN_16                  (6 << ADGN)
#define ADGN_4                   (4 << ADGN)
#define ADGN_1                   (0 << ADGN)   //WT.EDIT 2020-06-30

#endif 

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
//#define INP_                   (15 << INP)
//#define INP_                   (14 << INP)
//#define INP_                   (13 << INP)
//#define INP_                   (12 << INP) 
//#define INP_                   (11 << INP)
//#define INP_                   (10 << INP)
#define INP_VSS                  ( 9 << INP)
//#define INP_                   ( 8 << INP)
#define INP_VDDA               ( 7 << INP)
//#define INP_                   ( 6 << INP)
//#define INP_                   ( 5 << INP)
#define INP_VDDDIV10       ( 4 << INP)
//#define INP_                   ( 3 << INP)
#define INP_TS0                 ( 2 << INP)
//#define INP_                   ( 1 << INP)
#define INP_AI2                   ( 0 << INP)


#define INN                       0
#define INN_MSK                  (15 << INN)
//#define INN_                   (15 << INN)
//#define INN_                   (14 << INN)
//#define INN_                   (13 << INN)
//#define INN_                   (12 << INN)
//#define INN_                   (11 << INN)
//#define INN_                   (10 << INN)
//#define INN_                   ( 9 << INN)
#define INN_VDDA                 ( 8 << INN)
#define INN_VCMS                 ( 7 << INN)    //VCMS[0]=0 ->VDDA/2 ; VCMS[0]=1 ->1.2V
//#define INN_                   ( 6 << INN)
//#define INN_                   ( 5 << INN)
#define INN_AI3                      ( 4 << INN)
//#define INN_                   ( 3 << INN)
//#define INN_                   ( 2 << INN)
#define INN_VSS                     ( 1 << INN)
//#define INN_                   ( 0 << INN)

// AD1CN4 //
#define VRH                       6
#define VRH_MSK                  (3 << VRH)
//#define VRH_                   (3 << VRH)
//#define VRH_                   (2 << VRH)
#define VRH_VCMS                (1 << VRH)
#define VRH_AI2                     (0 << VRH)


#define VRL                       4
#define VRL_MSK                   (3 << VRL)
//#define VRL_                    (3 << VRL)
//#define VRL_                    (2 << VRL)
#define VRL_AI3                      (1 << VRL)
#define VRL_VSS                    (0 << VRL)

#define INX                       2
#define INX_MSK                     (3 << INX)
#define INX_CROSS                (3 << INX)
#define INX_INP                       (2 << INX)
#define INX_INN                       (1 << INX)
#define INX_NORMAL              (0 << INX)


// AD1CN5 //
#define ENACM                     7
#define ENACM_MSK                (1 << ENACM)
#define ENACM_ENABLE             (1 << ENACM)
#define ENACM_DISABLE            (0 << ENACM)

#define VCMS                      5
#define VCMS_MSK                 (1 << VCMS)
#define VCMS_V12                 (1 << VCMS)
#define VCMS_VDDADIV2            (0 << VCMS)

#define LDOPL                     4
#define LDOPL_MSK                (1 << LDOPL)
#define LDOPL_ENABLE             (1 << LDOPL)
#define LDOPL_DISABLE            (0 << LDOPL)

#define ENTPS                     1
#define ENTPS_MSK                (1 << ENTPS)
#define ENTPS_ENABLE             (1 << ENTPS)
#define ENTPS_DISABLE            (0 << ENTPS)

#define TPSCH                     0
#define TPSCH_MSK                (1 << TPSCH)
#define TPSCH_REVERSE            (1 << TPSCH)
#define TPSCH_NORMAL             (0 << TPSCH)

// CSFCN1 //
#define ENSDRV                    7
#define ENSDRV_MSK               (1 << ENSDRV)
#define ENSDRV_ENABLE            (1 << ENSDRV)
#define ENSDRV_DISABLE           (0 << ENSDRV)
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

#define ADC_CLK_DivSelect(DADCSel)      (OSCCN1 = (OSCCN1 & (~DADC_MSK)) | DADCSel)
//#define CLK_ADCCKDivSel(ADCDivSel)      (OSCCN1 = ((OSCCN1 & (~DADC_MSK)) | ADCDivSel))


#define ADC_INT_Enable()                (INTE0 |= ADIE_ENABLE)
#define ADC_INT_Disable()               (INTE0 &= (~ADIE_MSK))
#define ADC_INT_IsFlag()                (INTF0 & ADIF_SET)
#define ADC_INT_ClearFlag()             (INTF0 &= (~ADIF_MSK))
//#define ADIE_Enable()               (INTE0 |= ADIE_ENABLE)
//#define ADIE_Disable()              (INTE0 &= (~ADIE_MSK))
//#define ADIF_IsFlag()               (INTF0 & ADIF_SET)
//#define ADIF_ClearFlag()            (INTF0 &= (~ADIF_MSK))

#define AD1CN0_SET(AD1CN0Sel)           (AD1CN0 |= (1<<AD1CN0Sel))
#define AD1CN0_CLR(AD1CN0Sel)           (AD1CN0 &= ~(1<<AD1CN0Sel))
#define ADC_Enable()                    (AD1CN0 |= ENAD1_ENABLE)
#define ADC_Disable()                   (AD1CN0 &= (~ENAD1_MSK))
#define ADC_CMFREnable()                (AD1CN0 |= CMFR_ENABLE)
#define ADC_CMFRDisable()               (AD1CN0 &= (~CMFR_MSK))
#define ADC_OSRSelect(OSRSel)           (AD1CN0 = (AD1CN0 & (~OSR_MSK)) | OSRSel)

#define AD1CN1_SET(AD1CN1Sel)           (AD1CN1 |= (1<<AD1CN1Sel))
#define AD1CN1_CLR(AD1CN1Sel)           (AD1CN1 &= ~(1<<AD1CN1Sel))
#define ADC_VREGNEnable()               (AD1CN1 |= VREGN_DIV2)
#define ADC_VREGNDisable()              (AD1CN1 &= ~(VREGN_MSK))
#define ADC_VRXSelect(VRXSel)           (AD1CN1 = ((AD1CN1 & (~VREGN_MSK)) | VRXSel))
#define ADC_GainSelect(adgn,pgagn)      (AD1CN1 = ((AD1CN1 & (~(ADGN_MSK | PGAGN_MSK)))|(adgn | pgagn)) )


#define AD1CN2_SET(AD1CN2Sel)           (AD1CN2 |= (1<<AD1CN2Sel))
#define AD1CN2_CLR(AD1CN2Sel)           (AD1CN2 &= ~(1<<AD1CN2Sel))
#define ADC_DCSETSelect(dcset)          (AD1CN2 = ((AD1CN2 & (~DCSET_MSK)) | dcset))

#define AD1CN3_SET(AD1CN3Sel)           (AD1CN3 |= (1<<AD1CN3Sel))
#define AD1CN3_CLR(AD1CN3Sel)           (AD1CN3 &= ~(1<<AD1CN3Sel))
#define ADC_VINSelect(inp,inn)           (AD1CN3 = ((AD1CN3 & (~(INP_MSK | INN_MSK))) | (inp | inn)))

#define AD1CN4_SET(AD1CN4Sel)           (AD1CN4 |= (1<<AD1CN4Sel))
#define AD1CN4_CLR(AD1CN4Sel)           (AD1CN4 &= ~(1<<AD1CN4Sel))
#define ADC_VRINSelect(vrh,vrl)          (AD1CN4 = ((AD1CN4 & (~(VRH_MSK | VRL_MSK))) | (vrh | vrl)))
#define ADC_INXSelect(INXSel)           (AD1CN4 = ((AD1CN4 & (~INX_MSK)) | INXSel))

#define AD1CN5_SET(AD1CN5Sel)           (AD1CN5 |= (1<<AD1CN5Sel))
#define AD1CN5_CLR(AD1CN5Sel)           (AD1CN5 &= ~(1<<AD1CN5Sel))
#define ADC_ENACMEnable()               (AD1CN5 |= ENACM_ENABLE)
#define ADC_ENACMDisable()              (AD1CN5 &= (~ENACM_MSK))
#define ADC_VCMSSelect(VCMS_Sel)        (AD1CN5 = ((AD1CN5 & (~VCMS_MSK)) | VCMS_Sel))
#define ADC_LDOPLEnable()               (AD1CN5 |= LDOPL_ENABLE)
#define ADC_LDOPLDisable()              (AD1CN5 &= (~LDOPL_MSK))
#define ADC_ENTPSEnable()               (AD1CN5 |= ENTPS_ENABLE)
#define ADC_ENTPSDisable()              (AD1CN5 &= (~ENTPS_MSK))
#define ADC_TPSCHEnable()               (AD1CN5 |= TPSCH_ENABLE)
#define ADC_TPSCHDisable()              (AD1CN5 &= (~TPSCH_MSK))



/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/

void ADC_Open(unsigned char ck,         //Selector of SD18 peripheral operating clock source
              unsigned char cks,        //Prescaler of SD18 peripheral operating frequency
              unsigned char inh,        //SI+ input signal selector
              unsigned char inl,        //SI- input signal selector
              unsigned char vrh,        //VR+ voltage signal selector
              unsigned char vrl,        //VR- voltage signal selector
              unsigned char adgn,       //AD amplification adjuster
              unsigned char pgagn,      //PGA amplification adjuster
              unsigned char vrgn,       //VR amplification adjuster
              unsigned char dcset,      //SI+/- bias adjuster
              unsigned char osr,       //SD18 over-sampling rate divider
              unsigned char vcms) ; //VCMS signal selector

long ADC_GetData(void);
void ADC_SDRVEnable(void);
void ADC_SDRVDisable(void);
