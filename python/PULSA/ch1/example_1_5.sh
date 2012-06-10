#!/usr/bin/env bash
#A System Information Gathering Script

#Command 1
function uname_func()
{
    UNAME="uname -a"
    printf "Gathering system information with the $UNAME command:\n\n"
    $UNAME
}

#Command 2
function diskspace_func()
{
    DISKSPACE="df -h"
    printf "Gathering system information with the $DISKSPACE command:\n\n"
    $DISKSPACE
}

#Main function to call other functions
function main()
{
    uname_func
    diskspace_func
}

main
