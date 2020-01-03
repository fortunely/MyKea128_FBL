/*
* @file    : queue.c
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
#include "queue.h"
#include <string.h>

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

/*==============================================================================
=======                        Global Function                           =======
==============================================================================*/

/*==============================================================================
=======                        Local Function                            =======
==============================================================================*/

/*==============================================================================
=======                    Function Implement List                       =======
==============================================================================*/

Status Queue_Init(Queue_t *Q, QElemType arr[], uint16_t size)
{
	if(Q)
	{
		Q->base = arr;
		Q->maxSize = size;
		Q->front = 0;
		Q->rear = 0;

		if(size > QUEUE_MAX_SIZE)
		{
			return ERROR_OVERMAXSIZE;
		}
		else if(0 == size)
		{
			return ERROR_EMPTYBUFFER;
		}

		memset(Q->base, 0, size);
	}
	else
	{
		return ERROR_NULLPOINTER;
	}
}


bool    Queue_IsEmpty(Queue_t *Q)
{
	if(Q)
	{
		if(Q->front != Q->rear) // initial status

		{
			return true;
		}
	}

	return false;
}


bool  Queue_IsFull(Queue_t *Q)
{
	if(!Queue_IsEmpty(Q))
	{
		if ((Q->rear + 1) % Q->maxSize == Q->front) // data full
		{
			return true;
		}
	}

	return false;
}


uint16_t Queue_Length(Queue_t *Q)
{
	if(!Queue_IsEmpty(Q))
	{
		return (uint16_t)(( Q->rear - Q->front ) % Q->maxSize);
	}

	return 0;
}


Status Queue_Enquene(Queue_t *Q, const QElemType e)
{
	if(Q)
	{
		if(!Queue_IsFull(Q))
		{
			Q->base[Q->rear] = e; // specific method of copy is defined by datas type
			Q->rear = (Q->rear + 1 ) % Q->maxSize;
		}
		else
		{
			return ERROR_INDEXOUTOFBOUNDS;
		}
	}
	else
	{
		return ERROR_NULLPOINTER;
	}
}


Status Queue_Dequene(Queue_t *Q, QElemType *pe)
{
	if(Q)
	{
		if(!Queue_IsEmpty(Q))
		{
			if(pe != NULL && Q->maxSize != 0)
			{
				*pe = Q->base[Q->front];
				Q->front = (Q->front + 1 ) % Q->maxSize;
			}
			else
			{
				return ERROR_NULLPOINTER;
			}
		}
		else
		{
			return ERROR_EMPTYBUFFER;
		}
	}
	else
	{
		return ERROR_NULLPOINTER;
	}
}


Status Queue_ClearQuene(Queue_t *Q)
{
	if(Q)
	{
		Q->front = 0;
		Q->rear = 0;

		memset(Q->base, 0, Q->maxSize);

		return OK;
	}
	else
	{
		return ERROR_NULLPOINTER;
	}
}
