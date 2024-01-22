#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#include <avr/io.h>
#include "../../Driver/Button/Button.h"
#include "../../Driver/FND/FND.h"
#include "../../periph/Timer/Timer.h"

enum{STOP, RUN, RESET};
	
void StopWatch_incMilisec();
void StopWatch_init();
void StopWatch_excute();
void StopWatch_eventCheck();
void StopWatch_run();


#endif 