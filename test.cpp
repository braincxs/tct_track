#include <Servo.h>
#include <Arduino.h>

// Create a servo object to control a servo
Servo myServo;  

// Define the PWM pin connected to the servo signal wire (Orange/Yellow)
const int servoPin = 9; 

void setup() {
  // Attach the servo object to the specified pin
  myServo.attach(servoPin);  
}

void loop() {
  // Sweep from 0 degrees to 180 degrees
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);              // Tell servo to go to position in variable 'angle'
    delay(15);                         // Wait 15ms for the servo to reach the position
  }

  delay(1000); // Wait 1 second at 180 degrees

  // Sweep back from 180 degrees to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);              // Tell servo to go to position in variable 'angle'
    delay(15);                         // Wait 15ms for the servo to reach the position
  }

  delay(1000); // Wait 1 second at 0 degrees
}