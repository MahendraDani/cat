#!/bin/sh

. ./lib.sh

echo "TEST (t0003) : Fail if the file does not exist"

if ! $CAT tempdir >/dev/null 2>&1; then
  echo "SUCCESS (t0003): OK"
  exit 0
fi

echo "FAILED (t0003): OK"
exit 1

