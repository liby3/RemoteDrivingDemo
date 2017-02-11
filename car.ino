#define leftforward 13
#define rightforward 11
#define leftbehind 12
#define rightbehind 10
#define stoplight 9
#define goheadlight 8
#define backlight 7
// command from raspberry pi
char command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Set the port function, output or input.
  pinMode(leftforward, OUTPUT);
  pinMode(rightforward, OUTPUT);
  pinMode(leftbehind, OUTPUT);
  pinMode(rightbehind, OUTPUT);
  pinMode(stoplight, OUTPUT);
  pinMode(goheadlight, OUTPUT);
}

void goAhead() {
  digitalWrite(leftforward, HIGH);
  digitalWrite(rightforward, HIGH);
  digitalWrite(leftbehind, HIGH);
  digitalWrite(rightbehind, HIGH);
  digitalWrite(goheadlight, HIGH);
  digitalWrite(stoplight, LOW);
  digitalWrite(backlight, LOW);
}

void goStop() {
  digitalWrite(leftforward, LOW);
  digitalWrite(rightforward, LOW);
  digitalWrite(leftbehind, LOW);
  digitalWrite(rightbehind, LOW);
  digitalWrite(goheadlight, LOW);
  digitalWrite(stoplight, HIGH);
  digitalWrite(backlight, LOW);
}

void turnLeft() {
  digitalWrite(leftforward, LOW);
  digitalWrite(rightforward, HIGH);
  digitalWrite(leftbehind, LOW);
  digitalWrite(rightbehind, HIGH);
}

void turnRight() {
  digitalWrite(leftforward, HIGH);
  digitalWrite(rightforward, LOW);
  digitalWrite(leftbehind, HIGH);
  digitalWrite(rightbehind, LOW);
}

void goBack() {
  digitalWrite(leftforward, LOW);
  digitalWrite(rightforward, LOW);
  digitalWrite(leftbehind, HIGH);
  digitalWrite(rightbehind, HIGH);
  digitalWrite(goheadlight, LOW);
  digitalWrite(stoplight, LOW);
  digitalWrite(backlight, HIGH);
}

void goCircle() {
  digitalWrite(leftforward, HIGH);
  digitalWrite(rightforward, LOW);
  digitalWrite(leftbehind, LOW);
  digitalWrite(rightbehind, LOW);
  digitalWrite(goheadlight, HIGH);
  digitalWrite(stoplight, LOW);
  digitalWrite(backlight, LOW);
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  command = Serial.read();
  if (command == 'S') {
    goStop();
  }
  else if (command == 'A') {
    goAhead();
    delay(100);
  }
  else if (command == 'L') {
    turnLeft();
    delay(100);
  }
  else if (command == 'R') {
    turnRight();
    delay(100);
  }
  else if (command == 'B') {
    goBack();
    delay(100);
  }
  else if (command == 'C') {
    goCircle();
    delay(1000);
  }
}

