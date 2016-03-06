#include <SoftwareSerial.h>
#define RXPIN 10
#define TXPIN 9
SoftwareSerial cw(RXPIN, TXPIN);


byte cmd_scan[] = {0x43, 0x03, 0x01};//{ 0x43, 0x03, 0x01 };

unsigned char incomingByte;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
cw.begin(9600);

}

void loop() {

      cw.write(cmd_scan, sizeof(cmd_scan)); //read command
delay(1000);
   while(cw.available())
  {
    incomingByte = cw.read();
    Serial.print(incomingByte,HEX);
    Serial.print(" ");
  // put your main code here, to run repeatedly:

  Serial.println();

}
}
