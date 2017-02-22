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
    if (c == 'h')
      val = 255;
    if (c == 'l')
      val = 0;
      analogWrite(LED, val);  
  }
  if(Serial.available()){  //Se invece il serial monitor riceve un dato da inviare
    char c = Serial.read();  //La variabile c viene memorizzata e letta dal monitor seriale
    Serial1.write(c);  //Il dato viene inviato al bluetooth perchè sia elaborato e quindi trasmesso
    Serial.println(c);
    if (c == 'h')
      val = 255;
    if (c == 'l')
      val = 0;
      analogWrite(LED, val);  
  }
}
