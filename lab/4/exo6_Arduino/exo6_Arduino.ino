const int OUTPUTPIN = 13;
int value;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  value = analogRead(A0);
  pinMode(OUTPUTPIN, OUTPUT);
  Serial.begin(115200);  
}
 
// the loop routine runs over and over again forever:
void loop() {
  value = analogRead(A0);
  digitalWrite(OUTPUTPIN, value);
  Serial.println(value);
}
