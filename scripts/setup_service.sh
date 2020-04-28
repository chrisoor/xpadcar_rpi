#!/bin/bash

#change permissions of file, so it can be executed
chmod 766 /home/pi/xpadcar_rpi/scripts/xpadcar_rpi.service

#copy file with service to proper directory
cp /home/pi/xpadcar_rpi/scripts/xpadcar_rpi.service /etc/systemd/system/

#reload whole systemd
systemctl daemon-reload

#enable service, so it is started on system startup
#systemctl enable xpadcar_rpi

#start the service immediatelly
systemctl start xpadcar_rpi

