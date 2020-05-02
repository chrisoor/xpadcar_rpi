#!/usr/bin/expect -f

set start_char "#"
#set mac_address [lindex $argv 0]
set expected_response "Device C8:3F:26:A9:D2:6D Xbox Wireless Controller"

spawn bluetoothctl
expect -re $start_char

send "devices\r"
expect $expected_response

send "quit\r"
expect eof
