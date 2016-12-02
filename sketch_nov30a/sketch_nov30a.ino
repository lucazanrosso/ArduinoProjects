// A simple sketch that turns on the LEDs gradually.
// n^2 LEDs are required.

int myLeds[] = {6, 9, 10, 11};
int size = sizeof(myLeds) / sizeof(int);
int divider = 1024 / size;
int multiplier = 1024 / divider;
int divider2 = 4 / size;
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
  val = 1023 - analogRead(0);
//  val = 1023 - intensity;
  Serial.println(val);

// Using this, you consider, for example, val == 255 and 256 equals
  
//  for (int i = 0; i < size; i++) {
//    if (val > divider - 1)
//      analogWrite(myLeds[i], 255);
//    else if (val < 0)
//      analogWrite(myLeds[i], 0);
//    else
//      analogWrite(myLeds[i], val / divider2);
//    val -= divider;
//  }

// Using this, you consider, for example, val == 255 and 256 different
  
  for (int i = 0; i < size; i++) {
    if (val > divider - 1)
      analogWrite(myLeds[i], 255);
    else if (val < 0)
      analogWrite(myLeds[i], 0);
    else
      analogWrite(myLeds[i], val / divider2);
    val -= divider - 1;
  }

  if (go)
    intensity++;
  else
    intensity--;
//  if (intensity == 1023 || intensity == 0)
  if (intensity == (divider - 1) * multiplier || intensity == 0)
    go = !go;
 
  delay(5);
}
