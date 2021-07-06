
uint8_t buf[8] = {
  0
};  // Keyboard Report Buffer: 8 bytes

#define PIN_SPACE A0
#define PIN_AST A1
#define PIN_S A2
#define PIN_D A3
#define PIN_HOME A4

//#define SERIAL_DEBUG  // for serial debug: remove //
                        // for actual HID: put //

bool currState_SPACE = HIGH;
bool currState_AST = HIGH;
bool currState_S = HIGH;
bool currState_D = HIGH;
bool currState_HOME = HIGH;
          
bool prevState_SPACE = HIGH; 
bool prevState_AST = HIGH; 
bool prevState_S = HIGH; 
bool prevState_D = HIGH; 
bool prevState_HOME = HIGH;

unsigned long prevTime_SPACE = 0;
unsigned long prevTime_AST = 0;
unsigned long prevTime_S = 0;
unsigned long prevTime_D = 0;
unsigned long prevTime_HOME = 0;

unsigned long waitTime_SPACE = 50;
unsigned long waitTime_AST = 50;
unsigned long waitTime_S = 50;
unsigned long waitTime_D = 50;
unsigned long waitTime_HOME = 50;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_SPACE, INPUT_PULLUP);
  pinMode(PIN_AST, INPUT_PULLUP);
  pinMode(PIN_S, INPUT_PULLUP);
  pinMode(PIN_D, INPUT_PULLUP);
  pinMode(PIN_HOME, INPUT_PULLUP);
  
  delay(200);
}

void loop() 
{
  checkButton();
}


void checkButton() {

  bool currRead_SPACE = digitalRead(PIN_SPACE);
  bool currRead_AST = digitalRead(PIN_AST);
  bool currRead_S = digitalRead(PIN_S);
  bool currRead_D = digitalRead(PIN_D);
  bool currRead_HOME = digitalRead(PIN_HOME);

  if (currRead_SPACE != prevState_SPACE) {
    prevTime_SPACE = millis();
  }
  if (currRead_AST != prevState_AST) {
    prevTime_AST = millis();
  }
  if (currRead_S != prevState_S) {
    prevTime_S = millis();
  }
  if (currRead_D != prevState_D) {
    prevTime_D = millis();
  }
  if (currRead_HOME != prevState_HOME) {
    prevTime_HOME = millis();
  }

  if ((millis() - prevTime_SPACE) > waitTime_SPACE) {
    if (currRead_SPACE != currState_SPACE) {
      currState_SPACE = currRead_SPACE;
      if (currState_SPACE == LOW) {
        // Send the code
        buf[2] = 44;    // HID: W key
#ifdef SERIAL_DEBUG
        buf[2] = 'Space';     // Serial: W key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_AST) > waitTime_AST) {
    if (currRead_AST != currState_AST) {
      currState_AST = currRead_AST;
      if (currState_AST == LOW) {
        // Send the code
        buf[2] = 85;   // HID: A key
#ifdef SERIAL_DEBUG
        buf[2] = '*';   // Serial: A key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_S) > waitTime_S) {
    if (currRead_S != currState_S) {
      currState_S = currRead_S;
      if (currState_S == LOW) {
        // Send the code
        buf[2] = 22;    // HID: S key
#ifdef SERIAL_DEBUG
        buf[2] = 'S';     // Serial: S key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_D) > waitTime_D) {
    if (currRead_D != currState_D) {
      currState_D = currRead_D;
      if (currState_D == LOW) {
        // Send the code
        buf[2] = 7;   // HID: D key
#ifdef SERIAL_DEBUG        
        buf[2] = 'D';   // Serial: D key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }
  if ((millis() - prevTime_HOME) > waitTime_HOME) {
    if (currRead_HOME != currState_HOME) {
      currState_HOME = currRead_HOME;
      if (currState_HOME == LOW) {
        // Send the code
        buf[2] = 74;   // HID: D key
#ifdef SERIAL_DEBUG        
        buf[2] = 'HOME';   // Serial: D key
#endif
        Serial.write(buf, 8); // Send keypress
      } else {
        // Release the keyboard
        releaseKey();
      }
    }
  }

  prevState_SPACE = currRead_SPACE;
  prevState_AST = currRead_AST;
  prevState_S = currRead_S;
  prevState_D = currRead_D;
  prevState_HOME = currRead_HOME;
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
