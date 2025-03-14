#!/bin/sh

. ./lib.sh

echo "TEST (t0005): Test -n flag"

ACTUAL=$("$CAT" -n "$DATA_TEST1") 
EXPECTED=$(cat -n "$DATA_TEST1")  

echo "$ACTUAL" > actual_output.txt
echo "$EXPECTED" > expected_output.txt

if ! diff actual_output.txt expected_output.txt > /dev/null; then
  echo "FAILED (t0005): NOT OK"
  rm -f actual_output.txt expected_output.txt
  exit 1
fi

rm -f actual_output.txt expected_output.txt

echo "SUCCESS (t0005): OK"