/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
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
#include <ADC.h>


// PWRCN //
#define ENBGR                      7
#define ENBGR_MSK                 (1 << ENBGR)
#define ENBGR_ENABLE              (1 << ENBGR)
#define ENBGR_DISABLE             (0 << ENBGR)

#define LDOC                       4
#define LDOC_MSK                  (7 << LDOC)
#define LDOC_5V0                  (7 << LDOC)
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

//AD1CN1//
#define REFOS                      3
#define REFOS_MSK                 (3 << REFOS)
#define REFOS_3V0                 (3 << REFOS)
#define REFOS_2V4                 (2 << REFOS)
#define REFOS_2V0                 (1 << REFOS)
#define REFOS_1V2                 (0 << REFOS)

//AD1CN5//
#define LDOPL                      4                
#define LDOPL_MSK                 (1 << LDOPL)
#define LDOPL_ENABLE              (1 << LDOPL)
#define LDOPL_DISABLE             (0 << LDOPL)

#define ENREFO                     3                
#define ENREFO_MSK                (1 << ENREFO)
#define ENREFO_ENABLE             (1 << ENREFO)
#define ENREFO_DISABLE            (0 << ENREFO)

//MCCN1//
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
#define PWR_BGREnable()                 (PWRCN |= ENBGR_ENABLE)
#define PWR_BGRDisable()                (PWRCN &= (~ENBGR_MSK))
#define PWR_LDOEnable()                 (PWRCN |= ENLDO_ENABLE)
#define PWR_LDODisable()                (PWRCN &= (~ENLDO_MSK))
#define PWR_LDOPLEnable()               (AD1CN5 |= LDOPL_ENABLE)
#define PWR_LDOPLDisable()              (AD1CN5 &= (~LDOPL_MSK))
//#define ADC_LDOPLEnable()               (AD1CN5 |= LDOPL_ENABLE)
//#define ADC_LDOPLDisable()              (AD1CN5 &= (~LDOPL_MSK))
#define PWR_ENREFOEnable()              (AD1CN5 |= ENREFO_ENABLE)
#define PWR_ENREFODisable()             (AD1CN5 &= (~ENREFO_MSK))
#define PWR_REFOISel(Sel)                 (MCCN1 = ((MCCN1 & (~VRSEL_MSK)) | Sel))
#define PWR_VRSEL_REFOint()               (MCCN1 |= VRSEL_REFOint)
#define PWR_VRSEL_ACMint()              (MCCN1 &= (~VRSEL_MSK))
  
#define PWR_VDDASel(Sel)             (PWRCN = ((PWRCN & (~LDOC_MSK)) | Sel))
#define PWR_LDOMode(Sel)            (PWRCN = ((PWRCN & (~LDOM_MSK)) | Sel))
#define PWR_REFOSel(Sel)            (AD1CN1 = ((AD1CN1 & (~REFOS_MSK)) | Sel))


/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void PWR_VDDAOpen(unsigned char vdda);    //VDDA regulated selector
void REFOI_REFOint_Open(unsigned char refo);	//REFOint regulated selector
void REFOI_ACMint_Open(unsigned char acm);	//ACMint regulated selector

