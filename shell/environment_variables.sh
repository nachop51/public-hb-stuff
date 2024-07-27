#!/usr/bin/env bash
# This script tests the for environment

source tests/testing_functions.sh

PATH2=$PATH
unset PATH

run_test '\tls' '1'
run_test 'df' '1'
run_test 'w' '1'
run_test 'kakaka' '1'
run_test 'exit 0' '1'

echo -e "\nTests completed\n"
echo "Failed tests: $failed_tests"
