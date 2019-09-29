
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {  0x90, 0xA2, 0xDA, 0x0D, 0x43, 0xCC };
char server[] = "www.google.de";

EthernetClient client;

void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    for(;;)
      ;
  }
  delay(1000);
  Serial.println("connecting...");

  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println("GET /search?q=\"Fridericus Willem\" HTTP/1.0");
    client.println();
  } 
  else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    for(;;)
      ;
  }
}
