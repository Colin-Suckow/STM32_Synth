/*
 * midi_callbacks.h
 *
 *  Created on: Jan 16, 2020
 *      Author: colin
 */

#ifndef INC_MIDI_CALLBACKS_H_
#define INC_MIDI_CALLBACKS_H_


void note_on(char chan, char data1, char data2);
void note_off(char chan, char data1, char data2);

int midiNoteTable[];
int midiFreqTable[];

#endif /* INC_MIDI_CALLBACKS_H_ */
