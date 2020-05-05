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
#include <PWR.h>
#include <ADC.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------|
|  Function: PWR_VDDAOpen                                                                                       |
|                                                                                               				                               |
|  Parameters:                                                                                                                        |
|         vdda  		  - [in]  LDOC_2V4  / LDOC_2V6 / LDOC_2V9 / LDOC_3V3                    |
|                                     LDOC_3V6  / LDOC_4V0 / LDOC_4V5 / LDOC_5V0                     |
|                                                                                                                                              |
|  Returns:                                                                                                                               |
|         None                                                                                                                             |
|                                                                                                                                               |
|  Description:                                                                                                                          |
|         This function is used to open the PWR of VDDA                                                          |
|----------------------------------------------------------------------------------------------------------------------*/
void PWR_VDDAOpen(unsigned char vdda)    //VDDA regulated selector
{
	PWR_LDOPLEnable();	
	PWR_VDDASel(vdda);		//VDDA Voltage Selection
	PWR_LDOMode(LDOM_VDD);
    PWR_LDOEnable();		  //Enable VDDA
	
}
/*----------------------------------------------------------------------------------------------------------------------|
|  Function: REFOI_REFOint_Open                                                                                       |
|                                                                                               				                               |
|  Parameters:                                                                                                                        |
|         refo        - [in]  REFOS_1V2    / REFOS_2V0   / REFOS_2V4 / REFOS_3V0             |
|                                                                                                                                              |
|  Returns:                                                                                                                               |
|         None                                                                                                                             |
|                                                                                                                                               |
|  Description:                                                                                                                          |
|         This function is used to open the voltage of REFO ,and select REFOI from REFOint     |
|----------------------------------------------------------------------------------------------------------------------*/
void REFOI_REFOint_Open(unsigned char refo)	//REFOint regulated selector
{
	PWR_REFOSel(refo);		//REFO Voltage Selection
	PWR_ENREFOEnable();		//Enable REFOint
	ADC_VRSEL_REFOint();
}

/*--------------------------------------------------------------------------------------------------------------------|
|  Function: REFOI_REFOint_Open                                                                                     |
|                                                                                           				                                 |
|  Parameters:                                                                                   	                       	         |
|         acm             - [in]  SELVIN_VDDADIV2    / SELVIN_1V2                                           |
|                                                                                                                                             |
|  Returns:                                                                                                                              |
|         None                                                                                                                            |
|                                                                                                                                              |
|  Description:                                                                                                                         |
|         This function is used to open the voltage of ACM ,and select REFOI from ACMint     |
|----------------------------------------------------------------------------------------------------------------------*/
void REFOI_ACMint_Open(unsigned char acm)	//ACMint regulated selector
{
	ADC_ACMBufSelect(acm);		//ACM Souce Selection
	ADC_ENACMEnable();		//Enable ACMint
	ADC_VRSEL_ACMint();
}
/**************************************************************************************************|
|*  Static Functions                                                                              *|
|**************************************************************************************************/
