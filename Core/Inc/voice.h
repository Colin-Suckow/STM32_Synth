/*
 * voice.h
 *
 *  Created on: Jan 9, 2020
 *      Author: colin
 */

#ifndef INC_VOICE_H_
#define INC_VOICE_H_

#define SAMPLE_RATE 4000000
#define PI 3.14159

//ADSR Constants
#define ATTACK_DELTA 0.02
#define ATTACK_PEAK 0.4
#define SUSTAIN_PEAK 0.2
#define DECAY_DELTA 0.00001


enum voice_state {
	sustain= 1,
	decay = 2,
	attack = 3,
	inactive = 0
};

struct voice {
	float currentAngle;
	float angleDelta;
	enum voice_state state;
	int frequency;
	float gain;
};


int get_voice_out(struct voice* voice);

void update_voice(struct voice* voice);

void set_frequency(struct voice* voice, int freq);

#endif /* INC_VOICE_H_ */
