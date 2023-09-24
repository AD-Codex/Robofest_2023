
int sample_values[100][5];
int ir_read_count = 0;




void ir_read_loop() {
  
  ir_read_count = 0;
  while (1) {

    ir_L_1 = analogRead(PA5);
    ir_L_2 = analogRead(PA4);
    ir_F_0 = analogRead(PA3);
    ir_R_2 = analogRead(PA2);
    ir_R_1 = analogRead(PA1);
//
    char values[50];
    sprintf(values, "values :%d:%d:%d:%d:%d",ir_L_1,ir_L_2,ir_F_0,ir_R_2,ir_R_1);
    Serial.println(values);

    
  
    sample_values[ir_read_count][4] = ir_R_1;
    sample_values[ir_read_count][3] = ir_R_2;
    sample_values[ir_read_count][2] = ir_F_0;
    sample_values[ir_read_count][1] = ir_L_2;
    sample_values[ir_read_count][0] = ir_L_1;

    ir_read_count = ir_read_count + 1;

    if (ir_read_count == 20) {
      break;
    }
    else{
      delay(10);
    }
  }
}


void ir_calibration() {

  // front setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  for (int i=0; i<20; i=i+1) {
    ir_L_P_limit = ir_L_P_limit + sample_values[i][0]/20;
    ir_LF_limit  = ir_LF_limit + sample_values[i][1]/20; 
    ir_F_U_limit = ir_F_U_limit + sample_values[i][2]/20;
    ir_RF_limit  = ir_RF_limit + sample_values[i][3]/20; 
    ir_R_P_limit = ir_R_P_limit + sample_values[i][4]/20;

  }
  
  move_M_turnL();

  gyro_read = angle_detector( gyro_read, -90);
  
  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);
  

  // left setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  for (int i=0; i<20; i=i+1) {
    ir_L_P_limit = ir_L_P_limit + sample_values[i][0]/20;
    ir_F_P_limit = ir_F_P_limit + sample_values[i][2]/20;
    ir_R_U_limit = ir_R_U_limit + sample_values[i][4]/20;
  }


  move_M_turn_B();

  gyro_read = angle_detector( gyro_read, 180);
  
  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);
  

  // right setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  for (int i=0; i<20; i=i+1) {
    ir_L_U_limit = ir_L_U_limit + sample_values[i][0]/20;
    ir_F_P_limit = ir_F_P_limit + sample_values[i][2]/20;
    ir_R_P_limit = ir_R_P_limit + sample_values[i][4]/20;
  }
  
  ir_L_P_limit = ir_L_P_limit/2;
  ir_F_P_limit = ir_F_P_limit/2;
  ir_R_P_limit = ir_R_P_limit/2;


  move_M_turnL();
  
  gyro_read = angle_detector( gyro_read, -90);
  
  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);

//  ir_L_limit = (ir_L_P_limit + ir_L_U_limit) /2;
//  ir_F_limit = (ir_F_P_limit + ir_F_U_limit) *1/4;
//  ir_R_limit = (ir_R_P_limit + ir_R_U_limit) /2; 

  char values[50];
  sprintf(values, "ir_L_P_limit, ir_F_P_limit, ir_R_P_limit : %d:%d:%d",ir_L_P_limit,ir_F_P_limit,ir_R_P_limit);
  Serial.println(values);

  sprintf(values, "ir_LF_limit, ir_RF_limit : %d:%d",ir_LF_limit,ir_RF_limit);
  Serial.println(values);

  sprintf(values, "ir_L_U_limit, ir_F_U_limit, ir_R_U_limit : %d:%d:%d",ir_L_U_limit,ir_F_U_limit,ir_R_U_limit);
  Serial.println(values);

  delay(1000);
  
  
}


void ir_calibration2() {

  // --------------------------------------------

  for (int i=0; i<20; i=i+1) {
    ir_F_P_limit = ir_F_P_limit + sample_values[i][2];
  }

  ir_F_P_limit = ir_F_P_limit/20;

  // -------------------------------------------------
  
  right_E_count = 0;
  left_E_count = 0;

  calibration_mouse_move();

  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);

  delay(100);

  // left setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  
  for (int i=0; i<20; i=i+1) {
    ir_F_limit = ir_F_limit + sample_values[i][2];
  }

  ir_F_limit = ir_F_limit/20;

  // -----------------------------------------------------------------------------


  move_M_turnL();

  gyro_read = angle_detector( gyro_read, -90);
  
  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);
  

  // left setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  for (int i=0; i<20; i=i+1) {
    ir_R_limit = ir_R_limit + sample_values[i][4];
  }
  ir_R_limit = ir_R_limit/20;

  // --------------------------------------------------------------------------------


  move_M_turn_B();

  gyro_read = angle_detector( gyro_read, 180);
  
  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);
  

  // right setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  for (int i=0; i<20; i=i+1) {
    ir_L_limit = ir_L_limit + sample_values[i][0];
  }
  ir_L_limit = ir_L_limit/20;

  // -------------------------------------------------------------------------------------------

  move_M_turnR();

  gyro_read = angle_detector( gyro_read, +90);
  
  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);

  // -------------------------------------------------------------------------------
  right_E_count = 0;
  left_E_count = 0;

  calibration_mouse_move();

  digitalWrite(PA7, HIGH);
  dir_error_check();
  digitalWrite(PA7, LOW);


  right_E_count = 0;
  left_E_count = 0;

  // front setup ir calibration
  digitalWrite(PB0, HIGH);
  ir_read_loop();
  digitalWrite(PB0, LOW);

  for (int i=0; i<20; i=i+1) {
    ir_L_P_limit = ir_L_P_limit + sample_values[i][0];
    ir_LF_limit  = ir_LF_limit + sample_values[i][1]; 
    ir_F_U_limit = ir_F_U_limit + sample_values[i][2];
    ir_RF_limit  = ir_RF_limit + sample_values[i][3]; 
    ir_R_P_limit = ir_R_P_limit + sample_values[i][4];

  }


  ir_L_P_limit = ir_L_P_limit/20;
  ir_LF_limit  = ir_LF_limit/20; 
  ir_F_U_limit = ir_F_U_limit/20;
  ir_RF_limit  = ir_RF_limit/20; 
  ir_R_P_limit = ir_R_P_limit/20;

  

  // --------------------------------------------------------------------------

  
}
