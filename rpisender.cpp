#include <iostream>
#include "wiringPi.h"

using namespace std;

const int outputPin = 10;
const int cycle = 166;

int main() {
    wiringPiSetup();
    pinMode(outputPin, OUTPUT);

    for (int i = 0; i < 6; i++) {
        digitalWrite(outputPin, i%2);
        delay(cycle);
    }
}