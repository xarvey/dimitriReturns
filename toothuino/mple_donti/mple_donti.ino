#include <SoftwareSerial.h> 

int bluetoothTx = 6;  // TX pin of bluetooth mate (RX of arduino)
int bluetoothRx = 7;  // RX pin of bluetooth mate (TX of arduino)
 
/*

NOTES
D0 pin really shouldn't be used because the arduino programming will fail. 
Passcode on the RN42 is 1234 by default.

*/
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


/*----------------------SETUP----------------------------*/
void setup() { 
  Serial.begin(115200); //same baud rate as 
  bluetooth.begin(115200);
  bluetooth.println("\n====================");
  bluetooth.println("Now, /that's/ SALTy"); //Will print bt name in console
  bluetooth.println("====================");

  
}

  unsigned i = 0;

/*----------------------LOOP----------------------------*/
void loop() { 
  bluetooth.print(i);
  delay(50);
  if (i==9)
  {
    i=0;
    Serial.print("\n");
  }
  else
      i=i+1;
  /*if (bluetooth.available())
  {
   Serial.print((char)bluetooth.read());
  }
  
  if (Serial.available())
  {
   bluetooth.print((char)Serial.read()); 
  }
  
   bluetooth.print(t); 
  if (t=="SALT")
    bluetooth.print("Smart Aging and Living Technologies\n");
  if (t=="cmdmode")
  {
    bluetooth.print("$");
    bluetooth.print("$");
    bluetooth.print("$");
  }  
  /*
  if(Serial.available())
  {
    bluetooth.print((char)Serial.read());  
  }
  */
  
 }
