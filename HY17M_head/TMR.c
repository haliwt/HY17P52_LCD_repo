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
#include <TMR.h>
#include <CLK.h>
#include <INT.h>


/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/
/*-------------------------------------------------------------------------------------------------|
|  Function: TMA_Open                                                                              |
|                                                                                                  |
|  Parameters:                                                                                     |
|         ck        - [in] TMAS1_DMSCK / TMAS1_LPCCK                                   |
|         cks       - [in] DTMA1_TMA1CKDIV2    / DTMA1_TMA1CKDIV4                                   |
|                          DTMA1_TMA1CKDIV8   / DTMA1_TMA1CKDIV16                                  |
|                          DTMA1_TMA1CKDIV32   / DTMA1_TMA1CKDIV64                                  |
|                          DTMA1_TMA1CKDIV128   / DTMA1_TMA1CKDIV256                                  |
|          ck        - [in] 0x0~0xFF                                   |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the Timer-A(TMA)                                           |
|-------------------------------------------------------------------------------------------------*/
void TMA_Open(unsigned char ck,    //Timer-A operating frequency selector
              unsigned char cks,  //Timer-A overflow controller
              unsigned char tma_cmp)	//setting TMA comparison count
{
	TMA1_CLKSelect(ck);
	TMA1_CLKDiv(cks);
	TMA1_ClearTMA1();
	TMA1_CompSet(tma_cmp);
	TMA1Enable();
	TA1IE_Enable();
}

/*-------------------------------------------------------------------------------------------------|
|  Function: TMB_Open                                                                              |
|                                                                                                  |
|  Parameters:                                                                                     |
|         ck        - [in] TMBS_LPCCK / TMBS_HSCK                                   |
|         cks       - [in] DTMB_TMBCKDIV8    / DTMB_TMBCKDIV4                                  |
|                          DTMB_TMBCKDIV2   / DTMB_TMBCKDIV1                                  |
|         mode       - [in] TB1M_16bit / TB1M_17bit / TB1M_2_8bit / TB1M_8_8bit                              |
|         trig_mode        - [in] TB1RT_LogicH / TB1RT_CP11                                   |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the Timer-B(TMB)                                           |
|-------------------------------------------------------------------------------------------------*/
void TMB_Open(unsigned char ck,
						  unsigned char cks,
						  unsigned char mode,
						  unsigned char trig_mode)
{
	CLK_TMBCKDivSelect(cks);
	CLK_TMBCKSelect(ck);
	TB1_ModeSelect(mode);
	TB1_TRIG_MODE(trig_mode);
	TMBIE_Enable();
}

void TB1C0Set(unsigned int TMB)
{
	TB1C0H=(TMB>>8);
	TB1C0L= (0x00FF & TMB);
}

void TB1C1Set(unsigned int TMB)
{
	TB1C1H=(TMB>>8);
	TB1C1L= (0x00FF & TMB);
}

void TB1C2Set(unsigned int TMB)
{
	TB1C2H=(TMB>>8);
	TB1C2L= (0x00FF & TMB);
}