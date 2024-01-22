#include "StopWatch.h"

uint8_t stopWatchState;
uint16_t milisec;
uint8_t sec;
uint8_t min;
uint8_t hour;

button_t btnMode, btnReset;

void StopWatch_incMilisec()
{
	if (stopWatchState == RUN)
	{
		milisec = (milisec + 1) % 1000;
	}
	else return;
	
	if (milisec) return;
	
	sec = (sec + 1) % 60;
	if (sec) return;
	
	min = (min + 1) % 60;
	if (min) return;
	
	hour = (hour + 1) % 24;
}

void StopWatch_init()
{
	stopWatchState = STOP;
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	
	Button_init(&btnMode, &DDRA, &PINA, 0);
	Button_init(&btnReset, &DDRA, &PINA, 1);
	FND_init();
	TIM0_init();
	TIM2_init();
}

void StopWatch_excute()
{
	StopWatch_eventCheck();
	StopWatch_run();
}

void StopWatch_eventCheck()
{
	switch(stopWatchState) // event 처리
	{
		case STOP:
		if (Button_getState(&btnMode)==ACT_RELEASED)
		{
			stopWatchState = RUN;
		}
		else if (Button_getState(&btnReset)==ACT_RELEASED)
		{
			stopWatchState = RESET;
		}
		break;
		case RUN:
		if (Button_getState(&btnMode)==ACT_RELEASED)
		{
			stopWatchState = STOP;
		}
		break;
		case RESET:
		stopWatchState = STOP;
		break;
	}
	
}

void StopWatch_run()
{
	uint16_t stopWatchData;
	
	if (stopWatchState == RESET)
	{
		milisec = 0;
		sec = 0;
		min = 0;
		hour = 0;
	}
	stopWatchData = (min%10 * 1000) + (sec * 10) + (milisec / 100 % 10);
	
	FND_setFndData(stopWatchData);
}