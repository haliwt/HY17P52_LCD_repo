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
#include <GPIO.h>

/*-------------------------------------------------------------------------------------------------|
|  Function: GPIO_OpenPTxInput                                                                     |
|                                                                                                  |
|  Parameters:                                                                                     |
|         InputBits    - [in] Enter the 8-bit data for Pin setting                                 |
|         PullHighBits - [in] Enter the 8-bit data for Pin setting                                 |
|                                                                                                  |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the PTx input mode  (PT1->x=0~6 / PT2->x=0~1 / PT3->x=0~7)        |
|-------------------------------------------------------------------------------------------------*/
void GPIO_OpenPT1Input(unsigned char InputBits,unsigned char PullHighBits)
{
  GPIO_PT1InputMode(InputBits);
  GPIO_PT1SETPU(InputBits & PullHighBits);
}
void GPIO_OpenPT2Input(unsigned char InputBits,unsigned char PullHighBits)
{
  GPIO_PT2InputMode(InputBits);
  GPIO_PT2SETPU(InputBits & PullHighBits);
}
void GPIO_OpenPT3Input(unsigned char InputBits,unsigned char PullHighBits)
{
  GPIO_PT3InputMode(InputBits);
  GPIO_PT3SETPU(InputBits & PullHighBits);
}

/*-------------------------------------------------------------------------------------------------|
|  Function: GPIO_OpenPTxOuput                                                                     |
|                                                                                                  |
|  Parameters:                                                                                     |
|         OutputBits  - [in] Enter the 8-bit data for Pin setting                                  |
|         OutHighBits - [in] Enter the 8-bit data for Pin setting                                  |
|                                                                                                  |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the PTx ouput mode (PT1->x=0~6 / PT2->x=0~1 / PT3->x=0~7)          |
|-------------------------------------------------------------------------------------------------*/
void GPIO_OpenPT1Output(unsigned char OutputBits,unsigned char OutHighBits)
{
  GPIO_PT1OutputMode(OutputBits);
  GPIO_PT1OutputHigh(OutputBits & OutHighBits);
}
void GPIO_OpenPT2Output(unsigned char OutputBits,unsigned char OutHighBits)
{
  GPIO_PT2OutputMode(OutputBits);
  GPIO_PT2OutputHigh(OutputBits & OutHighBits);
}
void GPIO_OpenPT3Output(unsigned char OutputBits,unsigned char OutHighBits)
{
  GPIO_PT3OutputMode(OutputBits);
  GPIO_PT3OutputHigh(OutputBits & OutHighBits);
}
