#!/bin/sh

. ./lib.sh

echo "TEST (t0002): Test to fail if argument is a directory"

mkdir -p tempdir 

# Check if the directory exists
if ! $CAT tempdir >/dev/null 2>&1; then
  echo "SUCCESS (t0002): OK"
  rmdir tempdir
  exit 0
fi

rmdir tempdir

echo "FAILED (t0002): OK"
exit 1
