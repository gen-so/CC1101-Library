//void printRadioStream()
//{
//	int incomingByte = 0; // for incoming serial data
//						  // read the incoming byte:
//	incomingByte = digitalRead(2);
//
//	// say what you got:
//	Serial.print(incomingByte);
//}
//
//void printRSSI()
//{
//	//read raw rssi
//	char rssiRaw = cc1101.readStatusReg(CC1101_RSSI);
//	Serial.print(F("rssi: "));
//	Serial.print(calculateRssi(rssiRaw));
//	Serial.println(F("dBm"));
//}
//
//void printStatus()
//{
//	Serial.print(F("CC1101_PARTNUM "));
//	Serial.println(cc1101.readReg(CC1101_PARTNUM, CC1101_STATUS_REGISTER));
//	Serial.print(F("CC1101_VERSION "));
//	Serial.println(cc1101.readReg(CC1101_VERSION, CC1101_STATUS_REGISTER));
//	Serial.print(F("Frequency Offset Estimate from Demodulator "));
//	Serial.println(cc1101.readReg(CC1101_FREQEST, CC1101_STATUS_REGISTER));
//	Serial.print(F("Demodulator Estimate for Link Quality "));
//	Serial.println(cc1101.readReg(CC1101_LQI, CC1101_STATUS_REGISTER));
//	Serial.print(F("Received Signal Strength Indication "));
//	Serial.println(cc1101.readReg(CC1101_RSSI, CC1101_STATUS_REGISTER));
//	Serial.print(F("Main Radio Control State Machine State "));
//	Serial.println(cc1101.readReg(CC1101_MARCSTATE, CC1101_STATUS_REGISTER));
//	Serial.print(F("High Byte of WOR Time "));
//	Serial.println(cc1101.readReg(CC1101_WORTIME1, CC1101_STATUS_REGISTER));
//	Serial.print(F("Low Byte of WOR Time "));
//	Serial.println(cc1101.readReg(CC1101_WORTIME0, CC1101_STATUS_REGISTER));
//	Serial.print(F("Current GDOx Status and Packet Status "));
//	Serial.println(cc1101.readReg(CC1101_PKTSTATUS, CC1101_STATUS_REGISTER));
//	Serial.print(F("Current Setting from PLL Calibration Module "));
//	Serial.println(cc1101.readReg(CC1101_VCO_VC_DAC, CC1101_STATUS_REGISTER));
//	Serial.print(F("Underflow and Number of Bytes "));
//	Serial.println(cc1101.readReg(CC1101_TXBYTES, CC1101_STATUS_REGISTER));
//	Serial.print(F("Overflow and Number of Bytes "));
//	Serial.println(cc1101.readReg(CC1101_RXBYTES, CC1101_STATUS_REGISTER));
//	Serial.print(F("Last RC Oscillator Calibration Result "));
//	Serial.println(cc1101.readReg(CC1101_RCCTRL1_STATUS, CC1101_STATUS_REGISTER));
//	Serial.print(F("Last RC Oscillator Calibration Result "));
//	Serial.println(cc1101.readReg(CC1101_RCCTRL0_STATUS, CC1101_STATUS_REGISTER));
//}
//
////EXP
////byte offdata[13] = { 0x88, 0x88, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x88, 0xEE, 0x88, 0xEE, 0x80 };
////printArray(offdata, sizeof(offdata));
//void printByteArray(byte* arr, int size)
//{
//	Serial.println();
//
//	for (int i = 0; i < size; i++)
//	{
//		Serial.print(F(":"));
//		Serial.print(arr[i], HEX);
//	}
//
//	Serial.println();
//}
//
//void printRxFifoStatus()
//{
//	//get rx bytes status
//	byte rxBytes = cc1101.readStatusReg(CC1101_RXBYTES);
//
//	Serial.print("INFO:RX FIFO STATUS = ");
//	Serial.println(rxBytes);
//
//	//Any byte waiting to be read and no overflow?
//	if (rxBytes & 0x7F && !(rxBytes & 0x80))
//	{
//		//print message
//		Serial.println("INFO:RX Byte available, and no overflow.");
//	}
//}
//
////OLD METHOD
//void printFifo()
//{
//	Serial.print(F("TX : Underflow & Number of Bytes "));
//	Serial.println(cc1101.readReg(CC1101_TXBYTES, CC1101_STATUS_REGISTER));
//	Serial.print(F("RX : Overflow & Number of Bytes "));
//	Serial.println(cc1101.readReg(CC1101_RXBYTES, CC1101_STATUS_REGISTER));
//}
//
//void printRxFifoData() {
//	const int pktLength = 64; //max bytes in RX FIFO is 64 bytes
//	byte dataPacket[pktLength]; //place to store data
//
//	 // Read data packet
//	cc1101.readBurstReg(dataPacket, CC1101_RXFIFO, pktLength);
//
//	//print data
//	//Serial.print(F("RX FIFO Data: "));
//	printByteArray(dataPacket, pktLength);
//}
//
////prints size of data in RX fifo (bytes)
//void printRxFifoSize() {
//
//	//get rx fifo size full register with overflow
//	byte fullRegister = cc1101.readReg(CC1101_RXBYTES, CC1101_STATUS_REGISTER);
//
//	//print only the size part
//	Serial.print(F("RX FIFO Size: "));
//	printBitRange(fullRegister, 0, 6);
//	Serial.println(F(" bytes"));
//}
//
//void printCarierSenseStatus() {
//
//	//get pkt status full register
//	byte pktStatus = cc1101.readReg(CC1101_PKTSTATUS, CC1101_STATUS_REGISTER);
//
//	//print carier sense bit
//	Serial.print(F("CS Status: "));
//	printBit(pktStatus, 6);
//
//}
//
//
////
////GENERAL PRINTERS
////
//
////prints 8 bit of a byte
//void printByte(byte data) {
//
//	Serial.print(getBit(data, 7));
//	Serial.print(getBit(data, 6));
//	Serial.print(getBit(data, 5));
//	Serial.print(getBit(data, 4));
//	Serial.print(getBit(data, 3));
//	Serial.print(getBit(data, 2));
//	Serial.print(getBit(data, 1));
//	Serial.println(getBit(data, 0));
//
//}
//
////prints value of specif bit in input byte
//void printBit(byte data, int location) {
//	Serial.println(getBit(data, location));
//}
//
////prints value of range of bits in the inputed byte in DECIMAL
//void printBitRange(byte data, int start, int _end) {
//
//	Serial.print(getBitRange(data, start, _end), DEC);
//}
//
//
//
//
//
//
