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
#include <CMP.h>
#include <INT.h>
/*-----------------------------------------------------------------------------------------------------|
|  Function: CMP_Open                                                                                     |
|                                                                                                                         |
|  Parameters:                                                                                                    |
|         cpps        - [in] CPPS_CH0 / CPPS_CH1 / CPPS_CH2 / CPPS_1V2        |
|         cpns         - [in] CPNS_CH0 / CPNS_CH1 / CPNS_CH2 / CPNS_RLO      |
|         cmphs      - [in] CMPHS_NORMAL/ CMPHS_LOWPOWER                       |
|         cpor         - [in] CPOR_REVERSE / CPOR_NORMAL                                |
|         enrcc        - [in] ENRCC_DISABLE / ENRCC_RX                                      |
|                                  ENRCC_PT16 / ENRCC_RESERVED                              |
|                                                                                                                          | 
|  Returns:                                                                                                          |
|         None                                                                                                        |
|                                                                                                                          |
|  Description:                                                                                                      |
|         This function is used to open the CMP								                        |
|------------------------------------------------------------------------------------------------------*/
void CMP_Open( unsigned char cpps,   //CMP P Input select
           					 unsigned char cpns,   //CMP N Input select
              				 unsigned char cmphs, //CMP Work mode select
              				 unsigned char cpor,     //CMP Output reverse control
              				 unsigned char enrcc)   //CMP Output control
{
	CMP_PInput(cpps);
	CMP_NInput(cpns);
	CMP_MODESel(cmphs);	
	CMP_OutInverse(cpor);		
	CMP_OutputSelect(enrcc);
	CMPIE_Enable();
	CMPIF_ClearFlag();
	CMP_Enable();
	
}

/*------------------------------------------------------------------------------------------------------------------------------------|
|  Function: CMP_RLOSet                                                                                                                   |
|                                                                                                                                                            |
|  Parameters:                                                                                                                                      |
|         cprh     - [in] CPRH_DISABLE / CPRH_VDD / CPRH_VDDA / CPRH_RESERVED                |
|         cprl     - [in] CPRL_OPEN / CPRL_SHORT                                                                               |
|         cpda     - [in] CPDA_0 / CPDA_1DIV32 / CPDA_2DIV32 / CPDA_3DIV32                               |
|                              CPDA_4DIV32 / CPDA_5DIV32 / CPDA_6DIV32 / CPDA_7DIV32                     |
|                              CPDA_8DIV32 / CPDA_9DIV32 / CPDA_10DIV32 / CPDA_11DIV32                 |
|                              CPDA_12DIV32 / CPDA_13DIV32 / CPDA_14DIV32 / CPDA_15DIV32             |
|                              CPDA_16DIV32 / CPDA_17DIV32 / CPDA_18DIV32 / CPDA_19DIV32             |
|                              CPDA_20DIV32 / CPDA_21DIV32 / CPDA_22DIV32 / CPDA_23DIV32             |
|                              CPDA_24DIV32 / CPDA_25DIV32 / CPDA_26DIV32 / CPDA_27DIV32             |
|                              CPDA_28DIV32 / CPDA_29DIV32 / CPDA_30DIV32 / CPDA_31DIV32             |
|         cpdm     - [in] CPDM4_ENABLE / CPDM3_ENABLE / CPDM2_ENABLE                                 |
|                               CPDM1_ENABLE / CPDM0_ENABLE  / CPDM_DISABLE                                                            |
|                                                                                                                                                            |
|  Returns:                                                                                                                                             |
|         None                                                                                                                                          |
|                                                                                                                                                            |
|  Description:                                                          				                                                               |
|         This function is used to set RLO as the CMP Input      	                                                        |
|------------------------------------------------------------------------------------------------------------------------------------*/
void CMP_RLOSet( unsigned char cprh,   //CMP RLO reference voltage source selection
           					    unsigned char cprl,   //CMP RLO  resistor(22.5R/20R) short control
              				    unsigned char cpda,   //CMP RLO  reference voltage division control
              			   	    unsigned char cpdm)  //CMP hysteresis control 
{
	CMP_RLO_VrefSel(cprh);
	if(cprl == CPRL_SHORT)
		CMP_CPRLShort();
	else
		CMP_CPRLOpen();
		
	CMP_R_DASel(cpda);
	CMP_CPDMSet(cpdm);
}

