/*
* @file    : S19Paraser.c
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
#include "s19_paraser.h"

#include <stddef.h>

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
static S19_Format_t s19LineData = {0};

/*==============================================================================
=======                        Global Function                           =======
==============================================================================*/

/*==============================================================================
=======                        Local Function                            =======
==============================================================================*/

/*==============================================================================
=======                    Function Implement List                       =======
==============================================================================*/
uint8_t S19ParseByLine(uint8_t *pS19LineData,  uint32_t size )
{
	if(pS19LineData == NULL)
		return ERR_NULLPOINTER;

	uint8_t i = 0;
	for(i = 0; i < size; i ++)
	{
//		switch(pS19LineData[])
//		{
//
//		}
	}


	return 0;
}



