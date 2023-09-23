
// Constants for control
// 1. Kp = 15; Ki = 0; Kd = 0; encoder_move_box = 310; encoder_move_speed = 100;

double Kp = 10; // Proportional gain
double Ki = 1; // Integral gain
double Kd = 0; // Derivative gain
double prevError = 0;
double integral = 0;
int delta_Speed=0;

int encoder_move_box = 310;
int encoder_move_speed = 100;

// encoder 90 turn value 
// 1. encoder_90_R_count = 125; encode_90_R_speed = 80;

int encoder_90_R_count = 125;
int encoder_180_R_count = 250;
int encode_90_R_speed = 80;


void move_M_stop() {

  analogWrite(motorA_PWM, encoder_move_speed);
  analogWrite(motorB_PWM, encoder_move_speed);

  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA2, LOW);

  delay(50);

  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);

  analogWrite(motorB_PWM, 0);
  analogWrite(motorA_PWM, 0);

  Encode_error = (left_E_count + right_E_count)/2 - encoder_move_box;

  Serial.println("stop");
 
}

void move_M_turnL(){
  left_E_count = 0;
  right_E_count = 0;

  prevError = 0;
  integral = 0;

  analogWrite(motorA_PWM, encode_90_R_speed);
  analogWrite(motorB_PWM, encode_90_R_speed);

  while (left_E_count < encoder_90_R_count && right_E_count < encoder_90_R_count) {
    digitalWrite(motorPinA1, HIGH);
    digitalWrite(motorPinA2, LOW);
    digitalWrite(motorPinB1, LOW);
    digitalWrite(motorPinB2, HIGH);
  }

  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);

  delay(50);
  
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}


void move_M_turn_B() {
  left_E_count = 0;
  right_E_count = 0;

  prevError = 0;
  integral = 0;

  analogWrite(motorA_PWM, encode_90_R_speed);
  analogWrite(motorB_PWM, encode_90_R_speed);

  while (left_E_count < encoder_180_R_count && right_E_count < encoder_180_R_count) {
    digitalWrite(motorPinA1, HIGH);
    digitalWrite(motorPinA2, LOW);
    digitalWrite(motorPinB1, LOW);
    digitalWrite(motorPinB2, HIGH);
  }

  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);

  delay(50);
  
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}



void move_M_turnR(){

  left_E_count = 0;
  right_E_count = 0;

  prevError = 0;
  integral = 0;

  analogWrite(motorB_PWM, encode_90_R_speed);
  analogWrite(motorA_PWM, encode_90_R_speed);

  while (left_E_count < encoder_90_R_count && right_E_count < encoder_90_R_count) {
    digitalWrite(motorPinB1, HIGH);
    digitalWrite(motorPinB2, LOW);
    digitalWrite(motorPinA1, LOW);
    digitalWrite(motorPinA2, HIGH);
  }

  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);

  delay(50);
    
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}


void move_M_forward() {

  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB2, HIGH);
  digitalWrite(motorPinA1, LOW); 
  digitalWrite(motorPinB1, LOW);
  
  while (1) {
    // Calculate error for both encoders

    int Error = left_E_count - right_E_count;
    //int Error = 0;
    
    
    // Calculate integral and derivative terms
    integral += Error;
    double derivative = Error- prevError;
    
    // Calculate motor speed adjustments based on PID control
    delta_Speed = Kp * double(Error) + Ki * integral + Kd * derivative;
    
    int leftSpeed = encoder_move_speed - delta_Speed;
    int rightSpeed= encoder_move_speed + delta_Speed;

    if (rightSpeed<0){
      rightSpeed = 0;
    }

    if (leftSpeed<0) {
      leftSpeed=0;
    }
    
    //
    //  // Apply motor speed adjustments to achieve forward motion
    analogWrite(motorB_PWM, rightSpeed);
    analogWrite(motorA_PWM, leftSpeed);
    //
    //  // Update previous error for the next iteration
    prevError = Error;
  
//    Serial.print("Left Count: ");
//    Serial.print(left_E_count);
//    Serial.print(", Right Count: ");
//    Serial.print(right_E_count);
//    Serial.print("Left speed: ");
//    Serial.print(leftSpeed);
//    Serial.print(", Right speed: ");
//    Serial.println(rightSpeed);

    if ((left_E_count + right_E_count)/2 > encoder_move_box) {
      move_M_stop();
      break;
    }
    else{
      delay(10);
    }

    
  }
}
