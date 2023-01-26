#include "sound.h"

void audio_setup(){
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
}

void play_audio(audioToPlay toPlay){
    double speed;
    uint16_t note_length = 0;// sizeof(melody)/sizeof(melody[0]); 
	struct noteStruct (*cur_music);  // gotta double check this
    
    switch(toPlay){
        case(START_UP):
			break;
        case(AMM_ALARM):
			cur_music = dejavu;
			speed = DEJAVU_SPEED;
			break;
        case(WL_ALARM):
			cur_music = dejavu;
			speed = DEJAVU_SPEED;
			break;
        default:
			return;
    }
    note_length = sizeof(cur_music)/sizeof(cur_music[0]);
    for (int thisNote = 0; thisNote < note_length; thisNote++) { // just follow the original, cuz need cut the music
        double duration = cur_music[thisNote].duration * speed;
        if (cur_music[thisNote].note != REST){
        ledcWriteNote(BUZZER_CHANNEL, cur_music[thisNote].note, cur_music[thisNote].octave);
    //      delay(duration);
        } else {
        ledcWriteTone(BUZZER_CHANNEL, 0);
    //      delay(duration * 2);
        }  
        delay(duration);
        ledcWriteNote(BUZZER_CHANNEL, REST, cur_music[thisNote].octave);    
        delay(duration);
    }
}