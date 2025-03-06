#include <Wire.h>
#include "MPU6050.h"

// Create an MPU6050 object
MPU6050 accelgyro;

// Sensor reading variables
int16_t ax, ay, az, gx, gy, gz;
float roll, pitch, yaw;
float radToDeg = 180.0 / 3.14159; // To convert radians to degrees

// For yaw calculation
unsigned long lastTime = 0;
float gyroZrate = 0.0;
float yawAngle = 0.0;

// Initialize serial communication
void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Initialize Wire (I2C) library with SDA on GPIO21 and SCL on GPIO19
  Wire.begin(8, 9);  // SDA -> GPIO21, SCL -> GPIO19

  // Initialize the MPU6050 sensor
  accelgyro.initialize();

  // Check if the MPU6050 is connected
  if (accelgyro.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
    while (1);  // Halt the program if the connection fails
  }
}

// Main loop
void loop() {
  // Read raw accelerometer and gyroscope values
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert raw accelerometer values to g's
  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  // Calculate Roll (X-axis rotation) and Pitch (Y-axis rotation)
  roll = atan2(ay_g, az_g) * radToDeg;
  pitch = atan2(-ax_g, sqrt(ay_g * ay_g + az_g * az_g)) * radToDeg;

  // Yaw (Z-axis rotation) calculation: integrate the gyroscope values over time
  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0; // time difference in seconds
  lastTime = currentTime;

  // Convert gyroscope raw value to degrees per second
  gyroZrate = gz / 131.0; // 131 is the sensitivity factor for the MPU6050 gyroscope (in degrees per second)

  // Integrate to get the angle
  yawAngle += gyroZrate * dt;

  // Normalize the yaw angle to 0-360 degrees range
  if (yawAngle < 0) yawAngle += 360;
  if (yawAngle > 360) yawAngle -= 360;

  // Print the calculated angles to Serial Monitor
  Serial.print("Roll: ");
  Serial.print(roll);
  Serial.print(" Pitch: ");
  Serial.print(pitch);
  Serial.print(" Yaw: ");
  Serial.println(yawAngle);

  // Add a delay for better readability (optional)
  delay(500);
}
