

#define Declination       -0.00669
#define hmc5883l_address  0x1E


void stop_mouse() {
      
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA2, LOW);

  delay(100);

  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);

  analogWrite(motorB_PWM, 0);
  analogWrite(motorA_PWM, 0);

  Serial.println("stop");
 
}




void move_forward_combine(){
  digitalWrite(PB10, HIGH);
  
  
  double Kp_gyro = 1.1; // Proportional gain - 1
  double Ki_gyro = 0.2; // Integral gain - 0.2
  double Kd_gyro = 0; // Derivative gain
  int gyro_error = 0;
  double gyro_prevError = 0;
  double gyro_integral = 0;
  double gyro_derivative = 0;

  left_E_count = 0;
  right_E_count = 0;

//  int gyro_read = hmc5883l_GetHeading();
  
  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB2, HIGH);
  digitalWrite(motorPinA1, LOW); 
  digitalWrite(motorPinB1, LOW);
  
  delay(150);

  while(1) {
    int gyro_N_read = hmc5883l_GetHeading();

    if ((gyro_N_read - gyro_read) > 300){
      gyro_error = -(360 - (gyro_N_read - gyro_read));
    }
    else if ((gyro_N_read - gyro_read) < -300){
      gyro_error = 360 + (gyro_N_read - gyro_read);
    }
    else {
      gyro_error = gyro_N_read - gyro_read;
    }
    
    gyro_integral = gyro_integral + gyro_error;
    gyro_derivative = gyro_error - gyro_prevError;

    double gyro_speed_diff = Kp_gyro*gyro_error + Ki_gyro*gyro_integral + Kd_gyro*gyro_derivative;

    
    int leftSpeed = 100 - gyro_speed_diff;
    int rightSpeed = 100 + gyro_speed_diff;

    if (rightSpeed < 0){
      rightSpeed = 0;
    }

    if (leftSpeed < 0) {
      leftSpeed=0;
    }

    analogWrite(motorB_PWM, rightSpeed);
    analogWrite(motorA_PWM, leftSpeed);

//    Serial.print("gyro_read :");
//    Serial.print(gyro_read);
//    Serial.print(" gyro_N_read :");
//    Serial.print(gyro_N_read);
//    Serial.print(" gyro_error :");
//    Serial.print(gyro_error);
//    Serial.print(" right:");
//    Serial.print(rightSpeed);
//    Serial.print(" left :");
//    Serial.println(leftSpeed);
    
    gyro_prevError = gyro_error;

    delay(150);

    if ((left_E_count + right_E_count)/2 >= 200) {      
      left_E_count = 0;
      right_E_count = 0;
      stop_mouse();
      
      break;
    }  

  }
  digitalWrite(PB10, LOW);
  
}

void turn_Rgyro_90() {

  digitalWrite(PB0, HIGH);

  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH); 

  while (1) {
    int now_read = hmc5883l_GetHeading();
    int turn_read = now_read - gyro_read;

    if ( turn_read <= -180) {
      turn_read = turn_read + 360;
    }
    Serial.print(now_read);
    Serial.print(" -" );
    Serial.print(gyro_read);
    Serial.print(" ");
    Serial.println(turn_read);
  
    if ( turn_read > 80 ) {
      digitalWrite(motorPinA1, HIGH);
      digitalWrite(motorPinA2, LOW); 
      digitalWrite(motorPinB1, LOW);
      digitalWrite(motorPinB2, HIGH);

      delay(20);

      digitalWrite(motorPinA1, LOW);
      digitalWrite(motorPinA2, LOW); 
      digitalWrite(motorPinB1, LOW);
      digitalWrite(motorPinB2, LOW);
  
      break;
    }
    else {
      delay(150);
    }
  }

  digitalWrite(PB0, LOW);
  
}
