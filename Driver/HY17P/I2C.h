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
// CFG0 //
#define GCRst                             2
#define GCRst_MSK                        (1 << GCRst)
#define GCRst_ENABLE                     (1 << GCRst)
#define GCRst_DISABLE                    (0 << GCRst)

#define ENI2CT                            1
#define ENI2CT_MSK                       (1 << ENI2CT)
#define ENI2CT_ENABLE                    (1 << ENI2CT)
#define ENI2CT_DISABLE                   (0 << ENI2CT)
                                        
#define ENI2C                             0
#define ENI2C_MSK                        (1 << ENI2C)
#define ENI2C_ENABLE                     (1 << ENI2C)
#define ENI2C_DISABLE                    (0 << ENI2C)		
							

// ACT0 //
#define SLAVE                             7
#define SLAVE_MSK                        (1 << SLAVE)
#define SLAVE_ENABLE                     (1 << SLAVE)
#define SLAVE_DISABLE                    (0 << SLAVE)

#define I2CER                             4
#define I2CER_MSK                        (1 << I2CER)
#define I2CER_ERROR                      (1 << I2CER)
#define I2CER_NORMAL                     (0 << I2CER)

#define START                             3
#define START_MSK                        (1 << START)
#define START_1                          (1 << START)
#define START_0                          (0 << START)

#define STOP                              2
#define STOP_MSK                         (1 << STOP)
#define STOP_1                           (1 << STOP)
#define STOP_0                           (0 << STOP)

#define I2CINT                            1
#define I2CINT_MSK                       (1 << I2CINT)
#define I2CINT_1                         (1 << I2CINT)
#define I2CINT_0                         (0 << I2CINT)

#define ACK                               0
#define ACK_MSK                          (1 << ACK)
#define ACK_1                            (1 << ACK)
#define ACK_0                            (0 << ACK)

// STA0 //
#define MACTF                             7
#define MACTF_MSK                        (1 << MACTF)
#define MACTF_ENABLE                     (1 << MACTF)
#define MACTF_DISABLE                    (0 << MACTF)

#define SACTF                             6
#define SACTF_MSK                        (1 << SACTF)
#define SACTF_ENABLE                     (1 << SACTF)
#define SACTF_DISABLE                    (0 << SACTF)

#define RDBF                              5
#define RDBF_MSK                         (1 << RDBF)
#define RDBF_1                           (1 << RDBF)
#define RDBF_0                           (0 << RDBF)

#define RWF                               4
#define RWF_MSK                          (1 << RWF)
#define RWF_1                            (1 << RWF)
#define RWF_0                            (0 << RWF)

#define DFF                               3
#define DFF_MSK                          (1 << DFF)
#define DFF_1                            (1 << DFF)
#define DFF_0                            (0 << DFF)

#define ACKF                              2
#define ACKF_MSK                         (1 << ACKF)
#define ACKF_1                           (1 << ACKF)
#define ACKF_0                           (0 << ACKF)

#define GCF                               1
#define GCF_MSK                          (1 << GCF)
#define GCF_1                            (1 << GCF)
#define GCF_0                            (0 << GCF)

#define ARBF                              0
#define ARBF_MSK                         (1 << ARBF)
#define ARBF_1                           (1 << ARBF)
#define ARBF_0                           (0 << ARBF)

// TOC0 //
#define I2CTF                             7
#define I2CTF_MSK                        (1 << I2CTF)
#define I2CTF_TIMEOUT                    (1 << I2CTF)
#define I2CTF_DNORMAL                    (0 << I2CTF)

#define DI2C                              4
#define DI2C_MSK                         (7 << DI2C)
#define DI2C_CPUCKDIV128                 (7 << DI2C)
#define DI2C_CPUCKDIV64                  (6 << DI2C)
#define DI2C_CPUCKDIV32                  (5 << DI2C)
#define DI2C_CPUCKDIV16                  (4 << DI2C)
#define DI2C_CPUCKDIV8                   (3 << DI2C)
#define DI2C_CPUCKDIV4                   (2 << DI2C)
#define DI2C_CPUCKDIV2                   (1 << DI2C)
#define DI2C_CPUCKDIV1                   (0 << DI2C)

#define I2CTLT                            0
#define I2CTLT_MSK                       (15 << I2CTLT)
#define I2CTLT_CLKPS16                   (15 << I2CTLT)
#define I2CTLT_CLKPS15                   (14 << I2CTLT)
#define I2CTLT_CLKPS14                   (13 << I2CTLT)
#define I2CTLT_CLKPS13                   (12 << I2CTLT)
#define I2CTLT_CLKPS12                   (11 << I2CTLT)
#define I2CTLT_CLKPS11                   (10 << I2CTLT)
#define I2CTLT_CLKPS10                   (9 << I2CTLT)
#define I2CTLT_CLKPS9                    (8 << I2CTLT)
#define I2CTLT_CLKPS8                    (7 << I2CTLT)
#define I2CTLT_CLKPS7                    (6 << I2CTLT)
#define I2CTLT_CLKPS6                    (5 << I2CTLT)
#define I2CTLT_CLKPS5                    (4 << I2CTLT)
#define I2CTLT_CLKPS4                    (3 << I2CTLT)
#define I2CTLT_CLKPS3                    (2 << I2CTLT)
#define I2CTLT_CLKPS2                    (1 << I2CTLT)
#define I2CTLT_CLKPS0                    (0 << I2CTLT)
/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
//CLK Config function for Peripherals were placed in each peripheral module individually
//CLK Config for MCU(System Clock)were declared/defined below

//  I2C0  //
#define I2C0Enable()               (CFG0 |= ENI2C_ENABLE)
#define I2C0Disable()              (CFG0 &= ~(ENI2C_MSK))
#define I2C0_TimeOutEnable()       (CFG0 |= ENI2CT_ENABLE)
#define I2C0_TimeOutDisable()      (CFG0 &= ~(ENI2CT_MSK))
#define I2C0_GCRstEnable()         (CFG0 |= GCRst_ENABLE)
#define I2C0_GCRstDisable()        (CFG0 &= ~(GCRst_MSK))

#define I2C0_SlaveModeEnable()     (ACT0 |= SLAVE_ENABLE)
#define I2C0_SlaveModeDisable()    (ACT0 &= ~(SLAVE_MSK)

#define I2C0_SCLCLKSet(Set)        (CRG0 = Set)
#define I2C0_TimeOutCLKSelect(Sel) (TOC0 = (TOC0 & (~DI2C_MSK)) | Sel)
#define I2C0_TimeOutCYCSelect(Sel) (TOC0 = (TOC0 & (~I2CTLT_MSK)) | Sel)

#define I2C0_SlaveAddSet(Add)      (SID0 = Add | 0x01)
#define I2C0_STAState()            (STA0)
#define I2C0_SPIA(Sel)             (ACT0 = (ACT0 & 0xf0) | Sel)

#define I2C0_SendData(Sel)         (TDB0= Sel)

//  I2C2  //
#define I2C2Enable()               (CFG2 |= ENI2C_ENABLE)
#define I2C2Disable()              (CFG2 &= ~(ENI2C_MSK))
#define I2C2_TimeOutEnable()       (CFG2 |= ENI2CT_ENABLE)
#define I2C2_TimeOutDisable()      (CFG2 &= ~(ENI2CT_MSK))
#define I2C2_GCRstEnable()         (CFG2 |= GCRst_ENABLE)
#define I2C2_GCRstDisable()        (CFG2 &= ~(GCRst_MSK))

#define I2C2_SlaveModeEnable()     (ACT2 |= SLAVE_ENABLE)
#define I2C2_SlaveModeDisable()    (ACT2 &= ~(SLAVE_MSK)

#define I2C2_SCLCLKSet(Set)        (CRG2 = Set)
#define I2C2_TimeOutCLKSelect(Sel) (TOC2 = (TOC2 & (~DI2C_MSK)) | Sel)
#define I2C2_TimeOutCYCSelect(Sel) (TOC2 = (TOC2 & (~I2CTLT_MSK)) | Sel)

#define I2C2_SlaveAddSet(Add)      (SID2 = Add | 0x01)
#define I2C2_STAState()            (STA2)
#define I2C2_SPIA(Sel)             (ACT2 = (ACT2 & 0xf0) | Sel) 

#define I2C2_SendData(Sel)         (TDB2= Sel)

