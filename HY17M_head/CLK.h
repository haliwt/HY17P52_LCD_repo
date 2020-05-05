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

//// OSCCN0 //
#define OSCS                      6
#define OSCS_MSK                 (3 << OSCS)
//#define OSCS_XT                  (3 << OSCS)
#define OSCS_XT                  (2 << OSCS)
#define OSCS_LPO                 (1 << OSCS)
#define OSCS_HAO                 (0 << OSCS)

#define DHS                       4
#define DHS_MSK                  (3 << DHS)
#define DHS_HSCKDIV8             (3 << DHS)
#define DHS_HSCKDIV4             (2 << DHS)
#define DHS_HSCKDIV2             (1 << DHS)
#define DHS_HSCKDIV1             (0 << DHS)

#define DMS                       1
#define DMS_MSK                  (7 << DMS)
#define DMS_DHSCKDIV256          (7 << DMS)
#define DMS_DHSCKDIV128          (6 << DMS)
#define DMS_DHSCKDIV64           (5 << DMS)
#define DMS_DHSCKDIV32           (4 << DMS)
#define DMS_DHSCKDIV16           (3 << DMS)
#define DMS_DHSCKDIV8            (2 << DMS)
#define DMS_DHSCKDIV4            (1 << DMS)
#define DMS_DHSCKDIV2            (0 << DMS)

#define CPUS                      0
#define CPUS_MSK                 (1 << CPUS)
#define CPUS_DHSCK               (1 << CPUS)
#define CPUS_HSCK                (0 << CPUS)

//// OSCCN1 //
#define LCPS                      6
#define LCPS_MSK                 (1 << LCPS)
#define LCPS_XT                  (1 << LCPS)
#define LCPS_LPO                 (0 << LCPS)
 
#define DADC                      4
#define DADC_MSK                 (3 << DADC)
#define DADC_DHSCKDIV16          (3 << DADC)
#define DADC_DHSCKDIV8           (2 << DADC)
#define DADC_DHSCKDIV4           (1 << DADC)
#define DADC_DHSCKDIV2           (0 << DADC)

#define DTMB                      2
#define DTMB_MSK                 (3 << DTMB)
#define DTMB_TMBCKDIV8           (3 << DTMB)
#define DTMB_TMBCKDIV4           (2 << DTMB)
#define DTMB_TMBCKDIV2           (1 << DTMB)
#define DTMB_TMBCKDIV1           (0 << DTMB)

#define TMBS                      1
#define TMBS_MSK                 (1 << TMBS)
#define TMBS_LPCCK               (1 << TMBS)
#define TMBS_HSCK                (0 << TMBS)

//// OSCCN2 //
#define ENXT                      5
#define ENXT_MSK                 (1 << ENXT)
#define ENXT_ENABLE              (1 << ENXT)
#define ENXT_DISABLE             (0 << ENXT)

#define XTS                       3
#define XTS_MSK                  (3 << XTS)
#define XTS_16M                  (3 << XTS)
#define XTS_2M                   (2 << XTS)
#define XTS_32768                (1 << XTS)
//#define XTS_32768                (0 << XTS)

#define HAOM                      1
#define HAOM_MSK                 (3 << HAOM)
#define HAOM_17M1      	         (3 << HAOM)
#define HAOM_8M7                 (2 << HAOM)
#define HAOM_4M2	               (1 << HAOM)
#define HAOM_2M 	               (0 << HAOM)

#define ENHAO                     0
#define ENHAO_MSK                (1 << ENHAO)
#define ENHAO_ENABLE             (1 << ENHAO)
#define ENHAO_DISABLE            (0 << ENHAO)

/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
//CLK Config function for Peripherals were placed in each peripheral module individually
//CLK Config for MCU(System Clock)were declared/defined below

// Ext Oscillator //
#define CLK_XTEnable()                 (OSCCN2 |= ENXT_ENABLE)
#define CLK_XTDisable()                (OSCCN2 &= (~ENXT_MSK)) 
#define CLK_XTSelect(XTSel)            (OSCCN2 = ((OSCCN2 & (~XTS_MSK)) | XTSel))
// HAO Oscillator //
#define CLK_HAOEnable()                (OSCCN2 |= ENHAO_ENABLE)
#define CLK_HAODisable()               (OSCCN2 &= (~ENHAO_MSK)) 
#define CLK_HAOSelect(HAOSel)          (OSCCN2 = ((OSCCN2 & (~HAOM_MSK)) | HAOSel))

// System Clock Selection //
#define CLK_LPCCKSelect(LPCCKSel)      (OSCCN1 = ((OSCCN1 & (~LCPS_MSK)) | LPCCKSel))

// ADC CLK Selection //
//#define ADC_CLK_DivSelect(DADCSel)     (OSCCN1 = (OSCCN1 & (~DADC_MSK)) | DADCSel)  
#define CLK_ADCCKDivSelect(DADCSel)     (OSCCN1 = ((OSCCN1 & (~DADC_MSK)) | DADCSel))


// TMB CLK Selection //
#define CLK_TMBCKDivSelect(TMBCKDivSel)   (OSCCN1 = ((OSCCN1 & (~DTMB_MSK)) | TMBCKDivSel))
#define CLK_TMBCKSelect(TMBCKSel)         (OSCCN1 = ((OSCCN1 & (~TMBS_MSK)) | TMBCKSel))




// System Clock Selection //
#define CLK_OSCSelect(OSCSel)          (OSCCN0 = ((OSCCN0 & (~OSCS_MSK)) | OSCSel))
#define CLK_DHSCKSelect(DHSCKSel)      (OSCCN0 = ((OSCCN0 & (~DHS_MSK)) | DHSCKSel))
#define CLK_DMSCKSelect(DMSCKSel)      (OSCCN0 = ((OSCCN0 & (~DMS_MSK)) | DMSCKSel))
#define CLK_CPUCKSelect(CPUCKSel)      (OSCCN0 = ((OSCCN0 & (~CPUS_MSK)) | CPUCKSel))
#define CLK_CPUCK_Sel(DHSdiv,CPUCKsel) (OSCCN0 = (OSCCN0 &(~(DHS_MSK | CPUS_MSK))) | DHSdiv | CPUCKsel)






/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
void CLK_CPUCKOpen(unsigned char haom,				//HAO Frequence Selection
                                       unsigned char oscs,       		   //HS_CK Selection 
                                       unsigned char dhsck,			     //DHS_CK Selection                                          
                                       unsigned char cpuck);               //CPU_CK Source Selection 
