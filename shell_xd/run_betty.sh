#!/usr/bin/env bash
# Runs betty for every *.c and *.h file in the current directory

status=0
for file in *.c *.h; do
	output="$(betty $file)"
	if [ $? -ne 0 ]; then
		status=1
	fi

	echo -e "$output" | grep "ERROR:"
	if [ $? -eq 0 ]; then
		status=1
	fi
	echo -e "$output" | grep "WARNING:"
	if [ $? -eq 0 ]; then
		status=1
	fi
	echo -e "$output" | grep "warning:"
	if [ $? -eq 0 ]; then
		status=1
	fi
done

if [ $status -eq 0 ]; then
	echo -e "\nLinter passed!\n"
	exit 0
else
	echo -e "\nLinter failed!\n"
fi

exit $status
