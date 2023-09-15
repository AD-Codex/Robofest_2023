int encoderPin1 = PB13; // Encoder Output 'A' must be connected to interrupt pin of Arduino.
int encoderPin2 = PB12; // Encoder Output 'B' must be connected to interrupt pin of Arduino.
int encoderPin3 = PA10; // Encoder Output 'A' must be connected to interrupt pin of Arduino.
int encoderPin4 = PA11; // Encoder Output 'B' must be connected to interrupt pin of Arduino.

int right_count = 0;
int left_count = 0;

// Motor control pins
int motorPin1 = PB4; // Replace with your actual motor control pins
int motorPin2 = PB7; // Replace with your actual motor control pins

// Constants for control
int desiredCount = 1000; // Desired encoder count for forward motion
double Kp = 0.1; // Proportional gain
double Ki = 0.01; // Integral gain
double Kd = 0.05; // Derivative gain
double prevError = 0;
double integral = 0;

void setup() {
  Serial.begin(115200); // Initialize serial communication

  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
  pinMode(encoderPin3, INPUT_PULLUP);
  pinMode(encoderPin4, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder_left, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder_left, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderPin3), updateEncoder_right, FALLING);
  attachInterrupt(digitalPinToInterrupt(encoderPin4), updateEncoder_right, FALLING);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Initialize motor control pins (set one HIGH and the other LOW to make the robot move forward)
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void loop() {
  // Calculate error for both encoders
  int leftError = desiredCount - left_count;
  int rightError = desiredCount - right_count;

  // Calculate integral and derivative terms
  integral += (leftError + rightError) / 2.0;
  double derivative = (leftError + rightError) / 2.0 - prevError;

  // Calculate motor speed adjustments based on PID control
  double leftSpeed = Kp * leftError + Ki * integral + Kd * derivative;
  double rightSpeed = Kp * rightError + Ki * integral + Kd * derivative;

  // Apply motor speed adjustments to achieve forward motion
  analogWrite(motorPin1, constrain(255 - leftSpeed, 0, 255));
  analogWrite(motorPin2, constrain(255 - rightSpeed, 0, 255));

  // Update previous error for the next iteration
  prevError = (leftError + rightError) / 2.0;

  Serial.print("Left Count: ");
  Serial.print(left_count);
  Serial.print(", Right Count: ");
  Serial.println(right_count);
  delay(100);
}

void updateEncoder_left() {
  left_count++;
}

void updateEncoder_right() {
  right_count++;
}
