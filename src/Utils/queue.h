/*
* @file    : queue.h
* @author  : Martin
* @brief   : xxx module Header file
*/
#ifndef UTILS_QUEUE_H_
#define UTILS_QUEUE_H_
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
#include "status.h"

/*==============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE               =======
==============================================================================*/

#define QUEUE_MAX_SIZE           	256
/*==============================================================================
=======                        CONSTANTS & TYPES                         =======
==============================================================================*/
typedef uint8_t QElemType;

typedef struct{
	QElemType *base; /// pointer to base of data array
	uint16_t maxSize; /// max size of data array
	uint16_t front;  /// front index of the queue
	uint16_t rear;   /// rear index of the queue
}Queue_t;

/*==============================================================================
=======                             EXPORTS                              =======
==============================================================================*/

/*==============================================================================
=======                  PROTOTYPES OF PUBLIC FUNCTIONS                  =======
==============================================================================*/
Status Queue_Init(Queue_t *Q, QElemType arr[], uint16_t size);
bool   Queue_IsEmpty(Queue_t *Q);
Status Queue_Enquene(Queue_t *Q, const QElemType e);
Status Queue_Dequene(Queue_t *Q, QElemType *pe);
Status Queue_ClearQuene(Queue_t *Q);

#endif /* UTILS_QUEUE_H_ */
