/*
* @file    : uart_manager.c
* @author  : Martin
* @brief   : xxx module Header file
*/


/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
Version   Date         User                Comment
********************************************************************************
    0.1   2019-01-01   xxx                 - xxx xxx
*******************************************************************************/
/*==============================================================================
=======                             Includes                             =======
==============================================================================*/
#include "uart.h"
#include "clock_manager.h"
#include "uart_manager.h"

/*==============================================================================
=======               Defines & Macros for General Purpose               =======
==============================================================================*/
/*==============================================================================
=======                        Constants & Types                         =======
==============================================================================*/
#define TERMINAL_UART_PORT  UART_2
/*==============================================================================
=======                        Global variables                          =======
==============================================================================*/

/*==============================================================================
=======                        Local variables                           =======
==============================================================================*/

/*==============================================================================
=======                        Global Function                           =======
==============================================================================*/

/*==============================================================================
=======                        Local Function                            =======
==============================================================================*/

/*==============================================================================
=======                    Function Implement List                       =======
==============================================================================*/
void UartManager_Init()
{
	UART_ConfigType sUartConfig = {0};
	sUartConfig.u32SysClkHz = BUS_CLK_FREQ;
	sUartConfig.u32Baudrate = UART_BIT_BAUDRATE;

	sUartConfig.sctrl2settings.bits.bTe = 1;
	sUartConfig.sctrl2settings.bits.bRe = 1;

	UART_Init(TERMINAL_UART_PORT, &sUartConfig);
}


/**
 * void UartManager_Task()
 * @note called by cycle time
 */
void UartManager_Task()
{
	static char c = 'a';
	UART_PutChar(TERMINAL_UART_PORT, c);
	c ++;
}
