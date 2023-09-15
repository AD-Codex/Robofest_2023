#include <Arduino.h>
#include <Encoder.h>

// Define encoder pins
int encoderPinA = 2;  // Replace with your actual pin numbers
int encoderPinB = 3;

Encoder myEncoder(encoderPinA, encoderPinB);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long encoderValue = myEncoder.read();
  Serial.println(encoderValue);
  // You can also control the motor based on the encoder value here.
}
