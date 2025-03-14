#!/bin/sh

. ./lib.sh

echo "TEST (t0007): Test cat for stdin"

cat > actual_output.txt << EOF
"Your heart is the size of an ocean. Go find yourself in its hidden depths."
"I Don'T Believe In Failure. It Is Not Failure If You Enjoyed The Process."
EOF

$CAT > expected_output.txt << EOF
"Your heart is the size of an ocean. Go find yourself in its hidden depths."
"I Don'T Believe In Failure. It Is Not Failure If You Enjoyed The Process."
EOF


if ! diff actual_output.txt expected_output.txt > /dev/null; then
  echo "FAILED (t0005): NOT OK"
  rm -f actual_output.txt expected_output.txt
  exit 1
fi

rm -f actual_output.txt expected_output.txt

echo "SUCCESS (t0005): OK"