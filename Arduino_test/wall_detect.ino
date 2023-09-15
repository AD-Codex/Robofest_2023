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
  }
  if (button1 == 3) {
    if (button2 == 1) {

      if ( (ir_L_limit-ir_L_1) > 400 ) {
        L_sensor = 0;
        digitalWrite(PB10, LOW);
      }
      else {
        L_sensor = 1;
        digitalWrite(PB10, HIGH);
      }

      if ( (ir_F_limit-ir_F_0) > 400 ) {
        F_sensor = 0;
        digitalWrite(PB0, LOW);
      }
      else {
        F_sensor = 1;
        digitalWrite(PB0, HIGH);
      }

      if ( (ir_R_limit-ir_R_1) > 400 ) {
        R_sensor = 0;
        digitalWrite(PA7, LOW);
      }
      else {
        R_sensor = 1;
        digitalWrite(PA7, HIGH);
      }
      
      button2 = 0;
    }
  }

  

  delay(100);
  

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
