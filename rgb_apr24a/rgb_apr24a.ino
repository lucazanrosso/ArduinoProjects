const int RED = 10;
const int GREEN = 9;
const int BLUE = 8;
//const int RED2 = 4;
//const int GREEN2 = 3;
//const int BLUE2 = 2;
int intensity = 0;
char color;
int i = 0;
int c = 0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
//  digitalWrite(RED, HIGH);
//  digitalWrite(GREEN, HIGH);
//  digitalWrite(BLUE, HIGH);
  //  pinMode(RED2, OUTPUT);
  //  pinMode(GREEN2, OUTPUT);
  //  pinMode(BLUE2, OUTPUT);
  //  digitalWrite(RED2, LOW);
  //  digitalWrite(GREEN2, LOW);
  //  digitalWrite(BLUE2, LOW);
}

void loop() {
  if (Serial1.available()) {
    if (i < 3) {
      c = Serial1.read();
      intensity += c * pow(10, (2 - i));
    } else {
      color = Serial1.read();
    }
    i += 1;
  }
  if (i == 4) {
    //    Serial.println(intensity - 5327);
    //    Serial.println(color);
    switch (color) {
      case 'r':
        analogWrite(RED, intensity  - 5327);
        //        analogWrite(RED2, intensity  - 5327);
        break;
      case 'g':
        analogWrite(GREEN, (int) (intensity  - 5327)/2);
        //        analogWrite(GREEN2, intensity  - 5327);
        break;
      case 'b':
        analogWrite(BLUE, (int) (intensity  - 5327)/2);
        //        analogWrite(BLUE2, intensity  - 5327);
        break;
    }
    intensity = 0;
    i = 0;
  }
}
