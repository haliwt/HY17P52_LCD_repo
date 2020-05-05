/**************************************************************************************************|
|* Copyright 2019 Hycon Technology, Corp.                                                         *|
|* http://www.hycontek.com/                                                                       *|
|* Description:                                                                                   *|
|* - Generic Peripheral Library: A general and functional Interface for the specific Peripheral   *|
|* - Low Level Peripheral Access: Register-Bits Level access Macro, user must take care           *|
|*   of calling procedure and hardware constraints                                                *|
|* - Support Target: HY17M Series                                                                 *|
|**************************************************************************************************/

/**************************************************************************************************|
|*                               Peripheral Register Bits field                                   *|
|**************************************************************************************************/
////	BIE2CN		//
#define	BIEER2		5
#define	BIEER2_NORMAL		(0<<BIEER2)
#define	BIEER2_CLEAR			(1<<BIEER2)
////	BIE2ARH		//
#define	ENBIE2		7
#define	ENBIE2_MSK				(1<<ENBIE2)
#define	ENBIE2_DISABLE		(0<<ENBIE2)
#define	ENBIE2_ENABLE			(1<<ENBIE2)

////	EECR1		//
#define	EEWR		0
#define	EEWR_MSK			(1<<EEWR)
#define	EEWR_NORMAL		(0<<EEWR)
#define	EEWR_WRITE			(1<<EEWR)

/**************************************************************************************************|
|*                                      Function Level                                            *|
|**************************************************************************************************/
/*-------------------------------------------------------------------------------------------------|
|  Function-like Macro:                                                                            |
|    Register Bits field Configuration without function call overhead,                             |
|    user should take care of detail of h/w behavior and constrains.                               |
|-------------------------------------------------------------------------------------------------*/
#define BIE2_Enable()					(BIE2ARH |= ENBIE2_ENABLE)
#define BIE2_Disable()					(BIE2ARH &= ~ (ENBIE2_MSK))

#define	BIE2_EEWR_Normal()		(EECR1 &= (~EEWR_MSK))
#define BIE2_DataWriter()        (EECR1 |= EEWR_WRITE)
#define	BIE2_EEWR_Write()		(EECR1 |= EEWR_WRITE)

#define	BIE2_DataRead()		(EECR2 = 0xa5)
#define	BIE2_Clear()					(BIE2CN |= BIEER2_CLEAR)




/*-------------------------------------------------------------------------------------------------|
|  Function call:                                                                                  |
|    For general and functional register access.                                                   |
|-------------------------------------------------------------------------------------------------*/
//void BIE_WriterData(unsigned char wrdata);
//unsigned int BIE_ReadData(void);

	