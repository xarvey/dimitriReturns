#include <SoftwareSerial.h>

#define RXPIN 10 //TX on C/W connected to pin on arduino
#define TXPIN 9 //RX on C/W connected to pin on arduino
#define hash_num 12289
#define rock 575
#define scissors 456
#define paper 801

byte incomingByte;
byte cmd_scan[] = { 0x43, 0x03, 0x01 };
int last_tag_hash;
int player_score = 0;
int cpu_score = 0;
int flag=0;
char* element[] = { "Rock", "Scissors", "Paper" };

int player_played; //0 ROCK 1 scissors 2 paper
int cpu_played; //0 ROCK 1 scissors 2 paper

SoftwareSerial myserial(RXPIN, TXPIN);

void setup()
{
    Serial.begin(9600); //arduino
    myserial.begin(9600); //cotton wud
    randomSeed(analogRead(0));
}

void loop()
{

    myserial.write(cmd_scan, sizeof(cmd_scan)); //read command

    delay(1000); //Wait 1 Sec so it doesn't go H.A.M.

    int counter = 0;
    int res[30] = { 0 };
    int current_tag_hash = 0;

    while (myserial.available()) {
        incomingByte = myserial.read();

        if (counter >= 10) //store only ID bytes returned form scan command
        {
            //Serial.print(incomingByte,HEX);
            res[counter - 10] = incomingByte;
            current_tag_hash += incomingByte;
            current_tag_hash = current_tag_hash % hash_num;
        }
        counter++;
    }

    //Serial.print("\ndebug: ");
    //Serial.print(current_tag_hash);
    flag=0;
    if (current_tag_hash != last_tag_hash) {
        last_tag_hash = current_tag_hash;

        int stat; //0 tie , 1 player won, -1, cpu won
        if (current_tag_hash == rock) {
            Serial.println("----------------------");
            Serial.println("You played Rock");
            player_played = 0;
            flag=1;
            delay(500);
        }
        else if (current_tag_hash == scissors) {
            Serial.println("----------------------");
            Serial.println("You played Scissors");
            player_played = 1;
            flag=1;
            delay(500);
        }
        else if (current_tag_hash == paper) {
            Serial.println("----------------------");
            Serial.println("You played Paper");
            player_played = 2;
            flag=1;
            delay(500);
        }
        if (flag==1)
        { 
        cpu_played = random(3);

        if (cpu_played == player_played) {
            stat = 0;
            Serial.print("CPU played ");
            Serial.print(element[player_played]);
        }
        else if (cpu_played == 1) {
            if (player_played == 2) {
                cpu_score++;
            }
            else {
                player_score++;
            }
            Serial.print("CPU played ");
            Serial.print(element[cpu_played]);
        }
        else if (cpu_played == 2) {
            if (player_played == 0) {
                cpu_score++;
            }
            else {
                player_score++;
            }
            Serial.print("CPU played ");
            Serial.print(element[cpu_played]);
        }
        else if (cpu_played == 0) {
            if (player_played == 1) {
                cpu_score++;
            }
            else {
                player_score++;
            }
            Serial.print("CPU played ");
            Serial.print(element[cpu_played]);
        }

        Serial.print("\nScore: Computer ");
        Serial.print(cpu_score);
        Serial.print("- ");
        Serial.print(player_score);
        Serial.println(" Player");
    }
    }
    
}


