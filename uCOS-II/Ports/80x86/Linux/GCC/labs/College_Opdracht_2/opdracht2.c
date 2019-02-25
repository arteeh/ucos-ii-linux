#include "includes.h"

#define TASK_STK_SIZE 256

OS_STK TaskStartStack[TASK_STK_SIZE];
OS_STK TaskTilesStack[TASK_STK_SIZE];

void TaskStart(void *pdata);
void TaskTiles(void *pdata);

int main()
{
	OSInit();
	PC_DispClrScr(DISP_BGND_WHITE); 
	OSTaskCreate(TaskStart, NULL, &TaskStartStack[TASK_STK_SIZE - 1],10);
	OSStart();
	
	return 1;
}

void TaskStart(void *pdata)
{
	OSTaskCreate(TaskTiles, (void *)(DISP_BGND_GREEN + DISP_FGND_WHITE), &TaskTilesStack[TASK_STK_SIZE - 1],9);
	
	while(1)
	{
		INT16S key;
		BOOLEAN avail = PC_GetKey(&key);
		if (avail)
		{
			if (key == 27)
			{
				PC_DispClrScr(DISP_BGND_BLACK); 
				exit(0);
			}
		}
		OSTimeDlyHMSM(0,0,1,0);
	}
}

void TaskTiles(void *pdata)
{
	int color = (int)pdata;
	while(1)
	{
		INT8U x = get_random(80);
		INT8U y = get_random(24);
		PC_DispChar(x, y, ' ', color);
		OSTimeDlyHMSM(0,0,1,0);
	}
}

int get_random(int border)
{
	return (double)rand() / (RAND_MAX + 1) * border;
}
