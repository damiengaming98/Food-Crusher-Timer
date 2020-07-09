#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

const int  buttonPin = 2;// the pin that the pushbutton is attached to
const int Start = 3;
const int RELAY1 = 4;       // the pin that the LED is attached to
const int RELAY2 = 5;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int StartCounter = 0;
int buttonState = 0;         // current state of the button
int StartState = 0;
int lastButtonState = 0;     // previous state of the button
int lastStartState = 1;
unsigned long currentTime = 0;
unsigned long previousTime = 0;
unsigned long difference = 0;
unsigned long minutes = 0;
unsigned long seconds = 0;
int i = 0;
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT_PULLUP); // initialize the LED as an output:
  pinMode(Start, INPUT_PULLUP);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_osb21);
    u8g.setPrintPos(2, 45);
    u8g.print("SANOTA");

  }
  while ( u8g.nextPage());
  delay(250);
}


void loop() {

  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  StartState = digitalRead(Start);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 0) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      //  Serial.println("on");
      // Serial.print("number of button pushes: ");
      // Serial.println(buttonPushCounter);
      if (buttonPushCounter == 1) {
        u8g.firstPage();
        do {
          u8g.setFont(u8g_font_fur17);
          u8g.setPrintPos(10, 40);
          u8g.print("5 Minutes");

        }
        while ( u8g.nextPage());
        delay(250);
      }
      if (buttonPushCounter == 2) {
        u8g.firstPage();
        do {
          u8g.setFont(u8g_font_fur17);
          u8g.setPrintPos(2, 40);
          u8g.print("10 Minutes");

        }
        while ( u8g.nextPage());
        delay(250);
      }
      if (buttonPushCounter == 3) {
        u8g.firstPage();
        do {
          u8g.setFont(u8g_font_fur17);
          u8g.setPrintPos(2, 40);
          u8g.print("15 Minutes");

        }
        while ( u8g.nextPage());
        delay(250);
      }
    }
  }
  if (StartState != lastStartState) {
    // if the state has changed, increment the counter
    if (StartState == 0) {
      // if the current state is HIGH then the button went from off to on:
      ++StartCounter;
      // Serial.println("Start");
      digitalWrite(RELAY1, HIGH);
      digitalWrite(RELAY2, HIGH);

      if (buttonPushCounter == 1 && StartCounter == 1) {                       // Run timer for 5 minute
        previousTime = millis();
        Serial.println(previousTime);
        difference = previousTime - currentTime;
        abs(difference);
        while (difference < 300000) {
          currentTime = millis();
          //Serial.println(currentTime);
          difference = -previousTime + currentTime;
          Serial.println(difference);
          digitalWrite(RELAY1, LOW);
          digitalWrite(RELAY2, LOW);// Turn  LED ON while Timer is running
          delay(11);
          minutes = difference / 60000;
          seconds = difference % 1000;
          if (seconds <= 50) {
            i = i + 1;
            if (i == 60) {
              i = 0;
            }
          }
          u8g.firstPage();
          do {
            u8g.setFont(u8g_font_fur17);
            u8g.setPrintPos(40, 45);
            u8g.print(minutes);
            //    u8g.setPrintPos(15, 40);
            u8g.print(":");
            if (i < 10) {
              u8g.print("0");
            }
            u8g.print(i);
            Serial.println(seconds);
          }
          while ( u8g.nextPage());
          //   delay(250);
        }
        buttonPushCounter == 0;
        difference = 0;
        previousTime == 0;
        currentTime == 0;
        i = 0;
      }
      Serial.println(buttonPushCounter);
      Serial.println(StartCounter);
      // Turn LED OFF  when timer reaches to Zero.
      if (buttonPushCounter == 2 && StartCounter == 1) {                       // Run timer for 10 minute

        previousTime = millis();
        Serial.println(previousTime);
        difference = previousTime - currentTime;
        abs(difference);
        while (difference < 600000) {
          currentTime = millis();
          //          Serial.println(currentTime);
          difference = -previousTime + currentTime;
          //Serial.println(difference);
          digitalWrite(RELAY1, LOW);
          digitalWrite(RELAY2, LOW);// Turn  LED ON while Timer is running
          delay(11);

          minutes = difference / 60000;
          seconds = difference % 1000;

          if (seconds <= 50) {
            i = i + 1;

            if (i == 60) {
              i = 0;
            }
          }
          u8g.firstPage();
          do {
            u8g.setFont(u8g_font_fur17);
            u8g.setPrintPos(40, 45);
            u8g.print(minutes);
            //    u8g.setPrintPos(15, 40);
            u8g.print(":");
            if (i < 10) {
              u8g.print("0");
            }
            u8g.print(i);
            Serial.println(seconds);
          }
          while ( u8g.nextPage());
          //   delay(250);
        }
        buttonPushCounter == 0;
        difference = 0;
        previousTime == 0;
        currentTime == 0;
        i = 0;
      }
      // Serial.println(buttonPushCounter);
      // Serial.println(StartCounter);
      if (buttonPushCounter == 3 && StartCounter == 1) {                         // Run timer for 15 minute
        previousTime = millis();
        Serial.println(previousTime);
        difference = previousTime - currentTime;
        abs(difference);
        while (difference < 900000) {
          currentTime = millis();
          //          Serial.println(currentTime);
          difference = -previousTime + currentTime;
          //Serial.println(difference);
          digitalWrite(RELAY1, LOW);
          digitalWrite(RELAY2, LOW);// Turn  LED ON while Timer is running
          //delay(11);

          minutes = difference / 60000;
          seconds = difference % 1000;

          if (seconds <= 50) {
            i = i + 1;

            if (i == 60) {
              i = 0;
            }
          }
          u8g.firstPage();
          do {
            u8g.setFont(u8g_font_fur17);
            u8g.setPrintPos(40, 45);


            u8g.print(minutes);
            //    u8g.setPrintPos(15, 40);
            u8g.print(":");
            if (i < 10) {
              u8g.print("0");
            }
            u8g.print(i);
            Serial.println(seconds);
          }
          while ( u8g.nextPage());
          delay(11);
        }
        buttonPushCounter == 0;
        difference = 0;
        previousTime == 0;
        currentTime == 0;
        i = 0;
      }


      // Delay a little bit to avoid bouncing
    }

  }
  // Turn LED OFF  when timer reaches to Zero.
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  delay(100);
  //
  //  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  lastStartState = StartState;
  StartCounter = 0;

  //
  if (buttonPushCounter > 3) {
    Serial.println("Reset");
    buttonPushCounter = 0;
  }

}
