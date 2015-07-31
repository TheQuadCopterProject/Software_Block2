#include <Servo.h>
#include <Wire.h>
#include <math.h>

void manualFlight()
{
  int motorSum = 0;
    for (int i = 0; i < mCount; ++i) {
            motorPos [i] = Serial.parseInt();  
            motorSum += motorPos [i];
            if ((motorPos [i] != 40 && motorPos [i] != 0 && motorPos[i] < 62) || 
                (motorPos[i] > 114) )//||
                //(abs(motorPos[i]-previousMotorPos[i]) > 60))
            {
                motorPos [i] = (badReceiveCounter >= 10 ? 40 : previousMotorPos [i]);
                ++badReceiveCounter; 
                continue;
            }
            badReceiveCounter = 0;         
            if (motorPos [i] != 0)
            {
                if (i == 2)
                {
                    motorPos [i] = motorPos [i] + 1; 
                }  
            }
    }
    int chkSum = Serial.parseInt();
    if (chkSum != motorSum)
      ++badReceiveCounter;
    for (int i = 0; i < mCount; ++i) {
       if (chkSum != motorSum)
         motors [i].write (previousMotorPos[i]);
       else {
         previousMotorPos[i] = motorPos[i];
         motors [i].write (motorPos[i]); 
       }
    }
}
