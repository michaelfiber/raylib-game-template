#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
extern void Say(char *text);
#else
void Say(char *text) {}
#endif