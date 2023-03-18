#include <iostream>
#include <ctime>
#include <wiringPi.h>
#include <stdlib.h>

using namespace std;

const int outputPin = 16;
const int ledPin = 1;
const int cycle = 1000/6;
const char codes[16][100] = {"It's morbin' time", "Beam me up, Scotty", "Power up the borg cube", "Red alert", "Exterminate!", "Reverse the polarity of the neutron flow", "The name's Bond, James Bond", "Use the force Luke", "Go back to the future", "Shut up and take my money", "Initiate DOH procedure", "Summon the tardis", "Sudo make me a sandwich", "initiate a neural network", "Startup the quantum internet routers proposed by Bernard Couchman", "Wake up Big Chungus"};

int main() {
    int command = -1;
    char c;
    int instructions[6] = {0, 0, 0, 0, 0, 0};
    
    wiringPiSetup();
    pinMode(outputPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    
    while (1) {
        system("clear");
        printf("Enter number for command to send or -1 to quit:\n\n");
        for (int i = 0; i < 16; i++) {
            printf("(%i) --> %s\n", i, codes[i]);
        }
        while ((!scanf("%i", &command))||command<-1||command>15) {
            while((c = getchar()) != '\n' && c != EOF);
            printf("Invalid, try again: ");
        }
        
        if (command==-1) break;
        
        for (int i = 0; i < 4; i++) {
            if (command-(1<<(3-i))>=0) {
                instructions[i+1] = 1;
                command-=1<<(3-i);
            } else instructions[i+1] = 0;
        }

        for (int i = 0; i < 6; i++) {
            digitalWrite(outputPin, instructions[i]);
            digitalWrite(ledPin, instructions[i]);
            delay(cycle);
        }
        digitalWrite(ledPin, 0);
        digitalWrite(outputPin, 1);
    }
}
