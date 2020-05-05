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
#include <I2C.h>
#include <GPIO.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: I2C_Open                                                                      			     				   											|
|                                                                                                 																					|
|  Parameters:                                                                                                                                                         		     |	
|         dbr         - [in]	0~0xff			data baud rate = I2C_CLK / [4*(dbr+1)]																	 |
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        
|  Description:                                                                                																					 
|         This function is used to open I2C               														   
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void I2C_Open( unsigned char dbr)	// data baud rate = I2C_CLK / [4*(dbr+1)]
{
	I2CEnable();
	I2C_GCRstEnable();
	I2C_SCLCLKSet(dbr);
	I2C_SendData(0xff);
	I2CIE_Enable();			//I2C INT Enable
	I2CERIE_Enable();	//I2C ERROR INT Enable
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: I2C_TimeOutEnable                                                                      			     				   							|
|                                                                                                 																			     		|
|  Parameters:                                                                                                                                                         	       |	
|         cks         - [in]	DI2C_CPUCKDIV1 / DI2C_CPUCKDIV2 / DI2C_CPUCKDIV4 / DI2C_CPUCKDIV8		     	 |
|         							DI2C_CPUCKDIV16 / DI2C_CPUCKDIV32 / DI2C_CPUCKDIV64 / DI2C_CPUCKDIV128	   |
|         cyc         - [in]     I2CTLT_CLKPS1 / I2CTLT_CLKPS2 / I2CTLT_CLKPS3 / I2CTLT_CLKPS4							 |
|                                   I2CTLT_CLKPS5 / I2CTLT_CLKPS6 / I2CTLT_CLKPS7 / I2CTLT_CLKPS8							 |
|                                   I2CTLT_CLKPS9 / I2CTLT_CLKPS10 / I2CTLT_CLKPS11 / I2CTLT_CLKPS12					 |
|                                   I2CTLT_CLKPS13 / I2CTLT_CLKPS14 / I2CTLT_CLKPS15 / I2CTLT_CLKPS16					 |
|                                                                                                                                                                                       |
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        
|  Description:                                                                                																					 
|         This function is used to open Time-out                         														   
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void I2C_TimeOutOpen(unsigned char cks,	// Time-out Clock Pre-scale
					                   unsigned char cyc)		// Time-out Limit
{
	I2C_TimeOutEnable();
	I2C_TimeOutCLKSel(cks);
	I2C_TimeOutCYCSel(cyc);
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: I2C_TimeOutEnable                                                                      			     				   							|
|                                                                                                 																			     		|
|  Parameters:                                                                                                                                                         	       |	
|         upin         - [in]	 0		//SCL=PT1.3  SDA=PT1.4                                                                                                  |
|                                   1	   //SCL=PT2.1  SDA=PT2.0                                                                                                  |
|                                   2	   //SCL=PT3.0  SDA=PT3.1                                                                                                  |
|                                   3	   //SCL=PT3.2  SDA=PT3.3                                                                                                  |
|                                                                                                                                                                                       |
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        
|  Description:                                                                                																					 
|         This function is used to set I/O pin                        														   
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void I2C_SetIOPin(unsigned char upin)		// scl pin and sda pin select
{
	switch (upin)	// I2C SCL SELECT
	{
		case 0 :
			GPIO_PM13Sel(PM13_SCL);		//PT1.3	
		break;
		
		case 1:
			GPIO_PM21Sel(PM21_SCL_1);	//PT2.1
		break;
			
		case 2:
			GPIO_PM30Sel(PM30_SCL_2);	//PT3.0	
		break;
					
		case 3:
			GPIO_PM32Sel(PM32_SCL_3);	//PT3.2	
		break;	
	}
	
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: I2C_Ctrl                                                                      			     				   							|
|                                                                                                 																			     		|
|  Parameters:                                                                                                                                                         	       |	
|         S         - [in]	0 , 1	    	// Start   command                                                                                                            |
|         P         - [in]   0 , 1	   		// Stop     command                                                                                           |
|         I           - [in]   0 , 1	     // Interrupt    command                                                                                            |
|         A         - [in]   0 , 1	       // Acknowledge   command                                                                                        |
|                                                                                                                                                                                       |
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        
|  Description:                                                                                																					 
|         This function is used to Ctrl SPIA                         														   
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void I2C_Ctrl( unsigned char S,		// Start
                       unsigned char P,		// Stop
                       unsigned char I,		// Interrupt
                       unsigned char A) 	// Acknowledge
{
 A|=(S<<3);
 A|=(P<<2);
 A|=(I<<1);
 I2C_SPIA(A);
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------|
|  Function: I2C_SlaveSet                                                                   			     				   							|
|                                                                                                 																			     		|
|  Parameters:                                                                                                                                                         	       |	
|         sid         - [in]	 0x00~0xff																																			|
|  Returns:                                                                               		                                                                                  |
|         None               		                   		                   		                   		                   		                   		                       |
|                                                                                       		                   		                   		                                        
|  Description:                                                                                																					 
|         This function is used to set slave mode                         														   
|-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void I2C_SlaveSet(unsigned char sid)
{
	I2C_GCRstDisable();
	I2C_SlaveModeEnable();
	I2C_SlaveAddSet(sid);
	I2C_SendData(0xff);
}

