



void ir_read_check() {
  int ir_L_1 = analogRead(PA5);
  int ir_L_2 = analogRead(PA4);
  int ir_F_0 = analogRead(PA3);
  int ir_R_2 = analogRead(PA2);
  int ir_R_1 = analogRead(PA1);

  char values[50];
  sprintf(values, "final :%d:%d:%d:%d:%d",ir_L_1,ir_L_2,ir_F_0,ir_R_2,ir_R_1);
  Serial.println(values);

  F_sensor = 0;
  R_sensor = 0;
  L_sensor = 0;

  digitalWrite(PB0, HIGH);
  digitalWrite(PA6, HIGH);
  digitalWrite(PB10, HIGH);

  if ( ir_F_0 >= ir_F_limit) {
    // front wall present
    digitalWrite(PB0, HIGH);
    Serial.println("F_present");
    F_sensor = 1;
  }

  if ( ir_R_1 >= ir_R_limit) {
    // right wall present
    digitalWrite(PA6, HIGH);
    Serial.println("R_present");
    R_sensor = 1;
  }

  if ( ir_L_1 >= ir_L_limit) {
    // left wall present
    digitalWrite(PB10, HIGH);
    Serial.println("L_present");
    L_sensor = 1;
  }

  delay(100);
  
}
