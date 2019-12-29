/*
* @file    : clock_manager.c
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
#include "clock_manager.h"
#include "ics.h"
/*==============================================================================
=======               Defines & Macros for General Purpose               =======
==============================================================================*/
/*==============================================================================
=======                        Constants & Types                         =======
==============================================================================*/
#define EXT_CLK_FREQ           8000   /// unit: kHz
#define BUS_CLK_FREQ           20000  /// unit: kHz
#define ICS_Trim_VALUE         54u

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
static void ClockManager_Init_Bus_20M(void);

static inline SIM_DisableNMI(void)
{
	SIM->SOPT0 &= ~SIM_SOPT0_NMIE_MASK;
}


static inline SIM_EableNMI(void)
{
	SIM->SOPT0 |= SIM_SOPT0_NMIE_MASK;
}


/*==============================================================================
=======                    Function Implement List                       =======
==============================================================================*/

void ClockManager_Init(void)
{
	ICS_Trim(ICS_Trim_VALUE);

	ClockManager_Init_Bus_20M();
}

/**
 * void ClockManager_Init_Bus_20M(void)
 * @param void
 * @note configure bus clock work at 20MHz, core clock 40MHz, disable NMI pin as default
 */
void ClockManager_Init_Bus_20M(void)
{
	ICS_ConfigType sConfig = {0};

	SIM->CLKDIV |= SIM_CLKDIV_OUTDIV2_MASK;  //OUTDIV2 = 1, bus clock = core clock / 2

	sConfig.bdiv = 0;
	sConfig.bLPEnable = 0;
	sConfig.u8ClkMode = ICS_CLK_MODE_FEE;

#if EXT_CLK_FREQ > 4000
	sConfig.oscConfig.bRange =1;
#endif

	sConfig.oscConfig.bGain = 1;
	sConfig.oscConfig.bIsCryst = 1; // use OSC
	sConfig.oscConfig.bEnable = 1;
	sConfig.oscConfig.u32OscFreq = EXT_CLK_FREQ;

	ICS_Init(&sConfig);
}
