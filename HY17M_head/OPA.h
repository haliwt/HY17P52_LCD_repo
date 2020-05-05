/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                          *|
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
#include <INT.h>

// OP1CN0 //
#define OPINS                    7
#define OPINS_MSK               (1 << OPINS)
#define OPINS_SHORT             (1 << OPINS)
#define OPINS_NORMAL            (0 << OPINS)

#define OPDR                     6
#define OPDR_MSK                (1 << OPDR)
#define OPDR_NORMAL            (1 << OPDR)
#define OPDR_REVERSE           (0 << OPDR)

#define OPCS                     5
#define OPCS_MSK                (1 << OPCS)
#define OPCS_BUILT_IN           (1 << OPCS)
#define OPCS_SAMPLE             (0 << OPCS)

#define OPDFR                    4
#define OPDFR_MSK               (1 << OPDFR)
#define OPDFR_ENABLE            (1 << OPDFR)
#define OPDFR_DISABLE           (0 << OPDFR)

#define OPDEN                    3
#define OPDEN_MSK               (1 << OPDEN)
#define OPDEN_ENABLE            (1 << OPDEN)
#define OPDEN_DISABLE           (0 << OPDEN)

#define OP1OS                    1
#define OP1OS_MSK               (3 << OP1OS)
#define OP1OS_R1_O              (3 << OP1OS)
#define OP1OS_AI0               (2 << OP1OS)
#define OP1OS_DIGITAL           (1 << OP1OS)
#define OP1OS_RESERVED          (0 << OP1OS)

#define ENOP1                    0
#define ENOP1_MSK               (1 << ENOP1)
#define ENOP1_ENABLE            (1 << ENOP1)
#define ENOP1_DISABLE           (0 << ENOP1)

// OP1CN1 //
#define OPC                      6
#define OPC_MSK                 (1 << OPC)
#define OPC_HIGH                (1 << OPC)
#define OPC_LOW                 (0 << OPC)

#define OPGAINS                  4
#define OPGAINS_MSK             (3 << OPGAINS)
#define OPGAINS_32              (3 << OPGAINS)
#define OPGAINS_16              (2 << OPGAINS)
#define OPGAINS_8               (1 << OPGAINS)
#define OPGAINS_4               (0 << OPGAINS)

#define OPDIEN                   2
#define OPDIEN_MSK              (3 << OPDIEN)
#define OPDIEN_DAIO             (3 << OPDIEN)
#define OPDIEN_AI1              (2 << OPDIEN)
#define OPDIEN_REFOI            (1 << OPDIEN)
#define OPDIEN_VSS              (0 << OPDIEN)

#define OPOEG                    0
#define OPOEG_MSK               (3 << OPOEG)
#define OPOEG_LEV               (3 << OPOEG)
//#define OPOEG_LEV             (2 << OPOEG)
#define OPOEG_EDGERISE          (1 << OPOEG)
#define OPOEG_EDGEFALL          (0 << OPOEG)

// OP1INP //
#define OP1INP_VSS               7
#define OP1INP_VSS_MSK          (1 << OP1INP_VSS)
#define OP1INP_VSS_ENABLE       (1 << OP1INP_VSS)
#define OP1INP_VSS_DISABLE      (0 << OP1INP_VSS)

#define OP1INP_AI13              6
#define OP1INP_AI13_MSK         (1 << OP1INP_AI13)
#define OP1INP_AI13_ENABLE      (1 << OP1INP_AI13)
#define OP1INP_AI13_DISABLE     (0 << OP1INP_AI13)

#define OP1INP_DAOI              5
#define OP1INP_DAOI_MSK         (1 << OP1INP_DAOI)
#define OP1INP_DAOI_ENABLE      (1 << OP1INP_DAOI)
#define OP1INP_DAOI_DISABLE     (0 << OP1INP_DAOI)

#define OP1INP_REFOI             4
#define OP1INP_REFOI_MSK        (1 << OP1INP_REFOI)
#define OP1INP_REFOI_ENABLE     (1 << OP1INP_REFOI)
#define OP1INP_REFOI_DISABLE    (0 << OP1INP_REFOI)

#define OP1INP_AI10              3
#define OP1INP_AI10_MSK         (1 << OP1INP_AI10)
#define OP1INP_AI10_ENABLE      (1 << OP1INP_AI10)
#define OP1INP_AI10_DISABLE     (0 << OP1INP_AI10)

#define OP1INP_AI3               2
#define OP1INP_AI3_MSK          (1 << OP1INP_AI3)
#define OP1INP_AI3_ENABLE       (1 << OP1INP_AI3)
#define OP1INP_AI3_DISABLE      (0 << OP1INP_AI3)

#define OP1INP_AI2               1
#define OP1INP_AI2_MSK          (1 << OP1INP_AI2)
#define OP1INP_AI2_ENABLE       (1 << OP1INP_AI2)
#define OP1INP_AI2_DISABLE      (0 << OP1INP_AI2)

#define OP1INP_AI0               0
#define OP1INP_AI0_MSK          (1 << OP1INP_AI0)
#define OP1INP_AI0_ENABLE       (1 << OP1INP_AI0)
#define OP1INP_AI0_DISABLE      (0 << OP1INP_AI0)

// OP1INN1 //
#define OP1INN1_VSS              2
#define OP1INN1_VSS_MSK         (1 << OP1INN1_VSS)
#define OP1INN1_VSS_ENABLE      (1 << OP1INN1_VSS)
#define OP1INN1_VSS_DISABLE     (0 << OP1INN1_VSS)

#define OP1INN1_AI14             1
#define OP1INN1_AI14_MSK        (1 << OP1INN1_AI14)
#define OP1INN1_AI14_ENABLE     (1 << OP1INN1_AI14)
#define OP1INN1_AI14_DISABLE    (0 << OP1INN1_AI14)

#define OP1INN1_DAOI             0
#define OP1INN1_DAOI_MSK        (1 << OP1INN1_DAOI)
#define OP1INN1_DAOI_ENABLE     (1 << OP1INN1_DAOI)
#define OP1INN1_DAOI_DISABLE    (0 << OP1INN1_DAOI)

// OP1INN0 //

#define OP1INN0_OPO              7
#define OP1INN0_OPO_MSK         (1 << OP1INN0_OPO)
#define OP1INN0_OPO_ENABLE      (1 << OP1INN0_OPO)
#define OP1INN0_OPO_DISABLE     (0 << OP1INN0_OPO)

#define OP1INN0_OPOS             6
#define OP1INN0_OPOS_MSK        (1 << OP1INN0_OPOS)
#define OP1INN0_OPOS_ENABLE     (1 << OP1INN0_OPOS)
#define OP1INN0_OPOS_DISABLE    (0 << OP1INN0_OPOS)

#define OP1INN0_OPOI             5
#define OP1INN0_OPOI_MSK        (1 << OP1INN0_OPOI)
#define OP1INN0_OPOI_ENABLE     (1 << OP1INN0_OPOI)
#define OP1INN0_OPOI_DISABLE    (0 << OP1INN0_OPOI)

#define OP1INN0_R1_fb            4
#define OP1INN0_R1_fb_MSK       (1 << OP1INN0_R1_fb)
#define OP1INN0_R1_fb_ENABLE    (1 << OP1INN0_R1_fb)
#define OP1INN0_R1_fb_DISABLE   (0 << OP1INN0_R1_fb)

#define OP1INN0_REFOI            3
#define OP1INN0_REFOI_MSK       (1 << OP1INN0_REFOI)
#define OP1INN0_REFOI_ENABLE    (1 << OP1INN0_REFOI)
#define OP1INN0_REFOI_DISABLE   (0 << OP1INN0_REFOI)

#define OP1INN0_AI9              2
#define OP1INN0_AI9_MSK         (1 << OP1INN0_AI9)
#define OP1INN0_AI9_ENABLE      (1 << OP1INN0_AI9)
#define OP1INN0_AI9_DISABLE     (0 << OP1INN0_AI9)

#define OP1INN0_AI4              1
#define OP1INN0_AI4_MSK         (1 << OP1INN0_AI4)
#define OP1INN0_AI4_ENABLE      (1 << OP1INN0_AI4)
#define OP1INN0_AI4_DISABLE     (0 << OP1INN0_AI4)

#define OP1INN0_AI1              0
#define OP1INN0_AI1_MSK         (1 << OP1INN0_AI1)
#define OP1INN0_AI1_ENABLE      (1 << OP1INN0_AI1)
#define OP1INN0_AI1_DISABLE     (0 << OP1INN0_AI1)

/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define OP1_Enable()             (OP1CN0 |= ENOP1_ENABLE)
#define OP1_Disable()            (OP1CN0 &= (~ENOP1_MSK))

#define OP1_InputShort(Set)         (OP1CN0 = ((OP1CN0 & (~OPINS_MSK)) | Set))
#define OP1_IN_Short()			(OP1CN0 |= OPINS_SHORT)
#define OP1_IN_Normal()			(OP1CN0 &= (~OPINS_MSK))

#define OP1_OutputReverse(Set)   (OP1CN0 = ((OP1CN0 & (~OPDR_MSK)) | Set))
#define OP1_OUTNormal()		    (OP1CN0 |= OPDR_NORMAL)
#define OP1_OUTReverse()		(OP1CN0 &= (~OPDR_MSK))

#define OP1_10pF_AppSel(Sel)             (OP1CN0 = ((OP1CN0 & (~OPCS_MSK)) | Sel))
#define OP1_10pF_Built_In()				(OP1CN0 |= OPCS_BUILT_IN)
#define OP1_10pF_SAMPLE()				(OP1CN0 &= (~OPCS_MSK))

#define OP1_FilterEnable()				(OP1CN0 |= OPDFR_ENABLE)
#define OP1_FilterDisable()				(OP1CN0 &= (~OPDFR_MSK))
#define OP1_DigitalOutEnable()			(OP1CN0 |= OPDEN_ENABLE)
#define OP1_DigitalOutDisable()			(OP1CN0 &= (~OPDEN_MSK))

#define OP1_AnalogyOutSel(sel)		(OP1CN0 = ((OP1CN0 & (~OP1OS_MSK)) | sel))
#define OP1_GAINSelect(sel)			(OP1CN1 = ((OP1CN1 & (~OPGAINS_MSK)) | sel))
#define OP1_GAINSourceSel(sel)			(OP1CN1 = ((OP1CN1 & (~OPDIEN_MSK)) | sel))
#define OP1_INT_Trigger(sel)			(OP1CN1 = ((OP1CN1 & (~OPOEG_MSK)) | sel))

#define OP1_OPCRead(opc)              (opc = ((OP1CN1 & OPC_MSK)>> 6))

#define OP1_INPSet(Set)             (OP1INP = ((OP1INP & 0x00) | Set))
#define	OP1_INP_VSSEnable()		(OP1INP |= OP1INP_VSS_ENABLE)
#define	OP1_INP_VSSDisable()		(OP1INP &= (~OP1INP_VSS_MSK))
#define	OP1_INP_AI13Enable()		(OP1INP |= OP1INP_AI13_ENABLE)
#define	OP1_INP_AI13Disable()		(OP1INP &= (~OP1INP_AI13_MSK))
#define	OP1_INP_DAOIEnable()		(OP1INP |= OP1INP_DAOI_ENABLE)
#define	OP1_INP_DAOIDisable()		(OP1INP &= (~OP1INP_DAOI_MSK))
#define	OP1_INP_REFOIEnable()		(OP1INP |= OP1INP_REFOI_ENABLE)
#define	OP1_INP_REFOIDisable()		(OP1INP &= (~OP1INP_REFOI_MSK))
#define	OP1_INP_AI10Enable()		(OP1INP |= OP1INP_AI10_ENABLE)
#define	OP1_INP_AI10Disable()		(OP1INP &= (~OP1INP_AI10_MSK))
#define	OP1_INP_AI3Enable()		(OP1INP |= OP1INP_AI3_ENABLE)
#define	OP1_INP_AI3Disable()		(OP1INP &= (~OP1INP_AI3_MSK))
#define	OP1_INP_AI2Enable()		(OP1INP |= OP1INP_AI2_ENABLE)
#define	OP1_INP_AI2Disable()		(OP1INP &= (~OP1INP_AI2_MSK))
#define	OP1_INP_AI0Enable()		(OP1INP |= OP1INP_AI0_ENABLE)
#define	OP1_INP_AI0Disable()		(OP1INP &= (~OP1INP_AI0_MSK))

#define OP1_INN1Set(Set)          (OP1INN1 = ((OP1INN1 & 0xf8) | Set))	  // VSS / AI14 / DAOI
#define	OP1_INN_VSSEnable()		(OP1INN1 |= OP1INN1_VSS_ENABLE)
#define	OP1_INN_VSSDisable()		(OP1INN1 &= (~OP1INN1_VSS_MSK))
#define	OP1_INN_AI14Enable()		(OP1INN1 |= OP1INN1_AI14_ENABLE)
#define	OP1_INN_AI14Disable()		(OP1INN1 &= (~OP1INN1_AI14_MSK))
#define	OP1_INN_DAOIEnable()		(OP1INN1 |= OP1INN1_DAOI_ENABLE)
#define	OP1_INN_DAOIDisable()		(OP1INN1 &= (~OP1INN1_DAOI_MSK))

#define OP1_INN0Set(Set)          (OP1INN0 = ((OP1INN0 & 0x00) | Set))	   //OPO / OPOS / OPOI / R1_fb 
#define	OP1_INN_OPOEnable()		(OP1INN0 |= OP1INN0_OPO_ENABLE)
#define	OP1_INN_OPODisable()		(OP1INN0 &= (~OP1INN0_OPO_MSK))
#define	OP1_INN_OPOSEnable()		(OP1INN0 |= OP1INN0_OPOS_ENABLE)
#define	OP1_INN_OPOSDisable()		(OP1INN0 &= (~OP1INN0_OPOS_MSK))
#define	OP1_INN_OPOIEnable()		(OP1INN0 |= OP1INN0_OPOI_ENABLE)
#define	OP1_INN_OPOIDisable()		(OP1INN0 &= (~OP1INN0_OPOI_MSK))
#define	OP1_INN_R1_fbEnable()		(OP1INN0 |= OP1INN1_R1_fb_ENABLE)
#define	OP1_INN_R1_fbDisable()		(OP1INN0 &= (~OP1INN0_R1_fb_MSK))
#define	OP1_INN_REFOIEnable()		(OP1INN0 |= OP1INN0_REFOI_ENABLE)
#define	OP1_INN_REFOIDisable()		(OP1INN0 &= (~OP1INN0_REFOI_MSK))
#define	OP1_INN_AI9Enable()		(OP1INN0 |= OP1INN0_AI9_ENABLE)
#define	OP1_INN_AI9Disable()		(OP1INN0 &= (~OP1INN0_AI9_MSK))
#define	OP1_INN_AI4Enable()		(OP1INN0 |= OP1INN0_AI4_ENABLE)
#define	OP1_INN_AI4Disable()		(OP1INN0 &= (~OP1INN0_AI4_MSK))
#define	OP1_INN_AI1Enable()		(OP1INN0 |= OP1INN0_AI1_ENABLE)
#define	OP1_INN_AI1Disable()		(OP1INN0 &= (~OP1INN0_AI1_MSK))

//#define	OP1_PInput(sel)						(OP1INP = ((OP1INP & 0x00) | sel)) 
//#define	OP1_NInput0(sel)						(OP1INN0 = ((OP1INN0 & 0xF8) | sel))	//OPO / OPOS / OPOI / R1_fb 
																																	//REFOI / AI9 / AI4 / AI1	
//#define	OP1_NInput1(sel)						(OP1INN1 = ((OP1INN1 & 0x00) | sel))	// VSS / AI14 / DAOI

#define OP1_INT_Enable()              (INTE2 |= OPCIE_ENABLE)
#define OP1_INT_Disable()             (INTE2 &= (~OPCIE_MSK))
#define OP1_INT_IsFlag()              (INTF2 & OPCIF_SET)
#define OP1_INT_ClearFlag()           (INTF2 &= (~OPCIF_MSK))
//#define OPCIE_Enable()              (INTE2 |= OPCIE_ENABLE)
//#define OPCIE_Disable()             (INTE2 &= (~OPCIE_MSK))
//#define OPCIF_IsFlag()              (INTF2 & OPCIF_SET)
//#define OPCIF_ClearFlag()           (INTF2 &= (~OPCIF_MSK))

/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void OPA_Out2DigOpen(unsigned char ins,		//Input short or not
						   				unsigned char opdr,		//OPOD Reverse or not
						   				unsigned char trig);		 //OPA INT edge Select
void OPA_Out2AI0Open(unsigned char ins);		//Input short or not
void OPA_Out2R1_0Open(unsigned char ins,		//Input short or not
						   					unsigned char gain,		//OP GAIN Selection		
						   					unsigned char r1_fb);	//R1_fb souce select		   				