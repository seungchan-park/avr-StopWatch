#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "AP/StopWatch/StopWatch.h"


ISR(TIMER0_OVF_vect) // overflow interrupt 조건
{
	FND_ISR_Process();	
	TCNT0 = 130; // 1ms 주기마다 발생하도록 하는 조건 
}

ISR(TIMER2_COMP_vect) // CTC interrupt
{
	StopWatch_incMilisec();
}

int main(void)
{
	StopWatch_init();
	
	sei(); // set enable interrupt (global interrupt)
	
	while (1)
	{
		StopWatch_excute();
		
	}
}

