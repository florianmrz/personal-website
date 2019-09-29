#include <RCSwitch.h>
#include <Ethernet.h>
#include <SPI.h>
#include <etherShield.h>
boolean reading = false;

  byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x43, 0xCC };
  byte ip[] = { 192, 168, 178, 60 };
  EthernetServer server = EthernetServer(80); //port 80
  
  RCSwitch mySwitch = RCSwitch();
//  EthernetClient client;

////////////////////////////////////////////////////////////////////////

void setup(){
  Serial.begin(9600);
  mySwitch.enableTransmit(9);
  Ethernet.begin(mac);

  server.begin();
  Serial.println(Ethernet.localIP());

}

void loop(){

  // listen for incoming clients, and process qequest.
  checkForClient();

}

void checkForClient(){

  EthernetClient client = server.available();

  if (client) {

    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    boolean sentHeader = false;

    while (client.connected()) {
      if (client.available()) {

        if(!sentHeader){
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          sentHeader = true;
        }

        char c = client.read();

        if(reading && c == ' ') reading = false;
        if(c == '?') reading = true; //found the ?, begin reading the info

        if(reading){
          Serial.print(c);

           switch (c) {
            case '0':
              //LED-Ausschaltbefehl ausführen
               client.print("Steckdose abschalten");
               client.print("<br>");

              //Steckdose ausschalten
              mySwitch.switchOff("11111", 4);
              delay(10);
              break;
            case '1':
              //LED-Anschaltbefehl ausführen
              client.print("Steckdose anschalten");
              client.print("<br>");

              //Steckdose anschalten
              mySwitch.switchOn("11111", 4);
              delay(10);
              break;
          }

        }

        if (c == '\n' && currentLineIsBlank)  break;

        if (c == '\n') {
          currentLineIsBlank = true;
        }else if (c != '\r') {
          currentLineIsBlank = false;
        }

      }
    }

    delay(10); // give the web browser time to receive the data
    client.stop();
//    client.stop(); // close the connection:

  } 

}
