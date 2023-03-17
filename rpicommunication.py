import RPi.GPIO as GPIO;
import datetime;
from time import sleep;

outputPin = 10;
ledPin = 12;
cycle = 0.166;

GPIO.setwarnings(False);
GPIO.setmode(GPIO.BOARD);
GPIO.setup(outputPin, GPIO.OUT);
GPIO.setup(ledPin, GPIO.OUT);

command = int(input('(0)It\'s morbin\' time \n(1)Beam me up, Scotty \n(2)power up the borg cube \n(3)red alert \n(4)Exterminate! \n(5)Reverse the polarity of the neutron flow \n(6)The names Bond, James Bond \n(7)Use The Force Luke \n(8)Go Back To The Future \n(9)Shutup and take my money \n(10)initiate DOH procedure \n(11)Summon The Tardis \n(12)Sudo Make Me a Sandwitch \n(13)initiate a neural network \n(14)startup the quantum internet routers proposed by bernard couchman \n(15)Wake up Big Chungus  \n \ninput option here: '))
GPIO.output(outputPin, 1);
GPIO.output(ledPin, 0);
#print('HIGH')
#sleep(5)

def sendMessage(code):
	instructions = [0, 0, 0, 0, 0, 0];
	for i in range(4):
		if code-2**(3-i)>=0:
			instructions[i+1] = 1;
			code-=2**(3-i);
		else:
			instructions[i+1] = 0;
	return instructions;
			
instructions = sendMessage(command)


for i in instructions:
	GPIO.output(outputPin, i);
	GPIO.output(ledPin, i);
	print(i)
	sleep(cycle)
GPIO.output(outputPin, 1)
GPIO.output(ledPin, 0);
