int input = 11;


void setup()
 {
  Serial.begin(9600);
  pinMode(input, INPUT);
 }
 
void loop()
 {
  int PulsAuslesen=pulseIn(input, LOW);
  Serial.println(PulsAuslesen);
 }
