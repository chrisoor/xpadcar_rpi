#!/bin/bash

#C8:3F:26:A9:D2:6D
#Device C8:3F:26:A9:D2:6D Xbox Wireless Controller

echo 1 > /sys/module/bluetooth/parameters/disable_ertm

i="0"
while [ $i -lt 15 ]
do
	GAMEPAD_FILE=/dev/input/js0
	if test -e "$GAMEPAD_FILE"; then
		echo "Gampead should be connected"
	else
		echo "Gamepad not connected"
	fi

	i=$[$i+1]
	sleep 1
done

