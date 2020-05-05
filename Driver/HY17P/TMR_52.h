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
// TMA1CN //
#define ENTMA1                           7
#define ENTMA1_MSK                      (1 << ENTMA1)
#define ENTMA1_ENABLE                   (1 << ENTMA1)
#define ENTMA1_DISABLE                  (0 << ENTMA1)
                                        
#define TMACL1                           6
#define TMACL1_MSK                      (1 << TMACL1)
#define TMACL1_NORMAL                   (0 << TMACL1)
#define TMACL1_CLEAR                    (1 << TMACL1)

#define TMAS1                            5
#define TMAS1_MSK                       (1 << TMAS1)
#define TMAS1_DMSCK                     (0 << TMAS1)
#define TMAS1_LPCCK                     (1 << TMAS1)

#define DTMA1                             2
#define DTMA1_MSK                        (7 << DTMA1)
#define DTMA1_TMA1CKDIV2                 (0 << DTMA1)
#define DTMA1_TMA1CKDIV4                 (1 << DTMA1)
#define DTMA1_TMA1CKDIV8                 (2 << DTMA1)
#define DTMA1_TMA1CKDIV16                (3 << DTMA1)
#define DTMA1_TMA1CKDIV32                (4 << DTMA1)
#define DTMA1_TMA1CKDIV64                (5 << DTMA1)
#define DTMA1_TMA1CKDIV128               (6 << DTMA1)
#define DTMA1_TMA1CKDIV256               (7 << DTMA1)

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
//CLK Config function for Peripherals were placed in each peripheral module individually
//CLK Config for MCU(System Clock)were declared/defined below

#define TMA1Enable()            (TMA1CN |= ENTMA1_ENABLE)
#define TMA1Disable()           (TMA1CN &= ~(ENTMA1_MSK))
#define TMA1ClearSet()          (TMA1CN |= TMACL1_CLEAR)
#define TMA1_CLKSelect(Sel)     (TMA1CN =  (TMA1CN & (~TMAS1_MSK)) | (Sel))
#define TMA1_CLKDiv(Sel)        (TMA1CN =  (TMA1CN & (~DTMA1_MSK)) | (Sel))

#define TMA1_CompSet(Set)       (TMA1C=Set)
#define TMA1_ClearTMA1()        (TMA1R=0)
