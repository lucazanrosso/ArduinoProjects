int LED = 11;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  if(Serial1.available()){
      String s = Serial1.readString();
      Serial.println(s);
  }  
  if(Serial.available()){
    char c = Serial.read();
    Serial1.write(c);
  }
}
