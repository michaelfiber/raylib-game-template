#ifndef MYLIBRARY_H
#define MYLIBRARY_H


#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
extern void Say(char *text);
extern void RegisterOrientationPointers(float *beta, float *gamma);
extern void Vibrate(int *durations, int durationCount);
#else
void Say(char *text) {}
void RegisterOrientationPointers(float *beta, float *gamma) {}
void Vibrate(int *durations, int durationCount) {}
#endif

#endif