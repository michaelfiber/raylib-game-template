#include "stdlib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
extern void Vibrate(int *durations, int durationCount);
#else
void Vibrate(int *durations, int durationCount) {}
#endif

void StopVibrate()
{
	int zero[] = {0};
	Vibrate(zero, 1);
}
