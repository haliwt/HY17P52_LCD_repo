#define  USE_HY17P52_2M
#include "bsp_key.h"
void KEY_Init(void)
{

  GPIO_PT1InputMode(KeyBitSet_PT16);

  GPIO_PT1SETPU(KeyBitSet_PT16) ; /* 1 =ON ,0 = OFF */

}


