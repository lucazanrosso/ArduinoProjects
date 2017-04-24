//definiamo i pin ai quali collegare i piedini del LED RGB    
const int ROSSO = 10;  
const int VERDE = 9;  
const int BLU = 8;
int color = 0;
int i = 0;
  
void setup() {
  //impostazione i pin a cui sono collegadi i piedini del led RGB come uscite 
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(ROSSO, OUTPUT); 
  pinMode(VERDE, OUTPUT); 
  pinMode(BLU, OUTPUT);

  analogWrite(VERDE, 255);
  analogWrite(BLU, 255);
  // inizializziamo a LOW i pin ROSSO, VERDE, BLU
  // inizialmente il led RGB sarà spento 
//  pulisci();
//  colora(127,255,255);
}  
  
void loop() {    
  
  if(Serial1.available()){
//      Serial.print("A");
      int c = Serial1.read();
//      Serial.write(c);
      color += c * pow(10,2 - i);
//      Serial.println(color);
      i += 1;
//      String s = Serial1.readString();
//      Serial.println(s);
//      int i = Serial1.parseInt();
//      Serial.println(i);  
  }  
  if (i == 3) {
    Serial.println(color  - 5441);
    analogWrite(ROSSO, color  - 5441);
    color = 0;
    i = 0;
  }
//
//  void colora(int R, int G, int B){
//    analogWrite(ROSSO, R);
//    analogWrite(VERDE, G);
//    analogWrite(BLU, B);
//  }
//
//  void pulisci(){
//    digitalWrite(ROSSO, LOW); 
//    digitalWrite(VERDE, LOW);  
//    digitalWrite(BLU, LOW); 
//  }

}
