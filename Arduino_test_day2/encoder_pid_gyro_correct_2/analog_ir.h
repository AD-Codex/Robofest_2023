

void ir_read_check() {
  int ir_L_1 = analogRead(PA5);
  int ir_L_2 = analogRead(PA4);
  int ir_F_0 = analogRead(PA3);
  int ir_R_2 = analogRead(PA2);
  int ir_R_1 = analogRead(PA1);

  char values[50];
  sprintf(values, "final :%d:%d:%d:%d:%d",ir_L_1,ir_L_2,ir_F_0,ir_R_2,ir_R_1);
  Serial.println(values);

  delay(10);
  
}
