// Pin connections for the L298N motor driver
const int enablePin = 9;  // PWM pin for speed control
const int in1Pin = 8;     // Motor direction pin 1
const int in2Pin = 7;     // Motor direction pin 2

void setup() {
  // Set the motor control pins as outputs
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  // Rotate motor forward for 5 seconds
  rotateMotor(true);
  delay(5000);

  // Rotate motor backward for 5 seconds
  rotateMotor(false);
  delay(5000);
}

void rotateMotor(bool forward) {
  if (forward) {
    // Set motor direction forward
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  } else {
    // Set motor direction backward
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }

  // Enable the motor with PWM on the enable pin
  analogWrite(enablePin, 255);  // Adjust 255 for desired speed
}
