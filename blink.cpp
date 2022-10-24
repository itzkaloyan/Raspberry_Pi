#include <iostream>
#include <wiringPi.h>
using namespace std;

int ledPin = 29;

void setup()
{

	pinMode(ledPin, OUTPUT);
	cout << "Start" << endl;
}

void loop()
{
	digitalWrite(ledPin, HIGH);
	delay(1000);
	digitalWrite(ledPin, LOW);
	delay(1000);

	cout << "Blink the LED" << endl;
}

int main(void) //(int argc, char **argv)
{
	if (wiringPiSetup() < 0)
	{
		cout << "setup wiring pi failed" << endl;
		return 1;
	}
	setup();
	while (1)
	{
		loop();
	}

	return 0;
}