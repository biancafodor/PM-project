#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
const int BUTTON_1 = 12;
const int BUTTON_2 = 10;
const int BUTTON_3 = 9;
const int BUTTON_4 = 8;
const int BUTTON_5 = 7;
const int BUTTON_6 = 0;


const int Buzz = 6;
const int LED1 = A0;
const int LED2 = A1;
const int LED3 = A2;
const int LED4 = A3;
const int LED5 = A4;
const int LED6 = A5;

int contrast = 65;

int menuitem = 1;
int page = 1;

volatile boolean down = false;
volatile boolean middle = false;
boolean freemode = false;

int downButtonState = 0;
int selectButtonState = 0;          
int lastDownButtonState = 0;
int lastSelectButtonState = 0;

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 5, 4, 3);


void setup() {

  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);


  ////////////////
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  
  pinMode(BUTTON_1, INPUT);
  digitalWrite(BUTTON_1,HIGH);

  pinMode(BUTTON_2, INPUT);
  digitalWrite(BUTTON_2,HIGH);

  pinMode(BUTTON_3, INPUT);
  digitalWrite(BUTTON_3,HIGH);

  pinMode(BUTTON_4, INPUT);
  digitalWrite(BUTTON_4,HIGH);

  pinMode(BUTTON_5, INPUT);
  digitalWrite(BUTTON_5,HIGH);

  pinMode(BUTTON_6, INPUT);
  digitalWrite(BUTTON_6,HIGH);
  
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  digitalWrite(LED6,LOW);
  //////////////////
  Serial.begin(9600);
  
  display.begin();      
  display.setContrast(contrast); // setez contrastul la 65
  display.clearDisplay(); 
  display.display();   
}

void loop() {
  
  drawMenu();

  downButtonState = digitalRead(2);
  selectButtonState = digitalRead(1);
 
  checkIfDownButtonIsPressed();
  checkIfSelectButtonIsPressed();

  if (down && page == 1) {
    down = false;
    menuitem++;
    if (menuitem==4) 
    {
      menuitem=1;
    }      
  } else if (down && page == 2) {
    down = false;
    menuitem++;
    if (menuitem==4) 
    {
      menuitem=1;
      page = 1;
    } 
  } else if (down && page == 3) {
      down = false;
      menuitem++;
      if (menuitem==4) 
      {
        menuitem=3;
        page = 1;
      }     
  }


  if (middle) {
    middle = false;
    
    if (page == 1) {
      if (menuitem == 2) {
        freemode = true;
        free_mode();
      } else if(menuitem == 3) {
        page = 3;
        menuitem = 1;
      } else if (menuitem == 1) {
        page = 2;
        menuitem = 1;
      }
    } else if (page == 2) {
      if (menuitem == 1) {
        song1();
      } else if (menuitem == 2) {
        song2();
      } else if (menuitem == 3) {
        song3();
      }
    } else if (page == 3) {
      if (menuitem == 1) {
        song1_led();
      } else if (menuitem == 2) {
        song2_led();
      } else if (menuitem == 3) {
        song3_led();
      }
    }
  }
   
}

void checkIfDownButtonIsPressed()
{
  if (downButtonState != lastDownButtonState){
    if (downButtonState == 0) 
    {
      down=true;
    }
    delay(50);
  }
  lastDownButtonState = downButtonState;
}

void checkIfSelectButtonIsPressed()
{
   if (selectButtonState != lastSelectButtonState) 
  {
    if (selectButtonState == 0) {
      middle=true;
    }
    delay(50);
  }
   lastSelectButtonState = selectButtonState;
}

  
void drawMenu()
{
  
  if (page==1) 
  {    
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(15, 0);
    display.print("PIANO MENU");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0, 15);
   
    if (menuitem==1) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }
    display.print(">Singing Mode");
    display.setCursor(0, 25);
   
    if (menuitem==2) 
    {
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }    
    display.print(">Free Mode:");
    
    if (freemode) 
    {
      display.print("ON");
    }
    else 
    {
      display.print("OFF");
    }
    display.display();
    
    if (menuitem==3) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }  
    display.setCursor(0, 35);
    display.print(">Learning Mode");
    display.display();
  }
    
 
  else if (page==2) 
  {
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(15, 0);
    display.print("SONGS");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0, 15);
   
    if (menuitem==1) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }
    display.print(">Ode to joy");
    display.setCursor(0, 25);
   
    if (menuitem==2) 
    {
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }    
    display.print(">Keyboard cat");
    
    
    display.display();
    
    if (menuitem==3) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }  
    display.setCursor(0, 35);
    display.print(">Star wars");
    display.display();
    
  }
  else if (page==3) 
  {
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(15, 0);
    display.print("SONGS");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0, 15);
   
    if (menuitem==1) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }
    display.print(">Ode to joy");
    display.setCursor(0, 25);
   
    if (menuitem==2) 
    {
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }    
    display.print(">Jingle Bells");
    
    
    display.display();
    
    if (menuitem==3) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }  
    display.setCursor(0, 35);
    display.print(">O vioara mica");
    display.display();
    
  }

}
