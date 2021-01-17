#include <Servo.h>;

Servo servo1; 
Servo servo2;

int pos1 = 90, pos2 = 90, dir = 0, motor = 1, button = 8, xValue, yValue; // Variables for each motor position and motor selection, button for test purposes

void setup() {
  Serial.begin(9600);
  servo1.attach (9); // Pin selection - IMPORTANT: Pin needs to support PWM
  servo2.attach(10);
  pinMode(button, INPUT);
}


void serveBottle(Servo servo, int amount){
  servo.write(150); // Open position
  delay(amount);
  servo.write(10); // Closed position
}


void loop() {
  int buttonState = digitalRead(button);

  // Debugging
  Serial.print(pos1);
  Serial.print("\t\n");
  Serial.print(pos2);
  Serial.print("\t\n");
  
  if (buttonState == HIGH){
    switch(motor){
      case 1:
        serveBottle(servo1, 5000);
        motor = 2; // Switches to other motor for next serving
        break;

      case 2: 
        serveBottle(servo2, 5000);
        motor = 1; // Switches to other motor for next serving
    }
  }
}
