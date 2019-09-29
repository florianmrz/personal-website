#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x43, 0xCC};
byte ip[] = {192, 168, 178, 39};
byte gateway[] = {192, 168, 178, 1};
byte subnet[] = {255, 255, 0, 0};

EthernetServer server = EthernetServer(23);

void setup()
{
  Ethernet.begin(mac, ip, gateway, subnet);

  server.begin();
}

void loop()
{
  Serial.println(Ethernet.localIP());
}
