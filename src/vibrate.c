#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
extern void vibrate(int duration);
#else
void vibrate(int duration) {}
#endif

void Vibrate(int duration)
{
	vibrate(duration);
}

void StopVibrate()
{
	vibrate(0);
}