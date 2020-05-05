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
#include <OPA.h>
#include <INT.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function: OPA_Out2DigOpen                                                                                       |
|                                                                                           				                       		|
|  Parameters:                                                                                   	                       	    |
|         ins  		  - [in]  OPINS_SHORT    / OPINS_NORMAL                                            |
|         opdr      - [in]  OPDR_REVERSE    / OPDR_NORMAL   				                      |
|         trig        - [in]  OPOEG_LEV    / OPOEG_EDGERISE   / OPOEG_EDGEFALL    |
|                                                                                                                                        |
|  Returns:                                                                                                                         |
|         None                                                                                                                       |
|                                                                                                                                         |
|  Description:                                                                                                                    |
|         This function is used to open the Digital output of OPA                                          |
|-------------------------------------------------------------------------------------------------*/
void OPA_Out2DigOpen(unsigned char ins,		//Input short or not
						   unsigned char opdr,		//OPOD Reverse or not
						   unsigned char trig)		 //OPA INT edge Select
{
	OP1_AnalogyOutSel(OP1OS_DIGITAL);
	OP1_FilterEnable();
	OP1_DigitalOutEnable();
	OP1_InputShort(ins);
	OP1_OutputReverse(opdr);	
	OP1_INT_Trigger(trig);
	OP1_INT_Enable();
	OP1_INT_ClearFlag();
	OP1_Enable();
}

/*-------------------------------------------------------------------------------------------------|
|  Function: OPA_Out2AI0Open                                                                                       |
|                                                                                           				                       		|
|  Parameters:                                                                                   	                       	    |
|         ins  		  - [in]  OPINS_SHORT    / OPINS_NORMAL                                            |
|                                                                                                                                        |
|  Returns:                                                                                                                         |
|         None                                                                                                                       |
|                                                                                                                                         |
|  Description:                                                                                                                    |
|         This function is used to open the AI0 output of OPA                                          |
|-------------------------------------------------------------------------------------------------*/
void OPA_Out2AI0Open(unsigned char ins)		//Input short or not
{
	OP1_AnalogyOutSel(OP1OS_AI0);
	
    OP1_InputShort(ins);      
	OP1_Enable();
}

/*-------------------------------------------------------------------------------------------------|
|  Function: OPA_Out2R1_0Open                                                                                                       |
|                                                                                           				                       	                	    |
|  Parameters:                                                                                   	                       	                       |
|         ins  		       - [in]  OPINS_SHORT    / OPINS_NORMAL                                                         |
|         gain  		  - [in]  OPGAINS_4    / OPGAINS_8 / OPGAINS_16 / OPGAINS_32                    |
|         r1_fb  		  - [in]  OPDIEN_VSS    / OPDIEN_REFOI / OPDIEN_AI1 / OPDIEN_DAIO          |
|                                                                                                                                                         |
|  Returns:                                                                                                                                         |
|         None                                                                                                                                       |
|                                                                                                                                                         |
|  Description:                                                                                                                                    |
|         This function is used to open the R1_0 output of OPA                                                          |
|-------------------------------------------------------------------------------------------------*/
void OPA_Out2R1_0Open(unsigned char ins,		//Input short or not
						   					unsigned char gain,		//OP GAIN Selection		
						   					unsigned char r1_fb)	//R1_fb souce select
{
	OP1_AnalogyOutSel(OP1OS_R1_O);
	
	if(ins == OPINS_SHORT)			//OPINS Select
		OP1_IN_Short();
	else
		OP1_IN_Normal();
	
	OP1_GAINSelect(gain);
	OP1_GAINSourceSel(r1_fb);
	OP1_Enable();
}
/**************************************************************************************************|
|*  Static Functions                                                                              *|
|**************************************************************************************************/
