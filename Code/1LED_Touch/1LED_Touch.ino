int ledPin = 10;  // LED connected to digital pin 9
int buttonPin = 6;  // LED connected to digital pin 9
int fadeValueState = 0;

enum states { //Define states
  fadeUp,
  fadeDown,
  buttonHold,
  offState
};

states procState = offState; //Init state

void setup()
{
  // nothing happens in setup
}

void loop()
{
  switch(procState)
  {
    case offState:
      analogWrite(ledPin, 0); // Set LED to minimum brightness

      if(digitalRead(buttonPin) == HIGH)
      {
        procState = fadeUp;
      }

      break;

    case fadeUp:
      for (int fadeValue = 0; fadeValue <= 255; fadeValue += 15) // fade in from min to max in increments of 5 points:
      { 
        analogWrite(ledPin, fadeValue); // sets the value (range from 0 to 255):
        delay(30); // wait for 30 milliseconds to see the dimming effect
      }

      if(digitalRead(buttonPin) == HIGH)
      {
        procState = buttonHold;
      }

      else
      {
        procState = fadeDown;
      }

      break;

    case fadeDown:
       for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 8) // fade out from max to min in increments of 5 points:
        {
          analogWrite(ledPin, fadeValue);
          delay(30); // wait for 30 milliseconds to see the dimming effect

          if(digitalRead(buttonPin) == HIGH)
          {
            procState = fadeUp;

            break;
          }
        }

      if(digitalRead(buttonPin) == HIGH)
      {
        procState = fadeUp;
      }

      else
      {
        procState = offState;
      }

      break;

    case buttonHold:
      analogWrite(ledPin, 255); // Set LED to maximum brightness

      if(digitalRead(buttonPin) == HIGH)
      {
        procState = buttonHold;
      }

      else
      {
        procState = fadeDown;
      }

  }
}
