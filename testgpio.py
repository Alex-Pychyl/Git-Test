import RPi.GPIO as GPIO;
from time import sleep;
import datetime;
import os;
import subprocess;

GPIO.setwarnings(False);
GPIO.setmode(GPIO.BOARD);
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN);
GPIO.setup(12, GPIO.OUT);

timer = datetime.datetime.now();
on = 1;

#prg = input('type the program name you want to monitor here & escape out of spaces with a back slash \n')
prg = 'fake\ prg'
def pulse() :
	global timer;
	global on;
	if on :
		pulseTime = 5;
	else:
		pulseTime = 0.25
	if datetime.datetime.now() - datetime.timedelta(seconds = pulseTime)>timer:
		timer = datetime.datetime.now();
		if on:
			on = 0;
		else:
			on = 1;
			print('pulse');
		GPIO.output(12, on);
	if datetime.datetime.now() - datetime.timedelta(seconds = 0.25)>timer:
		return 1;

def buttonPress(channel) :
	pressed = GPIO.input(10);
	checks = 0;
	while checks<3:
		if pulse():
			if GPIO.input(10) == 0:
				return;
			checks+=1;
	shutDown();
	
def shutDown():
	print("poweroff");
	GPIO.output(12, 0);
#	os.system("poweroff");
	exit();
		
GPIO.add_event_detect(10, GPIO.RISING, callback=buttonPress, bouncetime=300)

while True:
	pulse();
	test = subprocess.check_output('ps -aef | grep sudo\ python3\ '+ prg + '.py', shell=True)
	test.splitlines()
	if len(test)<151:
		shutDown();
	#print(len(test))
	
		
		#if ledPulse == 0:
			#timer = datetime.datetime.now();
			#on = 1;
			#ledPulse = 1;
		#else:
			#ledPulse = 0;
	#if ledPulse:
		#print('on');
		#GPIO.output(12, on);
	#else:
		#GPIO.output(12, 0);
		

