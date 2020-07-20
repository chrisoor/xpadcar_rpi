#!/bin/bash

#C8:3F:26:A9:D2:6D
#Device C8:3F:26:A9:D2:6D Xbox Wireless Controller

echo 1 > /sys/module/bluetooth/parameters/disable_ertm

i="0"
READY_TO_RUN="0"
GAMEPAD_FILE=/dev/input/js0
SERIAL_PORT_FILE=/dev/ttyUSB0
while [ $i -lt 15 ]
do

	if test -e "$GAMEPAD_FILE"; then
		logger Gampead connected
	else
		logger Gamepad not connected
		continue
	fi

	
	if test -e "$SERIAL_PORT_FILE"; then
		logger Serial port connected
		READY_TO_RUN="1"
		break
	else
		logger Serial port not connected
	fi

	i=$[$i+1]
	sleep 1
done

if [ $READY_TO_RUN == "1" ]; then
	RETURN_VALUE=$(/home/pi/xpadcar_rpi/build/xpadcar_rpi)
	if "$RETURN_VALUE"; then
		logger Program ended succesfully
	else
		logger Program ended with failure
	fi
else
	logger Program did not start
fi
