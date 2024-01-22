#include "GPIO.h"

void GPIO_initPort(volatile uint8_t *DDR, uint8_t dir)
{                                  // INPUT방향 OR OUTPUT방향
	if (dir == OUTPUT)
	{
		*DDR = 0xff; // 포트 전체 Output
	}
	else
	{
		*DDR = 0x00; // 포트 전체 Input
	}
}

void GPIO_initPin(volatile uint8_t *DDR, uint8_t pinNum, uint8_t dir)
{
	if (dir == OUTPUT)
	{
		*DDR |= (1<<pinNum); // pinNum을 Output으로
	}
	else
	{
		*DDR &= ~(1<<pinNum); // pinNum을 Input으로
	}
}

void GPIO_writePort(volatile uint8_t *PORT, uint8_t data)
{
	*PORT = data;
}

void GPIO_writePin(volatile uint8_t *PORT, uint8_t pinNum, uint8_t state)
{
	if (state == GPIO_PIN_SET)
	{
		*PORT |= (1<<pinNum);
	}
	else
	{
		*PORT &= ~(1<<pinNum);
	}
}

uint8_t GPIO_readPort(volatile uint8_t *PIN)
{
	return *PIN;
}

uint8_t GPIO_readPin(volatile uint8_t *PIN, uint8_t pinNum)
{
	return ((*PIN & (1<<pinNum)) != 0); // 예를들어 버튼이0b000x0000이면 0인지 아닌지 비교
}