int myLeds[4] = {6, 9, 10, 11};
int size = sizeof(myLeds)/sizeof(int);
int val = 0;
bool go = true;
int intensity = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
//  val = analogRead(0);
  val = intensity;
  Serial.println(val);
  
  for (int i = 0; i < size; i++) {
    if (val > 255)
      analogWrite(myLeds[i], 255);
    else if (val < 0)
      analogWrite(myLeds[i], 0);
    else
      analogWrite(myLeds[i], val);
    val -= 256;
  }

//  for (int i = 0; i < size; i++) {
//    analogWrite(myLeds[i], val/4);
//    val = val / 2;
//  }

  if (go)
    intensity++;
  else
    intensity--;
  if (intensity == 1023 || intensity == 0)
    go = !go;
 
  delay(10);
}
