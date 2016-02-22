#include <SoftwareSerial.h>
 
#define RXPIN 10 //TX on C/W connected to pin on arduino
#define TXPIN 9 //RX on C/W connected to pin on arduino
 

byte incomingByte;
byte cmd_scan[] = {0x43,0x03,0x01};

SoftwareSerial myserial(RXPIN,TXPIN);


void setup()
{
Serial.begin(9600); //arduino
myserial.begin(9600); //cotton wud

}

void loop()
{

  
myserial.write(cmd_scan, sizeof(cmd_scan)); //read command

delay(1000); //Wait 1 Sec so it doesn't go H.A.M.

int counter=0;
int res[30]={0};
while (myserial.available())
{
incomingByte = myserial.read();

if (counter>=10) //store only ID bytes returned form scan command
  res[counter-10]=incomingByte;
counter++;
}

for (int i=0; i<12; i++)
  Serial.print(res[i],HEX); //

Serial.println("");
}

