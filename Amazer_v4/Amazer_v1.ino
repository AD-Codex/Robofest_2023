// universal veriable
int Universal_delay = 100;


// ---------------------------------------- maze solve ---------------------------------
int maze_size = 14;                      // change vaule based on maze_size

int terminal_maze[ 29][ 29];            // change vaule based on maze_size ( value = maze_size*2 +1 ) 
int edit_terminal_maze[ 2][ 29][ 29];   // change vaule based on maze_size ( value = maze_size*2 +1 ) 

int maze_lenght = maze_size*2 +1;     
        
int X_coordinate = 225 ;
int Y_coordinate= 225;
int X_ =0;
int Y_ =0;

char state[4] = "F_Y";
int count =1;


int F_sensor = 0;
int R_sensor = 0;
int L_sensor = 0;

int Path_find_1 = 0;
int maze_path = 0;
int maze_solved = 0;

int movement_count =0;

int turn_points[100][2];
int t_point = 0;
int points[100][2];
int ij =1;
int operation = 1;
int count_operation;
int y_coord;
int x_coord;

int mouse_move_state_int = 5 ;

int loop_condition = 1;

int four_by_4_found = 0;
int four_by_4_x = 0;
int four_by_4_y = 0;
// --------------------------------------------------------------------------------------

// ------------------------------------------ ir read ------------------------------------
int ir_L_P_limit = 0;
int ir_F_P_limit = 0;
int ir_R_P_limit = 0;
int ir_L_U_limit = 0;
int ir_F_U_limit = 0;
int ir_R_U_limit = 0;

int ir_L_limit = 0;
int ir_LF_limit = 0;
int ir_F_limit = 0;
int ir_R_limit = 0;
int ir_RF_limit = 0;

int ir_L_1 = 0;
int ir_L_2 = 0;
int ir_F_0 = 0;
int ir_R_2 = 0;
int ir_R_1 = 0;

int ir_calibration_done = 0;
// ---------------------------------------------------------------------------------------

// ------------------------------------------- motor --------------------------------
//  A - left
//  B - right

//  Motor control pins
int encoderA = PB13;
int encoderB = PA11;

int motorA_PWM = PB9;
int motorB_PWM = PB8;


int motorPinA1 = PA0;
int motorPinA2 = PC15;

int motorPinB1 = PC14;
int motorPinB2 = PB5;


int right_E_count = 0;
int left_E_count = 0;
int Encode_count = 0;
int Encode_error = 0;



void updateEncoder_left() {
  left_E_count = left_E_count + 1;
}

void updateEncoder_right() {
  right_E_count = right_E_count + 1;
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
  button2 =  1;
  interrupts();
}
// ----------------------------------------

int gyro_read;

#include <Wire.h>
#include "HMC5883L.h"
#include "analog_ir.h"
#include "move_encode.h"
#include "gyro_error.h"
#include "calibration.h"
#include "maze_move.h"
#include "maze_read.h"
#include "path_find.h"
#include "simulation_maz.h"
#include "mouse_move.h"



void setup() {
  Wire.begin();
  hmc5883l_init();
  
  // LED
  pinMode(PB10, OUTPUT);
  pinMode(PB1, OUTPUT);
  pinMode(PB0, OUTPUT);
  pinMode(PA6, OUTPUT);
  pinMode(PA7, OUTPUT);

  
  // button1 interrupt
  pinMode(PB15, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PB15), click1, RISING);

  // button1 interrupt
  pinMode(PA8, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PA8), click2, CHANGE);

  // ir setup
  pinMode(PA5, INPUT_ANALOG);
  pinMode(PA4, INPUT_ANALOG);
  pinMode(PA3, INPUT_ANALOG);
  pinMode(PA2, INPUT_ANALOG);
  pinMode(PA1, INPUT_ANALOG);

  //  motor setup
  pinMode(encoderA, INPUT_PULLUP);
  pinMode(encoderB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderA), updateEncoder_right, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderB), updateEncoder_left, FALLING);

  pinMode(motorA_PWM, OUTPUT);
  pinMode(motorB_PWM, OUTPUT);

  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(motorPinB1, OUTPUT);
  pinMode(motorPinB2, OUTPUT);

  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);

  // gyro setup
//  Wire.begin();
//  hmc5883l_init();

  delay(2000);
  

  Serial.begin(115200);

//  for ( int i=0; i<maze_lenght; i=i+1) {
//    for ( int j=0; j<maze_lenght; j=j+1) {
//      if ( i==0 || i == maze_lenght -1 || j==0 || j==maze_lenght -1 ) {
//            terminal_maze[i][j] = 101;
//        }
//        else{
//          terminal_maze[i][j] = -1;
//        }
//    }
//  }
//  terminal_maze[ 0][ 1] = 101;
//  terminal_maze[ 1][ 1] = 1;
//
//  
//  Path_find_1 = 1;
  
  Serial.println("Process start ...............");

  digitalWrite(PB10, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB0, LOW);
  digitalWrite(PA6, LOW);

  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  gyro_read = hmc5883l_GetHeading();

  delay(2000); 

}

void loop() {

  digitalWrite(PA7, HIGH);

  if ( button1 == 0 ) {
    if (button2 == 1) {
      digitalWrite(PB10, HIGH);
      digitalWrite(PB1, LOW);
      digitalWrite(PB0, LOW);
      digitalWrite(PA6, LOW);
      strcpy( state, "F_X");
    }
  }
  else if ( button1 ==1) {

    // calibration fn ------------------------------
    if (ir_calibration_done == 0) {

      for ( int i=0; i<maze_lenght; i=i+1) {
        for ( int j=0; j<maze_lenght; j=j+1) {
          if ( i==0 || i == maze_lenght -1 || j==0 || j==maze_lenght -1 ) {
                terminal_maze[i][j] = 101;
            }
            else{
              terminal_maze[i][j] = -1;
            }
        }
      }
      terminal_maze[ 0][ 1] = 101;
      terminal_maze[ 1][ 1] = 1;
    
      
      Path_find_1 = 1;
  
      digitalWrite(PB10, LOW);
      digitalWrite(PB1, LOW);
      digitalWrite(PB0, LOW);
      digitalWrite(PA6, LOW);
      
      delay(1000);
//      ir_calibration();
      ir_calibration2();

      ir_calibration();

//      digitalWrite(motorPinA1, LOW);
//      digitalWrite(motorPinA2, LOW);
//      digitalWrite(motorPinB1, LOW);
//      digitalWrite(motorPinB2, LOW);
//    
//      analogWrite(motorB_PWM, 60);
//      analogWrite(motorA_PWM, 60);
      
      ir_calibration_done = 1;

//      delay(1000);
    }


    ir_read_check();
     
    
    // maze fn --------------------------------
    if (loop_condition ==  1 ) {
  
      int x = 200;
      int y = 200;  
        
//      Sensor_check();
      ir_read_check();
      
      Fill_box();
    
//      Serial.println("------------------------------------------------------------------------------------");
//      Serial.println("");
//      for ( int i=0; i<maze_lenght; i=i+1) {
//        for ( int j=0; j<maze_lenght; j=j+1) {
//          char value_[20];
//          sprintf( value_, "%d\t",terminal_maze[i][j]);
//          Serial.print(value_);
//        }
//        Serial.println("");
//      }
//      Serial.println("-------------------------------------------------------------------------------------");
//      Serial.println("");
//      Serial.println("");
    
      delay(10);
    
      if ( maze_solved == 0){
        if ( Path_find_1 == 1) {
          move_mouse();
        }
        else {
          move_back();
        }
  
        delay(Universal_delay);
  
       mouse_move_maze();
  
        
      }
      else {
        Serial.println("maze solved----------------------\n");
  
        char value_[20];
        sprintf(value_, "\nmovement_count = %d\n", movement_count);
        Serial.print(value_);
        
        
        for ( int i=0; i<=t_point; i=i+1) {
          for ( int j=0; j<maze_lenght; j=j+1) {
            for ( int k=0; k<maze_lenght; k=k+1) {
              edit_terminal_maze[i][j][k] = terminal_maze[j][k];
            }
          }
          
        }
        
        
        Serial.println("--------------------------------0 maze -----------------------------------------------\n");
          
        for ( int j=0; j<maze_lenght; j=j+1) {
          for ( int k=0; k<maze_lenght; k=k+1) {
            char value_[20];
            sprintf(value_,  "%d\t",terminal_maze[j][k]);
            Serial.print(value_);
          }
          Serial.println("");
        }
        Serial.println("-------------------------------------------------------------------------------------");
        Serial.println("");
        Serial.println("");
          
        
        
        for ( int i=0; i<=t_point; i=i+1) {
          char value_[50];
          sprintf(value_, "----------------- %d maze breaked by [ %d, %d] -------------\n", i+1, turn_points[ i][0], turn_points[ i][1]);
          Serial.print(value_);
          Path_manage( i, turn_points[ i][0], turn_points[ i][1]);
          
          for ( int j=0; j<maze_lenght; j=j+1) {
            for ( int k=0; k<maze_lenght; k=k+1) {
              char value_[20];
              sprintf( value_, "%d\t",edit_terminal_maze[ i][j][k]);
              Serial.print(value_);
            }
            Serial.println("");
          }
          Serial.println("-------------------------------------------------------------------------------------");
          Serial.println("");
          Serial.println("");
        }
        
        Short_path_find(four_by_4_x,four_by_4_y);
        
        loop_condition = 0;
        
      }
  
      if ( Y_ == (maze_size/2)-1 && X_ == (maze_size/2)-1) {
        maze_path = maze_path + 1;
      }
      
      if ( X_==0 && Y_==0 && maze_path > 0 ) {
        maze_solved = 1;
      }
  
      char value_[20];
      sprintf(value_, "count number = %d \n", count);
      Serial.print(value_);
  
    }

    
  }
  
  

}
