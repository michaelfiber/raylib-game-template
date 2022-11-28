#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
extern void speak(char *text);
#else
void speak(char *text) {}
#endif

void Say(char *text)
{
	speak(text);
}