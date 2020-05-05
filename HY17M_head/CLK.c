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
#include <CLK.h>
#include <RST.h>
#include <GPIO.h>
/**************************************************************************************************|
|*  Static Function                                                                               *|
|**************************************************************************************************/

/**************************************************************************************************|
|*  Generic Peripheral Library                                                                    *|
|**************************************************************************************************/

/*-------------------------------------------------------------------------------------------------|
|  Function: CLK_GPIO_OpenXTInput                                                                      |
|                                                                                                  |
|  Parameters:                                                                                     |
|         None                                                                                     |
|                                                                                                  |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the XT mode for Pin setting                                |
|-------------------------------------------------------------------------------------------------*/
void CLK_GPIO_OpenXTInput(void)
{
    TRISC2 &= (~(TC20_MSK | TC21_MSK));  // config PT2.0/PT2.1 as Input Mode
    PT2PU &= (~(PU20_MSK | PU21_MSK));     // Disable Input pull up in case of Input Mode
}

/*-------------------------------------------------------------------------------------------------|
|  Function: CLK_CPUCKOpen                                                                         |
|                                                                                                  |
|  Parameters:     
|         haom -    [in] HAOM_17M1	/	HAOM_8M7  / HAOM_4M2	/	HAOM_2M              |
|         oscs  - [in] OSCS_HAO  / OSCS_LPO	/	OSCS_XT                    						            |
|         dhsck   - [in] DHS_HSCKDIV8	/	DHS_HSCKDIV4									  	 	 			|
|                              DHS_HSCKDIV2	/	DHS_HSCKDIV1                                                        |
|         cpuck  - [in] CPUS_DHSCK / CPUS_HSCK                               |
|                                                                                                  |
|  Returns:                                                                                        |
|         None                                                                                     |
|                                                                                                  |
|  Description:                                                                                    |
|         This function is used to open the CPU clock setting          
|  Modify date: 2019/07/19                                                             |
|-------------------------------------------------------------------------------------------------*/
void CLK_CPUCKOpen(unsigned char haom,				//HAO Frequence Selection
                                       unsigned char oscs,       		   //HS_CK Selection 
                                       unsigned char dhsck,			     //DHS_CK Selection                                          
                                       unsigned char cpuck)               //CPU_CK Source Selection 
{
    CCOPT_Enable(); 	//FOR C COMPILE
    CLK_HAOSelect(haom);         
    CLK_HAOEnable();                
    CLK_OSCSelect(oscs) ;        
    CLK_DHSCKSelect(dhsck);      
    CLK_CPUCKSelect(cpuck);     

}
/**************************************************************************************************|
|*  Static Functions                                                                              *|
|**************************************************************************************************/
