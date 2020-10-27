/*
 Arduino code for a remote control clone of an RC-switch using TI CC1101
 https://www.grspy.com/cloning-the-remote-control-of-an-rc-switch-using-ti-cc1101
 Distributed under GPL v3.0
 grspy, 2019
*/

#include "cc1101.h"

#define LEDOUTPUT LED_BUILTIN

CC1101 cc1101;

const int buttonPin1 = PD4;

int button1State = 0;

bool sending = false;

//code to open gate fully
byte openFull[15] = { 0x00, 0x08, 0xEE, 0xEE, 0xE8, 0xE8, 0x88, 0xE8, 0x88, 0x88, 0x8E, 0xE8, 0x88, 0x88, 0x00 };

void blinker() {
	digitalWrite(LEDOUTPUT, HIGH);
	delay(100);
	digitalWrite(LEDOUTPUT, LOW);
	delay(100);
}

void setup()
{
	Serial.begin(9600);

	pinMode(LEDOUTPUT, OUTPUT);
	digitalWrite(LEDOUTPUT, LOW);

	pinMode(PD4, INPUT_PULLUP);

	// blink once
	blinker();

	Serial.println("Initializing CC1101.");
	cc1101.init();

	Serial.println("Setting up the PA_TABLE.");
	byte PA_TABLE[] = { 0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00 }; // 10dBm
	cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

	Serial.println("Setting up the registers.");
	cc1101_SetupRegisters();

	delay(1000);
	Serial.println("CC1101 initialized.");
}

void sendOpenCode() {
	cc1101.sendData(openFull, 15);
}



void loop()
{
	//only when button 4 is pressed, open gate
	if (!digitalRead(PD4)) {
		//wait for radio to go to idle state (ready to receive new command)
		waitForIdleState(false);
		//send code to open gate
		sendOpenCode();
	}
}

void cc1101_SetupRegisters() {
	//
	// Rf settings for CC1101
	//
	cc1101.writeReg(CC1101_IOCFG0, 0x06);   // GDO0 Output Pin Configuration
	cc1101.writeReg(CC1101_FIFOTHR, 0x47);  // RX FIFO and TX FIFO Thresholds
	cc1101.writeReg(CC1101_PKTLEN, 0x0F);   // Packet Length
	cc1101.writeReg(CC1101_PKTCTRL0, 0x00); // Packet Automation Control
	cc1101.writeReg(CC1101_FSCTRL1, 0x06);  // Frequency Synthesizer Control
	cc1101.writeReg(CC1101_FREQ2, 0x10);    // Frequency Control Word, High Byte
	cc1101.writeReg(CC1101_FREQ1, 0xB0);    // Frequency Control Word, Middle Byte
	cc1101.writeReg(CC1101_FREQ0, 0xB3);    // Frequency Control Word, Low Byte
	cc1101.writeReg(CC1101_MDMCFG4, 0xF6);  // Modem Configuration (kB)
	cc1101.writeReg(CC1101_MDMCFG3, 0x9D);  // Modem Configuration (kB)
	cc1101.writeReg(CC1101_MDMCFG2, 0x30);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG1, 0x00);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG0, 0x2E);  // Modem Configuration
	cc1101.writeReg(CC1101_DEVIATN, 0x15);  // Modem Deviation Setting
	cc1101.writeReg(CC1101_MCSM0, 0x14);    // Main Radio Control State Machine Configuration
	cc1101.writeReg(CC1101_FOCCFG, 0x16);   // Frequency Offset Compensation Configuration
	cc1101.writeReg(CC1101_WORCTRL, 0xFB);  // Wake On Radio Control
	cc1101.writeReg(CC1101_FREND0, 0x11);   // Front End TX Configuration
	cc1101.writeReg(CC1101_FSCAL3, 0xE9);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL2, 0x2A);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL1, 0x00);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL0, 0x1F);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_TEST2, 0x81);    // Various Test Settings
	cc1101.writeReg(CC1101_TEST1, 0x35);    // Various Test Settings
	cc1101.writeReg(CC1101_TEST0, 0x09);    // Various Test Settings
}


//holds control until radio is in idle state
void waitForIdleState(bool verbose)
{
	//get current radio status
	byte radioStatus = getRadioState();

	//set what idle state looks like
	byte idleState = 0x01;

	//if not in idle state, wait here
	while (radioStatus != idleState)
	{
		//if in verbose mode, show message to user
		if (verbose) { Serial.println("Not in IDLE state"); }

		//wait 10 ms
		delayMicroseconds(10);

		//check again if radio is in idle
		radioStatus = getRadioState();
	}

	//if in verbose mode, show message to user
	if (verbose) { Serial.println("In IDLE state"); }

}

//gets radio state from registry
byte getRadioState()
{
	//get status full registery
	byte fullReg = cc1101.readStatusReg(CC1101_MARCSTATE);

	//extract only radio status
	byte radioStatus = getBitRange(fullReg, 0, 4);

	//return state to caller
	return radioStatus;
}

//gets a bits from a byte, and return a byte of the new bits
byte getBitRange(byte data, int start, int _end) {

	//shift binary to starting point of range
	byte shifted = (data >> start);

	//calculate range length (+1 for 0 index)
	int rangeLength = (_end - start) + 1;

	//get binary mask based on range length 
	byte maskBinary;

	switch (rangeLength) {
	case 1: maskBinary = 0b00000001; break;
	case 2: maskBinary = 0b00000011; break;
	case 3: maskBinary = 0b00000111; break;
	case 4: maskBinary = 0b00001111; break;
	case 5: maskBinary = 0b00011111; break;
	case 6: maskBinary = 0b00111111; break;
	case 7: maskBinary = 0b01111111; break;
	case 8: maskBinary = 0b11111111; break;
	default:
		// default statements
		Serial.println("Error: Range length too long!!");
	}

	//cancel out 
	byte finalByte = (shifted & maskBinary);

	return finalByte;
}