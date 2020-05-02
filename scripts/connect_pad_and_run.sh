#!/bin/bash

#C8:3F:26:A9:D2:6D
#Device C8:3F:26:A9:D2:6D Xbox Wireless Controller

echo 1 > /sys/module/bluetooth/parameters/disable_ertm

GAMEPAD_FILE=/etc/input/js0
if test -e "$GAMEPAD_FILE"; then
	echo "Gampead should be connected"
else
	echo "Gamepad not connected"
fi

