

void dir_error_check() {

  while(1) {
    
    int gyro_value = hmc5883l_GetHeading();
    int gyro_error = gyro_value - gyro_read;

    if (gyro_error > 180) {
      gyro_error = gyro_error - 360;
    }
    else if (gyro_error < -180) {
      gyro_error = gyro_error + 360;
    }

    if ( abs(gyro_error) <= 5) {
      break;
    }
    else {
      analogWrite(motorB_PWM, 55);
      analogWrite(motorA_PWM, 55);
    }
    
    if ( gyro_error > 0 ) {
      // turn left

      digitalWrite(motorPinA1, HIGH);
      digitalWrite(motorPinA2, LOW);
      digitalWrite(motorPinB1, LOW);
      digitalWrite(motorPinB2, HIGH);

      delay(60);

      digitalWrite(motorPinA1, LOW);
      digitalWrite(motorPinA2, LOW);
      digitalWrite(motorPinB1, LOW);
      digitalWrite(motorPinB2, LOW);
      
      delay(90);
      
    }
    else if ( gyro_error < 0 ) {
      // turn right

      digitalWrite(motorPinB1, HIGH);
      digitalWrite(motorPinB2, LOW);
      digitalWrite(motorPinA1, LOW);
      digitalWrite(motorPinA2, HIGH);

      delay(60);
      
      digitalWrite(motorPinA1, LOW);
      digitalWrite(motorPinA2, LOW);
      digitalWrite(motorPinB1, LOW);
      digitalWrite(motorPinB2, LOW);

      delay(90);
    }

  
  }

  
}
