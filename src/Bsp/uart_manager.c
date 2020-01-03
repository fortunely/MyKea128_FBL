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
#include "queue.h"

#include <size_t.h>

/*==============================================================================
=======               Defines & Macros for General Purpose               =======
==============================================================================*/
/*==============================================================================
=======                        Constants & Types                         =======
==============================================================================*/
#define TERMINAL_UART_PORT  UART_2

#define UART_TX_BUFFER_MAX_SIZE           	256
#define UART_RX_BUFFER_MAX_SIZE 			UART_TX_BUFFER_MAX_SIZE

/*==============================================================================
=======                        Global variables                          =======
==============================================================================*/

/*==============================================================================
=======                        Local variables                           =======
==============================================================================*/
static uint8_t txBuffer[UART_TX_BUFFER_MAX_SIZE] = {0};
static uint8_t rxBuffer[UART_RX_BUFFER_MAX_SIZE] = {0};

static Queue_t txQueue;
static Queue_t rxQueue;

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


	UartManager_InitGlobalVariables();
}

void UartManager_InitGlobalVariables()
{
	Queue_Init(&txQueue, txBuffer, sizeof(txBuffer));
	Queue_Init(&rxQueue, rxBuffer, sizeof(rxQueue));
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
	uint8_t txBuffer1[] = "hi";
	char * log = "hi";
	size_t len = strlen(txBuffer1);


//	memcmp(log, txBuffer, len);


	UART_SendWait(TERMINAL_UART_PORT, txBuffer1, len);
	UART_WaitTxComplete(TERMINAL_UART_PORT);
}

void UartManager_Interrupt()
{

}

