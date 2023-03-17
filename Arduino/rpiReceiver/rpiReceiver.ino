// set the length of a single cycle of the input signal
const unsigned int cycle = 1000/6;

// set the input pin number
const unsigned int inputPin = 3;

void setup() {
  // set up serial communication
  Serial.begin(9600);
  
  // attach interrupt to input pin (if desired)
  // attachInterrupt(digitalPinToInterrupt(inputPin), interruptHandler, FALLING);
}

void loop() {
  unsigned long timer;

  // check if input pin is LOW (i.e. signal received)
  if (!digitalRead(inputPin)) {
    // read input signal and store as decimal value
    getInput();
    
    // wait for the remainder of the cycle to complete
    timer = millis();
    while(millis()-timer < cycle);
    
    // wait for input signal to return to HIGH before moving on
    while (!digitalRead(inputPin));
  }
}

// function to read binary input signal and convert to decimal value
int getInput() {
  unsigned long timer = millis();
  int output = 0;
  
  // print "working" message to serial monitor
  //Serial.println("working");
  
  // wait for half a cycle (83 milliseconds)
  while (millis()-timer < cycle/2) {
    // check for input signal errors
    if (digitalRead(2)) return -1;
  }
  
  // wait for the remainder of the cycle to complete
  timer = millis();
  while(millis()-timer < cycle);
  
  // read binary input signal and convert to decimal value
  for (int i = 0; i < 4; i++) {
    // use bit shifting to calculate decimal value of binary input
    output += digitalRead(inputPin) << (3 - i);
    
    // print values for debugging purposes
    // Serial.println(String(digitalRead(inputPin)) + " * " + String(pow(2,3-i)) + " = " + String(digitalRead(inputPin)*pow(2,3-i)) + " = " + String(output));

    // wait for remainder of cycle to complete before moving on to next bit
    timer = millis();
    while(millis()-timer < cycle);
  }
  
  // check for input signal errors
  if (digitalRead(inputPin)) return -1;

  // print decimal value of input signal to serial monitor
  Serial.println(String(output) + "\n");
  
  // print "==============" separator to serial monitor for debugging purposes
  //Serial.println("================");
  
  // return decimal value of input signal
  return output;
}
