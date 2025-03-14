CAT=../bin/cat
DATA_TEST1=data/test.txt
DATA_TEST2=data/test2.txt

test_program_exists(){
  if ! test -f "$CAT"; then
  echo "ERROR: cat executable not found, please build the program"
  exit 1
  fi
}