#include <Servo.h>;

Servo servo1; // Dem Servo eine Bezeichnung geben
Servo servo2;

#define joyX A0 // Pin A0 - Joystick X
#define joyY A1 // Pin A1 - Joystick Y
#define joyBTN D7  // Pin D7 - Joystick Button


int pos1 = 90, pos2 = 90, dir = 0, motor = 1, button = 8, xValue, yValue; // Variablen für Position (pos), Richtung (dir), sowie den X und Y Wert des Joysticks 

void setup() {
  Serial.begin(9600);
  servo1.attach (9); // Steuerungsleitung vom Servo wird mit Pin 9 verbunden
  servo2.attach(10);
  pinMode(button, INPUT);
}


void serveBottle(Servo servo, int amount){
  servo.write(150);
  delay(amount);
  servo.write(10);
}


void loop() {
  xValue = analogRead(joyX); // X-Position des Joysticks abfragen
  yValue = analogRead(joyY); // Y-Position des Joysticks abfragen
  int buttonState = digitalRead(button);
  //Auf Seriellem Monitor ausgeben - nur zur Fehlersuche
  Serial.print(pos1);
  Serial.print("\t\n");
  Serial.print(pos1);
  Serial.print("\t\n");
  Serial.print(xValue);
  Serial.print("\t\n");
  Serial.print(yValue);
  Serial.print("\t\n");

  if (buttonState == HIGH){
    switch(motor){
      case 1:
        serveBottle(servo1, 5000);
        motor = 2;
        break;

      case 2: 
        serveBottle(servo2, 5000);
        motor = 1;
    }
  }
/*
  if (yValue > 505){
    motor = 1;
  }

  if (yValue < 485){
    motor = 2;
  }
  
  if (motor == 1){
    if (xValue < 500){ // Wenn Joy nach Links <- 
      pos1 = --pos1; // pos wird veringert
    } 
    
    if (xValue > 520){ // Wenn Joy nach Rechts
      pos1 = ++pos1;  // pos wir erhöht
    }
  
    if (pos1 < 0){ // Damit pos nicht negativ wird
      pos1 = 0;
    }
    if (pos1 > 180){ // Damit pos nicht über 180 geht
      pos1 = 180;
    }
  }

  if (motor == 2){
    if (xValue < 500){ // Wenn Joy nach Links <- 
      pos2 = --pos2; // pos wird veringert
    } 
    
    if (xValue > 520){ // Wenn Joy nach Rechts
      pos2 = ++pos2;  // pos wir erhöht
    }
  
    if (pos2 < 0){ // Damit pos nicht negativ wird
      pos2 = 0;
    }
    if (pos2 > 180){ // Damit pos nicht über 180 geht
      pos2 = 180;
    }
  }
  
  delay(5);
  if (motor == 1){
    servo1.write(pos1); // Servo auf Position "pos" bewegen
  }

  else{
     servo2.write(pos2);
  }
*/
 
}
