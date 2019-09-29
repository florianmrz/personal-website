int dimmer = 0;
int led = 9;

void setup()
{
pinMode (A0, INPUT);  
pinMode (led, OUTPUT);
Serial.begin (9600);
}

void loop()
{
dimmer = analogRead (A0)/4;
analogWrite (led, dimmer);
Serial.print("Dimmer: ");
Serial.println(dimmer);
}
