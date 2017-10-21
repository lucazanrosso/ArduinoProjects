#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

int i = 0;

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
  Firebase.set("data", i);
  i++;
  
  if (Firebase.failed()) {
    Serial.print("Firebase failed:");
    Serial.print(Firebase.error());
    return;
  }

   delay(5000);
}
