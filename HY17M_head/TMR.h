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

// TB1CN0 //
#define ENTB1                           7
#define ENTB1_MSK                      (1<<ENTB1)
#define ENTB1_ENABLE                   (1<<ENTB1)                           
#define ENTB1_DISABLE                  (0<<ENTB1)

#define TB1M                            5
#define TB1M_MSK                       (3<<TB1M)
#define TB1M_16bit                     (0<<TB1M)
#define TB1M_17bit                     (1<<TB1M)
#define TB1M_2_8bit                    (2<<TB1M)
#define TB1M_8_8bit                    (3<<TB1M)

#define TB1RT                           3
#define TB1RT_MSK                      (3<<TB1RT) 
#define TB1RT_LogicH                   (0<<TB1RT)
#define TB1RT_CP11                     (3<<TB1RT) 

#define TB1CL                           2
#define TB1CL_MSK                      (1<<TB1CL)
#define TB1CL_NORMAL                   (0<<TB1CL)
#define TB1CL_CLEAR                    (1<<TB1CL)

#define PWMO1                           1
#define PWMO1_MSK                      (1<<PWMO1)
#define PWMO1_DISABLE                  (0<<PWMO1)
#define PWMO1_OUTPUT                   (1<<PWMO1)

#define PWMO0                           0
#define PWMO0_MSK                      (1<<PWMO0)
#define PWMO0_DISABLE                  (0<<PWMO0)
#define PWMO0_OUTPUT                   (1<<PWMO0)

// TB1CN1 //
#define PA1IV                           7
#define PA1IV_MSK                      (1<<PA1IV)
#define PA1IV_INVER                    (0<<PA1IV)
#define PA1IV_NORMAL                   (1<<PA1IV)

#define PA0IV                           3
#define PA0IV_MSK                      (1<<PA0IV)
#define PA0IV_INVER                    (0<<PA0IV)
#define PA0IV_NORMAL                   (1<<PA0IV)

#define PWMA1                           4
#define PWMA1_MSK                      (7<<PWMA1)
//#define PWMA1_PWM7O                  (7<<PWMA1)
#define PWMA1_PWM7O                    (6<<PWMA1)
#define PWMA1_PWM6O                    (5<<PWMA1)
#define PWMA1_PWM5O                    (4<<PWMA1)
#define PWMA1_PWM4O                    (3<<PWMA1)
#define PWMA1_PWM3O                    (2<<PWMA1)
#define PWMA1_PWM2O                    (1<<PWMA1)
#define PWMA1_PWM1O                    (0<<PWMA1)

#define PWMA0                           0
#define PWMA0_MSK                      (7<<PWMA0)
//#define PWMA0_PWM7O                  (7<<PWMA0)
#define PWMA0_PWM7O                    (6<<PWMA0)
#define PWMA0_PWM6O                    (5<<PWMA0)
#define PWMA0_PWM5O                    (4<<PWMA0)
#define PWMA0_PWM4O                    (3<<PWMA0)
#define PWMA0_PWM3O                    (2<<PWMA0)
#define PWMA0_PWM2O                    (1<<PWMA0)
#define PWMA0_PWM1O                    (0<<PWMA0)

// TC1CN0 //
#define TC1S                            5
#define TC1S_MSK                       (3<<TC1S)
#define TC1S_TBI0                      (0<<TC1S) 
#define TC1S_TBI1                      (1<<TC1S)
#define TC1S_LSCK                      (2<<TC1S)
#define TC1S_OPC                       (3<<TC1S)
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

#define TB1Enable()             (TB1CN0 |= ENTB1_ENABLE)
#define TB1Disable()            (TB1CN0 &= ~(ENTB1_MSK))
#define TB1_ModeSelect(Sel)     (TB1CN0 =  (TB1CN0 & (~TB1M_MSK)) | (Sel))
#define TB1_TRIG_MODE(Sel)      (TB1CN0 =  (TB1CN0 & (~TB1RT_MSK)) | (Sel))
#define TB1_ClearTMB1()            (TB1CN0 |=  TB1CL_CLEAR )
#define TB1_PWMO1(Sel)          (TB1CN0 =  (TB1CN0 & (~PWMO1_MSK )) | (Sel)) 
#define TB1_PWMO0(Sel)          (TB1CN0 =  (TB1CN0 & (~PWMO0_MSK )) | (Sel))

#define TB1_PWM1ModeSelect(Sel)   (TB1CN1 =   (TB1CN1 &  (~PWMA1_MSK)) | (Sel))
#define TB1_PWM0ModeSelect(Sel)   (TB1CN1 =   (TB1CN1 &  (~PWMA0_MSK)) | (Sel))
#define TB1_PWM1_PHASE(Sel)     (TB1CN1 =   (TB1CN1 &  (~PA1IV_MSK)) | (Sel))
#define TB1_PWM0_PHASE(Sel)     (TB1CN1 =   (TB1CN1 &  (~PA0IV_MSK)) | (Sel))
#define TB1_TB1C0HSet(Set)     (TB1C0H =  Set)
#define TB1_TB1C0LSet(Set)     (TB1C0L =  Set)
#define TB1_TB1C1HSet(Set)     (TB1C1H =  Set)
#define TB1_TB1C1HSet(Set)     (TB1C1H =  Set)
#define TB1_TB1C2HSet(Set)     (TB1C2H =  Set)
#define TB1_TB1C2HSet(Set)     (TB1C2H =  Set)

#define TB1_TC1Select(Set)      (TC1CN0 = TC1CN0 &  (~TC1S_MSK)) | (Sel))

void TMA_Open(unsigned char ck, unsigned char cks,unsigned char tma_cmp);

void TMB_Open(unsigned char ck,
						  unsigned char cks,
						  unsigned char mode,
						  unsigned char trig_mode);
						  
void TB1C0Set(unsigned int TMB);
void TB1C1Set(unsigned int TMB);
void TB1C2Set(unsigned int TMB);