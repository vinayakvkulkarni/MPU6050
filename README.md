This project reads data from the MPU6050 6-axis motion sensor and calculates the roll, pitch, and yaw angles using Arduino. It uses I2C communication and simple trigonometry & gyroscope integration to estimate orientation in 3D space.

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

📦 Features
📐 Calculates roll (X-axis tilt), pitch (Y-axis tilt), and yaw (Z-axis rotation)
📊 Real-time data printing via Serial Monitor
🔄 Yaw is estimated via gyroscope Z-axis integration
⚡ Fast and lightweight code

🧰 Hardware Required
Component	Quantity
MPU6050 Sensor	1
Arduino Board (Uno/ESP32/etc.)	1
Jumper Wires	as needed
Breadboard	Optional

📜 How It Works
Accelerometer Data is used to calculate:
Roll → atan2(ay, az)
Pitch → atan2(-ax, sqrt(ay² + az²))
Gyroscope Z-Axis (gz) is integrated over time to estimate Yaw
Uses gz / 131.0 to convert to deg/sec
Accumulates angle over time using millis()

🚀 Future Improvements
Add Kalman Filter or Complementary Filter for more stable results
Send data to a mobile app or dashboard using Bluetooth/Wi-Fi
Use for controlling servo motors or flight control systems
