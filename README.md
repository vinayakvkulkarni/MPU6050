"Arduino Uno project for real-time roll, pitch, and yaw calculation using the MPU6050 sensor. Reads accelerometer and gyroscope data via I2C (pins 8, 9) and prints the calculated angles to the Serial Monitor. Developed in Arduino IDE."

Here are the connections for your MPU6050 with Arduino Uno setup:
MPU6050 to Arduino Uno:
VCC → 5V
GND → GND
SDA → Pin 8 (I²C Data)
SCL → Pin 9 (I²C Clock)
Serial Monitor Settings:
Baud Rate: 115200
However, typically the default I²C pins on the Arduino Uno are:
SDA → A4
SCL → A5
