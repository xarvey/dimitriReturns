#include <SoftwareSerial.h>
#define RXPIN 3
#define TXPIN 2
SoftwareSerial cw(RXPIN, TXPIN);


byte cmd_scan[] = {0x10, 0x03, 0x00};//{ 0x43, 0x03, 0x01 };

unsigned char incomingByte;
void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
cw.begin(230400);

}

void loop() {

      cw.write(cmd_scan, sizeof(cmd_scan)); //read command

   while(cw.available())
  {
    incomingByte = cw.read();
    Serial.print(incomingByte,HEX);
    Serial.print(" ");
  // put your main code here, to run repeatedly:

  Serial.println();

}
}
