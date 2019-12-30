/*
* @file    : timer_manager.c
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
#include "timer_manager.h"
#include "rtc.h"

/*==============================================================================
=======               Defines & Macros for General Purpose               =======
==============================================================================*/
/*==============================================================================
=======                        Constants & Types                         =======
==============================================================================*/

/*==============================================================================
=======                        Global variables                          =======
==============================================================================*/

/*==============================================================================
=======                        Local variables                           =======
==============================================================================*/
Timer timers_1ms = 0;
Timer timers_10ms = 0;
Timer timers_100ms = 0;

/*==============================================================================
=======                        Global Function                           =======
==============================================================================*/

/*==============================================================================
=======                        Local Function                            =======
==============================================================================*/
void TimerManager_Interrupt(void);
/*==============================================================================
=======                    Function Implement List                       =======
==============================================================================*/

/**
 * void TimerManager_Init(void)
 * @note RTC clock freq = clock source / prescaler = 20M / 100 = 200KHz
 * Tq = 1/freq * (mod+1) = 1/200KHz * 200 = 1ms
 */
void TimerManager_Init(void)
{
	RTC_ConfigType sConfig = {0};

	sConfig.bClockSource = RTC_CLKSRC_BUS;
	sConfig.bClockPrescaler = RTC_CLK_PRESCALER_100;
	sConfig.bInterruptEn = RTC_INTERRUPT_ENABLE;
	sConfig.u16ModuloValue = (200 - 1); // interrupt at the end time of every tq, that is , 0 is included
	RTC_Init(&sConfig);

	RTC_CallbackType *callbackFunc = TimerManager_Interrupt;
	RTC_SetCallback(TimerManager_Interrupt);
}


/**
 * void TimerManager_Interrupt(void)
 * @note called by cycle time @ 1ms
 */
void TimerManager_Interrupt(void)
{

	timers_1ms ++;

	timers_10ms ++;

	timers_100ms ++;
}
