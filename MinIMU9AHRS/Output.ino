

void sendTelemetry()
{
  /*String s = "" + String (accel_x / 26.2 , 2);
  s += " " + String(accel_y / 26.2 , 2);
  s += " " + String(accel_z / 26.2 , 2);
  Serial.write (s); Serial.write(" ");*/
  Serial.write(accel_x * 1000 / 262 >> 8);
  Serial.write(accel_x * 1000 / 262 & mask);
  receiveData();
  delay(5);
  Serial.write(accel_y * 1000 / 262 >> 8);
  Serial.write(accel_y * 1000 / 262 & mask);
  receiveData();
  Serial.write(accel_z * 1000 / 262 >> 8);
  Serial.write(accel_z * 1000 / 262 & mask);
  Serial.write((int)(ToDeg(roll)*100) >> 8);
  Serial.write((int)(ToDeg(roll)*100) & mask);
  receiveData();
  Serial.write((int)(ToDeg(pitch)*100) >> 8);
  Serial.write((int)(ToDeg(pitch)*100) & mask);
  receiveData();
  delay(5);
  Serial.write((int)(ToDeg(yaw)*100) >> 8);
  Serial.write((int)(ToDeg(yaw)*100) & mask);
  receiveData();
  
  /*for (int i=0; i<4; ++i)
  {
    Serial.write(rpm[i] >> 8); 
    Serial.write(rpm[i] & mask); 
    receiveData();
  }
  
  Serial.write((int)(volt_v2*100) >> 8);
  Serial.write((int)(volt_v2*100) & mask);*/
  receiveData();
  delay(5);
  //Serial.write((int)cm >> 8); 
  //Serial.write((int)cm & mask);
  
  Serial.write((int)(pressure * 100) >> 8);
  Serial.write((int)(pressure * 100) & mask);
  Serial.write((int)(altitude * 100) >> 8);
  Serial.write((int)(altitude * 100) & mask); 
  Serial.write((int)(temperature * 100) >> 8);
  Serial.write((int)(temperature * 100) & mask);
  
  Serial.write("\n");
  //debugPrint();
}


long convert_to_dec(float x)
{
  return x*10000000;
}

void debugPrint()
{
  Serial.write(digitalRead(2));
  Serial.write(half_revolutions[0]);
  Serial.write(half_revolutions[1]);
  Serial.write(half_revolutions[2]);
  Serial.write(half_revolutions[3]);
}

void printdata(void)
{    
      /*Serial.print("!");

      #if PRINT_EULER == 1
      Serial.print("ANG:");
      Serial.print(ToDeg(roll));
      Serial.print(",");
      Serial.print(ToDeg(pitch));
      Serial.print(",");
      Serial.print(ToDeg(yaw));
      #endif      
      #if PRINT_ANALOGS==1
      Serial.print(",AN:");
      Serial.print(AN[0]);  //(int)read_adc(0)
      Serial.print(",");
      Serial.print(AN[1]);
      Serial.print(",");
      Serial.print(AN[2]);  
      Serial.print(",");
      Serial.print(AN[3]);
      Serial.print (",");
      Serial.print(AN[4]);
      Serial.print (",");
      Serial.print(AN[5]);
      Serial.print(",");
      Serial.print(c_magnetom_x);
      Serial.print (",");
      Serial.print(c_magnetom_y);
      Serial.print (",");
      Serial.print(c_magnetom_z);
      #endif
      /*#if PRINT_DCM == 1
      Serial.print (",DCM:");
      Serial.print(convert_to_dec(DCM_Matrix[0][0]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[0][1]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[0][2]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[1][0]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[1][1]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[1][2]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[2][0]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[2][1]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[2][2]));
      #endif*/
      /*Serial.print("p: ");
      Serial.print(pressure);
      Serial.print(" mbar\ta: ");
      Serial.print(altitude);
      Serial.print(" m\tt: ");
      Serial.print(temperature);
      Serial.println(" deg C");
      Serial.println();    */
      
}

