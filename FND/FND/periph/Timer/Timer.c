#include "Timer.h"

void TIM0_init() // 1ms Overflow Interrupt, Display
{
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (1<<CS00)); // 128 PreScaler xxxxxxxx -> xxxxx101
	TIMSK |= (1<<TOIE0); // TIMSK Timer/Counter0 Overflow Interrupt Enable
	TCNT0 = 130; // 1ms마다 interrupt발생
}

void TIM2_init() // 1ms CTC mode Interrupt, Time
{
	TCCR2 |= ((0<<CS22) | (1<<CS21) | (1<<CS20)); // 64 PreScaler
	TCCR2 |= ((1<<WGM21)|(0<<WGM20)); // CTC Mode 
	TIMSK |= ((1<<OCIE2)); // Timer/Counter2 Output Compare Interrupt Enable
	OCR2 = 250 - 1; // 1ms마다 interrupt발생
}