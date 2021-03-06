#!/bin/bash

#C8:3F:26:A9:D2:6D
#Device C8:3F:26:A9:D2:6D Xbox Wireless Controller

chmod 766 /home/pi/xpadcar_rpi/scripts/disable_ertm.sh
su -c /home/pi/xpadcar_rpi/scripts/disable_ertm.sh root

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
		sleep 1
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

if [ "$READY_TO_RUN" == "1" ]; then
	/home/pi/xpadcar_rpi/build/xpadcar_rpi
	RETURN_VALUE=$?
	logger Program started
	if [ "$RETURN_VALUE" == "0" ]; then
		logger Program ended succesfully
		exit 0
	else
		logger Program ended with failure
		exit 1
	fi
else
	logger Program did not start
	exit 1
fi
