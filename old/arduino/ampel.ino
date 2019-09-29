int led_gelb = 13;
int led_rot = 12;
int led_gruen = 11;
int led_rgb1 = 10;

void setup()
{
  pinMode(led_rot, OUTPUT);
  pinMode(led_gelb, OUTPUT);
  pinMode(led_gruen, OUTPUT);
  pinMode(led_rgb1, OUTPUT);
}

void loop()
{
  digitalWrite(led_rot, HIGH);   // Rot   -> an
  digitalWrite(led_gelb, LOW);   // Gelb  -> aus
  digitalWrite(led_gruen, LOW);  // Gruen -> aus
  digitalWrite(led_rgb1, HIGH); 
  delay(500);
  
  digitalWrite(led_rot, LOW);    // Rot   -> aus
  digitalWrite(led_gelb, HIGH);  // Gelb  -> an
  digitalWrite(led_gruen, LOW);  // Gruen -> aus
  delay(500);
  
  digitalWrite(led_rot, LOW);    // Rot   -> aus
  digitalWrite(led_gelb, LOW);   // Gelb  -> aus
  digitalWrite(led_gruen, HIGH); // Gruen -> an
  delay(500); 
}
