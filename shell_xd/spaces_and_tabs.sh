#!/usr/bin/env bash
# This script tests the for spaces in the command line

source tests/testing_functions.sh

run_test '/usr/bin/ls -l'
run_test '/usr/bin/ls\t-l'
run_test '/usr/bin/ls   -l'
run_test '/usr/bin/ls\t-l'
run_test '/usr/bin/ls -l   '
run_test '/usr/bin/ls\t-l   -a'
run_test '/usr/bin/ls   -l   '
run_test '\t/usr/bin/ls     -l\t \t-a'
run_test '/usr/bin/ls   -l   -a'
run_test '/usr/bin/ls\t\t-l \t -a'
run_test '/usr/bin/ls   -l   -a   '
run_test '/usr/bin/ls\t-l\t-a\t'
run_test 'ls -l'
run_test 'ls\t-l'
run_test 'ls   -l'
run_test 'ls\t-l'
run_test 'ls -l   '
run_test 'ls\t-l   -a'
run_test 'ls   -l   '
run_test '\tls     -l\t \t-a'
run_test 'ls   -l   -a'
run_test 'ls\t\t-l \t -a'
run_test 'ls   -l   -a   '
run_test 'ls\t-l\t-a\t'

echo -e "\nTests completed\n"
echo "Failed tests: $failed_tests"
