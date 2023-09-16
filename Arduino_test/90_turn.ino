int encoderPin1 = PB13;  // Encoder Output 'A' must be connected to interrupt pin of Arduino.
int encoderPin2 = PB12;  // Encoder Output 'B' must be connected to interrupt pin of Arduino.
int encoderPin3 = PA12;  // Encoder Output 'A' must be connected to interrupt pin of Arduino.
int encoderPin4 = PA11;  // Encoder Output 'B' must be connected to interrupt pin of Arduino.

int right_count = 0;
int left_count = 0;

// Motor control pins
int motorPin1 = PB8;  // Replace with your actual motor control pins
int motorPin2 = PB9;  // Replace with your actual motor control pins

int motorPinA1 = PC14;  // Replace with your actual motor control pins
int motorPinA2 = PB5;   // Replace with your actual motor control pins

int motorPinB1 = PB6;  // Replace with your actual motor control pins
int motorPinB2 = PB7;  // Replace with your actual motor control pins

int delta_Speed = 0;
// Constants for control
int desiredCount = 1000;  // Desired encoder count for forward motion
double Kp = 1;            // Proportional gain
double Ki = 0;            // Integral gain
double Kd = 0;            // Derivative gain
double prevError = 0;
double integral = 0;

int button1 = 0;

void setup() {
  Serial.begin(115200);  // Initialize serial communication

  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
  pinMode(encoderPin3, INPUT_PULLUP);
  pinMode(encoderPin4, INPUT_PULLUP);

  pinMode(PB15, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PB15), click1, FALLING);

  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder_right, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderPin4), updateEncoder_left, FALLING);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(motorPinB1, OUTPUT);
  pinMode(motorPinB2, OUTPUT);


  // Initialize motor control pins (set one HIGH and the other LOW to make the robot move forward)
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);

  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}

void loop() {

  if (button1 == 1) {
    // digitalWrite(motorPinA1, LOW);
    // digitalWrite(motorPinA2, HIGH);

    // digitalWrite(motorPinB1, LOW);
    // digitalWrite(motorPinB2, HIGH);

    delay(1000);

    turn_R();

    delay(500);

    turn_L();
  }



  //  // Calculate error for both encoders

  int Error = left_count - right_count;
  //int Error = 0;

  //
  //  // Calculate integral and derivative terms
  integral += Error;
  double derivative = Error - prevError;
  //
  //  // Calculate motor speed adjustments based on PID control
  delta_Speed = Kp * double(Error) + Ki * integral + Kd * derivative;

  int leftSpeed = leftSpeed - delta_Speed;
  int rightSpeed = rightSpeed + delta_Speed;

  //
  //  // Apply motor speed adjustments to achieve forward motion
  analogWrite(motorPin1, constrain(255 - leftSpeed, 0, 150));
  analogWrite(motorPin2, constrain(255 - rightSpeed, 0, 150));
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

  delay(100);
}

void updateEncoder_left() {
  left_count++;
}

void updateEncoder_right() {
  right_count++;
}

void click1() {
  button1 = 1;
}


void turn_R() {
  left_count = 0;
  right_count = 0;

  analogWrite(motorPin1, 80);
  analogWrite(motorPin2, 80);

  while (left_count < 85 && right_count < 85) {
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

void turn_L() {
  left_count = 0;
  right_count = 0;

  analogWrite(motorPin1, 80);
  analogWrite(motorPin2, 80);

  while (left_count < 85 && right_count < 85) {
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
