/*
 * voice.c
 *
 *  Created on: Jan 9, 2020
 *      Author: colin
 */


#include "voice.h"
#include <math.h>
#include "wave_tables.h"

double interpolate_segment(double x0, int y0, double x1, int y1, double x);

int get_voice_out(struct voice* voice) {

	//TODO Implement interpolation
	int val = wavetable_sine[(int) voice->currentAngle] - 2048;
	//double cAngle = voice->currentAngle;
	//int val = (int) interpolate_segment((int) cAngle, wavetable_sine[(int) cAngle] ,(int) cAngle + 1, wavetable_sine[(int) cAngle + 1], cAngle);
	return (val * voice->gain);
}

void update_voice(struct voice* voice) {
	voice->currentAngle += voice->angleDelta;
	if (voice->currentAngle > WAVE_SAMPLE_COUNT) voice->currentAngle = 0;

	switch(voice->state) {
		case attack:
			if(voice->gain > ATTACK_PEAK) {
				voice->state = sustain;
				break;
			}
			voice->gain += ATTACK_DELTA;
			break;
		case sustain:
			if(voice->gain < SUSTAIN_PEAK) {
				break;
			}
			voice->gain -= ATTACK_DELTA;
			break;
		case decay:
			if(voice->gain <= 0) {
				voice->state = inactive;
				break;
			}
			voice->gain -= DECAY_DELTA;
			if(voice->gain < 0) voice->gain = 0;
			break;
		case inactive:
			voice->gain = 0;
			break;
		default:
			break;
	}


}

void set_frequency(struct voice* voice, int freq) {
	voice->angleDelta = freq/200.0;
	voice->frequency = freq;
}

/**
* Returns the interpolated y-value.
* Saturates to y0 or y1 if x outside interval [x0, x1].
*/
double interpolate_segment(double x0, int y0, double x1, int y1, double x)
{
    double t;

    if (x <= x0) { return y0; }
    if (x >= x1) { return y1; }

    t =  (x-x0);
    t /= (x1-x0);

    return y0 + t*(y1-y0);
}
