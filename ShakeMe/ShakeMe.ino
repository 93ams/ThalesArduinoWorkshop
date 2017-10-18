// include the library code:
#include <LiquidCrystal.h>


int lastButtonState, buttonState, buttonPushCounter, shakerPin = 8;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String quotes[8] = {"Yes", "No", "Tomorow", "Today", "Never", "Always", "Tomoray", "Ma man" };

void printRandomQuote(){
  lcd.clear();
  lcd.print(quotes[random(sizeof(quotes))]);
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Shake me!");
}

void loop() {
  buttonState = digitalRead(shakerPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      buttonPushCounter++;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter > 5) {
    printRandomQuote();
    delay(2000);
    lcd.clear();
    lcd.print("Shake me!");
    buttonPushCounter = 0;
  }
}


