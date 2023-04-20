#!/usr/bin/env bash
# This script runs all the tests in the tests directory

# Check if the tests directory exists
if [ ! -d tests ]; then
	echo "Error: tests directory not found"
	exit 1
fi

# Check if the tests directory is empty
if [ ! "$(ls -A tests)" ]; then
	echo "Error: tests directory is empty"
	exit 1
fi

# Run all the tests
for test in tests/*.sh; do
	if [ "$test" = "tests/testing_functions.sh" ]; then
		continue
	fi
	echo -e "\nRunning test file: '$test'\n"
	./$test
done
