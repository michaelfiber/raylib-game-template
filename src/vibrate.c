#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
extern void Vibrate(int duration, ...);
#else
void Vibrate(int duration, ...) {}
#endif

void StopVibrate()
{
	Vibrate(0);
}
