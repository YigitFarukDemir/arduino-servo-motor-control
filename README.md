# arduino-selvo-motor-control

**Project Report: Arduino Robot Hand Control**  

1. **Project Title:**  
Control of Robot Hand with Arduino Uno  

2. **Project Objective:**  
This project aims to control a robotic hand using two servo motors based on the movements of a joystick. The setup includes an Arduino Uno board, a joystick, two servo motors, a breadboard, and necessary connections. The X and Y-axis movements of the joystick will adjust the angles of the two servo motors.  

3. **Required Hardware:**  
- 1 x Arduino Uno board  
- 1 x Joystick (analog) module  
- 2 x Servo motors  
- 1 x Robotic hand model  
- 1 x Breadboard  
- Several jumper wires  
- 1 x USB cable (for connecting Arduino to the computer)  

4. **Connection Diagram:**  

**Joystick Connections:**  
- Joystick X-axis (Vx) output: Connects to Arduino’s A0 pin.  
- Joystick Y-axis (Vy) output: Connects to Arduino’s A1 pin.  
- Joystick VCC pin: Connects to Arduino’s 5V pin.  
- Joystick GND pin: Connects to Arduino’s GND pin.  

**Servo Motor Connections:**  
- Servo 1 (for X-axis): Connects to pin 6.  
- Servo 2 (for Y-axis): Connects to pin 7.  
- Both servo motor GND pins: Connect to Arduino’s GND pin.  
- Both servo motor VCC pins: Connect to Arduino’s 5V pin.  

**Breadboard Connections:**  
Since the Arduino board does not have sufficient 5V and GND pins to support two servo motors and the joystick, a bus line is set up on the breadboard for these pins, and the 5V and GND connections of the servo motors and joystick are routed through the breadboard.  

5. **Software:**  
A program was written using Arduino IDE to read the X and Y-axis movements of the joystick and use these readings to control the angles of the two servo motors.  

**Code:**  

#include <Servo.h>  // Include the Servo library

// Servo motor pins
int servoPin1 = 6;  // First servo motor for X-axis
int servoPin2 = 7;  // Second servo motor for Y-axis

// Joystick analog pins
int joyX = A0;  // X-axis
int joyY = A1;  // Y-axis

// Create Servo objects
Servo servo1;
Servo servo2;

void setup() {
  // Attach servo motors
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // Set initial servo angles to 90 degrees
  servo1.write(90);
  servo2.write(90);

  // Start Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read analog values from joystick X and Y axes
  int xValue = analogRead(joyX);  // X-axis (range 0-1023)
  int yValue = analogRead(joyY);  // Y-axis (range 0-1023)

  // Map joystick values to servo angles (0-180 degrees)
  int servo1Angle = map(xValue, 0, 1023, 0, 180);  // X-axis for servo
  int servo2Angle = map(yValue, 0, 1023, 0, 180);  // Y-axis for servo

  // Set servo angles
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);

  // Display joystick values and servo angles on Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.print(yValue);
  Serial.print(" Servo1: ");
  Serial.print(servo1Angle);
  Serial.print(" Servo2: ");
  Serial.println(servo2Angle);
}

6. **Software Explanations:**  
- **Servo Library:** The Servo.h library was used to control the servo motors.  
- **Analog Reading:** Analog values from the joystick’s X and Y axes were read using the `analogRead()` function.  
- **Angle Conversion:** Joystick values were converted into servo motor angles (0-180 degrees) using the `map()` function.  
- **Servo Motor Control:** Servo motor angles were set using the `servo.write()` function.  
- **Serial Monitor:** Joystick movements and servo angles were displayed on the Serial Monitor using the `Serial.print()` function.  

7. **Working Principle:**  
- The X and Y axes of the joystick are read as analog signals by Arduino.  
- The X-axis controls the angle of the first servo motor, while the Y-axis controls the second.  
- As the joystick is moved, the servo motors change angles accordingly.  
- Both servo motors remain at 90 degrees initially but adjust their angles as the joystick is moved right, left, up, or down.  

8. **Results and Observations:**  
- The angles of both servo motors were successfully controlled through joystick movements.  
- The X-axis of the joystick controlled the movement of the first servo motor, while the Y-axis controlled the second.  
- The project demonstrated a basic but effective implementation of joystick control over servo motors.  

9. **Possible Improvements:**  
- Adding more servo motors to allow individual finger control.  
- Using the unused switch pin of the joystick to switch between different servo motors, enabling more complex movements.  

10. **Conclusion:**  
This project provided a practical solution for integrating a joystick and servo motors with Arduino, enabling users to control the physical movements of a robotic hand in a digital environment.  

---  
