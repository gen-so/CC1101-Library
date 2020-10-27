//
////blink led the the number of time specified
//void blinkLed(int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		digitalWrite(LED_BUILTIN, HIGH);
//		delay(500);
//		digitalWrite(LED_BUILTIN, LOW);
//		delay(500);
//	}
//}
//
////Waits for radio to be ready
//void waitForRadio(bool _verbose)
//{
//
//	while (((cc1101.readStatusReg(CC1101_MARCSTATE)) & 0x1F) != 0x0D)
//	{
//		//let user know radio not ready (only in verbose mode)
//		if (_verbose) { Serial.println("RX State NOT ready"); }
//
//		//wait for a while before checking again
//		//delay(10);
//	}
//
//	//let user know radio is ready (only in verbose mode)
//	if (_verbose) { Serial.println("RX State Ready!"); }
//}
//
////hold control untill radio is in idle state
//void waitForIdleState()
//{
//	//get current radio status
//	byte radioStatus = getRadioState();
//
//	//set what idle state looks like
//	byte idleState = 0x01;
//
//	//if not in idle state, wait here
//	while (radioStatus != idleState)
//	{
//		Serial.println("Not in IDLE state");
//		delayMicroseconds(10);
//		//check again if radio is idle
//		radioStatus = getRadioState();
//	}
//}
//
////gets radio state from registry
//byte getRadioState()
//{
//	//get status full registery
//	byte fullReg = cc1101.readStatusReg(CC1101_MARCSTATE);
//
//	//extract only radio status
//	byte radioStatus = getBitRange(fullReg, 0, 4);
//
//	//return state to caller
//	return radioStatus;
//}
//
//void sendCode1()
//{
//
//	digitalWrite(PD2, 0);
//	delay(1000);
//
//	int data[127] = { 0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,0 };
//
//	for (int i = 0; i < 127; i++)
//	{
//		digitalWrite(PD2, data[i]);
//		delayMicroseconds(385);
//	}
//
//	digitalWrite(PD2, 0);
//}
//
//void sendCode2()
//{
//
//	digitalWrite(PD2, LOW);
//	delay(500);
//
//	byte data[10] = { HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW };
//
//	for (int i = 0; i < 10; i++)
//	{
//		digitalWrite(PD2, data[i]);
//		//delayMicroseconds(10);
//		delay(1);
//	}
//
//	digitalWrite(PD2, LOW);
//}
//
//void sendCode()
//{
//	////TOP BIT:   E8	   88    88    E8    EE    E8    EE    EE   EE    88    EE    EE
//	//byte ondata[12] = { 0xE8, 0x88, 0x88, 0xE8, 0xEE, 0xE8, 0xEE, 0xEE, 0xEE, 0x88, 0xEE, 0xEE };
//	//sending = true;
//	//cc1101.sendData(ondata, 12);
//	//sending = false;
//
//	//TOP BIT:    71   11    11    71    77    71    77    77    77    11    77    77
//	byte ondata2[12] = { 0x71, 0x11, 0x11, 0x71, 0x77, 0x71, 0x77, 0x77, 0x77, 0x11, 0x77, 0x77 };
//	sending = true;
//	cc1101.sendData(ondata2, 12);
//	sending = false;
//
//	////BOT BIT: 8E    EE    EE    8E    88    8E    88    88    88    EE    88    88
//	//byte ondata3[12] = { 0x8E, 0xEE, 0xEE, 0x8E, 0x88, 0x8E, 0x88, 0x88, 0x88, 0xEE, 0x88, 0x88 };
//	//sending = true;
//	//cc1101.sendData(ondata3, 12);
//	//sending = false;
//
//	////BOT BIT:             17    77    77   17    11    17    11    11    11    77   11     11
//	//byte ondata4[12] = { 0x17, 0x77, 0x77, 0x17, 0x11, 0x17, 0x11, 0x11, 0x11, 0x77, 0x11, 0x11 };
//	//sending = true;
//	//cc1101.sendData(ondata4, 12);
//	//sending = false;
//}
//
//void sendoncode() {
//	byte ondata[13] = { 0x88, 0x88, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x88, 0xEE, 0x88, 0xEE, 0x80 };
//	sending = true;
//	cc1101.sendData(ondata, 13);
//	sending = false;
//}
//
//void receiveCode()
//{
//	byte offdata[13];
//	//sending = true;
//	printFifo();
//	int len = cc1101.receiveData(offdata, 13);
//	delay(2000);
//	Serial.println(len);
//	printByteArray(offdata, sizeof(offdata));
//	//sending = false;
//}