#!/bin/sh

echo | ${EXECUTABLE} -r 44100 -c 1 -s 2 -i /dev/zero -n track.raw

if [ $? -eq 0 ]; then
	exit 1
else
	exit 0
fi
