
/**************************************************************************************************|
|* Copyright 2018 Hycon Technology, Corp._Steve                                                         *|
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
// DACCN0 //
#define DANS                      4
#define DANS_MSK                 (3 << DANS) 
#define DANS_AI8                 (3 << DANS)
#define DANS_AI0                 (2 << DANS)
#define DANS_REFOI               (1 << DANS)
#define DANS_VSS                 (0 << DANS)

#define DAPS                      0
#define DAPS_MSK                 (7 << DAPS) 
#define DAPS_AI13                (7 << DAPS)
#define DAPS_AI9                 (6 << DAPS)
#define DAPS_AI7                 (5 << DAPS)
#define DAPS_AI5                 (4 << DAPS)
#define DAPS_AI4                 (3 << DAPS)
#define DAPS_AI0                 (2 << DAPS)
#define DAPS_REFOI               (1 << DAPS)
#define DAPS_VDDA                (0 << DAPS)

// DACCN1 //
#define DALH                      3
#define DALH_MSK                 (1 << DALH) 
#define DALH_ENABLE              (1 << DALH)
#define DALH_DISABLE             (0 << DALH)

#define DAOE                      1
#define DAOE_MSK                 (1 << DAOE) 
#define DAOE_ENABLE              (1 << DAOE)
#define DAOE_DISABLE             (0 << DAOE)

#define ENDA                      0
#define ENDA_MSK                 (1 << ENDA) 
#define ENDA_ENABLE              (1 << ENDA)
#define ENDA_DISABLE             (0 << ENDA)


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/

#define LADDER_DALH_Enable()            (DACCN1 |= DALH_ENABLE)
#define LADDER_DALH_Disable()           (DACCN1 &= (~DALH_MSK))
#define LADDER_DAOE_Enable()            (DACCN1 |= DAOE_ENABLE)
#define LADDER_DAOE_Disable()           (DACCN1 &= (~DAOE_MSK))
#define LADDER_ENDA_Enable()            (DACCN1 |= ENDA_ENABLE)
#define LADDER_ENDA_Disable()           (DACCN1 &= (~ENDA_MSK))

#define LADER_DASelect(DAPSel,DANSel)   (DACCN0 = ((DACCN0 & (~(DAPS_MSK | DANS_MSK))) | (DAPSel | DANSel)))

/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void DAC_Open(unsigned char vdda,					//VDDA Voltage Selection
                                       unsigned char daps,				   //DA_Vrefp source Selection 
                                       unsigned char dans,			  	  //DA_Vrefn source Selection                                           
                                       unsigned int dabit);			     //DABIT[11:0],DACO Voltage ratio