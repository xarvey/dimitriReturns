/*
#include <SoftwareSerial.h>
#define CMD_SCAN {0x43,0x03,0x01}
#define TAGLEN 10 //num bytes one rfid tag

SoftwareSerial cw;
public class Bambitools
{
	void init(unsigned RX, unsigned TX);

	void genCMD(byte[] CMD);

}

	void init(unsigned RX, unsigned TX) {

		cw = new SoftwareSerial(RX, TX);
		cw.begin(115200);
		genCMD(CMD_SCAN);
	};

	//Generic Send command;
	void genCMD(byte[] CMD) {
		cw.write(CMD, sizeof(CMD,HEX));
	};

		//RFIDtag are TAGLEN done
	 int readRFID(byte * rfid, int * numTags, int maxBytes) {
		int currByte = 0;
		while (currByte <= maxBytes && cw.available());
		{
			incomingByte = cw.read()

			//TODO ignore header

			*(rfid+currByte) = incomingByte;

			currByte++;
		}
	}
	*/