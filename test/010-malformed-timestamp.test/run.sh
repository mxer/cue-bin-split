#!/bin/sh

echo -e '0:a' | ${EXECUTABLE} -r 1 -c 1 -i /dev/zero -s 1 -n -track.raw

if [ $? -eq 0 ]; then
	exit 1
else
	exit 0
fi
