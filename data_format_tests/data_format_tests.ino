#include "openAFEComm.h"
#include "openafe.h"

AFE openafe;

void setup() 
{
	Serial.begin(115200);

	openafe.setupCV();

	openAFEComm_waitForCommands(&openafe);
}

void loop() 
{
	// woah, such empty :O
}
