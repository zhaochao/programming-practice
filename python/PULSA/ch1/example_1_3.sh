#!/usr/bin/env bash
# A Systemp Information Gathering Script

#Command 1
UNAME="uname -a"
printf "Gathering system information with the $UNAME command:\n\n"
$UNAME

#Command 2
DISKSPACE="df -h"
printf "Gathering system information with the $DISKSPACE command:\n\n"
$DISKSPACE
