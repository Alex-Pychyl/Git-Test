from time import sleep
import os

while True:
	test = os.system('ps -aef | grep sudo\ python3\ testgpio.py')
	sleep(1)
	print(test)
