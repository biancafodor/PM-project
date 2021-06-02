#define NOTE_A3  220
#define NOTE_G3  196
#define NOTE_B3  247


void song2() {
    // change this to make the song slower or faster
  int tempo = 160;
  
  // change this to whichever pin you want to use
  int buzzer = 6;
  
  // notes of the moledy followed by the duration.
  // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
  // !!negative numbers are used to represent dotted notes,
  // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
  int melody[] = {
  
      REST,1,
      REST,1,
      NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
      NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
      NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
      NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
      NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
      NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,
  
      NOTE_G3,4, NOTE_G3,8, NOTE_G3,-4, NOTE_G3,8, NOTE_G3,4, 
      NOTE_G3,4, NOTE_G3,4, NOTE_G3,8, NOTE_G3,4
    
  };
  
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  
  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;
  
  int divider = 0, noteDuration = 0;
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
