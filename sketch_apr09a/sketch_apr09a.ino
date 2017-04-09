//definiamo i pin ai quali collegare i piedini del LED RGB    
const int ROSSO = 10;  
const int VERDE = 9;  
const int BLU = 8;
  
// tempo di attesa tra i colori in millisecondi
const int delayTime = 1000;  
  
void setup() {
  //impostazione i pin a cui sono collegadi i piedini del led RGB come uscite 
  pinMode(ROSSO, OUTPUT); 
  pinMode(VERDE, OUTPUT); 
  pinMode(BLU, OUTPUT);
  
  // inizializziamo a LOW i pin ROSSO, VERDE, BLU
  // inizialmente il led RGB sarà spento 
  pulisci();
  colora(127,255,255);
}  
  
void loop() {    

}  

void colora(int R, int G, int B){
  analogWrite(ROSSO, R);
  analogWrite(VERDE, G);
  analogWrite(BLU, B);
}

void pulisci(){
  digitalWrite(ROSSO, LOW); 
  digitalWrite(VERDE, LOW);  
  digitalWrite(BLU, LOW); 
}
