#!/bin/bash
if [ ! $1 ]; then (>&2 echo "ERROR: No Drive found"); exit 1; fi
if [ ! -b $1 ]; then (>&2 echo "ERROR: $1 is not a drive"); exit 1; fi
mount | grep $11 > /dev/null 2>&1
if [ $? != "0" ]; then
	sudo umount $1
	sudo mkdir -p /home/catloverkid$1
	sudo chmod -R 777 /home/catloverkid/dev
	sudo mount "$1"1 /home/catloverkid$1
else
	(
	echo o # Create a new empty DOS partition table
	echo n # Add a new partition
	echo p # Primary partition
	echo 1 # Partition number
	echo   # First sector (Accept default: 1)
	echo   # Last sector (Accept default: varies)
	echo w # Write changes
	) | sudo fdisk $1
	sudo mkfs.ext4 $11
	sudo mkdir -p /home/catloverkid$1
	sudo mount $11 /home/catloverkid$1
fi
