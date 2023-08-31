#!/usr/bin/env bash

shell_name="./hsh"
failed_tests=0

function run_test {
	echo -e "Test case: '$1' \n"
	if [ -z "$2" ]; then
		compare_with_sh "$1"
	else
		compare_errors "$1"
	fi
	echo "-----------------"
}

function compare_with_sh {
	output="$(echo -e "$1" | $shell_name 2>&1)"
	output_sh="$(echo -e "$1" | /usr/bin/sh 2>&1)"
	diff_output=$(/usr/bin/diff <(echo "$output") <(echo "$output_sh"))
	if [ -z "$diff_output" ]; then
		echo "Test passed"
	else
		echo "Test failed"
		failed_tests=$((failed_tests + 1))
		echo -e "\nOutput from $shell_name:\n$output"
		echo -e "\nOutput from sh:\n$output_sh"
		output_length=${#output}
		output_sh_length=${#output_sh}
		echo -e "Got: $output_length characters\nExpected: $output_sh_length characters"
	fi
}

function compare_errors {
	echo -e "$1" | $shell_name 2>&1 > /dev/null
	error_code=$?
	echo -e "unset PATH && $1" | /usr/bin/sh 2>&1 > /dev/null
	error_code_sh=$?
	if [ "$error_code" -eq "$error_code_sh" ]; then
		echo "Test passed"
	else
		echo "Test failed"
		failed_tests=$((failed_tests + 1))
		echo -e "Got: $error_code\nExpected: $error_code_sh"
	fi
}

echo "-----------------"
