#include <SoftwareSerial.h>
 
#define RXPIN 11
#define TXPIN 10
 
char command_scantag[]={0x18,0x03,0xFF};//const
int incomingByte;
SoftwareSerial myserial(RXPIN,TXPIN) ;
 
void setup()
{
Serial.begin(9600);
myserial.begin(9600);
Serial.println("YOLO");
}
void loop()
{
  
  
/* 
myserial.write(0x33);
myserial.write(0x0F);
myserial.write(0x0C);
myserial.write(0x01);
myserial.write(0x02);
myserial.write(0x03);
myserial.write(0x04);
myserial.write(0x05);
myserial.write(0x06);
myserial.write(0x07);
myserial.write(0x07);
myserial.write(0x07);
myserial.write(0x07);
myserial.write(0x08);
myserial.write(0x09);
myserial.write(0x10);
myserial.write(0x6A);
myserial.write(0x0F);
*/
  
Serial.println("\n\n===============\n");
//turn on antenna
while(Serial.available())
{
incomingByte = Serial.read();
if(incomingByte='r')
{
  
/*
myserial.print(0x33);
myserial.print(0x0F);
myserial.print(0x0C);
myserial.print(0x01);
myserial.print(0x02);
myserial.print(0x03);
myserial.print(0x04);
myserial.print(0x05);
myserial.print(0x06);
myserial.print(0x07);
myserial.print(0x07);
myserial.print(0x07);
myserial.print(0x07);
myserial.print(0x08);
myserial.print(0x09);
myserial.print(0x10);
myserial.print(0x6A);
myserial.print(0x0F);
*/
}
 
 
myserial.write(0x37);
myserial.write(0x05);
myserial.write(0x01);
myserial.write(0x02);
myserial.write(0x06);  

myserial.print(0x37);
myserial.print(0x05);
myserial.print(0x01);
myserial.print(0x02);
myserial.print(0x06);  
}
delay (1000);
while (myserial.available())
{
incomingByte = myserial.read();
Serial.println(incomingByte,HEX);
}
}
 

