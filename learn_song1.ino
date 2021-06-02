void song1_led() {
  int melody[] = {
  
    
    LED3,  LED3,  LED4,  LED5,//1
    LED5,  LED4,  LED3,  LED2,
    LED1,  LED1,  LED2,  LED3,
    LED3, LED2,  LED2,
  
    LED3,  LED3,  LED4,  LED5,//1
    LED5,  LED4,  LED3,  LED2,
    LED1,  LED1,  LED2,  LED3,
    LED2, LED1,  LED1
    
  };
  int notes = 30;
  int button;
  int note;
  for (int thisNote = 0; thisNote < notes; thisNote = thisNote + 1) {
    digitalWrite(melody[thisNote],HIGH);
    if (melody[thisNote] == LED1) {
      button = BUTTON_1;
      note = NOTE_C;
    } else if (melody[thisNote] == LED2) {
      button = BUTTON_2;
      note = NOTE_D;
    } else if (melody[thisNote] == LED3) {
      button = BUTTON_3;
      note = NOTE_E;
    } else if (melody[thisNote] == LED4) {
      button = BUTTON_4;
      note = NOTE_F;
    } else if (melody[thisNote] == LED5) {
      button = BUTTON_5;
      note = NOTE_G;
    } else if (melody[thisNote] == LED6) {
      button = BUTTON_6;
      note = NOTE_A;
    }
    while(digitalRead(button) == HIGH)
    {
      tone(Buzz,note);
    }
    while(digitalRead(button) == LOW)
    {
      tone(Buzz,note);
    }
    noTone(Buzz);
    digitalWrite(melody[thisNote],LOW);
    delay(500);
  }
}
