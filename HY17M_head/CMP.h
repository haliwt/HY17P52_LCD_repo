/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                     *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17M Series                                                                 *|
|**************************************************************************************************/

/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
#include <INT.h>           // Interrupt Config for CMP


// MCCN0 //
#define ENRCC                    6
#define ENRCC_MSK               (3 << ENRCC) 
#define ENRCC_RESERVED          (3 << ENRCC)
#define ENRCC_PT16              (2 << ENRCC)
#define ENRCC_RC                (1 << ENRCC)
#define ENRCC_DISABLE           (0 << ENRCC)

#define CMPO                     5
#define CMPO_MSK                (1 << CMPO)
#define CMPO_PGN                (1 << CMPO)
#define CMPO_NGP                (0 << CMPO)
  
#define CPIS                     4
#define CPIS_MSK                (1 << CPIS)
#define CPIS_CLOSED             (1 << CPIS)
#define CPIS_OPEN               (0 << CPIS)

#define CPOR                     3
#define CPOR_MSK                (1 << CPOR)
#define CPOR_INVERSE            (1 << CPOR)
#define CPOR_NORMAL             (0 << CPOR)

#define CPDF                     2
#define CPDF_MSK                (1 << CPDF)
#define CPDF_ENABLE             (1 << CPDF)
#define CPDF_DISABLE            (0 << CPDF)

#define CMPHS                    1
#define CMPHS_MSK               (1 << CMPHS)
#define CMPHS_NORMAL            (1 << CMPHS)
#define CMPHS_LOWPOWER          (0 << CMPHS)

#define ENCMP                    0
#define ENCMP_MSK               (1 << ENCMP)
#define ENCMP_ENABLE            (1 << ENCMP)
#define ENCMP_DISABLE           (0 << ENCMP)

// MCCN1 //
#define CPRL                     7
#define CPRL_MSK                (1 << CPRL)
#define CPRL_SHORT              (1 << CPRL)
#define CPRL_OPEN               (0 << CPRL)

#define CPRH                     4
#define CPRH_MSK                (3 << CPRH) 
#define CPRH_RESERVED           (3 << CPRH)
#define CPRH_VDDA               (2 << CPRH)
#define CPRH_VDD                (1 << CPRH)
#define CPRH_DISABLE            (0 << CPRH)

#define CPPS                     2
#define CPPS_MSK                (3 << CPPS) 
#define CPPS_1V2                (3 << CPPS)
#define CPPS_CH2                (2 << CPPS)
#define CPPS_CH1                (1 << CPPS)
#define CPPS_CH0                (0 << CPPS)

#define CPNS                     0
#define CPNS_MSK                (3 << CPNS) 
#define CPNS_RLO                (3 << CPNS)
#define CPNS_CH2                (2 << CPNS)
#define CPNS_CH1                (1 << CPNS)
#define CPNS_CH0                (0 << CPNS)

// MCCN2 //
#define CPDA                     0
#define CPDA_MSK                (31 << CPDA)
#define CPDA_31DIV32            (31 << CPDA) 
#define CPDA_30DIV32            (30 << CPDA)
#define CPDA_29DIV32            (29 << CPDA)
#define CPDA_28DIV32            (28 << CPDA)
#define CPDA_27DIV32            (27 << CPDA)
#define CPDA_26DIV32            (26 << CPDA)
#define CPDA_25DIV32            (25 << CPDA)
#define CPDA_24DIV32            (24 << CPDA)
#define CPDA_23DIV32            (23 << CPDA)
#define CPDA_22DIV32            (22 << CPDA)
#define CPDA_21DIV32            (21 << CPDA)
#define CPDA_20DIV32            (20 << CPDA)
#define CPDA_19DIV32            (19 << CPDA)
#define CPDA_18DIV32            (18 << CPDA)
#define CPDA_17DIV32            (17 << CPDA)
#define CPDA_16DIV32            (16 << CPDA)
#define CPDA_15DIV32            (15 << CPDA)
#define CPDA_14DIV32            (14 << CPDA)
#define CPDA_13DIV32            (13 << CPDA)
#define CPDA_12DIV32            (12 << CPDA)
#define CPDA_11DIV32            (11 << CPDA)
#define CPDA_10DIV32            (10 << CPDA)
#define CPDA_9DIV32             (9 << CPDA)
#define CPDA_8DIV32             (8 << CPDA)
#define CPDA_7DIV32             (7 << CPDA)
#define CPDA_6DIV32             (6 << CPDA)
#define CPDA_5DIV32             (5 << CPDA)
#define CPDA_4DIV32             (4 << CPDA)
#define CPDA_3DIV32             (3 << CPDA)
#define CPDA_2DIV32             (2 << CPDA)
#define CPDA_1DIV32             (1 << CPDA)
#define CPDA_0                  (0 << CPDA)

// MCCN3 //
#define CPDM4                    4
#define CPDM4_MSK               (1 << CPDM4)
#define CPDM4_ENABLE            (1 << CPDM4)
#define CPDM4_DISABLE           (0 << CPDM4)

#define CPDM3                    3
#define CPDM3_MSK               (1 << CPDM3)
#define CPDM3_ENABLE            (1 << CPDM3)
#define CPDM3_DISABLE           (0 << CPDM3)

#define CPDM2                    2
#define CPDM2_MSK               (1 << CPDM2)
#define CPDM2_ENABLE            (1 << CPDM2)
#define CPDM2_DISABLE           (0 << CPDM2)

#define CPDM1                    1
#define CPDM1_MSK               (1 << CPDM1)
#define CPDM1_ENABLE            (1 << CPDM1)
#define CPDM1_DISABLE           (0 << CPDM1)

#define CPDM0                    0
#define CPDM0_MSK               (1 << CPDM0)
#define CPDM0_ENABLE            (1 << CPDM0)
#define CPDM0_DISABLE           (0 << CPDM0)

#define CPDM_DISABLE    0xe0


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define CMP_Enable()			     (MCCN0 |= ENCMP_ENABLE)
#define CMP_Disable()			     (MCCN0 &= (~ENCMP_MSK))
#define CMP_InShort(Sel)		    	(MCCN0 = ((MCCN0 & (~CPIS_MSK)) | Sel))
#define CMP_OutInverse(Sel)          (MCCN0 = ((MCCN0 & (~CPOR_MSK)) | Sel))
#define CMP_OutputReverse()			(MCCN0 |= CPOR_INVERSE)
#define CMP_OutputNormal()			(MCCN0 &= (~CPOR_MSK))
#define CMP_MODESel(Sel)           (MCCN0 = ((MCCN0 & (~CMPHS_MSK)) | Sel))
#define CMP_NormlMode()			  (MCCN0 |= CMPHS_NORMAL)
#define CMP_LowPowerMode()			  (MCCN0 &= (~CMPHS_MSK))
#define CMP_2usLPFEnable()			(MCCN0 |= CPDF_ENABLE)
#define CMP_2usLPFDisable()			(MCCN0 &= (~CPDF_MSK))
#define	CMP_OutputSelect(sel)			(MCCN0 = ((MCCN0 & (~ENRCC_MSK)) | sel))

#define CMP_CMPResult()                  (MCCN0 & CMPO_MSK)
#define CMP_CMPOIsPGN()					(MCCN0 & CMPO_PGN)
#define CMP_CMPOIsNGP()					(~(MCCN0 | CMPO_NGP))
#define CMP_CPRLShort()					(MCCN1 |= CPRL_SHORT)
#define CMP_CPRLOpen()					(MCCN1 &= (~CPRL_MSK))
#define CMP_RLO_VrefSel(sel)			(MCCN1 = ((MCCN1 & (~CPRH_MSK)) | sel))
#define CMP_PInput(sel)						(MCCN1 = ((MCCN1 & (~CPPS_MSK)) | sel))
#define CMP_NInput(sel)						(MCCN1 = ((MCCN1 & (~CPNS_MSK)) | sel))

#define CMP_R_DASel(Sel)				(MCCN2 = ((MCCN2 & (~CPDA_MSK)) | Sel))

#define CMP_CPDM4Enable()				(MCCN3 |= CPDM4_ENABLE)
#define CMP_CPDM4Disable()				(MCCN3 &= (~CPDM4_MSK))
#define CMP_CPDM3Enable()				(MCCN3 |= CPDM3_ENABLE)
#define CMP_CPDM3Disable()				(MCCN3 &= (~CPDM3_MSK))
#define CMP_CPDM2Enable()				(MCCN3 |= CPDM2_ENABLE)
#define CMP_CPDM2Disable()				(MCCN3 &= (~CPDM2_MSK))
#define CMP_CPDM1Enable()				(MCCN3 |= CPDM1_ENABLE)
#define CMP_CPDM1Disable()				(MCCN3 &= (~CPDM1_MSK))
#define CMP_CPDM0Enable()				(MCCN3 |= CPDM0_ENABLE)
#define CMP_CPDM0Disable()				(MCCN3 &= (~CPDM0_MSK))
#define	CMP_CPDMSet(set)				(MCCN3 = ((MCCN3 & 0xe0) | set))
#define	CMP_CPDMALLCLR()				     (MCCN3 &= 0xe0)


#define CMP_INT_Enable()                (INTE2 |= CMPIE_ENABLE)
#define CMP_INT_Disable()             (INTE2 &= (~CMPIE_MSK))
#define CMP_INT_IsFlag()              (INTF2 & CMPIF_SET)
#define CMP_INT_ClearFlag()           (INTF2 &= (~CMPIF_MSK))
//#define CMPIE_Enable()              (INTE2 |= CMPIE_ENABLE)
//#define CMPIE_Disable()             (INTE2 &= (~CMPIE_MSK))
//#define CMPIF_IsFlag()              (INTF2 & CMPIF_SET)
//#define CMPIF_ClearFlag()           (INTF2 &= (~CMPIF_MSK))
/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void CMP_Open( unsigned char cpps,   //CMP P Input select
           					 unsigned char cpns,   //CMP N Input select
              				 unsigned char cmphs, //CMP Work mode select
              				 unsigned char cpor,     //CMP Output reverse control
              				 unsigned char enrcc);   //CMP Output control
void CMP_RLOSet( unsigned char cprh,   //CMP RLO reference voltage source selection
           					    unsigned char cprl,   //CMP RLO  resistor(22.5R/20R) short control
              				    unsigned char cpda,   //CMP RLO  reference voltage division control
              			   	    unsigned char cpdm);  //CMP hysteresis control 
