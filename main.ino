//
//#include "cc1101.h"
//
//#define LEDOUTPUT LED_BUILTIN
//
//CC1101 cc1101;
//
//bool sending = false;
//
//void setup()
//{
//	//Init MCU
//	setupMCU2();
//
//	//Configure Radio
//	setupCC1101_2();
//
//	//Enter RX state by issuing an SRX strobe command
//	//cc1101.setRxState();
//
//	//Wait for radio to enter RX state
//	//waitForRadio(true);
//
//	//setup interupts
//	//attachInterrupt(INT0, messageReceived, FALLING);
//	//cc1101.setTxState();
//}
//
//void loop()
//{
//	//only if not sending continue
//	loop0();
//
//}
//
////---------------------------------------------------------------
//// CUSTOM FUNCTIONS
////---------------------------------------------------------------
//
//void messageReceived()
//{
//	//pause interupts
//	detachInterrupt(INT0);
//	//print message
//	Serial.println("INTERUPT!!!!!");
//	printRxFifoData();
//	delay(2000);
//	//attach interupt back again
//
//}
//
//void temp() {
//	byte data = 0xAE;
//	//byte ondata[13] = {0xAA, 0x05, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88};
//
//	//printBitRange(data,0,3);
//	//printByte(data);
//
//
//	Serial.println(getBitRange(data, 0, 3), DEC);
//
//}
//
//
