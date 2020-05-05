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
// PSTAT //
#define BOR                        7
#define BOR_MSK                   (1 << BOR)
#define BOR_BOR                   (1 << BOR)
#define BOR_CLR                   (0 << BOR)
                                        
#define PD                         6
#define PD_MSK                    (1 << PD)
#define PD_SLEEP                  (1 << PD)
#define PD_CLR                    (0 << PD)
                                        
#define TO                         5
#define TO_MSK                    (1 << TO)
#define TO_WDT                    (1 << TO)
#define TO_CLR                    (0 << TO)

#define IDL                        4
#define IDL_MSK                   (1 << IDL)
#define IDL_IDLE                  (1 << IDL)
#define IDL_CLR                   (0 << IDL)

#define RST                        3
#define RST_MSK                   (1 << RST)
#define RST_RST                   (1 << RST)
#define RST_CLR                   (0 << RST)
                                        
#define SKERR                      2
#define SKERR_MSK                 (1 << SKERR)
#define SKERR_ERR                 (1 << SKERR)
#define SKERR_CLR                 (0 << SKERR)

#define BOR2LV                     1
#define BOR2LV_MSK                (1 << BOR2LV)
#define BOR2LV_LOWVDD             (1 << BOR2LV)
#define BOR2LV_NORMAL             (0 << BOR2LV)

#define GCRstIF                    0
#define GCRstIF_MSK               (1 << GCRstIF)
#define GCRstIF_I2CRST            (1 << GCRstIF)
#define GCRstIF_CLR               (0 << GCRstIF)

// PWRCN //
#define PWRCN_CSFON                0
#define PWRCN_CSFON_MSK           (1 << PWRCN_CSFON)
#define PWRCN_CSFON_ENABLE        (1 << PWRCN_CSFON)
#define PWRCN_CSFON_DISABLE       (0 << PWRCN_CSFON)

// CSFCN0 //
#define SKRST                      7
#define SKRST_MSK                 (1 << SKRST)
#define SKRST_ENABLE              (1 << SKRST)
#define SKRST_DISABLE             (0 << SKRST)

// CSFCN1 //
#define MCLR                       7
#define MCLR_MSK                  (1 << MCLR)
#define MCLR_ENABLE               (1 << MCLR)
#define MCLR_DISABLE              (0 << MCLR)

#define BORTH                      2
#define BORTH_MSK                 (7 << BORTH)
#define BORTH_4V0                 (7 << BORTH)
#define BORTH_3V65                (6 << BORTH)
#define BORTH_3V0                 (5 << BORTH)
#define BORTH_2V75                (4 << BORTH)
#define BORTH_2V5                 (3 << BORTH)
#define BORTH_2V2                 (2 << BORTH)
#define BORTH_2V0                 (1 << BORTH)
#define BORTH_1V7                 (0 << BORTH)

#define BORS                       1
#define BORS_MSK                  (1 << BORS)
#define BORS_RST                  (1 << BORS)
#define BORS_INT                  (0 << BORS)

#define ENBOR2                     0
#define ENBOR2_MSK                (1 << ENBOR2)
#define ENBOR2_ENABLE             (1 << ENBOR2)
#define ENBOR2_DISABLE            (0 << CSENBOR2FCN1_BORS)

// OSCCN1 //
#define CCOPT                      7
#define CCOPT_MSK                 (1 << CCOPT)
#define CCOPT_ENABLE              (1 << CCOPT)
#define CCOPT_DISABLE             (0 << CCOPT)


/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define CCOPT_Enable()                  (OSCCN1 |= CCOPT_ENABLE)			//FOR C COMPILE!! MUST ENABLE!
#define CSFON_Enable()                  (PWRCN |= PWRCN_CSFON_ENABLE)
#define CSFON_Disable()                  (PWRCN &= (~PWRCN_CSFON_MSK))

#define SKRST_Enable()					 (CSFCN0 |= SKRST_ENABLE)
#define SKRST_Disable()					 (CSFCN0 &= (~SKRST_MSK))

#define ENBOR2_Enable()                 (CSFCN1 |= ENBOR2_ENABLE)
#define ENBOR2_Disable()                (CSFCN1 &= (~ENBOR2_MSK))
#define BOR2_RSTMode()                 (CSFCN1 |= BORS_RST)
#define BOR2_INTMode()                (CSFCN1 &= (~BORS_MSK))
#define BOR_THSelect(sel)                 (CSFCN1 = ((CSFCN1 & (~BORTH_MSK)) | sel))
#define MCLR_Enable()					 (CSFCN1 |= MCLR_ENABLE)
#define MCLR_Disable()					 (CSFCN1 &= (~MCLR_MSK))


#define Sleep()                         __asm__ ("SLP")   //Sleep Mode
#define Idle()                          __asm__ ("IDLE")  //Idle Mode
#define NOP()                           __asm__ ("NOP")  //NOP Mode
#define SYS_ReadSKERR()								 (PSTAT&SKERR_ERR)
#define SYS_ReadBOR()							     (PSTAT&BOR_BOR)	
#define SYS_ReadBOR2LV()							 (PSTAT&BOR2LV_LOWVDD)	
#define SYS_ReadIDLE()								 (PSTAT&IDL_IDLE)	
#define SYS_ReadSLEEP()								 (PSTAT&PD_SLEEP)
#define SYS_ReadWDT()								   (PSTAT&TO_WDT)	
#define SYS_ReadRST()                  (PSTAT&RST_RST)
#define SYS_ReadI2CGCR()               (PSTAT&GCRstIF_I2CRST)

#define SYS_ClearBOR()								 (PSTAT &=(~BOR_MSK))
#define SYS_ClearSLEEP()							 (PSTAT &=(~PD_MSK))
#define SYS_ClearWDT()								 (PSTAT &=(~TO_MSK))
#define SYS_ClearIDLE()								 (PSTAT &=(~IDL_MSK))
#define SYS_ClearSKERR()							 (PSTAT &=(~SKERR_MSK))

/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void PT10_HWResetEnable(void);

