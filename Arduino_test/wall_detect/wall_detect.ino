// ---> F_X
// <--- B_X
// ^ B_Y
// v F_Y

// ------------------------------------------- maz solve --------------------------------
int maze_size = 4; // change vaule based on maze_size
int terminal_maze[ 9][ 9]; // change vaule based on maze_size ( value = maze_size*2 +1 ) 

int maze_lenght = maze_size*2 +1;
int X =0;
int Y =0;

char state[4] = "F_Y";
int count =1;

int F_sensor = 0;
int R_sensor = 0;
int L_sensor = 0;

int movement_count =0;
// ----------------------------------------------------------------------------------------

// ------------------------------------------ ir read ------------------------------------
int sample_values[100][5];
int ir_read_count = 0;
int ir_L_limit = 0;
int ir_F_limit = 0;
int ir_R_limit = 0;
// ---------------------------------------------------------------------------------------

// ------------------------------------------- motor --------------------------------
int encoderPin1 = PB13; // Encoder Output 'A' must be connected to interrupt pin of Arduino.
int encoderPin2 = PB12; // Encoder Output 'B' must be connected to interrupt pin of Arduino.
int encoderPin3 = PA12; // Encoder Output 'A' must be connected to interrupt pin of Arduino.
int encoderPin4 = PA11; // Encoder Output 'B' must be connected to interrupt pin of Arduino.

int right_count = 0;
int left_count = 0;

// Motor control pins
int motorPin1 = PB8; // Replace with your actual motor control pins
int motorPin2 = PB9; // Replace with your actual motor control pins

int motorPinA1 = PC14; // Replace with your actual motor control pins
int motorPinA2 = PB5; // Replace with your actual motor control pins

int motorPinB1 = PB6; // Replace with your actual motor control pins
int motorPinB2 = PB7; // Replace with your actual motor control pins

int delta_Speed=0;
// Constants for control
int desiredCount = 1000; // Desired encoder count for forward motion
double Kp = 15; // Proportional gain
double Ki = 0; // Integral gain
double Kd = 0; // Derivative gain
double prevError = 0;
double integral = 0;

void updateEncoder_left() {
  left_count++;
}

void updateEncoder_right() {
  right_count++;
}
// ---------------------------------------------------


// -------- button1 ----------------------
int button1 = 0;

void click1(){
  noInterrupts();
  button1 =1;
  interrupts();
}
// ----------------------------------------
// -------- button2 ----------------------
int button2 = 0;
void click2(){
  noInterrupts();
  button2 =1;
  interrupts();
}
// ----------------------------------------



void setup() {
  // led set
  pinMode(PB10, OUTPUT);
  pinMode(PB1, OUTPUT);
  pinMode(PB0, OUTPUT);
  pinMode(PA6, OUTPUT);
  pinMode(PA7, OUTPUT);

  // button1 interrupt
  pinMode(PB15, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PB15), click1, RISING);

  // button2 interrupt
  pinMode(PA8, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PA8), click2, RISING);
  
  // ir set
  pinMode(PA5, INPUT_ANALOG);
  pinMode(PA4, INPUT_ANALOG);
  pinMode(PA3, INPUT_ANALOG);
  pinMode(PA2, INPUT_ANALOG);
  pinMode(PA1, INPUT_ANALOG);

  //  motor set
  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
  pinMode(encoderPin3, INPUT_PULLUP);
  pinMode(encoderPin4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder_right, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderPin4), updateEncoder_left, FALLING);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(motorPinB1, OUTPUT);
  pinMode(motorPinB2, OUTPUT);

  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);

  Serial.begin(115200);
  Serial.println("Process start ..........");

}

void loop() {

//  ir read
  int ir_L_1 = analogRead(PA5);
  int ir_L_2 = analogRead(PA4);
  int ir_F_0 = analogRead(PA3);
  int ir_R_2 = analogRead(PA2);
  int ir_R_1 = analogRead(PA1);
//

  if (button1 == 1 ) {
    
    digitalWrite(PB1, HIGH);
     
    sample_values[ir_read_count][4] = ir_R_1;
    sample_values[ir_read_count][3] = ir_R_2;
    sample_values[ir_read_count][2] = ir_F_0;
    sample_values[ir_read_count][1] = ir_L_2;
    sample_values[ir_read_count][0] = ir_L_1;

    char values[50];
    sprintf(values, "%d:%d:%d:%d:%d",ir_L_1,ir_L_2,ir_F_0,ir_R_2,ir_R_1);
    Serial.println(values);
    
    ir_read_count = ir_read_count + 1;

    if (ir_read_count == 99) {
      ir_read_count = 0;
      button1 = 2;
      digitalWrite(PB1, LOW);
    }
  }
  else if (button1 == 2){;

    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    int val4 = 0;
    int val5 = 0;
    for (int i=0; i<100;i=i+1){
      val1 = val1 + sample_values[i][0];
      val2 = val2 + sample_values[i][1];
      val3 = val3 + sample_values[i][2];
      val4 = val4 + sample_values[i][3];
      val5 = val5 + sample_values[i][4];
    }

    ir_L_limit = val1/100;
    ir_F_limit = val3/100;
    ir_R_limit = val5/100;

    char values[50];
    sprintf(values, "final :%d:%d:%d:%d:%d",val1/100,val2/100,val3/100,val4/100,val5/100);
    Serial.println(values);
    
    button1 = 3;  
    button2 = 1;
  }
  if (button1 == 3) {
    if (button2 == 1) {

      if ( (ir_L_limit-ir_L_1) > 2000 ) {
//  ((ir_R_limit+ir_L_limit)/2-ir_F_limit)        
        L_sensor = 0;
        digitalWrite(PB10, LOW);
      }
      else {
        L_sensor = 1;
        digitalWrite(PB10, HIGH);
      }

      if ( ((ir_R_limit+ir_L_limit)/2-ir_F_0) > 2000 ) {
//        ((ir_R_limit+ir_L_limit)/2-ir_F_limit)
        F_sensor = 0;
        digitalWrite(PB0, LOW);
      }
      else {
        F_sensor = 1;
        digitalWrite(PB0, HIGH);
      }

      if ( (ir_R_limit-ir_R_1) > 2000 ) {
//        ((ir_R_limit+ir_L_limit)/2-ir_F_limit)
        R_sensor = 0;
        digitalWrite(PA6, LOW);
      }
      else {
        R_sensor = 1;
        digitalWrite(PA6, HIGH);
      }

      char values[50];
    sprintf(values, "read :%d:%d:%d",ir_L_1,ir_F_0,ir_R_1);
    Serial.println(values);

    delay(1000);

    if (F_sensor == 0) {
      move_M_forward();
    }
    else if (R_sensor == 0) {
      move_M_turnL();
      delay(500);
      move_M_forward();
    }
    else if (L_sensor == 0) {
      move_M_turnR();
      delay(500);
      move_M_forward();
    }
    else {
      move_M_turnR();
      delay(500);
      move_M_turnR();
      delay(500);
      move_M_forward();
    }
      
      button2 = 1;
      delay(500);
    }
  }

  
  delay(100);
  

}

void move_M_turnL(){
  left_count = 0;
  right_count = 0;

  analogWrite(motorPin1, 60);
  analogWrite(motorPin2, 60);

  while (left_count < 118 && right_count < 118) {
    digitalWrite(motorPinA1, HIGH);
    digitalWrite(motorPinA2, LOW);
    digitalWrite(motorPinB1, LOW);
    digitalWrite(motorPinB2, HIGH);
  }
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}

void move_M_turnR(){
  left_count = 0;
  right_count = 0;

  analogWrite(motorPin1, 60);
  analogWrite(motorPin2, 60);

  while (left_count < 118 && right_count < 118) {
    digitalWrite(motorPinA1, LOW);
    digitalWrite(motorPinA2, HIGH);
    digitalWrite(motorPinB1, HIGH);
    digitalWrite(motorPinB2, LOW);
  }
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}


void move_M_forward() {
  while (1) {
    digitalWrite(motorPinA1, LOW);
    digitalWrite(motorPinA2, HIGH);
    
    digitalWrite(motorPinB1, LOW);
    digitalWrite(motorPinB2, HIGH);

    //  // Calculate error for both encoders

    int Error = left_count - right_count;
    //int Error = 0;
    
    //
    //  // Calculate integral and derivative terms
    integral += Error;
    double derivative = Error- prevError;
    //
    //  // Calculate motor speed adjustments based on PID control
    delta_Speed = Kp * double(Error) + Ki * integral + Kd * derivative;
    
    int leftSpeed=60-delta_Speed;
    int rightSpeed=60+delta_Speed;

    if (rightSpeed<0){
      rightSpeed = 0;
    }

    if (leftSpeed<0) {
      leftSpeed=0;
    }
    
    //
    //  // Apply motor speed adjustments to achieve forward motion
    analogWrite(motorPin1, rightSpeed);
    analogWrite(motorPin2, leftSpeed);
    //
    //  // Update previous error for the next iteration
    prevError = Error;
  
    Serial.print("Left Count: ");
    Serial.print(left_count);
    Serial.print(", Right Count: ");
    Serial.print(right_count);
    Serial.print("Left speed: ");
    Serial.print(leftSpeed);
    Serial.print(", Right speed: ");
    Serial.println(rightSpeed);

    if ((left_count + right_count)/2 > 310) {
      digitalWrite(motorPinA1, LOW);
      digitalWrite(motorPinA2, LOW);
      
      digitalWrite(motorPinB1, LOW);
      digitalWrite(motorPinB2, LOW);

      Kp = 1; // Proportional gain
      Ki = 0; // Integral gain
      Kd = 0; // Derivative gain
      prevError = 0;
      integral = 0;
      
      right_count = 0;
      left_count = 0;
      
      button1 = 2;
      break;
    }

  
  
    delay(10);
  }
}

void fill_box() {
  int terminalX_coord = X*2 +1;
  int terminalY_coord = Y*2 +1;

  if ( strcmp( state, "F_Y") == 0) {  
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    
  }
  else if ( strcmp( state, "B_Y") == 0) {
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
      
  }
  else if ( strcmp( state, "F_X") == 0) {
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord +1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord +2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord +2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord +1] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    
  }
  else if ( strcmp( state, "B_X") == 0) {
    if ( F_sensor == 0 ) {
      terminal_maze[ terminalY_coord][ terminalX_coord -1] = 0;
      if ( terminal_maze[ terminalY_coord][ terminalX_coord -2] == -1) {
        terminal_maze[ terminalY_coord][ terminalX_coord -2] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord][ terminalX_coord -1] = 101;
    
    if ( R_sensor == 0 ) {
      terminal_maze[ terminalY_coord -1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord -2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord -2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord -1][ terminalX_coord] = 101;
    
    if ( L_sensor == 0 ) {
      terminal_maze[ terminalY_coord +1][ terminalX_coord] = 0;
      if ( terminal_maze[ terminalY_coord +2][ terminalX_coord] == -1) {
        terminal_maze[ terminalY_coord +2][ terminalX_coord] = count +1;
      }     
    }
    else terminal_maze[ terminalY_coord +1][ terminalX_coord] = 101;
    
  }
}


void move_mouse() {
  int terminalX_coord = X *2 +1;
  int terminalY_coord = Y *2 +1;

  if ( strcmp( state, "F_Y") == 0 ) {
    
    if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y = Y +1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
    } 
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X = X -1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X = X +1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
    }
//    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0) {
//      strcpy( state, "B_Y");
//      Path_find_1 = 0;
//      printf("change move fn to move_back fn\n");   
//    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101) {
        strcpy( state, "B_Y");
//        Path_find_1 = 0;
        printf("F_Y change move fn to move_back fn\n");
    }
    else {
        printf("11111111111111111\n");
    } 
    
  }
  else if ( strcmp( state, "B_Y") == 0) {
    
    if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y = Y -1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X = X +1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X = X -1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
    }
//    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 ) {
//      strcpy( state, "F_Y");
//      Path_find_1 = 0;
//      printf("change move fn to move_back fn\n");
//    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101) {
      strcpy( state, "F_Y");
//      Path_find_1 = 0;
      printf("B_Y change move fn to move_back fn\n");
    }
    else {
      printf("2222222222222222222\n");      
    }
       
  }
  else if ( strcmp( state, "F_X") == 0) {
    
    if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord +2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord +3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord +2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord +2] == -1) ) {
      X = X +1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_X");
    } 
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y = Y +1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
    }
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y = Y -1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
    }
//    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0) {
//      strcpy( state, "B_X");
//      Path_find_1 = 0;
//      printf("change move fn to move_back fn\n");
//    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord +1] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101) {
      strcpy( state, "B_X");
//      Path_find_1 = 0;
      printf("F_X change move fn to move_back fn\n");
    }
    else {
      printf("33333333333333333333333\n");      
    }
    
  }
  else if ( strcmp( state, "B_X") == 0) {
    
    if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 && terminal_maze[ terminalY_coord][ terminalX_coord -2] == count +1 && ( terminal_maze[ terminalY_coord][ terminalX_coord -3] == -1 || terminal_maze[ terminalY_coord +1][ terminalX_coord -2] == -1 || terminal_maze[ terminalY_coord -1][ terminalX_coord -2] == -1) ) {
      X = X -1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_X");
    } 
    else if ( terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord -2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord -3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord -2][ terminalX_coord -1] == -1) ) {
      Y = Y -1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "B_Y");
    }
    else if ( terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0 && terminal_maze[ terminalY_coord +2][ terminalX_coord] == count +1 && ( terminal_maze[ terminalY_coord +3][ terminalX_coord] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord +1] == -1 || terminal_maze[ terminalY_coord +2][ terminalX_coord -1] == -1) ) {
      Y = Y +1;
      movement_count = movement_count +1;
      count = count +1;
      strcpy( state, "F_Y");
    }
//    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 0 || terminal_maze[ terminalY_coord -1][ terminalX_coord] == 0 || terminal_maze[ terminalY_coord +1][ terminalX_coord] == 0) {
//      strcpy( state, "F_X");
//      Path_find_1 = 0;
//      printf("change move fn to move_back fn\n");     
//    }
    else if ( terminal_maze[ terminalY_coord][ terminalX_coord -1] == 101 && terminal_maze[ terminalY_coord -1][ terminalX_coord] == 101 && terminal_maze[ terminalY_coord +1][ terminalX_coord] == 101) {
      strcpy( state, "F_X");
//      Path_find_1 = 0;
      printf("B_X change move fn to move_back fn\n");
    }
    else {
      printf("444444444444444444444\n");      
    }
  }

  
}
