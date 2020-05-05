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
// WDTCN //
#define ENBZ                       7
#define ENBZ_MSK                  (1 << ENBZ)
#define ENBZ_ENABLE               (1 << ENBZ)
#define ENBZ_DISABLE              (0 << ENBZ)

#define BZS                        6
#define BZS_MSK                   (1 << BZS)
#define BZS_LPCCK                 (1 << BZS)
#define BZS_LSCK                  (0 << BZS)

#define DBZ                        4
#define DBZ_MSK                   (3 << DBZ)
#define DBZ_DZCKDIV16             (3 << DBZ)
#define DBZ_DZCKDIV8              (2 << DBZ)
#define DBZ_DZCKDIV4              (1 << DBZ)
#define DBZ_DZCKDIV2              (0 << DBZ)

#define ENWDT                      3
#define ENWDT_MSK                 (1 << ENWDT)
#define ENWDT_ENABLE              (1 << ENWDT)
#define ENWDT_DISABLE             (0 << ENWDT)

#define DWDT                       0
#define DWDT_MSK                  (7 << DWDT)
#define DWDT_WDTCKDIV16384        (0 << DWDT)
#define DWDT_WDTCKDIV8192         (1 << DWDT)
#define DWDT_WDTCKDIV4096         (2 << DWDT)
#define DWDT_WDTCKDIV2048         (3 << DWDT)
#define DWDT_WDTCKDIV64           (4 << DWDT)
#define DWDT_WDTCKDIV32           (5 << DWDT)
#define DWDT_WDTCKDIV16           (6 << DWDT)
#define DWDT_WDTCKDIV8            (7 << DWDT)

/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define BZ_Enable()                    (WDTCN |=  ENBZ_ENABLE)
#define BZ_Disable()                   (WDTCN &=  ~ENBZ_MSK)
#define BZ_BZCKSelect(Sel)             (WDTCN = (WDTCN & (~DBZ_MSK)) | Sel)
#define BZ_CLKSelect(Sel)              (WDTCN = (WDTCN & (~BZS_MSK)) | Sel)

#define WDT_Enable()                   (WDTCN |=  ENWDT_ENABLE)
#define WDT_WDTCKDivSelect(Sel)        (WDTCN = (WDTCN & (~DWDT_MSK)) | Sel) 

#define WDT_Clear()						__asm__ ("CWDT")   //CLEAR WDT COUNTER

/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void WDT_Open(unsigned char wdts);      //Configure WDT overflow time
