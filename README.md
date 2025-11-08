# Custom C++ Shell

This is a custom Linux shell implementation in C++ for the Capstone Project. It is based on the POSIX API concepts covered in the Linux System Programming (LSP) module.

## Features (Planned)
* Executes basic commands (e.g., `ls`, `pwd`, `echo`)
* Parses user input into arguments
* (Todo) Background process support (`&`)
* (Todo) Piping (`|`) and Redirection (`>`)
* (Todo) Basic job control

## Modules Used
* Linux System Programming (LSP): `fork()`, `exec()`, `wait()`
* C++ OOP: A `Shell` class is used to manage the state.
