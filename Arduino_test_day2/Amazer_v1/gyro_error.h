
// dir error check
// 1. gyro_error_cuttoff = 5; gyro_error_set_speed = 70;
int gyro_error_cuttoff = 1;
int gyro_error_set_speed = 70;

int gyro_angle_read[] = {0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 8, 9, 10, 10, 11, 12, 13, 14, 15, 16, 16, 17, 18, 18, 19, 20, 21, 21, 22, 22, 23, 24, 24, 24, 25, 26, 26, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 42, 43, 44, 45, 46, 47, 47, 48, 49, 50, 50, 51, 52, 52, 53, 54, 55, 55, 56, 57, 58, 59, 59, 60, 61, 62, 62, 63, 64, 64, 65, 66, 67, 67, 68, 69, 70, 70, 71, 72, 73, 74, 74, 75, 76, 77, 77, 78, 79, 80, 80, 81, 82, 82, 83, 84, 85, 86, 87, 88, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 130, 131, 132, 133, 134, 135, 137, 138, 140, 142, 144, 145, 147, 149, 150, 152, 153, 155, 156, 157, 158, 160, 161, 162, 164, 165, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 186, 188, 189, 190, 192, 193, 194, 195, 197, 198, 200, 201, 202, 204, 206, 207, 208, 210, 212, 213, 215, 216, 218, 219, 221, 223, 224, 226, 227, 229, 230, 231, 233, 234, 235, 236, 237, 239, 240, 241, 242, 244, 245, 247, 248, 249, 251, 252, 254, 255, 256, 257, 259, 260, 261, 262, 263, 265, 266, 267, 268, 269, 269, 270, 271, 272, 273, 273, 274, 275, 276, 278, 279, 280, 282, 283, 284, 285, 287, 288, 289, 290, 291, 292, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 302, 303, 304, 305, 306, 307, 308, 308, 309, 310, 311, 312, 312, 313, 314, 315, 316, 316, 317, 318, 319, 320, 320, 321, 322, 323, 324, 325, 326, 326, 327, 328, 329, 330, 331, 332, 332, 333, 334, 334, 335, 336, 337, 337, 338, 339, 339, 340, 340, 341, 342, 342, 343, 343, 344, 345, 346, 347, 348, 348, 349, 350, 351, 352, 353, 354, 354, 355, 356, 356, 357, 358, 359, 359};
  

int angle_detector(int current_gyro, int angle_gyro) {
  
  int pos_gyro = current_gyro;
  while(abs(gyro_angle_read[pos_gyro]-current_gyro)>=2){// connect the current value with array value
    
    if(gyro_angle_read[pos_gyro]<current_gyro){
      pos_gyro=pos_gyro+1;
    }
    else{
      pos_gyro=pos_gyro-1;
    }

    Serial.println("error");
    
  }

  if ( (pos_gyro + 1) <= 360 && gyro_angle_read[pos_gyro + 1]-current_gyro == 0 ) {
    pos_gyro=pos_gyro+1;
  }
  if ( (pos_gyro + 2) <= 360 && gyro_angle_read[pos_gyro + 2]-current_gyro == 0 ) {
    pos_gyro=pos_gyro+2;
  }
  if ( (pos_gyro + 3) <= 360 && gyro_angle_read[pos_gyro + 3]-current_gyro == 0 ) {
    pos_gyro=pos_gyro+3;
  }

  if ( (pos_gyro - 1) >=0 && gyro_angle_read[pos_gyro - 1]-current_gyro == 0 ) {
    pos_gyro=pos_gyro-1;
  }
  if ( (pos_gyro - 2) >=0 && gyro_angle_read[pos_gyro - 2]-current_gyro == 0 ) {
    pos_gyro=pos_gyro-2;
  }
  if ( (pos_gyro - 3) >=0 && gyro_angle_read[pos_gyro - 3]-current_gyro == 0 ) {
    pos_gyro=pos_gyro-3;
  }
  
//  Serial.println(pos_gyro);

  if ( (pos_gyro + angle_gyro) < 0) {
    pos_gyro = 360 + (pos_gyro + angle_gyro);
  }
  else if ( (pos_gyro + angle_gyro) > 360) {
    pos_gyro = -360 + (pos_gyro + angle_gyro);
  }
  else {
    pos_gyro = pos_gyro + angle_gyro;
  }

  Serial.println(pos_gyro);
 
  return(gyro_angle_read[pos_gyro]);
  
}


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

    if ( abs(gyro_error) <= gyro_error_cuttoff) {
      break;
    }
    else {
      analogWrite(motorB_PWM, gyro_error_set_speed);
      analogWrite(motorA_PWM, gyro_error_set_speed);
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
