/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  Modified by Roger Clark. www.rogerclark.net for Maple mini 25th April 2015 , where the LED is on PB1
  
 */

int button1 = 0;
int sample_values[100][5];
int ir_read_count = 0;

void click1(){
  noInterrupts();
  button1 =1;
  interrupts();
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PB1 as an output.
  pinMode(PC13, OUTPUT);
  pinMode(PB10, OUTPUT);
  
  pinMode(PA5, INPUT_ANALOG);
  pinMode(PA4, INPUT_ANALOG);
  pinMode(PA3, INPUT_ANALOG);
  pinMode(PA2, INPUT_ANALOG);
  pinMode(PA1, INPUT_ANALOG);

  pinMode(PB15, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PB15), click1, RISING);
  
  Serial.begin(115200);
  Serial.println("start");

  digitalWrite(PC13, LOW);
}

// the loop function runs over and over again forever
void loop() {

//  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(100);              // wait for a second
//  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
//  delay(100); 

  int ir_L_1 = analogRead(PA5);
  int ir_L_2 = analogRead(PA4);
  int ir_F_0 = analogRead(PA3);
  int ir_R_2 = analogRead(PA2);
  int ir_R_1 = analogRead(PA1);


  if (button1 == 1 ) {
    digitalWrite(PB10, HIGH);
    
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
      digitalWrite(PB10, LOW);
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

    char values[50];
    sprintf(values, "final :%d:%d:%d:%d:%d",val1/100,val2/100,val3/100,val4/100,val5/100);
    Serial.println(values);

    button1 = 3;
    
  }

  delay(100);
    
   
  
}
