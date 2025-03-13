# Cat - Coding Challenge
Building my own UNIX CLI utility "cat" from scratch in C.

Handle all the following cases
cat file1.txt
cat -
cat file1.txt -
cat file1.txt - file2.txt
cat file1.txt file2.txt -

TODO:
The original cat commands requires all flags before the arguments, whereas the current implementation allows flags to be after the arguments.

Flag handling:
Case 1 : ./cat file.txt

Case 2 : ./cat -n [files]

Case 3 : ./cat -b [files]

Case 4 : ./cat [files] -n
print all files then print -> cat : -n: No such file or directory

Case 4 : ./cat [files] -n
print all files then print -> cat : -b: No such file or directory
