<h1 align="center">
SIMPLE SHELL PROJECT
</h1>
___
## Introduction
This is a group project, and as part of low-level programming foundation and algorithm--Linux and Unix system programming, we are to develop a simple **UNIX** command interpreter (shell).
## Description
A simple **UNIX** command interpreter is a program that reads commands from the standard input or files and executes them in order to display a result.
## Requirements
### General
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository
## More Info
### Output:
* Unless specified otherwise, your program **must have the exact same output** as `sh`(`/bin/sh`) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below):
Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program `hsh`:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
## List of allowed functions and system calls
* `access` (man 2 access)

