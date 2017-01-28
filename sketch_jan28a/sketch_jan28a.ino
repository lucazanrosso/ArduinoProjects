int myLeds[] = {6, 9, 10, 11};
int size = sizeof(myLeds) / sizeof(int);
int val = 0;
int val2 = 0;
int val3 = 0;

bool go = true;
int intensity = 0;

int led = 0;
int led2 = 0;
bool firstStart = true;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
  val = 1023 - analogRead(0) + 1;
//  val = 1023 - intensity + 1; 
  led2 = led;

  if (firstStart) {
    val2 = val;
    led = 0;
    while (val2 > 256) {
      led++;
      val2 -= 256;
    }
    firstStart = false;
  } else {
    val2 = val - led * 256;
    if (val2 >= 288) {
      led++; 
    } else if (val2 <= -32) {
      led--;
    }
  }
  
  val3 = 0;
  if (val2 >= 256) {
    led2++;
    val3 = val2 - 256;
  } else if (val2 <= 0) {
    led2--;
    val3 = - val2;
  }

  for (int i = 0; i < size; i++) {
    if (i == led)
      analogWrite(myLeds[i], 255);
    else if (i == led2)
      analogWrite(myLeds[i], val3);
    else
      analogWrite(myLeds[i], 0);
  }

  Serial.println(val);
  Serial.println(led);
  Serial.println(val2);
  Serial.println(val3);
  Serial.println();

  if (go)
    intensity++;
  else
    intensity--;
  if (intensity == 1023 || intensity == 0)
    go = !go;
 
  delay(50);
}
