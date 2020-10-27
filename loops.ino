//
////TESTING RECEIVING CODE
//void loop0()
//{
//
//	if (!sending) {
//		//if button pressed blink led & send code
//		if (!digitalRead(PD4))
//		{
//			cc1101.setTxState();
//			while (((cc1101.readStatusReg(CC1101_MARCSTATE)) & 0x1F) != 0x13) {}
//			Serial.println("Sending!");
//			sendoncode();
//
//		}
//	}
//}
//
////Loop to send cloning code
//void loop2()
//{
//	if (!sending) {
//		//if button pressed blink led & send code
//		if (!digitalRead(PD4))
//		{
//			Serial.println("Sending!");
//			//blinkLed(1);
//			sendCode();
//
//		}
//	}
//}
//
//void loop4()
//{
//	if (!digitalRead(PD4))
//	{
//		Serial.println("Sending!");
//		cc1101.setTxState();
//		while (((cc1101.readStatusReg(CC1101_MARCSTATE)) & 0x1F) != 0x13) {}
//		//blinkLed(1);
//		sendCode2();
//
//	}
//}
//
//
////led light at button press
//void loop3()
//{
//	//if button pressed blink led
//	if (!digitalRead(PD4))
//	{
//		blinkLed(1);
//
//	}
//}
