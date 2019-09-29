int rot = 0;
int gruen = 0;
int blau = 0;
int pin_rot = 3;
int pin_gruen = 5;
int pin_blau = 6;

void setup()
{
pinMode (pin_rot, OUTPUT);
pinMode (pin_gruen, OUTPUT);
pinMode (pin_blau, OUTPUT);
Serial.begin (96000);
}

void loop()
{
if (Serial.available() > 0)
  {
  //Serial.print("Rot?\t");
  int rot = Serial.parseInt();
  
  if(Serial.read() == '\n')
    {
     Serial.print("Rot: \t");
     Serial.println(rot, HEX);
    }

  }
}
