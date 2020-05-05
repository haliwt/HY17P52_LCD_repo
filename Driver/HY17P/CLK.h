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

//// OSCCN0 //
#define OSCS                      6
#define OSCS_MSK                 (3 << OSCS)
#define OSCS_XT                  (3 << OSCS)
//#define OSCS_XT                (2 << OSCS)
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

#if defined(USE_HY17P56_2M) || defined(USE_HY17P56_4M) || defined(USE_HY17P56_8M)  //FOR P56
#define DADC_DHSCKDIV32          (3 << DADC)
#define DADC_DHSCKDIV16          (2 << DADC)
#define DADC_DHSCKDIV8           (1 << DADC)
#define DADC_DHSCKDIV4           (0 << DADC)

#else    //FOR P48/P52/P58
 // USE_HY17P52_2M || USE_HY17P52_4M || USE_HY17P52_8M
 // USE_HY17P48_2M || USE_HY17P48_4M || USE_HY17P48_8M
 // USE_HY17P58_2M || USE_HY17P58_4M || USE_HY17P58_8M
#define DADC_DHSCKDIV16       (3 << DADC)
#define DADC_DHSCKDIV8         (2 << DADC)
#define DADC_DHSCKDIV4         (1 << DADC)
#define DADC_DHSCKDIV2         (0 << DADC)
#endif

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

#define LCDS                      0
#define LCDS_MSK                 (1 << LCDS)
#define LCDS_LSCK                (1 << LCDS)
#define LCDS_LPCCK               (0 << LCDS)

//// OSCCN2 //


#define DLCD                      6
#define DLCD_MSK                 (3 << DLCD)
#define DLCD_LCDCKDIV16          (3 << DLCD)
#define DLCD_LCDCKDIV8           (2 << DLCD)
#define DLCD_LCDCKDIV4           (1 << DLCD)
#define DLCD_LCDCKDIV2           (0 << DLCD)

#define ENXT                      5
#define ENXT_MSK                 (1 << ENXT)
#define ENXT_ENABLE              (1 << ENXT)
#define ENXT_DISABLE             (0 << ENXT)

#define XTS                       3
#define XTS_MSK                  (3 << XTS)
#define XTS_16M                  (3 << XTS)
#define XTS_2M                   (2 << XTS)
//#define XTS_32768              (1 << XTS)
#define XTS_32768                (0 << XTS)

#define HAOM                      1
#define HAOM_MSK                 (3 << HAOM)
#define HAOM_7834KHZ             (3 << HAOM)
//#define HAOM_                  (2 << HAOM)
#define HAOM_3686KHZ             (1 << HAOM)
#define HAOM_1843KHZ             (0 << HAOM)

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
// LCD CLK Selection //
#define CLK_LCDCKDivSelect(LCDCKSel)      (OSCCN2 = ((OSCCN2 & (~DLCD_MSK)) | LCDCKSel))
#define CLK_LCDCKSelect(LCDCKSel)         (OSCCN1 = ((OSCCN1 & (~LCDS_MSK)) | LCDCKSel))

// System Clock Selection //
#define CLK_LPCCKSelect(LPCCKSel)      (OSCCN1 = ((OSCCN1 & (~LCPS_MSK)) | LPCCKSel))


// ADC CLK Selection //
//#define ADC_CLK_DivSelect(DADCSel)     (OSCCN1 = (OSCCN1 & (~DADC_MSK)) | DADCSel)  
#define CLK_ADCCKDivSelect(ADCDivSel)     (OSCCN1 = ((OSCCN1 & (~DADC_MSK)) | ADCDivSel))
//ä¸Šé¢?½æ•¸ç­‰æ ¡?¼ä??¢ï?ä¸Šé¢å·²ç??¨ADC.H å®šç¾©??

// TMB CLK Selection //
#define CLK_TMBCKDivSelect(TMBCKDivSel)   (OSCCN1 = ((OSCCN1 & (~DTMB_MSK)) | TMBCKDivSel))
#define CLK_TMBCKSelect(TMBCKSel)         (OSCCN1 = ((OSCCN1 & (~TMBS_MSK)) | TMBCKSel))




// System Clock Selection //
#define CLK_OSCSelect(OSCSel)          (OSCCN0 = ((OSCCN0 & (~OSCS_MSK)) | OSCSel))
#define CLK_DHSCKSelect(DHSCKSel)      (OSCCN0 = ((OSCCN0 & (~DHS_MSK)) | DHSCKSel))
#define CLK_DMSCKSelect(DMSCKSel)      (OSCCN0 = ((OSCCN0 & (~DMS_MSK)) | DMSCKSel))
#define CLK_CPUCKSelect(CPUCKSel)      (OSCCN0 = ((OSCCN0 & (~CPUS_MSK)) | CPUCKSel))
#define CLK_CPUCK_Sel(DHSdiv,CPUCKsel)  (OSCCN0 = (OSCCN0 &(~(DHS_MSK | CPUS_MSK))) | DHSdiv | CPUCKsel)






/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/

////! @name    CLK_GPIO_Mux
////! @brief   Configure GPIO Port to Peripheral usage.
////!          Using when PT2.0 or PT2.1 was config as GPIO,that is, Input Pull High or Output Mode
////! @param   None
////! @return  None
//// GPIO Multiplexing //
//void CLK_GPIO_Mux();
////! @name    CLK_CPUCKInit
////! @brief   Reset CPU CLK as Default status and Configure it as required
////! @param   CPUCKSel:
////! @param   ExtCKEn:
////! @param   SSCKDiv:
////! @return  None
//  //void CLK_CPUCKOpen(unsigned char CPUCKSel,unsigned char ExtCKEn,unsigned char HSSCKDiv);
////void CLK_CPUCKDeinit();
//void CLK_CPUCKOpen(
//unsigned char CPUCKSel,
//unsigned char ExtCKEn,
//unsigned char HSSCKDiv,
//unsigned char VXTSP,
//unsigned char oscSOURCE);