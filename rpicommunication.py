import RPi.GPIO as GPIO;
import datetime;
from time import sleep;

GPIO.setwarnings(False);
GPIO.setmode(GPIO.BOARD);
GPIO.setup(10, GPIO.OUT);

command = int(input('(0) \n(1) \n(2) \n(3) \n(4) \n(5) \n(6) \n(7) \n(8) \n(9) \n(10) \n(11) \n(12) \n(13) \n(14) \n(15) \n(16) \n \ninput option here: '))
GPIO.output(10, 1);
print('HIGH')
sleep(5)

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
	GPIO.output(10, i);
	print(i)
	sleep(166/1000)
GPIO.output(10, 1)
