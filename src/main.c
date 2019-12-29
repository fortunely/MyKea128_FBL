/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "derivative.h" /* include peripheral declarations SSKEAZ128M4 */
#include "Sys/init.h"
#include "Sys/task.h"


int main(void)
{

	Sys_Init();

	Sys_TaskCycle();

	return 0;
}
