#include <iostream>
#include <ctime>
#include <wiringPi.h>

using namespace std;

const int outputPin = 16;
const int ledPin = 1;
const int cycle = 1000/6;
const char codes[16][100] = {"It's morbin' time", "Beam me up, Scotty", "Power up the borg cube", "Red alert", "Exterminate!", "Reverse the polarity of the neutron flow", "The name's Bond, James Bond", "Use the force Luke", "Go back to the future", "Shut up and take my money", "Initiate DOH procedure", "Summon the tardis", "Sudo make me a sandwich", "initiate a neural network", "Startup the quantum internet routers proposed by Bernard Couchman", "Wake up Big Chungus"};

int main() {
    int command = -1;
    char c;
    //time_t timer;
    
    wiringPiSetup();
    pinMode(outputPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    
    printf("Enter number for command to send:\n\n");
    for (int i = 0; i < 16; i++) {
        printf("(%i) --> %s\n", i, codes[i]);
    }
    while ((!scanf("%i", &command))||command<0||command>15) {
        while((c = getchar()) != '\n' && c != EOF);
        printf("Invalid, try again: ");
    }

    for (int i = 0; i < 6; i++) {
        if (i==5) i=6;
        digitalWrite(outputPin, i%2);
        digitalWrite(ledPin, i%2);
        printf("%i", i%2);
        //timer = time(nullptr);
        //while(time(nullptr)-timer<cycle);
        delay(cycle);
    }
    digitalWrite(ledPin, 1);
    digitalWrite(outputPin, 1);
}
