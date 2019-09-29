int dimmer = 0;
int led = 12;

void setup()
{
pinMode (A0, INPUT);  
pinMode (led, OUTPUT);
Serial.begin (9600);
}

void loop()
{
dimmer = analogRead (A0);
digitalWrite (led, HIGH);
delay (dimmer/100);
digitalWrite (led, LOW);
Serial.print("Dimmer: ");
Serial.println(dimmer/100);
}
