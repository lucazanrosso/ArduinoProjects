// "Energy transer experiment" || 4 LEDS

int myLeds[] = {6, 9, 10, 11};
int size = sizeof(myLeds) / sizeof(int);
int light = 0;
int val = 0;
int val2 = 0;
int led = 0;
int led2 = 0;
bool firstStart = true;

bool go = true;
int intensity = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(myLeds[i], OUTPUT);
  }
}

void loop() {
  light = 1023 - analogRead(0) + 1;
//  light = 1023 - intensity + 1; 
  led2 = led;

  if (firstStart) {
    val = light;
    while (val2 > 256) {
      led++;
      val -= 256;
    }
    firstStart = false;
  } else {
    val = light - led * 256;
    if (val > 319) {
      led++; 
    } else if (val < -63) {
      led--;
    }
  }
  
  val2 = 0;
  if (val > 256) {
    led2++;
    val2 = val - 256;
  } else if (val < 0) {
    led2--;
    val2 = - val;
  }

  for (int i = 0; i < size; i++) {
    if (i == led)
      analogWrite(myLeds[i], 255 - val2);
    else if (i == led2)
      analogWrite(myLeds[i], val2);
    else
      analogWrite(myLeds[i], 0);
  }

//  Serial.println(light);
//  Serial.println(led);
//  Serial.println(val);
//  Serial.println(val2);
//  Serial.println();

  if (go)
    intensity++;
  else
    intensity--;
  if (intensity == 1023 || intensity == 0)
    go = !go;
 
  delay(20);
}
