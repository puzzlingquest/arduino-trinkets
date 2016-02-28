//
// Description:
//   https://www.puzzlingquest.com/2016/02/28/arduino/arduino-day-6-analog-outputs-and-pwm/
//   Fades an RGB LED from "off" to "yellow" and back again, in a cycle.
//
// GENERIC DISCLAIMER:
//   This is sample tutorial code for Arduino. It was written for the Arduino Uno
//   as part of generating the tutorials at www.puzzlingquest.com. It comes without any
//   warranty or gaurantees of any kind. It may not follow all best practices, in the
//   interest of shorter, easier-to-understand tutorial code.
//


// Setup our LED pins. Your RGB LED should be connected to these three pins.
const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Fade from "off" to "yellow" (red + green fully on)
  for (int value = 0; value <= 255; ++value)
  {
    analogWrite(redPin, value);
    analogWrite(greenPin, value);
    delay(1);
  }
  
  // Fade from "yellow" to "off"
  for (int value = 255; value >= 0; --value)
  {
    analogWrite(redPin, value);
    analogWrite(greenPin, value);
    delay(1);
  }
}
