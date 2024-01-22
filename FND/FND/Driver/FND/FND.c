#include "FND.h"

uint16_t fndData = 0;

void FND_init()
{
	//FNC 출력모드
	FND_DIGIT_DDR |= ((1<<FND_DIGIT_4)|(1<<FND_DIGIT_3)|(1<<FND_DIGIT_2)|(1<<FND_DIGIT_1));
	FND_DATA_DDR =0xff;
}

void FND_dispNum(uint16_t fndNum)
{
	uint8_t fndFont[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
	// 0      1     2     3     4    5     6     7     8     9
	static uint8_t fndDigitState = 0;
	fndDigitState = (fndDigitState + 1) % 4;
	
	FND_DIGIT_PORT |= ((1<<FND_DIGIT_4)|(1<<FND_DIGIT_3)|(1<<FND_DIGIT_2)|(1<<FND_DIGIT_1)); // FND 전부 OFF
	
	switch(fndDigitState)
	{
		case 0:
		FND_DATA_PORT = fndFont[fndNum/1000%10]; // %10을 하는 이유는 uint16값이 천의자리 이상일 수도 있기 때문
		FND_DIGIT_PORT &= ~(1<<4); // 천의자리
		break;
		case 1:
		FND_DATA_PORT = fndFont[fndNum/100%10];
		FND_DIGIT_PORT &= ~(1<<5); // 백의자리
		break;
		case 2:
		FND_DATA_PORT = fndFont[fndNum/10%10];
		FND_DIGIT_PORT &= ~(1<<6); // 십의자리
		break;
		case 3:
		FND_DATA_PORT = fndFont[fndNum%10];
		FND_DIGIT_PORT &= ~(1<<7); // 일의자리
		break;
	}
}
//seter
void FND_setFndData(uint16_t data) // main에서 100ms마다 올린 counter
{
	fndData = data; // fndData는 FND.c에서만 사용
}

void FND_ISR_Process()
{
	FND_dispNum(fndData);
}