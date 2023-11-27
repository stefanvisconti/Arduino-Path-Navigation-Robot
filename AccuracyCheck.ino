#include <Wire.h>
#include <HCSR04.h>

const int trigPin = 2;
const int echoPin = 3;
long duration;  // Time taken for the ultrasonic pulse to travel to the object and back
int distance;   // Calculated distance in centimeters
int m = 0;
int q = 1;
int r = 0;
int s = 0;
int i = 0;
const int MPU = 0x68;                                            // MPU6050 I2C address
float AccX, AccY, AccZ;                                          //linear acceleration
float GyroX, GyroY, GyroZ;                                       //angular velocity
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;  //used in void loop()
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;

int angle;  //due to how I orientated my MPU6050 on my car, angle = roll
float targetAngle = 0;

// Motor control pins for L298N
const int enablePin = 9;  // Enable pin of the L298N motor driver
const int in1 = 8;        // IN1 pin of the L298N motor driver
const int in2 = 7;        // IN2 pin of the L298N motor driver

// Constants for motor control
const int motorSpeed = 255;  // Adjust this value based on your motor and robot characteristics

void setup() {
  Serial.begin(9600);
  Wire.begin();                 // Initialize comunication
  Wire.beginTransmission(MPU);  // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);             // Talk to the register 6B
  Wire.write(0x00);             // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);   //end the transmission
  // Call this function if you need to get the IMU error values for your module
  calculateError();
  delay(20);
  currentTime = micros();

  pinMode(enablePin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);
}

void loop() {
  // === Read accelerometer (on the MPU6050) data === //
  readAcceleration();
  // Calculating Roll and Pitch from the accelerometer data
  accAngleX = (atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI) - AccErrorX;  //AccErrorX is calculated in the calculateError() function
  accAngleY = (atan(-1 * AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI) - AccErrorY;

  // === Read gyroscope (on the MPU6050) data === //
  previousTime = currentTime;
  currentTime = micros();
  elapsedTime = (currentTime - previousTime) / 1000000;  // Divide by 1000 to get seconds
  readGyro();
  // Correct the outputs with the calculated error values
  GyroX -= GyroErrorX;  //GyroErrorX is calculated in the calculateError() function
  GyroY -= GyroErrorY;
  GyroZ -= GyroErrorZ;
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by sendonds (s) to get the angle in degrees
  gyroAngleX += GyroX * elapsedTime;  // deg/s * s = deg
  gyroAngleY += GyroY * elapsedTime;
  yaw += GyroZ * elapsedTime;
  //combine accelerometer- and gyro-estimated angle values. 0.96 and 0.04 values are determined through trial and error by other people
  roll = 0.96 * gyroAngleX + 0.04 * accAngleX;
  pitch = 0.96 * gyroAngleY + 0.04 * accAngleY;
  angle = yaw;  //if you mounted MPU6050 in a different orientation to me, angle may not = roll. It can roll, pitch, yaw or minus version of the three
                //for me, turning right reduces angle. Turning left increases angle.

  // Print the values on the serial monitor
  angle = -angle;

  // Trigger the sensor by sending a 10-microsecond pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the pulse from the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters using the speed of sound (343 meters/second)
  distance = duration * 0.0343 / 2;

  if ((distance > 10) && (m == 0)) {
    driveForward();
  } else {
    if ((q == 1)) {
      i = turnRight1(i);
    }
    if (q == 2) {
      i = turnRight2(i);
    }
    if ((q == 3) && (i > 1)) {
      i = turnRight3(i);
    }
    if ((q == 4) && (i > 2)) {
      calculateError();
      Serial.println("WOOHOOO FUCK YEAH!!!!!");
      m = 0;
      q = 1;
      i = 0;
    }
  }
}

void calculateError() {
  //When this function is called, ensure the car is stationary. See Step 2 for more info

  // Read accelerometer values 200 times
  c = 0;
  while (c < 200) {
    readAcceleration();
    // Sum all readings
    AccErrorX += (atan((AccY) / sqrt(pow((AccX), 2) + pow((AccZ), 2))) * 180 / PI);
    AccErrorY += (atan(-1 * (AccX) / sqrt(pow((AccY), 2) + pow((AccZ), 2))) * 180 / PI);
    c++;
  }
  //Divide the sum by 200 to get the error value, since expected value of reading is zero
  AccErrorX = AccErrorX / 200;
  AccErrorY = AccErrorY / 200;
  c = 0;

  // Read gyro values 200 times
  while (c < 200) {
    readGyro();
    // Sum all readings
    GyroErrorX += GyroX;
    GyroErrorY += GyroY;
    GyroErrorZ += GyroZ;
    c++;
  }
  //Divide the sum by 200 to get the error value
  GyroErrorX = GyroErrorX / 200;
  GyroErrorY = GyroErrorY / 200;
  GyroErrorZ = GyroErrorZ / 200;
  Serial.println("The the gryoscope setting in MPU6050 has been calibrated");
}

void readAcceleration() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);  // Read 6 registers total, each axis value is stored in 2 registers
  //For a range of +-2g, we need to divide the raw values by 16384, according to the MPU6050 datasheet
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0;  // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0;  // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0;  // Z-axis value
}

void readGyro() {
  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
}

void driveForward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enablePin, motorSpeed);
}

void driveBackward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enablePin, motorSpeed);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enablePin, 0);
}

int turnRight1(int i) {
  if ((angle < 270)) {
    m = 1;
    driveBackward();
    delay(100);
  } else {
    q = 2;
    Stop();
  }
  return i = 1;
}

int turnRight2(int i) {
  if ((angle < 280) && (angle > 170)) {
    driveForward();
    m = 2;
    delay(100);
  } else {
    q = 3;
    s = 1;
    r = 0;
    Stop();
  }
  return i = 2;
}

int turnRight3(int i) {
  if ((angle < 280)) {
    driveBackward();
    m = 3;
  } else {
    q = 4;
  }
  return i = 3;
}
