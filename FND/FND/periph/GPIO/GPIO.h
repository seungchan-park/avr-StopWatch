#ifndef GPIO_H_
#define GPIO_H_
#include <avr/io.h>

enum{INPUT, OUTPUT};
enum{GPIO_PIN_RESET, GPIO_PIN_SET};

void GPIO_initPort(volatile uint8_t *DDR, uint8_t dir);
void GPIO_initPin(volatile uint8_t *DDR, uint8_t pinNum, uint8_t dir);
void GPIO_writePort(volatile uint8_t *PORT, uint8_t data);
void GPIO_writePin(volatile uint8_t *PORT, uint8_t pinNum, uint8_t state);
uint8_t GPIO_readPort(volatile uint8_t *PIN);
uint8_t GPIO_readPin(volatile uint8_t *PIN, uint8_t pinNum);

#endif 