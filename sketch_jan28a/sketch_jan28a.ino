// A simple sketch that turns on the LEDs gradually.
// If the input value is greater than 767 the light is set to the maximum.
// If the input value is less than 255 the light is off.
// n^2 LEDs are required.

int myLeds[] = {6, 9, 10, 11};
int size = sizeof(myLeds) / sizeof(int);
int val = 0;
int val2 = 0;
int val3 = 0;

bool go = true;
int intensity = 0;

int led = 0;
int led2 = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
  val = 1023 - analogRead(0) + 1;
//  val = 1023 - intensity + 1; 
  Serial.println(val);

  led = 0;
  val2 = val;
  while (val2 > 256) {
    led++;
    val2 -= 256;
  }
  
//  if (led > 0) {
//    while (val2 > 256) {
//      led++;
//      val2 -= 256;
//    }
//  } else if ((led < size) {
//    while (val2 < -32) {
//      led--;
//      val2 -= 256;
//    }
//  }
  
  led2 = led;
  val3 = 0;
  if (val2 > 224) {
    led2++;
    val3 = val2 - 224;
  } else if (val2 < 32) {
    led2--;
    val3 = 32 - val2;
  }
//  Serial.println(val3);

  if (led > led2) {
    
  } else if (led < led2) {
    
  }
  

  for (int i = 0; i < size; i++) {
    if (i == led)
      analogWrite(myLeds[i], 255);
    else if (i == led2)
      analogWrite(myLeds[i], val3);
    else
      analogWrite(myLeds[i], 0);
  }
  

  if (go)
    intensity++;
  else
    intensity--;
  if (intensity == 1023 || intensity == 0)
    go = !go;
 
  delay(10);
}
