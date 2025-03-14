#!/bin/sh
. ./lib.sh

echo "TEST (t0004): Cat multiple files"

ACTUAL=$("$CAT" "$DATA_TEST1" "$DATA_TEST2") 
EXPECTED=$(cat "$DATA_TEST1" "$DATA_TEST2")  

echo "$ACTUAL" > actual_output.txt
echo "$EXPECTED" > expected_output.txt

if ! diff actual_output.txt expected_output.txt > /dev/null; then
  echo "FAILED (t0004): NOT OK"
  rm -f actual_output.txt expected_output.txt
  exit 1
fi

rm -f actual_output.txt expected_output.txt

echo "SUCCESS (t0004): OK"