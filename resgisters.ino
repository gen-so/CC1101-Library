
//this mode is for raw reading async serial data
//RadioStream
//works with printing rssi constantly
void setupRegisters_mode1()
{
	Serial.println("Setting up the PA_TABLE.");
	byte PA_TABLE[] = { 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 10dBm
	cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

	//
	// Rf settings for CC1101
	//

	Serial.println("Setting up config registers");
	//serial data output on pin GDO0
	cc1101.writeReg(CC1101_IOCFG0, 0x0D);  // GDO0 Output Pin Configuration
	cc1101.writeReg(CC1101_FIFOTHR, 0x47); // RX FIFO and TX FIFO Thresholds
	cc1101.writeReg(CC1101_PKTLEN, 0x0D);  // Packet Length
	//enable async mode
	cc1101.writeReg(CC1101_PKTCTRL0, 0x30); // Packet Automation Control
	cc1101.writeReg(CC1101_PKTCTRL1, 0x00); // Packet Automation Control
	cc1101.writeReg(CC1101_FSCTRL1, 0x06);  // Frequency Synthesizer Control
	cc1101.writeReg(CC1101_FREQ2, 0x10);    // Frequency Control Word, High Byte
	cc1101.writeReg(CC1101_FREQ1, 0xB0);    // Frequency Control Word, Middle Byte
	cc1101.writeReg(CC1101_FREQ0, 0xB3);    // Frequency Control Word, Low Byte
	cc1101.writeReg(CC1101_MDMCFG4, 0xF7);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG3, 0xB0);  // Modem Configuration
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

//Default mode
void setupRegisters_mode0()
{
	Serial.println("Setting up the PA_TABLE.");
	byte PA_TABLE[] = { 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 10dBm
	cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

	//
	// Rf settings for CC1101
	//

	//Enable Carier Sense relative 10dBm
	cc1101.writeReg(CC1101_AGCCTRL1, 0x70); // GDO0 Output Pin Configuration

	//Carrier sense. High if RSSI level is above threshold. Cleared when entering IDLE mode
	cc1101.writeReg(CC1101_IOCFG0, 0x14); // GDO0 Output Pin Configuration

	//FIFO threshold 64 BYTES
	cc1101.writeReg(CC1101_FIFOTHR, 0x4F); // RX FIFO and TX FIFO Thresholds

	cc1101.writeReg(CC1101_PKTLEN, 0x0D);  // Packet Length

	//Fixed packet length mode. Length configured in PKTLEN register
	cc1101.writeReg(CC1101_PKTCTRL0, 0x02); // Packet Automation Control

	//all disabled CRC AUTOFLUSH, APPEND_STATUS, ADR_CHK
	cc1101.writeReg(CC1101_PKTCTRL1, 0x00); // Packet Automation Control

	cc1101.writeReg(CC1101_FSCTRL1, 0x06);  // Frequency Synthesizer Control
	cc1101.writeReg(CC1101_FREQ2, 0x10);    // Frequency Control Word, High Byte
	cc1101.writeReg(CC1101_FREQ1, 0xB0);    // Frequency Control Word, Middle Byte
	cc1101.writeReg(CC1101_FREQ0, 0xB3);    // Frequency Control Word, Low Byte
	cc1101.writeReg(CC1101_MDMCFG4, 0xF7);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG3, 0xB0);  // Modem Configuration

	//Sync word detection, CS above threshold
	cc1101.writeReg(CC1101_MDMCFG2, 0x34); // Modem Configuration

	cc1101.writeReg(CC1101_MDMCFG1, 0x00); // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG0, 0x2E); // Modem Configuration
	cc1101.writeReg(CC1101_DEVIATN, 0x15); // Modem Deviation Setting
	cc1101.writeReg(CC1101_MCSM0, 0x14);   // Main Radio Control State Machine Configuration
	cc1101.writeReg(CC1101_FOCCFG, 0x16);  // Frequency Offset Compensation Configuration
	cc1101.writeReg(CC1101_WORCTRL, 0xFB); // Wake On Radio Control
	cc1101.writeReg(CC1101_FREND0, 0x11);  // Front End TX Configuration
	cc1101.writeReg(CC1101_FSCAL3, 0xE9);  // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL2, 0x2A);  // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL1, 0x00);  // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL0, 0x1F);  // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_TEST2, 0x81);   // Various Test Settings
	cc1101.writeReg(CC1101_TEST1, 0x35);   // Various Test Settings
	cc1101.writeReg(CC1101_TEST0, 0x09);   // Various Test Settings
}


//Send code mode async 
void setupRegisters_mode2()
{
	Serial.println("Setting up the PA_TABLE.");
	byte PA_TABLE[] = { 0x00,0x12,0x0e,0x34,0x60,0xc5,0xc1,0xc0 }; // 10dBm
	cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

	cc1101.writeReg(CC1101_IOCFG2, 0x0B);   // GDO2 Output Pin Configuration
	cc1101.writeReg(CC1101_IOCFG0, 0x0C);   // GDO0 Output Pin Configuration
	cc1101.writeReg(CC1101_FIFOTHR, 0x47);  // RX FIFO and TX FIFO Thresholds
	cc1101.writeReg(CC1101_PKTCTRL0, 0x32); // Packet Automation Control
	cc1101.writeReg(CC1101_FSCTRL1, 0x06);  // Frequency Synthesizer Control
	cc1101.writeReg(CC1101_FREQ2, 0x10);    // Frequency Control Word, High Byte
	cc1101.writeReg(CC1101_FREQ1, 0xB1);    // Frequency Control Word, Middle Byte
	cc1101.writeReg(CC1101_FREQ0, 0x3A);    // Frequency Control Word, Low Byte
	cc1101.writeReg(CC1101_MDMCFG4, 0xF6);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG3, 0xA2);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG2, 0x30);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG1, 0x00);  // Modem Configuration
	cc1101.writeReg(CC1101_DEVIATN, 0x15);  // Modem Deviation Setting
	cc1101.writeReg(CC1101_MCSM0, 0x18);    // Main Radio Control State Machine Configuration
	cc1101.writeReg(CC1101_FOCCFG, 0x14);   // Frequency Offset Compensation Configuration
	cc1101.writeReg(CC1101_AGCCTRL0, 0x92); // AGC Control
	cc1101.writeReg(CC1101_WORCTRL, 0xFB);  // Wake On Radio Control
	cc1101.writeReg(CC1101_FREND0, 0x17);   // Front End TX Configuration
	cc1101.writeReg(CC1101_FSCAL3, 0xE9);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL2, 0x2A);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL1, 0x00);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL0, 0x1F);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_TEST2, 0x81);    // Various Test Settings
	cc1101.writeReg(CC1101_TEST1, 0x35);    // Various Test Settings
	cc1101.writeReg(CC1101_TEST0, 0x09);    // Various Test Settings







}

//Send code mode async 2
void setupRegisters_mode3()
{
	Serial.println("Setting up the PA_TABLE.");
	byte PA_TABLE[] = { 0x00, 0x12, 0x0E, 0x34, 0x60, 0xC5, 0xC1, 0xC0 }; // 10dBm
	cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);


	// Rf settings for CC1101
	//
	cc1101.writeReg(CC1101_IOCFG0, 0x11);   // GDO0 Output Pin Configuration
	cc1101.writeReg(CC1101_FIFOTHR, 0x47);  // RX FIFO and TX FIFO Thresholds
	cc1101.writeReg(CC1101_PKTLEN, 0x02);   // Packet Length (12 BYTES)  OLD = 0D
	cc1101.writeReg(CC1101_PKTCTRL0, 0x30); // Packet Automation Control
	cc1101.writeReg(CC1101_FSCTRL1, 0x06);  // Frequency Synthesizer Control
	cc1101.writeReg(CC1101_FREQ2, 0x10);    // Frequency Control Word, High Byte
	cc1101.writeReg(CC1101_FREQ1, 0xB0);    // Frequency Control Word, Middle Byte
	cc1101.writeReg(CC1101_FREQ0, 0xB3);    // Frequency Control Word, Low Byte
	cc1101.writeReg(CC1101_MDMCFG4, 0xF0);  // Modem Configuration (2.59kB)  //OLD f7 //F6
	cc1101.writeReg(CC1101_MDMCFG3, 0x00);  // Modem Configuration (2.59kB) //OLD 0xB0 // A2
	cc1101.writeReg(CC1101_MDMCFG2, 0x30);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG1, 0x00);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG0, 0x2E);  // Modem Configuration
	cc1101.writeReg(CC1101_DEVIATN, 0x15);  // Modem Deviation Setting
	cc1101.writeReg(CC1101_MCSM0, 0x14);    // Main Radio Control State Machine Configuration
	cc1101.writeReg(CC1101_FOCCFG, 0x16);   // Frequency Offset Compensation Configuration
	cc1101.writeReg(CC1101_WORCTRL, 0xFB);  // Wake On Radio Control
	cc1101.writeReg(CC1101_FREND0, 0x13);   // Front End TX Configuration
	cc1101.writeReg(CC1101_FSCAL3, 0xE9);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL2, 0x2A);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL1, 0x00);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_FSCAL0, 0x1F);   // Frequency Synthesizer Calibration
	cc1101.writeReg(CC1101_TEST2, 0x81);    // Various Test Settings
	cc1101.writeReg(CC1101_TEST1, 0x35);    // Various Test Settings
	cc1101.writeReg(CC1101_TEST0, 0x09);    // Various Test Settings
}


//Send code mode CLONER ORI
void setupRegisters_mode4()
{
	Serial.println("Setting up the PA_TABLE.");
	byte PA_TABLE[] = { 0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00 }; // 10dBm
	cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);

	cc1101.writeReg(CC1101_IOCFG0, 0x06);   // GDO0 Output Pin Configuration
	cc1101.writeReg(CC1101_FIFOTHR, 0x47);  // RX FIFO and TX FIFO Thresholds
	cc1101.writeReg(CC1101_PKTLEN, 0x0D);   // Packet Length
	cc1101.writeReg(CC1101_PKTCTRL0, 0x00); // Packet Automation Control
	cc1101.writeReg(CC1101_FSCTRL1, 0x06);  // Frequency Synthesizer Control
	cc1101.writeReg(CC1101_FREQ2, 0x10);    // Frequency Control Word, High Byte
	cc1101.writeReg(CC1101_FREQ1, 0xB0);    // Frequency Control Word, Middle Byte
	cc1101.writeReg(CC1101_FREQ0, 0xB3);    // Frequency Control Word, Low Byte
	cc1101.writeReg(CC1101_MDMCFG4, 0xF7);  // Modem Configuration
	cc1101.writeReg(CC1101_MDMCFG3, 0xB0);  // Modem Configuration
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
