#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 493



void free_mode()
{

  while (1) {
    drawMenu();

    selectButtonState = digitalRead(1);
    checkIfSelectButtonIsPressed();
    if (middle) {
      middle = false;
      freemode = false;
      break;
    }
    loop1();
  }
  
}

void loop1()
{
 
  while(digitalRead(BUTTON_1) == LOW)
  {
    tone(Buzz,NOTE_C);
    digitalWrite(LED1,HIGH);
  }


  while(digitalRead(BUTTON_2) == LOW)
  {
    tone(Buzz,NOTE_D);
    digitalWrite(LED2,HIGH);
  }

  while(digitalRead(BUTTON_3) == LOW)
  {
    tone(Buzz,NOTE_E);
    digitalWrite(LED3,HIGH);
  }

  while(digitalRead(BUTTON_4) == LOW)
  {
    tone(Buzz,NOTE_F);
    digitalWrite(LED4,HIGH);
  }

  while(digitalRead(BUTTON_5) == LOW)
  {
    tone(Buzz,NOTE_G);
    digitalWrite(LED5,HIGH);
  }

  while(digitalRead(BUTTON_6) == LOW)
  {
    tone(Buzz,NOTE_A);
    digitalWrite(LED6,HIGH);
  }

  noTone(Buzz);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  digitalWrite(LED6,LOW);


}
