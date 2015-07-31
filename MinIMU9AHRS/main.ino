#include <Wire.h>
#include <Servo.h>
#include <math.h>



void setup() {
  
  
  for (int i = 0; i < mCount; ++i) {
    motors [i].attach (ports [i]);
    motorPos [i] = 0;
    motors [i].write (motorPos [i]);
  }
  //Setup serial connection
  Serial.begin(115200);
  Serial.setTimeout(8);
  
  delay(3000);
  
  for (int i = 0; i < mCount; ++i) {
    motorPos [i] = 50;
    motors [i].write (motorPos[i]);
  }

  
  pololuSetup();
  //attachRPMSensors();
  
  delay(2000);

  analogWrite(1, LOW);
}

//Read commands and set the motors
void loop() {
  
  receiveData();
  receiveData();

  sensors();
}

void receiveData() {
  if (Serial.available()) {
    flightMode = Serial.parseInt();
     if (flightMode == 1) { 
        manualFlight();
     }
     
     if (flightMode == 2) {
        stabilisedHover();
     }
  
  lastSignalTime = millis();
  }
  
  if (millis() - lastSignalTime > 1500) {
  for (int i = 0; i < mCount; ++i) {
     motors [i].write (40); 
    }
  }
}
