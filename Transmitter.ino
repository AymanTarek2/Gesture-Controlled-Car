#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial mybt(2, 3);

const int MPU_addr = 0x68;  // I2C address of the MPU-6050

int16_t accelerometer_x, accelerometer_y;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true); 

  mybt.begin(9600);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);  // request a total of 14 registers

  accelerometer_x = Wire.read() << 8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read() << 8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)

  int m = map(accelerometer_x, -16384, 16383, 0, 1023);
  int n = map(accelerometer_y, -16384, 16383, 0, 1023);

  n -= 500;
  m -= 500;
  Serial.print("Received n: ");
  Serial.println(n);
  Serial.print("Received m: ");
  Serial.println(m);
  
  delay(20);
  
   mybt.print(n);
    mybt.print(',');
    mybt.println(m);
}