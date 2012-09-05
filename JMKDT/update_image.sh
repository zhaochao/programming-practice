#!/bin/bash

sudo losetup /dev/loop0 floppy.img
[ -e /tmp/JMKDT ] || mkdir /tmp/JMKDT
sudo mount /dev/loop0 /tmp/JMKDT
sudo cp kernel /tmp/JMKDT/kernel
sleep 2
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
