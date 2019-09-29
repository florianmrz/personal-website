#include <Ethernet.h>
#include <SPI.h>
boolean reading = false;

  byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x43, 0xCC };

  EthernetServer server = EthernetServer(80); //port 80
  
  //LED haengt an Pin 3
  int pin = 3;
  
////////////////////////////////////////////////////////////////////////

void setup(){
  Serial.begin(9600);

  pinMode(pin, OUTPUT);

  Ethernet.begin(mac);
  //Ethernet.begin(mac, ip, gateway, subnet); //for manual setup

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
              ausschalten(pin, client);
              break;
            case '1':
              //LED-Anschaltbefehl ausführen
              anschalten(pin, client);
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
    client.stop(); // close the connection:

  } 

}

void ausschalten(int pin, EthernetClient client){

  client.print("Turning off LED ");
  client.print("<br>");

  //LED ausschalten
  digitalWrite(pin, LOW);
  delay(10);
}
void anschalten(int pin, EthernetClient client){
  
  client.print("Turning on LED ");
  client.print("<br>");
  
  //LED anschalten
  digitalWrite(pin, HIGH);
  delay(10);
  
}
