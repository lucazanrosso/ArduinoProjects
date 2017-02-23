//int val = 0;
//int LED = 13;
//
//void setup(){
//  Serial.begin(9600);  //Inizializziamo l’interfaccia seriale al baud rate dell’AT-mode
//  Serial1.begin(9600);  //Inizializziamo l’interfaccia del modulo bluetooth sempre al baud rate riferito alla modalità AT
//  pinMode(LED, OUTPUT);
//}
//
//void loop(){
//  if(Serial1.available()){  //Se il bluetooth riceve qualche dato
//    char c = Serial1.read();  //Il dato viene posto in una variabile di tipo char, così da essere adatta sia a lettere che a numeri
//    Serial.write(c);  //Si scrive sul monitor seriale i dati presi dalla variabile, così da poterli osservare
//    if (c == 'h')
//      val = 255;
//    if (c == 'l')
//      val = 0;
//      analogWrite(LED, val);  
//  }
//  if(Serial.available()){  //Se invece il serial monitor riceve un dato da inviare
//    char c = Serial.read();  //La variabile c viene memorizzata e letta dal monitor seriale
//    Serial1.write(c);  //Il dato viene inviato al bluetooth perchè sia elaborato e quindi trasmesso
////    Serial.println(c);
//    if (c == 'h')
//      val = 255;
//    if (c == 'l')
//      val = 0;
//      analogWrite(LED, val);  
//  }
//}

int val = 0;
int LED = 13;

void setup(){
  Serial.begin(9600);  //Inizializziamo l’interfaccia seriale al baud rate dell’AT-mode
  Serial1.begin(9600);  //Inizializziamo l’interfaccia del modulo bluetooth sempre al baud rate riferito alla modalità AT
  pinMode(LED, OUTPUT);
}

void loop(){
  if(Serial1.available()){  //Se il bluetooth riceve qualche dato
    char c = Serial1.read();  //Il dato viene posto in una variabile di tipo char, così da essere adatta sia a lettere che a numeri
    Serial.write(c);  //Si scrive sul monitor seriale i dati presi dalla variabile, così da poterli osservare
    if (c == '1')
      val = 255;
    if (c == '0')
      val = 0;
      analogWrite(LED, val);
//      Serial.println("LED " + val); 
  }
  if(Serial.available()){  //Se invece il serial monitor riceve un dato da inviare
    char c = Serial.read();  //La variabile c viene memorizzata e letta dal monitor seriale
    Serial1.write(c);  //Il dato viene inviato al bluetooth perchè sia elaborato e quindi trasmesso
//    Serial.println(c);
    if (c == '1')
      val = 255;
    if (c == '0')
      val = 0;
      analogWrite(LED, val);
//      Serial.println(val); 
  }
}

//char incomingByte;  // incoming data
//int  LED = 12;      // LED pin
// 
//void setup() {
//  Serial.begin(9600); // initialization
//  pinMode(LED, OUTPUT);
//  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
//}
// 
//void loop() {
//  if (Serial.available() > 0) {  // if the data came
//    incomingByte = Serial.read(); // read byte
//    if(incomingByte == '0') {
//       digitalWrite(LED, LOW);  // if 1, switch LED Off
//       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
//    }
//    if(incomingByte == '1') {
//       digitalWrite(LED, HIGH); // if 0, switch LED on
//       Serial.println("LED ON. Press 0 to LED OFF!");
//    }
//  }
//}
