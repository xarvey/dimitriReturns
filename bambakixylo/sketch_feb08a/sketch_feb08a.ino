#include <SoftwareSerial.h>
 
#define RXPIN 10 //TX on C/W connected to pin on arduino
#define TXPIN 9 //RX on C/W connected to pin on arduino
#define hash_num 12289
#define rock 575
#define scissors 456
#define paper 801

byte incomingByte;
byte cmd_scan[] = {0x43,0x03,0x01};
int last_tag_hash;
int total_lost=0;


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
int current_tag_hash=0;

while (myserial.available())
{
incomingByte = myserial.read();

if (counter>=10) //store only ID bytes returned form scan command
{
  //Serial.print(incomingByte,HEX);
  res[counter-10]=incomingByte;
  current_tag_hash+=incomingByte;
  current_tag_hash=current_tag_hash % hash_num;
}
counter++;
}

//Serial.print("\ndebug: ");
//Serial.print(current_tag_hash);

if (current_tag_hash!=last_tag_hash)
{
  Serial.println("----------------------");
if (current_tag_hash==rock)
  {
    Serial.println("You played Rock");
    delay(500);
    Serial.println("CPU played Paper");
    total_lost++;
    Serial.print("Score: Computer " );
    Serial.print(total_lost);
    Serial.print("- 0 Player" ); 
  }
  else if (current_tag_hash==scissors)
  {
    Serial.println("You played Scissors");
    delay(500);
    Serial.println("CPU played Rock");
    total_lost++;
    Serial.print("Score: Computer " );
    Serial.print(total_lost);
    Serial.println("- 0 Player" ); 
  }
  else
  {
    Serial.println("You played Paper");
    delay(500);
    Serial.println("CPU played Scissors");  
    total_lost++;
    Serial.print("Score: Computer " );
    Serial.print(total_lost);
    Serial.println("- 0 Player" ); 
  }
    last_tag_hash=current_tag_hash;
}
}

