//Control Device using Joystick

// Define the pins for the motor driver
const int enablePin = 9;  // Motor driver enable pin (ENA)
const int in1Pin = 7;     // Motor driver input 1 (IN1)
const int in2Pin = 8;     // Motor driver input 2 (IN2)

// Define the joystick pin
const int joystickPinY = A0;

void setup() {

  // Set motor driver pins as OUTPUT
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  // Initialize the motor as stopped
  digitalWrite(enablePin, LOW);
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
}

void loop() {
  // Read the Y-axis value from the joystick
  int yValue = analogRead(joystickPinY);

  // Map the joystick value to motor speed (adjust the range if needed)
  int motorSpeed = map(yValue, 0, 1023, -255, 255);

  // Control the motor direction based on the joystick value
  if (motorSpeed > 0) {
    // Move forward
    analogWrite(enablePin, abs(motorSpeed));
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  } else if (motorSpeed < 0) {
    // Move backward
    analogWrite(enablePin, abs(motorSpeed));
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  } else {
    // Stop the motor if the joystick is centered
    digitalWrite(enablePin, LOW);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  }
  delay(100);
}
