/*To understand the context and purpose of this code, visit:
 * https://www.instructables.com/How-to-Make-a-Robot-Car-Drive-Straight-and-Turn-Ex/
 * This code makes references to steps on this Instructables website
 * written by square1a on 7th July 2022
 * 
 * Acknowledgement:
 * some of the MPU6050-raw-data-extraction code in void loop() and most in calculateError() are written by Dejan from:
 * https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/
*/
#include <Wire.h>


const int MPU = 0x68; // MPU6050 I2C address
float AccX, AccY, AccZ; //linear acceleration
float GyroX, GyroY, GyroZ; //angular velocity
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ; //used in void loop()
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;

float angle; //due to how I orientated my MPU6050 on my car, angle = roll
float targetAngle = 0;


void setup() {
  Serial.begin(9600);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission
  // Call this function if you need to get the IMU error values for your module
  calculateError();
  delay(20);

  currentTime = micros();
}

void loop() {
  // === Read accelerometer (on the MPU6050) data === //
  readAcceleration();
  // Calculating Roll and Pitch from the accelerometer data
  accAngleX = (atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI) - AccErrorX; //AccErrorX is calculated in the calculateError() function
  accAngleY = (atan(-1 * AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI) - AccErrorY;
  
  // === Read gyroscope (on the MPU6050) data === //
  previousTime = currentTime;
  currentTime = micros();
  elapsedTime = (currentTime - previousTime) / 1000000; // Divide by 1000 to get seconds
  readGyro();
  // Correct the outputs with the calculated error values
  GyroX -= GyroErrorX; //GyroErrorX is calculated in the calculateError() function
  GyroY -= GyroErrorY;
  GyroZ -= GyroErrorZ;
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by sendonds (s) to get the angle in degrees
  gyroAngleX += GyroX * elapsedTime; // deg/s * s = deg
  gyroAngleY += GyroY * elapsedTime;
  yaw += GyroZ * elapsedTime;
  //combine accelerometer- and gyro-estimated angle values. 0.96 and 0.04 values are determined through trial and error by other people
  roll = 0.96 * gyroAngleX + 0.04 * accAngleX;
  pitch = 0.96 * gyroAngleY + 0.04 * accAngleY;
  angle = yaw; //if you mounted MPU6050 in a different orientation to me, angle may not = roll. It can roll, pitch, yaw or minus version of the three
  //for me, turning right reduces angle. Turning left increases angle.
  
  // Print the values on the serial monitor
 
    Serial.print("angle: ");
      Serial.println(angle);
      // Serial.print("targetAngle: ");
      // Serial.println(targetAngle);
       Serial.print("GyroZ: ");
       Serial.println(GyroZ);
      // Serial.print("elapsedTime (in ms): "); //estimates time to run void loop() once
      // Serial.println(elapsedTime * pow(10, 3));




delay(100);
  static int count;
  static int countStraight;
  if (count < 6){  
    count ++;
  } else { //runs once after void loop() runs 7 times. void loop runs about every 2.8ms, so this else condition runs every 19.6ms or 50 times/second
    count = 0;

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
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  //For a range of +-2g, we need to divide the raw values by 16384, according to the MPU6050 datasheet
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
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
