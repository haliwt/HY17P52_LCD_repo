 /**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|*                                                                                                *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Includes                                                                                      *|
|**************************************************************************************************/
#include <hy17m24sfr.h>
#include <ADC.h>
#include <CLK.h>
#include <PWR.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: ADC_Open                                                                      			     				   											|
|                                                                                                 																					|
|  Parameters:                                                                                                                                                         		     |	
|         cks         - [in]	DADC_DHSCKDIV16	/	DADC_DHSCKDIV8	                    	 		     									  |
|								    DADC_DHSCKDIV4	/	DADC_DHSCKDIV2      															       |
|         inp          - [in]	 INP_DAOI	/	INP_VSS	/	INP_TS1	/	INP_TS0	/	INP_REFOI	/	INP_VDDA         		         |            
|									INP_OPOI	/	INP_AI14	/	INP_AI12	/	 INP_AI10	/	INP_AI8	/	INP_AI6        		          |            	
|									INP_AI4	/	INP_AI2	/	INP_AI1	/	INP_AI0                                                                            |
|         inn           - [in]    INN_DAOI	/	INN_VSS	/	INN_TS1	/	INN_TS0	/	INN_REFOI	/	INN_VDDA         		        |
|							   	   INN_OPOI	/	INN_VDDDIV10	/	INN_AI13	/	INN_AI11	/	INN_AI9	/	INN_AI7	     |
|							       INN_AI5	/	INN_AI2	/	INN_AI1	/	INN_AI0                                                                            |
|         vrh         - [in]	VRH_REFOI	/	VRH_AI10	/	VRH_AI0	/	VRH_VDDA                                                      |
|         vrl     	   - [in]    VRL_REFOI	/	RL_AI4	/	VRL_AI2	/	VRL_VSS                                                                   |
|         adgn      - [in]    ADGN_RSVD	/	ADGN_16	/	 ADGN_8	/	 ADGN_4	/	ADGN_2	/	ADGN_1     		                 |
|								   ADGN_1DIV2	/	ADGN_1DIV4                                                                                               |
|         vrgn       - [in]    VREGN_DIV2	/	VREGN_DIV1                                                                                              |
|         dcset  	 - [in]   DCSET_N7DIV8	/	DCSET_N6DIV8	/	DCSET_N5DIV8	/	DCSET_N4DIV8       			           |
|								   DCSET_N3DIV8	/	DCSET_N2DIV8	/	DCSET_N1DIV8	/	DCSET_N0                           |
|								   DCSET_P7DIV8	/	DCSET_P6DIV8	/	DCSET_P5DIV8	/	DCSET_P4DIV8						|	
|								   DCSET_P3DIV8	/	DCSET_P2DIV8	/	DCSET_P1DIV8	/	DCSET_P0                           |
|         osr         - [in]    OSR_64	/	OSR_128	/	OSR_256	/	OSR_512	/	OSR_1024	/	OSR_2048                	    |
|								   OSR_4096	/	OSR_8192	/	OSR_16384	/	OSR_32768	/	OSR_65536                      |
|         vcms      - [in]    VCMS_REFOint	/	VCMS_ACMint                                                            	                                 |
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        
|  Description:                                                                                																					 
|         This function is used to open the ADC                     														   
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void ADC_Open( unsigned char cks,   //Prescaler of SD18 peripheral operating frequency
              unsigned char inp,   //SI+ input signal selector
              unsigned char inn,   //SI- input signal selector
              unsigned char vrh,   //VR+ voltage signal selector
              unsigned char vrl,   //VR- voltage signal selector
              unsigned char adgn,  //AD amplification adjuster
              unsigned char vrgn,  //VR amplification adjuster
              unsigned char dcset, //SI+/- bias adjuster
              unsigned char osr,  //SD18 over-sampling rate divider
              unsigned char vcms)  //VCMS signal selector

{
    // ADC CLK setting //
    CLK_ADCCKDivSelect(cks);

    // ADC Init //
    ADC_VINSelect(inp,inn);             // Config ADC Input Channel
    ADC_VRINSelect(vrh,vrl);            // Config ADC Ref. Voltage Input Channel
    ADC_GainSelect(adgn,vrgn);         // Config VRE Gain and AD Gain
    ADC_DCSETSelect(dcset);             // Config DC offset
    ADC_OSRSelect(osr);                 // Config Over sampling ratio
    ADC_VCMSSelect(vcms);			//Config ADC common voltage
    
	ADC_VRSEL_REFOint();          //REFO voltage buffer select=REFOint
    ADC_ENACMEnable();				//ACMint Enable
	PWR_ENREFOEnable();				//REFO Enable    
    ADC_Enable();							//ADC Enable
    //==========Setup ADC INT======================================
	ADC_INT_ClearFlag();      //Clear ADIF
	ADC_INT_Enable();   //ADC INT Enable
	ADC_Enable();         //ADC Enable
	ADC_CMFREnable();     //CMFR=1, Comb Filter Reset

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
  long ADCData;
  ((char *)(&ADCData))[0] = AD1L;
  ((char *)(&ADCData))[1] = AD1M;
  ((char *)(&ADCData))[2] = AD1H;

  if (((char *)(&ADCData))[2]>0x80)
    ((char *)(&ADCData))[3] = 0xFF;
  else
    ((char *)(&ADCData))[3] = 0x00;
  return ADCData;
}
