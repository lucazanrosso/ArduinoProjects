#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

int verificationCode = 0;
String user = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin("", "");
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin("", "");
}

void loop() {
  if (Firebase.getBool(user + "/alarm_is_set")) {
    verificationCode += 1;
    if (verificationCode == 4) {
      verificationCode = 0;
    }
    if (analogRead(A0) > 511 || Firebase.getBool(user + "/thief_is_entered")) {
      setLed('r');
      Firebase.setBool(user + "/thief_is_entered", true);
    } else {
      setLed('g');
    }    
  } else {
    setLed('y');
    verificationCode = -1;
  }
  
  Firebase.setInt(user + "/verification_code", verificationCode);

  Serial.println(analogRead(A0));
  Serial.println(verificationCode);

  if (Firebase.failed()) {
    Serial.print("Firebase failed:");
    Serial.print(Firebase.error());
    return;
  }

   delay(5000);
}

void setLed(char c) {
  switch (c) {
    case 'g':
      analogWrite(5, 0);
      analogWrite(4, 255);
      analogWrite(0, 0);
      break;
    case 'y':
      analogWrite(5, 127);
      analogWrite(4, 255);
      analogWrite(0, 0);
      break;
    case 'r':
      analogWrite(5, 255);
      analogWrite(4, 0);
      analogWrite(0, 0);
      break;
  }
}

