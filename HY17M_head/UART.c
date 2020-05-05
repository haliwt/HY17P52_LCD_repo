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
#include <UART.h>
#include <GPIO.h>
#include <INT.h>

/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*---------------------------------------------------------------------------------------------------------------------------------|
|  Function: UART_Open                                                                                                                      |
|                                                                                                                                                             |
|  Parameters:                                                                                                                                       |
|         uBRGR     - [in] Desired baud rate.                                                                                             |
|         uDataBits - [in] "8"                 *8 bit mode*                                                                                   |
|                                  "9"                 *9 bit mode*                                                                                   |
|         uParity     - [in] PARITY_ODD / PARITY_Even / PARITY_None                                                 |
|         Uartxsel    -[in]  "0"                 *TX / RC*                                                                                       |
|                                  "1"                 *TX_1 / RC_1 *                                                                              |
|                                  "2"                 *TX_2 / RC_2 *                                                                              |
|                                  "3"                 *TX_3 / RC_3 *                                                                              |
|                                                                                                                                                              |
|  Returns:                                                                                                                                               |
|         None                                                                                                                                             |
|                                                                                                                                                               |
|  Description:                                                                                                                                          |
|         This function is used to open                                                                                                        |
|                  the Enhanced Universal Asynchronous Receiver Transmitter(UART)                                |
|-------------------------------------------------------------------------------------------------------------------------------------*/
void UART_Open(unsigned int  uBG0R,     //desired baud rate
               unsigned char uDataBits, //Enable the transmission of the ninth bit and send the ninth bit data
               unsigned char uParity,     //Odd/even bit check
               unsigned char Uartxsel)       // Tx/Rc or Tx_1/Rc_1 or Tx_2/Rc_2 or Tx_3/Rc_3 selector              
{

	BG0RH=(uBG0R>>8);
	BG0RL= (0x00FF & uBG0R);

    if (uDataBits==9)
    {
        UART_TX9Enable();
        UART_RC9Enable();
    }
    else
    {
        UART_TX9Disable();
        UART_RC9Disable();
    }
    UART_Parity(uParity);
    UART_TXEnable();
    UART_CREnable();
    UART_Enable();
    switch(Uartxsel)
    {
	    case 0:
	    	GPIO_PT1InputEnable(IN15_H | IN16_H);
	    	GPIO_PM15Sel(PM15_TX);   	
	    	break;
	    	
	    case 1:
	    	GPIO_PT2InputEnable(IN20_H | IN21_H);	    	
	    	GPIO_PM20Sel(PM20_TX_1);   		    
	    	break;
	    	
	    case 2:
	    	GPIO_PT3InputEnable(IN36_H | IN37_H);
	    	GPIO_PM36Sel(PM36_TX_2);   		    
	    	break;
	    	
	    case 3:
	    	GPIO_PT3InputEnable(IN34_H | IN35_H);
	    	GPIO_PM34Sel(PM34_TX_3);   		    
	    	break;
	}
	TXIE_Enable();
	RCIE_Enable();
	GIE_Enable();
}
/*---------------------------------------------------------------------------------------------------------------------------------|
|  Function: UART_BGRSet                                                                                                                      |
|                                                                                                                                                             |
|  Parameters:                                                                                                                                       |
|         uBG0R     - [in] UART send data                                                                                             |
|                                                                                                                                                               |
|  Returns:                                                                                                                                               |
|         None                                                                                                                                             |
|                                                                                                                                                               |
|  Description:                                                                                                                                          |
|         This function is used to set the UART send data                                                                          |
|                                                                                                                                                               |
|-------------------------------------------------------------------------------------------------------------------------------------*/
void UART_BGRSet(unsigned int uBG0R)
{
	BG0RH=(uBG0R>>8);
	BG0RL= (0x00FF & uBG0R);
}
