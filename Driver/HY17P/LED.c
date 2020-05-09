#define  USE_HY17P52_2M
/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|*                                                                                                *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Includes                                                                                      *|
|**************************************************************************************************/
#include <hy17p48sfr.h>
#include <LED.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: LEDSetting                                                                      			     				   											|
|                                                                                                 																					|
|  Parameters:                                                                                                                                                         		     |
|         cclevel         - [in]	CCLevel_2mA / CCLevel_3mA / CCLevel_5mA / CCLevel_7mA / CCLevel_9mA	              |
|                                        CCLevel_11mA / CCLevel_13mA / CCLevel_15mA
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        |
|  Description:                                                                                																					 |
|         This function is used to open LED Driver                                               														       |
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void LEDSetting(unsigned char cclevel)
{
	CCNT_CCLevelSel(cclevel);
	ENCCALL_Enable();
	PT12DA=0x00;
	INTE2 |= 0x40;
	TMA2CN=0xc0;
	TMA2C=2;		     //Set Scan Rate
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: GetDisplay                                                                      			     				   											|
|                                                                                                 																					|
|  Parameters:                                                                                                                                                         		     |
|         show         - [in]	LED show data                                                                                                        	              |
|         ledx           - [in]   LED show ledx
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        |
|  Description:                                                                                																					 |
|         This function is used to open LED Driver                                               														       |
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
unsigned char GetDisplay(unsigned char show,unsigned char ledx)
{
unsigned char RRTemp,RLTemp,RRR;
	RRTemp=show;
	RLTemp=show;

	RRR=0xff;

	RRTemp=(RRTemp<<1);
	RRR=(RRR<<ledx);
	RRTemp &= RRR;

	RRR=0xff;
	RRR=RRR>>(8-ledx);
	RLTemp &= RRR;
	RRR= RLTemp | RRTemp;

	return RRR;
}
