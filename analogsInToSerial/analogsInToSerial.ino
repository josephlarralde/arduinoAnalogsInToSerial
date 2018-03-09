/**
 * @file analogsInToSerial.ino
 * @author joseph.larralde@gmail.com
 * @copyright Copyright (C) 2017 by Joseph Larralde
 * @license GPL-v3.0
 *
 * This program sends analog inputs over serial
 * via a minimalistic message system : it prepends each channel value
 * with a "A0", "A1", ... "A5" message to allow any client to parse
 * the incoming data flow.
 * This file should be distributed together with "analogsInFromSerial.pd"
 * which is an example of how to parse the serial input in pd-extended.
 */

// MAX NB OF DIGITS TO REPRESENT VALUE
// HERE 0000 to 1023 -> WE NEED 4 DIGITS
const int MAXLEN = 4;

typedef struct {
  int id;
  String sid;  
} analogInput;

const analogInput inputs[] = {
  { A0, "A0" },
  { A1, "A1" },
  { A2, "A2" },
  { A3, "A3" },
  { A4, "A4" },
  { A5, "A5" },
};

const int nInputs = sizeof(inputs) / sizeof(inputs[0]);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int value;
  char valueStr[4];
  int len;
  int i;

  // TO DISABLE ANY ANALOG INPUT,
  // JUST COMMENT OUT THE CORRESPONDING BLOCK.

  for (int i = 0; i < nInputs; ++i) {
    Serial.print(inputs[i].sid);
    value = analogRead(inputs[i].id);
    itoa(value, valueStr, 10);
    len = MAXLEN - strlen(valueStr);
    for(i=0;i<len;i++) Serial.print(0);
    Serial.print(value);
  }
    
  delay(10);
}
