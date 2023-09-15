

int encoderPin1 = PB13; //Encoder Output 'A' must connected with intreput pin of arduino.
int encoderPin2 = PB12; //Encoder Otput 'B' must connected with intreput pin of arduino.
int encoderPin3 = PA10; //Encoder Output 'A' must connected with intreput pin of arduino.
int encoderPin4 = PA11; //Encoder Otput 'B' must connected with intreput pin of arduino.

int right_count = 0;
int left_count = 0;

void setup() {

  
  Serial.begin(9600); //initialize serial comunication

   pinMode(encoderPin1, INPUT_PULLUP); 
  pinMode(encoderPin2, INPUT_PULLUP);

//  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
//  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(encoderPin1, updateEncoder_left, FALLING); 
  attachInterrupt(encoderPin2, updateEncoder_left, FALLING);
  attachInterrupt(encoderPin3, updateEncoder_right, FALLING); 
  attachInterrupt(encoderPin4, updateEncoder_right, FALLING);


}

void loop() {


 Serial.print(left_count);
 Serial.print(" ");
 Serial.println(right_count);
 delay(100);
 


} 

void updateEncoder_left(){
  left_count = left_count+1;
}

void updateEncoder_right(){
  right_count= right_count+1;
}
