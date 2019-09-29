#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {  
  0x90, 0xA2, 0xDA, 0x0D, 0x43, 0xCC };

EthernetClient client;

void setup() {
  Serial.begin(9600);

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;)
      ;
  }
  // print your local IP address:
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
}

void loop() {

}


