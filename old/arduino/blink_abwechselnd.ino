// Pin 12 -> LED auf Steckboard
// Pin 13 -> LED auf Arduino
int led_ofb = 12;
int led_onb = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // PIN definieren.
  pinMode(led_onb, OUTPUT);
  pinMode(led_ofb, OUTPUT);
}

// Schleife wiederholt sich unenedlich oft:
void loop() {
  digitalWrite(led_ofb, HIGH);  // LED offboard wird angeschaltet
  digitalWrite(led_onb, LOW);   // LED onboard wird ausgeschaltet
  delay(1000);                  // Eine Sekunde warten
  digitalWrite(led_ofb, LOW);   // LED offboard wird ausgeschaltet
  digitalWrite(led_onb, HIGH);  // LED onboard wird angeschaltet
  delay(1000);                  // Eine Sekunde warten 
}
