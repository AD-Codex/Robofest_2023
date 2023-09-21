
//#include "HMC5883L.h"

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

  

//  while (1) {
//    if( left_E_count - end_E_count > +0) {
//      // move back left
//      mouse_L_move_dir = -1;
//      
//      digitalWrite(motorPinA1, HIGH);
//      digitalWrite(motorPinA2, LOW);
//  
//      analogWrite(motorA_PWM, 55);
//      
//    }
//    else if (left_E_count - end_E_count < 10) {
//      // move front left
//      mouse_L_move_dir = 1;
//      
//      digitalWrite(motorPinA1, LOW);
//      digitalWrite(motorPinA2, HIGH);
//  
//      analogWrite(motorA_PWM, 55);
//    }
//    else {
//      // left stop
//      mouse_L_move_dir = 0;
//      
//      digitalWrite(motorPinA1, LOW);
//      digitalWrite(motorPinA2, LOW);
//  
//      analogWrite(motorA_PWM, 0);
//    }
//    
//  
//    if( right_E_count - end_E_count > +0) {
//      // move back right
//      mouse_R_move_dir = -1;
//      
//      digitalWrite(motorPinB1, HIGH);
//      digitalWrite(motorPinB2, LOW);
//  
//      analogWrite(motorB_PWM, 55);
//      
//    }
//    else if (right_E_count - end_E_count < -0) {
//      // move front right
//      mouse_R_move_dir = 1;
//      
//      digitalWrite(motorPinB1, LOW);
//      digitalWrite(motorPinB2, HIGH);
//  
//      analogWrite(motorB_PWM, 55);
//    }
//    else {
//      // right stop
//      mouse_R_move_dir = 0;
//      
//      digitalWrite(motorPinB1, LOW);
//      digitalWrite(motorPinB2, LOW);
//  
//      analogWrite(motorB_PWM, 0);
//    }
//
//    if ( mouse_R_move_dir == 0 && mouse_R_move_dir == 0) {
//      break;
//    }
//    else {
//      delay(10);
//    }
//    
//  }

  Serial.println("stop");
 
}




void move_forward_combine(){
  double Kp_gyro = 1.1; // Proportional gain - 1
  double Ki_gyro = 0.2; // Integral gain - 0.2
  double Kd_gyro = 0; // Derivative gain
  int gyro_error = 0;
  double gyro_prevError = 0;
  double gyro_integral = 0;
  double gyro_derivative = 0;

  double Kp_ir = 1;
  int ir_error = 0;
  int ir_wall_limit = 2000;
  
  int left_to_right_S = 0;
  int right_to_left_S = 0;


//  int gyro_read = hmc5883l_GetHeading();

  digitalWrite(PB10, HIGH);
  
  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB2, HIGH);
  digitalWrite(motorPinA1, LOW); 
  digitalWrite(motorPinB1, LOW);
  
  delay(150);

  while(1) {
    int gyro_N_read = hmc5883l_GetHeading();
    int ir_L_1 = analogRead(PA5);
    int ir_R_1 = analogRead(PA1);

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
    double ir_speed_diff = 0;

    // ir condition check -------------------------- 
    
//    if (gyro_error > 0) {
//      if (ir_R_1 > ir_wall_limit) {  // right wall check
//        ir_error = ir_R_1 - ir_wall_limit;
//        ir_speed_diff = - Kp_ir*ir_error;    // + if cloes to right
//      }
//    }
//    else if ( gyro_error < 0){
//      if (ir_L_1 > ir_wall_limit) { // left wall check
//        ir_error = ir_L_1 - ir_wall_limit;
//        ir_speed_diff = Kp_ir*ir_error;    // + if cloes to left
//      } 
//    }
//    else {
//      if (ir_L_1 > ir_wall_limit) { // left wall check
//        ir_error = ir_L_1 - ir_wall_limit;
//        ir_speed_diff = Kp_ir*ir_error;    // + if cloes to left
//      } 
//      else if (ir_R_1 > ir_wall_limit) {  // right wall check
//        ir_error = ir_R_1 - ir_wall_limit;
//        ir_speed_diff = - Kp_ir*ir_error;    // + if cloes to right
//      }
//    }
    
    
//    if (ir_L_1 > ir_wall_limit && gyro_error == 0) { // left wall check
//      if ( ir_L_1 - ir_L_limit  > 0) {
//        // left close to wall
//        left_to_right_S = 10;
//        right_to_left_S = 0;
//      }
//      else {
//        // left away to wall
//        right_to_left_S = 10;
//        left_to_right_S = 0;
//      }
//    }
//    else if (ir_R_1 > ir_wall_limit && gyro_error == 0) {  // right wall check
//      if ( ir_R_1 - ir_R_limit  > 0) {
//        // right close to wall
//        right_to_left_S = 10;
//        left_to_right_S = 0;
//      }
//      else {
//        // right away to wall
//        left_to_right_S = 10;
//        right_to_left_S = 0;
//      }
//    }
//    else {
//      left_to_right_S = 0;
//      right_to_left_S = 0;
//    }
    // -------------------------------------------------
    
    int leftSpeed = 100 -gyro_speed_diff + left_to_right_S;
    int rightSpeed = 100+gyro_speed_diff + right_to_left_S;

//    int leftSpeed  = 60-gyro_speed_diff + ir_speed_diff;
//    int rightSpeed = 60+gyro_speed_diff - ir_speed_diff;

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

    if ((left_E_count + right_E_count)/2 >= 200) {
      digitalWrite(PB10, LOW);
      
      left_E_count = 0;
      right_E_count = 0;
      
      stop_mouse();
      
      break;
    }
    else {
      delay(150);
    }

  }
  
}

void turn_Rgyro_90() {

  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH); 

  while (1) {
    int turn_read = hmc5883l_GetHeading() - gyro_read;
    if ( turn_read < 0) {
      turn_read = turn_read + 360;
    }
  
    if ( turn_read >= 90 ) {
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
  
}
