int leds[] = {6, 9, 10, 11};
int size = sizeof(leds) / sizeof(int);
int i = -1;
int values[] = {0, 0, 0, 0};

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  for (int i = 0; i < size; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  if(Serial1.available()){
      i = Serial1.read() - 48;
//      Serial.println(i);
  }

  values[i] = 255;
  i = -1;

  for (int j = 0; j < size; j++) {
    if (values[j] >= 0) {
      analogWrite(leds[j], values[j]);
      values[j]--;
    }
  }

  delay(2);
}
