#if defined(PLATFORM_WEB)
extern void RegisterOrientationPointers(float *beta, float *gamma);
#else
void RegisterOrientationPointers(float *beta, float *gamma) {}
#endif