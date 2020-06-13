/**************************************************************************************************|
|* Copyright 2016 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|*                                                                                                *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Includes                                                                                      *|
|**************************************************************************************************/
#include <hy17p52sfr.h>
#include <ADC_52.h>
#include <CLK.h>
#include <PWR.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function: ADC_Open                                                                              |
|                                                                                                  |
|  Parameters:                                                                                     |
|         ck        - [in] DADC_DHSCKDIV2   / DADC_DHSCKDIV4                                |
|                            DADC_DHSCKDIV8      / DADC_DHSCKDIV16                              |
|         cks       - [in] CPUS_DHSCK     / CPUS_HSCK                                                 |
|         inh       - [in] INP_VSS     / INP_VDDA    / INP_VDDDIV10 / INP_TS0  / INP_AI2              |
|         inl       - [in] INN_VDDA    /  INN_VCMS     / INN_AI3 / INN_VSS            |
|         vrh       - [in] VRH_VCMS       / VRH_AI2                                   |
|         vrl       - [in] VRL_AI3      / VRL_VSS                                   |
|         adgn      - [in] ADGN_1    / ADGN_4   / ADGN_16              |
|         pgagn     - [in] PGAGN_1       / PGAGN_8                                   |
|         vrgn      - [in] VREGN_DIV1    / VREGN_DIV2                                |
|         dcset     - [in] DCSET_P0       / DCSET_P1DIV8 / DCSET_P2DIV8 / DCSET_P3DIV8        |
|                          DCSET_P4DIV8  / DCSET_P5DIV8     / DCSET_P6DIV8 / DCSET_P7DIV8        |
|                          DCSET_N0  / DCSET_N1DIV8 / DCSET_N2DIV8 / DCSET_N3DIV8                              |
|                          DCSET_N4DIV8  / DCSET_N5DIV8 / DCSET_N6DIV8 / DCSET_N7DIV8                              |
|         osr       - [in] OSR_64 / OSR_128 / OSR_256 / OSR_512                                                   |
|                             OSR_1024 / OSR_2048 / OSR_4096 / OSR_8192                  |
|                             OSR_16384 / OSR_32768  / OSR_65536                             |
|         vcms     - [in] VCMS_V12       / VCMS_VDDADIV2                                   |
|                                                                                                  |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the ADC                                     |
|-------------------------------------------------------------------------------------------------*/
void ADC_Open(unsigned char ck,    //Selector of SD18 peripheral operating clock source
              unsigned char cks,   //Prescaler of SD18 peripheral operating frequency
              unsigned char inh,   //SI+ input signal selector
              unsigned char inl,   //SI- input signal selector
              unsigned char vrh,   //VR+ voltage signal selector
              unsigned char vrl,   //VR- voltage signal selector
              unsigned char adgn,  //AD amplification adjuster
              unsigned char pgagn, //PGA amplification adjuster 
              unsigned char vrgn,  //VR amplification adjuster
              unsigned char dcset, //SI+/- bias adjuster 
              unsigned char osr,  //SD18 over-sampling rate divider
              unsigned char vcms)  //VCMS signal selector
              
{
    // ADC CLK setting //
    ADC_CLK_DivSelect(ck);
    CLK_DHSCKSelect(cks);

    // ADC Init //
    ADC_VINSelect(inh,inl);             // Config ADC Input Channel
    ADC_VRINSelect(vrh,vrl);            // Config ADC Ref. Voltage Input Channel
    ADC_GainSelect(adgn,pgagn);         // Config PGA Gain and AD Gain
    ADC_VRXSelect(vrgn);                // Config Ref. Gain and DC offset
    ADC_DCSETSelect(dcset);             // Config Ref. Gain and DC offset
    ADC_OSRSelect(osr);                 // Config Over sampling ratio
    ADC_VCMSSelect(vcms); 
    
    ADC_ENACMEnable();
    ADC_Enable();
}

/*-------------------------------------------------------------------------------------------------|
|  Function: ADC_GetData                                                                           |
|                                                                                                  |
|  Parameters:                                                                                     |
|         None                                                                                     |
|                                                                                                  |
|  Returns:                                                                                        |
|         ADCData   - [in] Read the 24-bit data for ADCR                                           |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to Read the Data for ADC                                           |
|-------------------------------------------------------------------------------------------------*/
long ADC_GetData(void)
{
    long ADCData; /*typedef */
    ((char *)(&ADCData))[0] = AD1L; /* ADC low byte register*/
    ((char *)(&ADCData))[1] = AD1M; /* ADC middle byte*/
    ((char *)(&ADCData))[2] = AD1H; /* ADC high byte register */

    if (ADCData&0x800000L)  //2^(24-1) -1 = 8388607  
        ((char *)(&ADCData))[3] = 0xFF;
    else
        ((char *)(&ADCData))[3] = 0x00;
    return ADCData;
}

/**************************************************************************************************|
|*  Static Functions                                                                              *|
|**************************************************************************************************/
void ENSDRVEnable (void)
{
	PWR_CSFONEnable();
	CSFCN1 |= 0x80;
	PWR_CSFONDisable();
}
void ENSDRVDisable (void)
{
	PWR_CSFONEnable();
	CSFCN1 &= 0x7F;
	PWR_CSFONDisable();
}