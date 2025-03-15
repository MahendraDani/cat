# Cat

Implementation of [cat(1)](https://www.man7.org/linux/man-pages/man1/cat.1.html) CLI utility from scratch in C following the [Build Your Own Cat Tool](https://codingchallenges.fyi/challenges/challenge-cat) coding challenge.

It took me ~2hrs to write the program, and over a day to write test :/

# Setting up locally
To setup and run this project locally, please follow the below steps:

## Prerequisites

1. C/C++ Compiler: 
Please make sure that you have a C/C++ compiler installed on your system, preferably gcc or clang.

2. Install make:

If you are using Mac, and have [Homebrew](https://brew.sh/) installed, use : 
```bash
brew install make
```

## Setup

1. Clone the project on your machine.
```
git clone https://github.com/Proxihox/Write-your-own-Cat-tool.git
```

2. Build from source 

First change directory, `cd cat`, then

```bash
make
```

This command will build the project from source, and output the executable `bin/cat`.

To verify clean installation, try running:
```bash
bin/cat data/test.txt
```
You should be able to see the [data/test.txt](https://github.com/MahendraDani/cat/blob/main/data/test.txt) file printed on the console.

## Usage
For usage, please read the [man page](https://www.man7.org/linux/man-pages/man1/cat.1.html) of cat(1). Note that, only -n and -b are supported in the current version.

1. Read input from a file
```bash
bin/cat file.txt
```

2. Read from multiple files and concatenate
```bash
bin/cat file1.txt file2.txt file3.txt
```

3. Read from stdin
```bash
bin/cat -
```

3. Show line numbers
```bash
bin/cat -n file.txt
```

4. Show line numbers (excluding blank lines)
```bash
bin/cat -b file.txt
```

## Testing

Although writing tests was not included in the challenge, any program to be called "production-ready" should and _must_ be appropriately tested. So I wrote a few tests in shell scripts to test my code.

Much of the inspiration of writing tests is taken from the [git project](https://github.com/git/git/tree/master/t) (as you can see from the names of test files :P)  which has a lot of tests written in shell scripts.

This also forced me to learn about shell scripting, unit testing and much more, which is also essential in writing good software.

To run the test suite, simply run :
```bash
make test
```

If you want to specially run a particular test file:
```bash
tests/t0001.sh
```

# Future Work

The project itself was meant to complete the coding challenge, which it has full-filled. Though, if found necessary, I might refactor it in the future.

Things that can be improved:
- namings : struct `config` doesn't not explain what configurations it holds. I mean using name `config` for storing the flags specified by the user is really _not_ a config, is it?

- parsing arguments and flags : Supporting two flags with if-else is _ok_, but not scalable. I would probably use a library to parse flags, but I really want to write my own, as I see myself doing the same thing again and again for all the challenges I will attempt in the future that require building a CLI utility.

# References
1. [The Shell Scripting Tutorial](https://www.shellscript.sh/)
2. [Learn Makefiles](https://makefiletutorial.com/)
3. [Beej's Guide to C Programming](https://beej.us/guide/bgc/html/split/)

