/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using a WiFi shield.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe
 */


#include <SPI.h>
#include <WiFi101.h>
#include <SoftwareSerial.h>

#define CWRX 10
#define CWTX 9
char ssid[] = "Dingding de xiaowu"; //our network SSID (name)
char pass[] = "5gerendejia";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

SoftwareSerial cw(CWRX, CWTX);


int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "epics.ecn.purdue.edu";    // name address for Google (using DNS)

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;
byte cmdscan[] = {0x43, 0x03, 0x01};

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  cw.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  randomSeed(analogRead(0));


  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWifiStatus();
  
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  char outBuf[128];
  byte incomingByte;
  memset(outBuf,sizeof(outBuf),0);
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    
    int counter = 0;
    int res[30] = { 0 };
    int current_tag_hash = 0;
         cw.write((byte *) cmdscan, sizeof(cmdscan));

       while (cw.available()) {
        incomingByte = cw.read();

        if (counter >= 10) //store only ID bytes returned form scan command
        {
            res[counter - 10] = incomingByte;
        }
        counter++;
    }

    
    sprintf(outBuf,"GET /uprc/secret/firebaseTest.php?arduino_data=%s HTTP/1.1", res);
    client.println(outBuf);
    memset(outBuf,sizeof(outBuf),0);
    sprintf(outBuf,"Host: %s", server);
    client.println(outBuf);
    client.println("Connection: close");
    client.println();
  }
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();
    }

  delay(1000);
  
  // if the server's disconnected, stop the client:
 
   client.stop();

    // do nothing forevermore:
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}





