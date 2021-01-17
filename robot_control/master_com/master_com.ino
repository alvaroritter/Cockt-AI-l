int ledForward = 2;
int ledBackward = 3;

int potPin = A5;

int carReady = 1; // ready, busy : 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledForward, INPUT);
  pinMode(ledBackward, INPUT);
  pinMode(potPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(ledForward), forward_command, RISING);
  attachInterrupt(digitalPinToInterrupt(ledBackward), backward_command, RISING);
}

void loop() {
  if (Serial.available() > 0){
    carReady = Serial.read();
  }
}

void forward_command(){
  if (carReady){
    carReady = 0;
    Serial.write('f');
    delay(100);
    Serial.write(map(analogRead(potPin), 0, 1024, 0, 127));
  }
}
void backward_command(){
  if (carReady) {
    carReady = 0;
    Serial.write('b');
    delay(100);
    Serial.write(map(analogRead(potPin), 0, 1024, 0, 127));
  }
}
