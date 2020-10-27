void setupLed()
{
	Serial.println("Setting up LED");
	//making LED availble to turn on
	pinMode(LEDOUTPUT, OUTPUT);
	digitalWrite(LEDOUTPUT, LOW);
}

void setupCC1101()
{
	cc1101.init();
	Serial.println("CC1101 initialized.");

	//setupRegisters_mode1();
	setupRegisters_mode0();
	Serial.println("Setup CC1101 completed");

	delay(1000);
}

//For sending code
void setupCC1101_2()
{
	cc1101.init();
	Serial.println("CC1101 initialized.");

	setupRegisters_mode4();
	Serial.println("Setup CC1101 completed");

	delay(1000);
}


void setupMCU0()
{
	//start serial
	Serial.begin(9600);
	Serial.println("Serial 9600 started");

	setupLed();

	//pin for async stream input
	//pinMode(2, INPUT);
}

//MCU setup for button press light turn on
void setupMCU1()
{
	//start serial
	Serial.begin(9600);
	Serial.println("Serial 9600 started");

	//making LED available to turn on
	pinMode(LED_BUILTIN, OUTPUT);

	//set for button press on A1
	pinMode(PD4, INPUT_PULLUP);
}

//MCU setup for button press light turn on & send code
void setupMCU2()
{
	//start serial
	Serial.begin(9600);
	Serial.println("Serial 9600 started");

	//making LED available to turn on
	pinMode(LED_BUILTIN, OUTPUT);

	//set for button press
	pinMode(PD4, INPUT_PULLUP);
	//pinMode(PD2, OUTPUT);
}