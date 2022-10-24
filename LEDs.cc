#include <iostream>
#include <csignal>
#include "WiringPi/wiringPi/wiringPi.h"

using namespace std;

// global flag used to exit from the main loop
bool RUNNING = true;
// Blink an LED
void blink_led(int led, int time)
{
    digitalWrite(led, HIGH);
    delay(time);
    digitalWrite(led, LOW);
    delay(time);
}
// Callback handler if CTRL-C signal is detected
void my_handler(int s)
{
    cout << "Detected CTRL-C signal no. " << s << '\n';
    RUNNING = false;
}

int main()
{
    // Register a callback function to be called if the user presses CTRL-C
    signal(SIGINT, my_handler);

    // Initialize wiringPi and allow the use of BCM pin numbering
    wiringPiSetupGpio();

    cout << "Controlling the GPIO pins with wiringPi\n";

    // Define the 3 pins we are going to use
    int short_ = 17, long_ = 22;

    // Setup the pins
    pinMode(short_, OUTPUT);
    pinMode(long_, OUTPUT);

    int time = 1000; // interval at which a pin is turned HIGH/LOW
    while (RUNNING)
    {
        blink_led(short_, time);
        blink_led(long_, time);
    }
    cout << "Program ended";
    return 0;
}
