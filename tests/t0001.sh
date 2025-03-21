#!/bin/sh

. ./lib.sh

echo "TEST (t0001): Test to cat from single file"

ACTUAL=$("$CAT" "$DATA_TEST1") 
EXPECTED=$(cat "$DATA_TEST1")  

echo "$ACTUAL" > actual_output.txt
echo "$EXPECTED" > expected_output.txt

if ! diff actual_output.txt expected_output.txt > /dev/null; then
  echo "FAILED (t0001): NOT OK"
  rm -f actual_output.txt expected_output.txt
  exit 1
fi

rm -f actual_output.txt expected_output.txt

echo "SUCCESS (t0001): OK"
