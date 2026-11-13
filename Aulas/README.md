# C Programming and Computer Architecture Studies

This repository documents my learning journey in C, focusing on formal rigor and a deep understanding of how code interacts directly with the hardware.

## 🚀 Lesson 1: Compilation Fundamentals and Operating System Interaction

In this first project, I explored the foundational structure of the C language using the GCC compiler inside the WSL (Ubuntu) environment.

### Formal Technical Concepts Mastered:
* **The `#include <stdio.h>` Directive:** Operates during the preprocessing stage, pasting the headers and prototypes for standard input-output functions.
* **GCC Compiler Anatomy:** Analyzed how arguments are mapped using position and flags, understanding that `gcc -o aula1 aula1.c` instructs the compiler to separate the source file to be read (`aula1.c`) from the executable binary to be created (`aula1`).
* **Exit Status Code (`return 0`):** Explored the POSIX/Unix convention in which returning `0` to the Operating System indicates success, while any non-zero value signals a failure and can encode which one. This makes success a single, unambiguous value and leaves the rest of the range to identify different errors.
* **Linux Permissions and Memory Security:** Deconstructed the `Permission denied` error, learning that the Linux Kernel restricts text source execution and requires explicit executable metadata bits (`chmod +x`) before loading a raw binary file into the RAM.

## 🧩 Lesson 2: Program Structure, Functions and the Build Pipeline

Based on Chapter 2 of K.N. King's *C Programming: A Modern Approach*, this lesson moved from "making code run" to understanding **why** a C program is organized the way it is.

### Formal Technical Concepts Mastered:
* **General Form of a Simple Program:** A simple C program is built from three key features: **directives** (commands for the preprocessor, always starting with `#`, one line long, no semicolon), **functions** (named blocks of executable code) and **statements** (commands performed at run time, terminated by `;`). Braces `{ }` delimit where a function begins and ends.
* **C Has No Built-in I/O:** The language itself only computes, decides and repeats. Input and output come from the **standard library**, and a header such as `stdio.h` tells the compiler that `printf` exists and how to call it.
* **Header vs. Library:** A header holds **declarations** (prototypes); the code that actually implements the function lives in a compiled library that is attached later. This is why `math.h` often requires linking with `-lm`.
* **What a Function Is:** A named block of code with a **signature** (return type, name, parameter types), invoked through the call operator `( )`. Arguments are **passed by value**: the function receives copies, so changing a parameter does not change the caller's variable.
* **Functions vs. Mathematical Functions:** A C function may have **side effects** (like `printf`) and is not necessarily a mathematical function. Only **pure** functions, which depend solely on their arguments and change nothing outside, behave like one.
* **The Call Stack:** Each call creates a **stack frame** holding parameters, local variables and the return address, released at `return`. This is why local variables vanish after a call and why recursion is possible.
* **Declaration vs. Definition:** A prototype (`int sum(int, int);`) declares a function's signature; the definition provides its body.
* **Why `main` Returns `int`:** The value returned by `main` is the program's **exit status**, delivered to the OS. It can be inspected in the shell with `echo $?`.
* **The Build Pipeline:** Preprocessor (edits text) → Compiler (C to assembly) → Assembler (assembly to machine code, producing an object file with unresolved symbols) → Linker (resolves symbols and builds the executable) → Loader (the OS places the program in memory) → Execution.
* **The Role of `main`:** The compiler treats every function in a file equally. The program's real entry point is `_start`, supplied by startup code added at link time, which calls `main`. To the linker, `main` is just another referenced symbol; a missing one produces `undefined reference to 'main'`.
* **Reachability:** A function only runs if it is reachable through the chain of calls starting at `main`. Exceptions exist: **hardware interrupts**, **OS signals**, functions registered with `atexit`, and startup code. In freestanding environments (microcontrollers) the entry point is implementation-defined.
* **How Libraries Are Built:** A library is a set of functions **without `main`**, compiled with `gcc -c` into object files, packaged as `.a` (static) or `.so` (dynamic), and exposed through a `.h` header. `nm` reveals which symbols an object file defines and which it still needs.

### Commands Explored:
```bash
gcc -E prog.c -o prog.i   # preprocess only
gcc -S prog.c             # generate assembly (prog.s)
gcc -c prog.c             # compile to an object file (prog.o)
nm prog.o                 # list defined and undefined symbols
gcc prog.o -o prog        # link into an executable
echo $?                   # show the exit status of the last program
```