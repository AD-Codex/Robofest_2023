// gyro_encode_error_correct = 2;

int gyro_encode_error_correct = 3;


void mouse_move_maze() {

      if (move_front_error == 1) {
        while (1) {
          ir_F_0 = analogRead(PA3);
          if ( ir_F_0 >= ir_F_P_limit) {
            move_front_error = 0;
            move_M_stop();
            break;
          }

          analogWrite(motorB_PWM, 90);
          analogWrite(motorA_PWM, 90);
        
          digitalWrite(motorPinA2, HIGH);
          digitalWrite(motorPinB2, HIGH);
          digitalWrite(motorPinA1, LOW); 
          digitalWrite(motorPinB1, LOW);

          delay(10);
          
        }
      }

        if (mouse_move_state_int == 8) {
          // move forward
          right_E_count = 0;
          left_E_count = 0;
          
//          gyro_read = hmc5883l_GetHeading();

          ir_L_2 = analogRead(PA4);
          ir_R_2 = analogRead(PA2);

          if ( ir_L_2 > ir_LF_limit ) {
            gyro_read = gyro_read + gyro_encode_error_correct;
            if ( ir_L_2 > ir_LF_limit * 2) {
              gyro_read = gyro_read + gyro_encode_error_correct;
            }
          }
          else if ( ir_R_2 > ir_RF_limit ) {
            gyro_read = gyro_read - gyro_encode_error_correct;
            if ( ir_R_2 > ir_RF_limit * 2) {
              gyro_read = gyro_read - gyro_encode_error_correct;
            }
          }
  
          digitalWrite(PA7, HIGH);
          dir_error_check();
          digitalWrite(PA7, LOW);
          
          move_M_forward();

          if ( ir_L_2 > ir_LF_limit ) {
            gyro_read = gyro_read - gyro_encode_error_correct;
          }
          else if ( ir_R_2 > ir_RF_limit ) {
            gyro_read = gyro_read + gyro_encode_error_correct;
          }
  
          digitalWrite(PA7, HIGH);
          dir_error_check();
          digitalWrite(PA7, LOW);
          
        }
        else if (mouse_move_state_int == 6) {
          // move right
          right_E_count = 0;
          left_E_count = 0;
          
          move_M_turnR();
          
          gyro_read = angle_detector( gyro_read, +90);
  
          digitalWrite(PA7, HIGH);
          dir_error_check();
          digitalWrite(PA7, LOW);
  
          delay(Universal_delay);
//          gyro_read = hmc5883l_GetHeading();
          
          move_M_forward();
        }
        else if (mouse_move_state_int == 4) {
          // move left
          right_E_count = 0;
          left_E_count = 0;
    
          move_M_turnL();
  
          gyro_read = angle_detector( gyro_read, -90);
  
          digitalWrite(PA7, HIGH);
          dir_error_check();
          digitalWrite(PA7, LOW);
  
          delay(Universal_delay);
//          gyro_read = hmc5883l_GetHeading();
          
          move_M_forward();
        }
        else if (mouse_move_state_int == 2) {
          // move back
          right_E_count = 0;
          left_E_count = 0;
          
          delay(Universal_delay);
          
          move_M_turn_B();
  
          gyro_read = angle_detector( gyro_read, 180);
  
          digitalWrite(PA7, HIGH);
          dir_error_check();
          digitalWrite(PA7, LOW);
        }
        else {
          Serial.println("NOT MOVE ...............................");
        }
  
}
