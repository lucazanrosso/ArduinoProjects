// A simple sketch that turns on the LEDs gradually.
// If the input value is greater than 767 the light is set to the maximum.
// If the input value is less than 255 the light is off.
// n^2 LEDs are required.

int myLeds[] = {6, 9, 10, 11};
int size = sizeof(myLeds) / sizeof(int);
int maxVal = 512 / size;
float divider = (float) 2 / size;
float val = 0;
bool go = true;
int intensity = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
//  val = 1023 - analogRead(0) + 1;
  val = 1023 - intensity + 1; 
//  Serial.println(val);
  
  if (val < 256)
    for (int i = 0; i < size; i++)
        analogWrite(myLeds[i], 0);
  else if (val > 768)
    for (int i = 0; i < size; i++)
        analogWrite(myLeds[i], 255);
  else {
    val -= 256;
    for (int i = 0; i < size; i++) {
      if (val >= maxVal)
        analogWrite(myLeds[i], 255);
      else if (val <= 1)
        analogWrite(myLeds[i], 0);
      else
        analogWrite(myLeds[i], (val / divider) - 1);
      val -= maxVal;
    }
  }

  if (go)
    intensity++;
  else
    intensity--;
  if (intensity == 1023 || intensity == 0)
    go = !go;
 
  delay(10);
}
