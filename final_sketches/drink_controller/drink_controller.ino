#include <Servo.h>;

Servo servo1; 
Servo servo2;

int carReady = 1; // ready, busy : 0

int pos1 = 90, pos2 = 90, dir = 0, motor = 1, button = 3, xValue, yValue; // Variables for each motor position and motor selection, button for test purposes
int pinMotor1 = 5;
int pinMotor2 = 6;
int openAngle = 160;
int closedAngle = 10;

void setup() {
  Serial.begin(9600);
  servo1.attach(pinMotor1);
  servo2.attach(pinMotor2);
  pinMode(button, INPUT);
}

void loop() {
  int startDrink = digitalRead(button);
  if (startDrink && carReady){
    carReady = 0;
    serve_drink();
    delay(1000); // wait 1 sec, no need to rush
    change_drink(1, 2);
    while(!carReady){
      if(Serial.available() > 0){
        carReady = Serial.read();
      }
      delay(10);
    }
    delay(1000); // wait 1 sec, no need to rush
    serve_drink();
    delay(1000); // wait 1 sec, no need to rush
    change_drink(2, 1);
  }
}

void change_drink(int startDrink, int destinationDrink){
  int change = destinationDrink - startDrink;
  switch(change){
    case 0:
      break;
    case 1:
      motor = 2; // Switches to other motor for next serving
      Serial.write('f');
      break;
    case -1: 
      motor = 1; // Switches to other motor for next serving
      Serial.write('b');
  }
}


void serve_bottle(Servo servo, int amount){
  servo.write(openAngle); // Open position
  delay(amount);
  servo.write(closedAngle); // Closed position
}


void serve_drink(){
   switch(motor){
     case 1:
       serve_bottle(servo1, 3000);
       break;
     case 2: 
       serve_bottle(servo2, 3000);
   }
}
