int led_gruen = 11;
int led_gelb = 12;
int led_rot = 13;

void setup()
{
  pinMode(led_gruen, OUTPUT);
  pinMode(led_gelb, OUTPUT);
  pinMode(led_rot, OUTPUT);
}

void loop()
{
  for(int led_pin = 13; led_pin>=11; led_pin--)
  {
    digitalWrite(led_pin, HIGH); //LED -> an
    delay(500);
    digitalWrite(led_pin, LOW);  //LED -> aus
  }
}
