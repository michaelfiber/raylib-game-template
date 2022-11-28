/**
 * @brief Trigger vibration when running as a WASM app in a compatible browser.
 * 
 * @param durations int[] of durations of milliseconds that alternate vibrating and not vibrating.  e.g. {500,500,500} would vibrate for 500ms, stop for 500ms, and then vibrate for 500ms again. Sending 0 stops vibration.
 * @param count Number of durations being passed.
 */
void Vibrate(int *durations, int count);
void StopVibrate();