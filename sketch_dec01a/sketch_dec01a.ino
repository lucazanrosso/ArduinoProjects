// A simple sketch that turns on the LEDs gradually.
// If the input value is greater than 765 the light is set to the maximum.
// If the input value is less than 255 the light is off.
// n^2 LEDs are required.

int myLeds[] = {6, 9, 10, 11};
int size = sizeof(myLeds) / sizeof(int);
int divider = 1024 / size;
int multiplier = 1024 / divider;
int divider2 = 4 / size;
int maxVal = (divider - 1) * multiplier;
int maxVal2 = (divider / 2 - 1) * multiplier;
int val = 0;
float fVal = 0;
bool go = true;
int intensity = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
//  val = 1023 - analogRead(0);
  val = 1023 - intensity;
  Serial.println(val);

  if (val < maxVal / 4)
    for (int i = 0; i < size; i++)
        analogWrite(myLeds[i], 0);
  else if (val > maxVal / 4 * 3)
    for (int i = 0; i < size; i++)
        analogWrite(myLeds[i], 255);
  else {
    val -= maxVal / 4;
    fVal = val;
    fVal = fVal / (maxVal / 2) * maxVal2;
    val = (int) fVal;
    for (int i = 0; i < size; i++) {
      if (val > divider / 2 - 1)
        analogWrite(myLeds[i], 255);
      else if (val < 0)
        analogWrite(myLeds[i], 0);
      else
        analogWrite(myLeds[i], val / divider2);
      val -= divider  / 2 - 1;
    }
  }

  if (go)
    intensity++;
  else
    intensity--;
  if (intensity == maxVal || intensity == 0)
    go = !go;
 
  delay(10);
}
