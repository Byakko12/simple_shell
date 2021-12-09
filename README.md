# Simple _Shell

## Creation of one simple_shell for  [Holberton School](https://github.com/holbertonschool)

**Simple_shell** is created by [Byakko12](http://daringfireball.net/) and  [NyRakath](https://github.com/NyRakath); It can be compiled using GCC and will execute a simple shell that can be used for some basic tasks and programs most commonly found in the /bin/ folder.

To start up simple_shell, compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.

## Quick Start

To start up simple_shell, compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.

run or execute

```
./hsh
```

## SYNOPSIS

simple_shell [command_string | file]

## Requirements for this project

- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall`, `-Werror`, `-Wextra`, and `-pedantic`
- Code should comply with [Betty](https://github.com/holbertonschool/Betty) style.
- No more than 5 functions per file.
- All header files should be include guarded.
- List of allowed functions and system calls:
  - `access` (man 2 access)
  - `chdir` (man 2 chdir)
  - `close` (man 2 close)
  - `closedir` (man 3 closedir)
  - `execve` (man 2 execve)
  - `exit` (man 3 exit)
  - `fork` (man 2 fork)
  - `free` (man 3 free)
  - `fstat` (man 2 fstat)
  - `getcwd` (man 3 getcwd)
  - `getline` (man 3 getline)
  - `kill` (man 2 kill)
  - `lstat` (man 2 lstat)
  - `malloc` (man 3 malloc)
  - `open` (man 2 open)
  - `opendir` (man 3 opendir)
  - `perror` (man 3 perror)
  - `read` (man 2 read)
  - `readdir` (man 3 readdir)
  - `signal` (man 2 signal)
  - `stat` (man 2 stat)
  - `strtok` (man 3 strtok) - advanced task recreate
  - `wait` (man 2 wait)
  - `waitpid` (man 2 waitpid)
  - `wait3` (man 2 wait3)
  - `wait4` (man 2 wait4)
  - `write` (man 2 write)
  - `_exit` (man 2 _exit)

## DESCRIPTION

simple_shell is an sh-compatible command language interpreter that executes commands read from the standard input or from a file.h.

### Overview

The simple_shell implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with built in history and line editing capabilities.

## File Descriptions

- `shell.h`: Header file which contains any library includes, structs created, and all function prototypes.
- `_strtok.c`: function for  string tokenization 
- `tools.c`: Contains functions for works and manipulate strings
- `valid_exec.c`: when it was validated the PATH to execute creates a new child
- `getenv.c`: Functions to handle PATH environment variable or any variable from env.
- `free_memory`: Functions to handle memory allocation and frees
- `built-in_functions.c`:  execute builtin function from pointer structure.