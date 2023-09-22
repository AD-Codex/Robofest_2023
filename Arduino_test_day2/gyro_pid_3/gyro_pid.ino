
// ------------------------------------------ ir read ------------------------------------
int sample_values[100][5];
int ir_read_count = 0;
int ir_L_limit = 0;
int ir_F_limit = 0;
int ir_R_limit = 0;
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



void updateEncoder_left() {
  left_E_count = left_E_count + 1;
//  if (mouse_L_move_dir == 1) {
//    left_E_count = left_E_count + 1;
//  }
//  else if ( mouse_L_move_dir == -1) {
//    left_E_count = left_E_count - 1;
//  }
}

void updateEncoder_right() {
  right_E_count = right_E_count + 1;
//  if (mouse_R_move_dir == 1) {
//    right_E_count = right_E_count + 1;
//  }
//  else if ( mouse_R_move_dir == -1) {
//    right_E_count = right_E_count - 1;
//  }
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

int gyro_read;

#include <Wire.h>
#include "HMC5883L.h"
#include "move_pid.h"
#include "move_encode.h"



void setup() {
  // LED
  pinMode(PB10, OUTPUT);
  pinMode(PB1, OUTPUT);
  pinMode(PB0, OUTPUT);
  pinMode(PA6, OUTPUT);
  pinMode(PA7, OUTPUT);

  
  // button1 interrupt
  pinMode(PB15, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PB15), click1, RISING);

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
  Wire.begin();
  hmc5883l_init();

  delay(2000);
  

  Serial.begin(115200);
  Serial.println("Process start ..........");

  digitalWrite(PB10, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB0, LOW);
  digitalWrite(PA7, LOW);

  analogWrite(motorB_PWM, 60);
  analogWrite(motorA_PWM, 60);

  gyro_read = hmc5883l_GetHeading();

  

}

void loop() {
  digitalWrite(PA6, HIGH);

//  move_forward();
  if ( button1 == 1) {

    right_E_count = 0;
    left_E_count = 0;

    delay(1000);
    
    move_M_forward();

    delay(1000);

    move_M_turnL();


  }
  

}
