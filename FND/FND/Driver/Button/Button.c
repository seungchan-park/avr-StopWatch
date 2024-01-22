#include "Button.h"

void Button_init(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{	
	// 구조체에 버튼에서 사용하는 변수들 초기화
	btn->DDR = ddr;
	btn->PIN = pin;
	btn->pinNum = pinNum;
	btn->prevState = RELEASED;
	GPIO_initPin(btn->DDR, btn->pinNum, INPUT);
}

uint8_t Button_getState(button_t *btn)
{
	uint8_t curState = GPIO_readPin(btn->PIN, btn->pinNum); // PULL-UP이므로 버튼이 안눌리면 1 눌리면 0
	
	if ((curState == PUSHED) && (btn->prevState == RELEASED))
	{
		_delay_ms(10); // bouncing 방지
		btn->prevState = PUSHED;
		return ACT_PUSHED; // 리턴값이 1이면 눌렀을때 동작 0이면 뗐을때 동작
	}
	else if ((curState != PUSHED) && (btn->prevState == PUSHED))
	{
		_delay_ms(10);
		btn->prevState = RELEASED;
		return ACT_RELEASED; // 리턴값이 0이면 눌렀을때 동작 1이면 뗐을때 동작
	}
	return ACT_NONE;
}