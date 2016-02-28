//
// Description:
//   https://www.puzzlingquest.com/2016/02/28/arduino/arduino-day-6-analog-outputs-and-pwm/
//   https://youtu.be/KLG7XRSCI7Q
//   Fades an RGB LED through six different cycles.
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

// These will track our RGB values, from 0 to 255.
int redValue = 0;
int blueValue = 0;
int greenValue = 0;

// These represent the "direction" that we are incrementing or decrementing the RGB values.
// We start with red increasing.
int redMultiplier = 1;
int blueMultiplier = 0;
int greenMultiplier = 0;

void loop() {
  // First, we move the RGB values based on current direction.
  redValue = redValue + redMultiplier;
  blueValue = blueValue + blueMultiplier;
  greenValue = greenValue + greenMultiplier;

  // Stage 1: Red increases until it's 255.
  if (redValue == 255 && redMultiplier == 1)
  {
    redMultiplier = 0;
    blueMultiplier = 1;
  }
  // Stage 2: Blue increases until it's 255.
  else if (blueValue == 255 && blueMultiplier == 1)
  {
    blueMultiplier = 0;
    greenMultiplier = 1;
  }
  // Stage 3: Green  increases until it's 255.
  else if (greenValue == 255 && greenMultiplier == 1)
  {
    greenMultiplier = 0;
    redMultiplier = -1;
  }
  // Stage 4: Red DEcreases until it's back to 0.
  else if (redValue == 0 && redMultiplier == -1)
  {
    redMultiplier = 0;
    blueMultiplier = -1;
  }
  // Stage 5: Blue decreases until it's back to 0.
  else if (blueValue == 0 && blueMultiplier == -1)
  {
    blueMultiplier = 0;
    greenMultiplier = -1;
  }
  // Stage 6: Green  decreases until it's back to 0.
  else if (greenValue == 0 && greenMultiplier == -1)
  {
    // We setup for stage 1 again.
    greenMultiplier = 0;
    redMultiplier = 1;
  }
 
  // Output the updated RGB values, and delay slightly to taste 
  analogWrite(redPin, redValue);
  analogWrite(bluePin, blueValue);
  analogWrite(greenPin, greenValue);
  delay(1);
}

