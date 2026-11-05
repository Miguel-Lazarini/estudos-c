# C Programming and Computer Architecture Studies

This repository documents my learning journey in C, focusing on formal rigor and a deep understanding of how code interacts directly with the hardware.

## 🚀 Lesson 1: Compilation Fundamentals and Operating System Interaction

In this first project, I explored the foundational structure of the C language using the GCC compiler inside the WSL (Ubuntu) environment.

### Formal Technical Concepts Mastered:
* **The `#include <stdio.h>` Directive:** Operates during the preprocessing stage, pasting the headers and prototypes for standard input-output functions.
* **GCC Compiler Anatomy:** Analyzed how arguments are mapped using position and flags, understanding that `gcc -o aula1 aula1.c` instructs the compiler to separate the source file to be read (`aula1.c`) from the executable binary to be created (`aula1`).
* **Exit Status Code (`return 0`):** Explored the POSIX standard, where returning `0` to the Operating System formally indicates "Zero Errors found" (Success). This layout optimizes execution speed on the CPU hardware level by triggering the physical *Zero Flag* via the `TEST` operation, while non-zero values map to specific failure codes.
* **Linux Permissions and Memory Security:** Deconstructed the `Permission denied` error, learning that the Linux Kernel restricts text source execution and requires explicit executable metadata bits (`chmod +x`) before loading a raw binary file into the RAM.
