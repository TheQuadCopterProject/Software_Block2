void stabilisedHover()
{
 int medianMotorPos = 0;
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
    if (chkSum != motorSum) {
      ++badReceiveCounter;
    }
    
    medianMotorPos = motorSum / 4;
         
    for (int i = 0; i < mCount; ++i) {
      motorPos[i] = medianMotorPos;
    }
         
    //pitchDifferential = 1/6 * ToDeg(pitch);
    
    float deltaPitch = ToDeg(pitch) - previousPitch;
    float deltaTime = millis() - previousPitchTime;
    
    if (ToDeg(pitch) < -0.75) {
      if (deltaPitch / deltaTime <= (3/50) + (3/50/10) && deltaPitch / deltaTime >= (3/50) - (3/50/10)) {
      }
      else {
        if (deltaPitch / deltaTime <= (3/50)) {
          pitchDifferential += 0.05 * (deltaTime / 10) - (ToDeg(pitch)/400);
        }
      
        if (deltaPitch / deltaTime >= (3/50)) {
          pitchDifferential -= 0.05 * (deltaTime / 10) + (ToDeg(pitch)/400);
        }
      }
    }
    
    if (ToDeg(pitch) > 0.75) {
      if (deltaPitch / deltaTime <= (3/50) + (3/50/10) && deltaPitch / deltaTime >= (3/50) - (3/50/10)) { 
      }
      else {
        if (deltaPitch / deltaTime <= (3/50)) {
          pitchDifferential -= 0.05 * (deltaTime / 10) - (ToDeg(pitch)/400);
        } 
        if (deltaPitch / deltaTime >= (3/50)) {
          pitchDifferential += 0.05 * (deltaTime / 10) + (ToDeg(pitch)/400);
        }
      }
    }
    
    else {
      pitchDifferential = 0; 
    }

    motorPos [0] += (int) pitchDifferential;
    motorPos [1] += (int) pitchDifferential;
    motorPos [2] -= (int) pitchDifferential;
    motorPos [3] -= (int) pitchDifferential;
    
    previousPitch = ToDeg(pitch);
    previousPitchTime = millis();
      
    for (int i = 0; i < mCount; ++i) {
       if (chkSum != motorSum)
         motors [i].write (previousMotorPos[i]);
         
       else {
         previousMotorPos[i] = motorPos[i];
         motors [i].write (motorPos[i]);
       }
    }
    
}


