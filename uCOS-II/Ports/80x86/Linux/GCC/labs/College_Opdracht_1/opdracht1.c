#include "includes.h"

#define TASK_STK_SIZE 256

OS_STK TaskStartStack[TASK_STK_SIZE];
OS_STK TaskHelloStack[TASK_STK_SIZE];

void TaskStart(void *pdata);
void TaskHello(void *pdata);

int main()
{
	OSInit();
	
	OSTaskCreate(TaskStart,  (void *) 0, &TaskStartStack[TASK_STK_SIZE - 1],10);
	
	OSStart();
	
	
	
	return 1;
}

void TaskStart(void *pdata)
{
	// Start hello task
	OSTaskCreate(TaskHello,  (void *) 0, &TaskHelloStack[TASK_STK_SIZE - 1],9);
	
	// Kill own task
	OSTaskDel(OS_PRIO_SELF);
}

void TaskHello(void *pdata)
{
	while(1)
	{
		printf("Hello! ");
		
		// Wait 1 second
		OSTimeDlyHMSM(0,0,1,0);
		
		//check ESC key
		INT16S key;
		BOOLEAN avail = PC_GetKey(&key);
		if (avail == TRUE)
		{
			if (key == 27)		//	escape key
			{
				printf("Exiting..");
				exit(0);
			}
		}
	}
}
