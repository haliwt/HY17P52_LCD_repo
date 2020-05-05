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
#include <INT.h>           // Interrupt Config for UART


#define TXIF                       5
#define TXIF_MSK                   (1 << TXIF)
#define TXIF_SET                   (1 << TXIF)

#define RCIF                       4
#define RCIF_MSK                   (1 << RCIF)
#define RCIF_SET                   (1 << RCIF)


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
#define PARITY_None                      (0 << PARITY)

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

#define UART_Enable()            (UR0CN |= ENSP_ENABLE)
#define UART_Disable()           (UR0CN &= ~(ENSP_MSK))
#define UART_TXEnable()         (UR0CN |= ENTX_ENABLE)
#define UART_TXDisable()        (UR0CN &= ~(ENTX_MSK))
#define UART_TX9Enable()        (UR0CN |= TX9_ENABLE)
#define UART_TX9Disable()       (UR0CN &= ~(TX9_MSK))
#define UART_TX9Data(Sel)       (UR0CN =  (UR0CN & (~TX9D_MSK)) | (Sel))
#define UART_Parity(Sel)        (UR0CN =  (UR0CN & (~PARITY_MSK)) | (Sel))
#define UART_WUEEnable()        (UR0CN |= WUE_ENABLE)
#define UART_WUEDisable()       (UR0CN &= ~(WUE_MSK))

#define UART_GetRC9D()          (UR0STA & RC9D_MSK)
#define UART_GetPERR()          (UR0STA & PERR_MSK)
#define UART_GetFERR()          (UR0STA & FERR_MSK)
#define UART_GetOERR()          (UR0STA & OERR_MSK)
#define UART_GetRCIDL()         (UR0STA & RCIDL_MSK)
#define UART_GetTRMT()          (UR0STA & TRMT_MSK)
#define UART_GetABDOVF()        (UR0STA & ABDOVF_MSK)

#define UART_CREnable()         (BA0CN = BA0CN |ENCR_ENABLE)
#define UART_CRDisable()        (BA0CN &= ~(ENCR_MSK))
#define UART_RC9Enable()        (BA0CN = BA0CN |RC9_ENABLE)
#define UART_RC9Disable()       (BA0CN &= ~(RC9_MSK))
#define UART_ADDEnable()        (BA0CN = BA0CN |ENADD_ENABLE)
#define UART_ADDDisable()       (BA0CN &= ~(ENADD_MSK))
#define UART_ABDEnable()        (BA0CN = BA0CN |ENABD_ENABLE)
#define UART_ABDDisable()       (BA0CN &= ~(ENABD_MSK))


#define UART_INT_TXEnable()        (INTE1 |= TXIE_ENABLE)
#define UART_INT_TXDisable()          (INTE1 &= (~TXIE_MSK))
#define UART_INT_RCEnable()        (INTE1 |= RCIE_ENABLE)
#define UART_INT_RCDisable()          (INTE1 &= (~RCIE_MSK))

#define UART_INT_RCIsFlag()             (INTF1 & RCIF_SET)
#define UART_INT_TXIsFlag()              (INTF1 & TXIF_SET)
#define UART_INT_RCClearFlag()        (INTF1 &= (~RCIF_MSK))
#define UART_INT_TXClearFlag()         (INTF1 &= (~TXIF_MSK))

//#define TXIE_Enable()               (INTE1 |= TXIE_ENABLE)
//#define TXIE_Disable()              (INTE1 &= (~TXIE_MSK))
//#define TXIF_IsFlag()               (INTF1 & TXIF_SET)
//#define TXIF_ClearFlag()            (INTF1 &= (~TXIF_MSK))

//#define RCIE_Enable()               (INTE1 |= RCIE_ENABLE)
//#define RCIE_Disable()              (INTE1 &= (~RCIE_MSK))
//#define RCIF_IsFlag()               (INTF1 & RCIF_SET)
//#define RCIF_ClearFlag()            (INTF1 &= (~RCIF_MSK))


void UART_Open(unsigned int  uBG0R,     // desired baud rate
               unsigned char uDataBits,       // Enable the transmission of the ninth bit and send the ninth bit data
               unsigned char uParity,              // Odd/even bit check
               unsigned char Uartxsel);          // Tx/Rc or Tx_1/Rc_1 or Tx_2/Rc_2 or Tx_3/Rc_3 selector
void UART_BGRSet(unsigned int uBG0R);


