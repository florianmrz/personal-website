int led = 12;
int input = 11;
int taster_status = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(input, INPUT);
  Serial.begin(9600);
}

void loop()
{
  taster_status = digitalRead(input);
  if (taster_status == HIGH)
  {
    digitalWrite(led, HIGH);
    Serial.println("LED an");
    delay(50);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("LED aus");
    delay(50);
  }
}
