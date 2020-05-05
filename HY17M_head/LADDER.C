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
#include <ladder.h>
#include <GPIO.h>
#include <PWR.h>
#include <ADC.h>
#include <OPA.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function: CLK_CPUCKOpen                                                                         |
|                                                                                                  |
|  Parameters:     
|         vdda -    [in] LDOC_2V4	/	LDOC_2V6  / LDOC_2V9	/	LDOC_3V3              |
|                             LDOC_3V6	/	LDOC_4V0  / LDOC_4V5	/	LDOC_5V0              |
|         daps  - [in] DAPS_VDDA  / DAPS_REFOI	/	DAPS_AI0 / DAPS_AI4 		          |
|                           DAPS_AI5 / DAPS_AI7  / DAPS_AI9	/	DAPS_AI13					           |
|         dans   - [in] DANS_VSS	/	DANS_REFOI									  	 	 			|
|                              DANS_AI0	/	DANS_AI8                                                               |
|         dabit  - [in] DABIT[11:0] 0x000~0xfff                                                                   |
|                                                                                                                                      |
|  Returns:                                                                                                                      |
|         None                                                                                                                   |
|                                                                                                                                       |
|  Description:                                                                                                                    |
|         This function is used to open the 12-bit resistance ladder DAC setting                 |
|  Modify date: 2019                                                                                                           |
|-------------------------------------------------------------------------------------------------*/
void DAC_Open(unsigned char vdda,					//VDDA Voltage Selection
                           unsigned char daps,				   //DA_Vrefp source Selection 
                           unsigned char dans,			  	  //DA_Vrefn source Selection                                           
                           unsigned int dabit)		     //DABIT[11:0],DACO Voltage ratio
{
	GPIO_PT1SETDA(DA14_H);
	PWR_LDOPLEnable();	
	PWR_LDOEnable();		//Enable VDDA
	PWR_VDDASel(vdda);		//VDDA Voltage Selection	
	DACBitH = dabit >> 8;				//	DABIT[11:0]
	DACBitL = dabit & 0xff;				
	LADER_DASelect(daps,dans);		//DAPS and DANS source selection
	switch (daps)
	{
		case DAPS_AI4:
			GPIO_PT1SETDA(DA10_H);
		break;
		
		case DAPS_AI5:
			GPIO_PT1SETDA(DA11_H);
		break;		

		case DAPS_AI7:
			GPIO_PT1SETDA(DA13_H);
		break;	

		case DAPS_AI9:
			GPIO_PT1SETDA(DA15_H);
		break;		

		case DAPS_AI13:
			GPIO_PT3SETDA(DA36_H);
		break;		
	}
	
	if(dans == DANS_AI8)			//Use OPA to short DAOI and AI0
	{
		OP1_INP_AI0Enable();	
		OP1_INN_DAOIEnable();	
		OP1_IN_Short();	
	}
	
	LADDER_DALH_Enable();
	LADDER_ENDA_Enable();
	LADDER_DAOE_Enable();
	

}
/**************************************************************************************************|
|*  Static Functions                                                                              *|
|**************************************************************************************************/
