int lEnable = 10;
int lForward = 9;
int lBackward = 8;
int rEnable = 11;
int rForward = 13;
int rBackward = 12;

int pulseWidth = 200;
int potValue = 0;
char mode;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode (rBackward, OUTPUT);
  pinMode (rForward, OUTPUT);
  pinMode (rEnable, OUTPUT);
  pinMode (lEnable, OUTPUT);
  pinMode (lForward, OUTPUT);
  pinMode (lBackward, OUTPUT);
}

void loop() {
  if( Serial.available() > 0 ){
    mode = Serial.read();
    delay(100);
    potValue = Serial.read();
    if( mode == 'f' ){
      move_forward();
    }
    if( mode == 'b' ){
      move_backward();
    }
  }
}

void move_forward() {
  int timeMoving = map(potValue, 0, 127, 0, 2000);
  digitalWrite (rForward, HIGH);
  digitalWrite (rBackward, LOW);
  digitalWrite (lForward, HIGH);
  digitalWrite (lBackward, LOW);
  analogWrite (rEnable, pulseWidth);
  analogWrite (lEnable, pulseWidth);
  delay (timeMoving);
  analogWrite (rEnable, 0);
  analogWrite (lEnable, 0);
  Serial.write(1); // ready to get new instructions
}

void move_backward() {
  int timeMoving = map(potValue, 0, 127, 0, 2000);
  digitalWrite (rBackward, HIGH);
  digitalWrite (rForward, LOW);
  digitalWrite (lBackward, HIGH);
  digitalWrite (lForward, LOW);
  analogWrite (rEnable, pulseWidth);
  analogWrite (lEnable, pulseWidth);
  delay (timeMoving);
  analogWrite (rEnable, 0);
  analogWrite (lEnable, 0);
  Serial.write(1); // ready to get new instructions
}
