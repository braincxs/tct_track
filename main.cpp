#include <Arduino.h>
#include <Servo.h>

const int SERVO_PIN = 15; 
Servo myServo;

int current_angle = 90; // Start in the middle

void setup() {
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);
  
  // Set initial position
  myServo.write(current_angle);
  
  // Wait a moment for the Serial Monitor to connect
  delay(2000); 
  Serial.println("--- Servo Control Ready ---");
  Serial.println("Type 'a' to move Left, 'd' to move Right, 'w' to Center.");
}

void loop() {
  // Check if the computer has sent any data over the USB cord
  if (Serial.available() > 0) {
    
    // Read the incoming keystroke
    char key = Serial.read(); 

    if (key == 'a' || key == 'A') {
      current_angle -= 15; // Move 15 degrees left
    } 
    else if (key == 'd' || key == 'D') {
      current_angle += 15; // Move 15 degrees right
    }
    else if (key == 'w' || key == 'W') {
      current_angle = 90; // Go to center
    }

    // Keep the angle within safe physical bounds (0 to 180 degrees)
    if (current_angle < 0) current_angle = 0;
    if (current_angle > 270) current_angle = 270;

    // Command the servo to move
    myServo.write(current_angle);
    
    // Print the new angle back to the computer screen
    if (key == 'a' || key == 'A' || key == 'd' || key == 'D' || key == 'w' || key == 'W') {
      Serial.print("Current Angle: ");
      Serial.println(current_angle);
    }
  }
}