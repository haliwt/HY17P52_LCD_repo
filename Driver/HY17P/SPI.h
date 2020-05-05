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
// SSPCN0 //
#define ENSSP                            7
#define ENSSP_MSK                       (1 << ENSSP)
#define ENSSP_ENABLE                    (1 << ENSSP)
#define ENSSP_DISABLE                   (0 << ENSSP)

#define CKP                              6
#define CKP_MSK                         (1 << CKP)
#define CKP_HI                          (1 << CKP)
#define CKP_LO                          (0 << CKP)

#define CKE                              5
#define CKE_MSK                         (1 << CKE)
#define CKE_IDLE                        (1 << CKE)   //Transmit when clock changes from effective status to idle status
#define CKE_EFFECTIVE                   (0 << CKE)   //Transmit when clock changes from idle status to effective status

#define SMP                              4
#define SMP_MSK                         (1 << SMP)
#define SMP_MASTEREND                   (1 << SMP)   //Master, Sampling input data at the end
#define SMP_MASTERMID                   (0 << SMP)   //Master, Sampling input data in the middle
#define SMP_SLAVE                       (0 << SMP)   //Slave, Users must clear SMP BIT as 0

#define SSPM                             0
#define SSPM_MSK                        (3 << SSPM)
#define SSPM_MLSCK                      (0 << SSPM)   //Master, clock source = LS_CK
#define SSPM_MCPUCK                     (1 << SSPM)   //Master, clock source = CPU_CK
#define SSPM_S3WIRE                     (2 << SSPM)   //Slave, 3wire mode
#define SSPM_S4WIRE                     (3 << SSPM)   //Slave, 4wire mode

// SSPSTA0 //
#define SSPBUY                           7                     //only for data transmission use
#define SSPBUY_MSK                      (1 << SSPBUY)
#define SSPBUY_TRANSMITTING             (1 << SSPBUY)   //The data is still in transmitting status
#define SSPBUY_NOCOLLISION              (0 << SSPBUY)   //No collision

#define SSPOV                            6
#define SSPOV_MSK                       (1 << SSPOV)
#define SSPOV_OVERFLOW                  (1 << SSPOV)
#define SSPOV_NOOVERFLOW                (0 << SSPOV)

#define BF                               0
#define BF_MSK                          (1 << BF)
#define BF_FULL                         (1 << BF)   //Reception accomplished, SSPBUF is full
#define BF_EMPTY                        (0 << BF)   //Reception not accomplished, SSPBUF is empty
/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define SPI0_Enable()                    (SSPCN0 |= ENSSP_ENABLE)
#define SPI0_Disable()                   (SSPCN0 &= (~SSPEN_MSK))

#define SPI0_PolarityConfig(Sel)      (SSPCN0 = (SSPCN0 & (~CKP_MSK) | Sel))
#define SPI0_SendConfig(Sel)          (SSPCN0 = (SSPCN0 & (~CKE_MSK) | Sel))
#define SPI0_SampleConfig(Sel)        (SSPCN0 = (SSPCN0 & (~SMP_MSK) | Sel))
#define SPI0_ModeSelect(Sel)          (SSPCN0 = (SSPCN0 & (~SSPM_MSK) | Sel))
#define SPI0_BUYCheck()               (SSPSTA0 & SSPBUY_TRANSMITTING)
#define SPI0_BFCheck()                (SSPSTA0 & BF_FULL)
#define SPI0_POVCheck()              (SSPSTA0 & SSPOV_OVERFLOW)
#define SPI0_ClearPOV()               (SSPSTA0 &= (~SSPOV_MSK))

void UART0_BGRSet(unsigned int BGR);


