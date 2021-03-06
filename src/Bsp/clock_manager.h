/*
* @file    : Clock.h
* @author  : Martin
* @brief   : xxx module Header file
*/
#ifndef DRIVER_CLOCK_MANAGER_H_
#define DRIVER_CLOCK_MANAGER_H_
/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
Version   Date         User                Comment
********************************************************************************
    0.1   2019-01-10   xxx                 - xxx xxx
*******************************************************************************/
/*==============================================================================
=======                             INCLUDES                             =======
==============================================================================*/
/*==============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE               =======
==============================================================================*/
#define EXT_CLK_FREQ           	8000u                /// unit: kHz
#define SYS_CLK_FREQ   			40000000L            /// unit: Hz
#define BUS_CLK_FREQ           	(SYS_CLK_FREQ >> 1)  /// unit: Hz

/*==============================================================================
=======                        CONSTANTS & TYPES                         =======
==============================================================================*/

/*==============================================================================
=======                             EXPORTS                              =======
==============================================================================*/

/*==============================================================================
=======                  PROTOTYPES OF PUBLIC FUNCTIONS                  =======
==============================================================================*/
void ClockManager_Init(void);

#endif /* DRIVER_CLOCK_MANAGER_H_ */
