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
// UR0CN //
#define ENSP                             7
#define ENSP_MSK                        (1 << ENSP)
#define ENSP_ENABLE                     (1 << ENSP)
#define ENSP_DISABLE                    (0 << ENSP)

#define ENTX                             6
#define ENTX_MSK                        (1 << ENTX)
#define ENTX_ENABLE                     (1 << ENTX)
#define ENTX_DISABLE                    (0 << ENTX)
                                        
#define TX9                              5
#define TX9_MSK                         (1 << TX9)
#define TX9_ENABLE                      (1 << TX9)
#define TX9_DISABLE                     (0 << TX9)		

#define TX9D                             4
#define TX9D_MSK                        (1 << TX9D)
#define TX9D_1                          (1 << TX9D)
#define TX9D_0                          (0 << TX9D)

#define PARITY                           3
#define PARITY_MSK                      (1 << PARITY)
#define PARITY_ODD                      (1 << PARITY)
#define PARITY_EVEN                     (0 << PARITY)

#define WUE                              0
#define WUE_MSK                         (1 << WUE)
#define WUE_ENABLE                      (1 << WUE)
#define WUE_DISABLE                     (0 << WUE)								

// UR0STA //
#define RC9D                             6
#define RC9D_MSK                        (1 << RC9D)
#define RC9D_1                          (1 << RC9D)
#define RC9D_0                          (0 << RC9D)

#define PERR                             5
#define PERR_MSK                        (1 << PERR)
#define PERR_ERR                        (1 << PERR)
#define PERR_PASS                       (0 << PERR)

#define FERR                             4
#define FERR_MSK                        (1 << FERR)
#define FERR_FAIL                       (1 << FERR)
#define FERR_PASS                       (0 << FERR)

#define OERR                             3
#define OERR_MSK                        (1 << OERR)
#define OERR_1                          (1 << OERR)
#define OERR_0                          (0 << OERR)

#define RCIDL                            2
#define RCIDL_MSK                       (1 << RCIDL)
#define RCIDL_1                         (1 << RCIDL)
#define RCIDL_0                         (0 << RCIDL)

#define TRMT                             1
#define TRMT_MSK                        (1 << TRMT)
#define TRMT_1                          (1 << TRMT)
#define TRMT_0                          (0 << TRMT)

#define ABDOVF                           0
#define ABDOVF_MSK                      (1 << ABDOVF)
#define ABDOVF_1                        (1 << ABDOVF)
#define ABDOVF_0                        (0 << ABDOVF)

// BA0CN //
#define ENCR                             3
#define ENCR_MSK                        (1 << ENCR)
#define ENCR_ENABLE                     (1 << ENCR)
#define ENCR_DISABLE                    (0 << ENCR)

#define RC9                              2
#define RC9_MSK                         (1 << RC9)
#define RC9_ENABLE                      (1 << RC9)
#define RC9_DISABLE                     (0 << RC9)

#define ENADD                            1
#define ENADD_MSK                       (1 << ENADD)
#define ENADD_ENABLE                    (1 << ENADD)
#define ENADD_DISABLE                   (0 << ENADD)

#define ENABD                            0
#define ENABD_MSK                       (1 << ENABD)
#define ENABD_ENABLE                    (1 << ENABD)
#define ENABD_DISABLE                   (0 << ENABD)
/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
//CLK Config function for Peripherals were placed in each peripheral module individually
//CLK Config for MCU(System Clock)were declared/defined below

#define UART0Enable()            (UR0CN |= ENSP_ENABLE)
#define UART0Disable()           (UR0CN &= ~(ENSP_MSK))
#define UART0_TXEnable()         (UR0CN |= ENTX_ENABLE)
#define UART0_TXDisable()        (UR0CN &= ~(ENTX_MSK))
#define UART0_TX9Enable()        (UR0CN |= ENTX9_ENABLE)
#define UART0_TX9Disable()       (UR0CN &= ~(ENTX9_MSK))
#define UART0_TX9Data(Sel)       (UR0CN =  (UR0CN & (~TX9D_MSK)) | (Sel))
#define UART0_Parity(Sel)        (UR0CN =  (UR0CN & (~PARITY_MSK)) | (Sel))
#define UART0_WUEEnable()        (UR0CN |= WUE_ENABLE)
#define UART0_WUEDisable()       (UR0CN &= ~(WUE_MSK))

#define UART0_GetRC9D()          (UR0STA & RC9D_MSK)
#define UART0_GetPERR()          (UR0STA & PERR_MSK)
#define UART0_GetFERR()          (UR0STA & FERR_MSK)
#define UART0_GetOERR()          (UR0STA & OERR_MSK)
#define UART0_GetRCIDL()         (UR0STA & RCIDL_MSK)
#define UART0_GetTRMT()          (UR0STA & TRMT_MSK)
#define UART0_GetABDOVF()        (UR0STA & ABDOVF_MSK)

#define UART0_CREnable()         (BA0CN = BA0CN |ENCR_ENABLE)
#define UART0_CRDisable()        (BA0CN &= ~(ENCR_MSK))
#define UART0_RC9Enable()        (BA0CN = BA0CN |ENRC9_ENABLE)
#define UART0_RC9Disable()       (BA0CN &= ~(ENRC9_MSK))
#define UART0_ADDEnable()        (BA0CN = BA0CN |ENADD_ENABLE)
#define UART0_ADDDisable()       (BA0CN &= ~(ENADD_MSK))
#define UART0_ABDEnable()        (BA0CN = BA0CN |ENABD_ENABLE)
#define UART0_ABDDisable()       (BA0CN &= ~(ENABD_MSK))


void UART0_BGRSet(unsigned int BGR);


