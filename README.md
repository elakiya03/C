# C Programming Guide: From Basics to Advanced

This guide is a complete C reference for study and practical use. It preserves your existing notes and adds deeper coverage of core concepts, memory, the standard library, and advanced C techniques.

## Table of Contents

1. [Introduction to C](#introduction-to-c)
2. [Basic Syntax and Structure](#basic-syntax-and-structure)
3. [Compilation and Running](#compilation-and-running)
4. [Data Types](#data-types)
5. [Operators and Precedence](#operators-and-precedence)
6. [Control Structures](#control-structures)
7. [Type Conversion and Casting](#type-conversion-and-casting)
8. [Functions](#functions)
9. [Arrays and Strings](#arrays-and-strings)
10. [Pointers](#pointers)
11. [Memory Management](#memory-management)
12. [Structures, Unions, and Enums](#structures-unions-and-enums)
13. [Preprocessor and Macros](#preprocessor-and-macros)
14. [File I/O](#file-io)
15. [Modular Programming](#modular-programming)
16. [Storage Classes and Scope](#storage-classes-and-scope)
17. [Error Types and Debugging](#error-types-and-debugging)
18. [Advanced C Concepts](#advanced-c-concepts)
19. [Standard Library and Useful Functions](#standard-library-and-useful-functions)
20. [C vs C++ Notes](#c-vs-c-notes)
21. [Quick Reference](#quick-reference)
22. [Remember When You Return](#remember-when-you-return)

---

## Introduction to C

C is a procedural programming language designed for systems programming and low-level tasks. It gives you direct control over memory and hardware while remaining efficient and portable.

### Key C Characteristics

- Procedural, not object-oriented
- Low-level memory access with pointers
- Small runtime and fast performance
- Portable across platforms
- C standard library provides I/O, memory, string, and math functions
- Does not include templates, namespaces, or classes

---

## Basic Syntax and Structure

### `#include <stdio.h>`

- Adds the standard input/output library.
- Provides `printf`, `scanf`, `fgets`, `fopen`, `fclose`, and more.
- Without the proper header, function declarations may be missing and behavior becomes undefined.

### Program Entry Point: `main()`

```c
int main(void) {
    return 0;
}
```

- `main()` is the required entry point for executable programs.
- `int main(void)` is the standard form; `int main(int argc, char *argv[])` accepts command-line arguments.
- The return value tells the OS whether the program succeeded.

### Why `return 0;`?

- `0` means success in C.
- Non-zero values indicate failure or error codes.
- Explicitly returning `0` is good practice, even though some compilers add it implicitly.

### Comments

- Single-line: `// comment`
- Multi-line: `/* comment */`
- Use comments to explain intent, not obvious code behavior.

---

## Compilation and Running

- Compile: `gcc helloworld.c -o helloworld`
- Run: `./helloworld`

### Common compile flags

- `-Wall` : enable warnings
- `-Wextra` : extra warnings
- `-std=c11` or `-std=c99` : select language standard
- `-g` : include debug information

### Compilation steps

1. Preprocessing: `gcc -E`
2. Compilation to assembly: `gcc -S`
3. Assembly to object code: `gcc -c`
4. Linking: create executable

---

## Data Types

### Basic Types

- `char` : single byte character or small integer
- `int` : integer number
- `short` : shorter integer
- `long` : larger integer
- `long long` : largest integer type
- `float` : single-precision floating point
- `double` : double-precision floating point
- `_Bool` : boolean type (`0` or `1`)
- `void` : no type / no return value

### Signed and Unsigned

- `signed int` : positive and negative numbers
- `unsigned int` : only non-negative numbers
- Use `unsigned` for bit masks and counts when negative values are invalid.

### Type Sizes

Typical sizes on modern 64-bit systems:

- `char` = 1 byte
- `short` = 2 bytes
- `int` = 4 bytes
- `long` = 8 bytes
- `long long` = 8 bytes
- `float` = 4 bytes
- `double` = 8 bytes

Use `sizeof(type)` to verify actual sizes.

### Constants

- `const int MAX = 100;`
- `#define PI 3.14159`
- Prefer `const` over `#define` for typed constants.

---

## Operators and Precedence

### Operator Categories

- Arithmetic: `+ - * / % ++ --`
- Relational: `> < >= <= == !=`
- Logical: `&& || !`
- Bitwise: `& | ^ ~ << >>`
- Assignment: `= += -= *= /= %= &= |= ^= <<= >>=`
- Other: `?:`, `sizeof`, `,`

### Important Operator Rules

- `=` assigns; `==` compares.
- Integer division truncates: `5 / 2 == 2`.
- Modulo `%` works only with integers.
- `++i` and `i++` differ when used in expressions.
- Avoid mixing signed and unsigned values in comparisons.

### Operator Precedence (High to Low)

1. `()` `[]` `->` `.`
2. unary `! ~ ++ -- + - (type) * &`
3. `* / %`
4. `+ -`
5. `<< >>`
6. `< <= > >=`
7. `== !=`
8. `&`
9. `^`
10. `|`
11. `&&`
12. `||`
13. `?:`
14. assignment

Use parentheses to avoid ambiguity.

---

## Control Structures

### `if` / `else`

```c
if (x > 0) {
    // true
} else if (x == 0) {
    // zero
} else {
    // negative
}
```

- Conditions are numeric: `0` is false, non-zero is true.
- Parentheses around conditions are required.

### `switch`

```c
switch (value) {
    case 1:
        // ...
        break;
    case 2:
        // ...
        break;
    default:
        // ...
}
```

- Allowed types: `int`, `char`, `enum`, and values convertible to integer.
- `break` stops fall-through.
- `default` is optional but recommended.

### Loops

- `for (init; condition; update) { ... }`
- `while (condition) { ... }`
- `do { ... } while (condition);`

Example:

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

### Loop Control

- `break` exits the nearest loop or `switch`.
- `continue` skips to the next iteration.
- `goto` jumps to a label and should be used sparingly.

### Nested Control Flow

- Nested `if`, loops, and `switch` are allowed.
- Keep nesting shallow for readability.

---

## Type Conversion and Casting

### Implicit Conversion

- Performed automatically by the compiler.
- Can widen types safely: `int` → `long`, `float` → `double`.
- Can lose data when narrowing: `double` → `int`.

### Explicit Casting

```c
int x = (int)3.14;
unsigned int u = (unsigned int)x;
```

- Use casts when you intentionally change type.
- Avoid unnecessary casts.
- C-style casts are not type-safe, but they are the only cast style in C.

### Important Rules

- Cast pointers only when you know the underlying type.
- Avoid casting away `const` incorrectly.
- Use `size_t` for object sizes and array indexing.

---

## Functions

### Declaration and Definition

```c
int add(int a, int b); // declaration

int add(int a, int b) {
    return a + b;
}
```

- Declaration tells the compiler about the function.
- Definition provides the function body.

### Calling Functions

- Arguments are passed by value.
- Use pointers to allow functions to modify the caller's data.

### Parameter Passing

#### Pass by Value

```c
void func(int x) {
    x = 10;
}
```

- The original value is not changed.

#### Pass by Pointer

```c
void func(int *p) {
    *p = 10;
}
```

- Use pointers to modify the caller's value.
- Check for `NULL` before dereferencing.

### Return Values

- Return one value or use pointers to return multiple values.
- `void` means no return value.

### Function Pointers

```c
int add(int a, int b) {
    return a + b;
}

int (*funcPtr)(int, int) = add;
printf("%d\n", funcPtr(5, 2));
```

- Useful for callbacks and dynamic behavior.
- Function pointers are common in C APIs.

### Inline Functions

- The `inline` keyword suggests that the compiler replace function calls with function body.
- Use for small functions to reduce call overhead.
- The compiler may ignore the suggestion.

---

## Arrays and Strings

### Arrays

```c
int arr[5] = {1, 2, 3, 4, 5};
```

- Arrays have fixed size.
- The array name decays to a pointer to the first element.
- Valid indices: `0` to `size-1`.
- Out-of-bounds access is undefined.

### Multidimensional Arrays

```c
int matrix[3][4];
```

- Stored in row-major order.
- Access with `matrix[i][j]`.

### Passing Arrays to Functions

- When you pass an array to a function, it is treated as a pointer to its first element.
- Changes made through that pointer inside the function affect the original array values.
- Example:

  ```c
  void set_zero(int arr[], int n) {
      for (int i = 0; i < n; i++) {
          arr[i] = 0;
      }
  }

  int main(void) {
      int data[3] = {1, 2, 3};
      set_zero(data, 3);
      // data is now {0, 0, 0}
  }
  ```

### Strings

- Strings are `char` arrays terminated with `\0`.
- Example:
  ```c
  char name[20] = "Alice";
  ```
- Always reserve space for the null terminator.

### Input with `scanf`

- `scanf("%s", name);` reads until whitespace.
- Prefer `scanf("%19s", name);` to avoid overflow.
- Avoid `gets()`; it is unsafe.

### Safer Input

- Use `fgets(name, sizeof(name), stdin);`
- `fgets` reads a full line including newline when it fits.
- Remove the newline if you do not want it.

### Common String Functions

- `strcpy`, `strncpy`
- `strcat`, `strncat`
- `strcmp`, `strncmp`
- `strlen`, `strchr`, `strstr`
- Always check buffer sizes and avoid overruns.

---

## Pointers

### What is a Pointer?

- A pointer stores the memory address of another object.
- Example:
  ```c
  int x = 10;
  int *p = &x;
  printf("%d\n", *p);
  ```
- `&` obtains the address; `*` dereferences.

### Pointer Arithmetic

- `p + 1` moves to the next element of the pointer's type.
- `p[i]` is equivalent to `*(p + i)`.

### NULL and Invalid Pointers

- Use `NULL` to represent an empty pointer.
- Do not dereference `NULL`.
- Initialize pointers before use.

### Pointers to Pointers

```c
int x = 5;
int *p = &x;
int **pp = &p;
```

- Useful for dynamic arrays and pointer-based APIs.

### Types of Pointers

- **Null pointer:** points to nothing.
  ```c
  int *p = NULL;
  ```
- **Void pointer:** a generic pointer that can hold any object address.
  ```c
  void *p;
  int x = 10;
  p = &x;
  int *ip = (int *)p;
  ```
- **Pointer to const:** points to data that should not be changed through this pointer.
  ```c
  const int *p = &x;
  ```
- **Const pointer:** the pointer itself cannot change, but the data it points to can.
  ```c
  int * const p = &x;
  ```
- **Pointer to const pointer:** neither the pointer nor the data can be modified through this pointer.
  ```c
  const int * const p = &x;
  ```
- **Function pointer:** points to a function and can be used to call it.

  ```c
  int (*funcPtr)(int, int) = add;
  ```

- Pointers can also be classified by what they point to:
  - pointer to basic type (`int *`, `char *`)
  - pointer to struct (`struct Point *`)
  - pointer to array element (`int (*arr)[10]`)
  - pointer to pointer (`int **`)

### Void Pointers

```c
void *p;
int x = 10;
p = &x;
int *ip = (int *)p;
```

- `void *` can point to any object type.
- Cast back to the correct pointer type before dereferencing.

### Common Pointer Mistakes

- Dangling pointer: pointer to freed memory.
- Wild pointer: uninitialized pointer.
- Buffer overflow via invalid pointer arithmetic.
- Always set freed pointers to `NULL`.

---

## Memory Management

### Stack vs Heap

- Stack: automatic storage for local variables.
- Heap: dynamic memory allocated with `malloc` and freed with `free`.
- Stack variables are automatically cleaned up when functions return.
- Heap memory must be explicitly released.

### Dynamic Allocation

```c
int *p = malloc(sizeof(int));
if (p == NULL) {
    // handle failure
}
*p = 42;
free(p);
```

- `malloc(size)` allocates raw memory.
- `calloc(count, size)` allocates zero-initialized memory.
- `realloc(ptr, new_size)` resizes previously allocated memory.
- `free(ptr)` deallocates memory.

### Memory Leaks

- Forgetting `free()` causes memory leaks.
- Every successful `malloc`/`calloc`/`realloc` should have a matching `free`.
- Use tools like `valgrind` to detect leaks.

### Common Heap Errors

- Double free: calling `free()` twice on the same pointer.
- Use after free: dereferencing freed memory.
- Allocating too little memory for a buffer.
- `malloc` returning `NULL` if memory is not available.

---

## Structures, Unions, and Enums

### `struct`

- Groups different data members under one name.
- Each member has its own storage.
- Example:
  ```c
  struct Point {
      int x;
      int y;
  };
  ```
- Create variables as `struct Point p;`.

### `typedef`

- `typedef` creates an alias for a type.
- Example:
  ```c
  typedef struct Point Point;
  ```
- Many C programs use `typedef` to simplify struct usage.

### Padding and Alignment

- Compilers may insert padding bytes for alignment.
- The order of members affects struct size.
- Group larger fields first to reduce padding.

### `union`

- All members share the same memory.
- Only one member should be used at a time.
- Useful for memory-saving representations.

### `enum`

- Defines named integer constants.
- Example:
  ```c
  enum Color { RED, GREEN, BLUE };
  ```
- If one value is assigned, following values continue from there.
- Good for state machines and readable code.

---

## Preprocessor and Macros

### Preprocessor Directives

- `#include` : include another file
- `#define` : define macros or constants
- `#ifdef`, `#ifndef`, `#endif` : conditional compilation

### Macros

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

- Macros are text replacements performed before compilation.
- Always parenthesize macro parameters.
- Macros do not obey scope rules.
- Prefer inline functions and constants when possible.

### Header Guards

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// declarations

#endif
```

- Prevents double inclusion of header files.
- Use in every header file.

### Conditional Compilation

- Use `#ifdef DEBUG` and `#ifndef RELEASE` for platform-specific code.
- Useful for enabling debug logging and feature flags.

---

## File I/O

### Opening Files

- `fopen(filename, mode)` opens a file.
- Modes: `r`, `w`, `a`, `r+`, `w+`, `a+`, `rb`, `wb`.
- Always check the returned pointer for `NULL`.

### Reading and Writing

- `fscanf`, `fprintf` for formatted input/output.
- `fgets` to read a line safely.
- `fputs` to write a string.
- `fgetc` and `fputc` for single characters.
- `fread` and `fwrite` for raw binary data.

### Example

```c
FILE *file = fopen("data.txt", "r");
if (file) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}
```

### File Positioning

- `fseek(file, offset, whence)` moves the position.
- `ftell(file)` tells current position.
- `rewind(file)` returns to the start.

### Error Handling

- Use `perror("message")` to print system error messages.
- Check return values of file functions.

---

## Modular Programming

### Header Files and Source Files

- Put declarations in `.h` files and definitions in `.c` files.
- Include headers with `#include "header.h"`.
- Use `extern` for shared global variables.

### Example

`calc.h`:

```c
#ifndef CALC_H
#define CALC_H

int add(int a, int b);

#endif
```

`calc.c`:

```c
#include "calc.h"

int add(int a, int b) {
    return a + b;
}
```

`main.c`:

```c
#include <stdio.h>
#include "calc.h"

int main(void) {
    printf("%d\n", add(2, 3));
    return 0;
}
```

### Linking Multiple Files

- Compile each `.c` file separately.
- Link object files into one executable.
- Example: `gcc -c main.c calc.c && gcc main.o calc.o -o app`

---

## Storage Classes and Scope

### `auto`

- Default for local variables.
- Usually not written explicitly.

### `static`

- Local `static` variables retain value between calls.
- Global `static` variables are visible only in the current source file.

### `extern`

- Declares a variable defined in another file.
- Used in headers to share globals.

### `register`

- Suggests storage in CPU register.
- Mostly ignored by modern compilers.

### Scope

- Block scope: variables declared inside `{}`.
- File scope: globals and static globals.
- Function scope: local variables and parameters.

---

## Error Types and Debugging

### Compile-time Errors

- Syntax errors like missing semicolons.
- Undeclared variables.
- Type mismatch errors.

### Runtime Errors

- Division by zero.
- Null pointer dereference.
- Buffer overflow.
- Using freed memory.

### Undefined Behavior

- Occurs when code violates the C standard.
- Examples: out-of-bounds access, signed overflow, invalid pointer dereference.
- Undefined behavior can crash, corrupt data, or appear to work.

### Debugging Tips

- Use `printf` to inspect values.
- Compile with `-Wall -Wextra`.
- Use tools like `gdb` or `valgrind`.
- Check return values and pointer validity.

---

## Advanced C Concepts

### `const` and `volatile`

- `const` prevents modification of a variable.
- `volatile` tells the compiler the value may change unexpectedly (hardware registers, signal handlers).

### `restrict` (C99)

- A hint that a pointer is the only way to access the object it points to.
- Can improve optimization in functions that operate on arrays.

### Variable Length Arrays (VLAs)

- Allowed in C99 and optional in later standards.
- Example:
  ```c
  void foo(int n) {
      int arr[n];
  }
  ```
- Use carefully because they allocate on the stack.

### Compound Literals

- Create anonymous objects.
- Example:
  ```c
  int *p = (int[]){1, 2, 3};
  ```

### Designated Initializers

- Initialize struct members by name.
- Example:
  ```c
  struct Point p = {.y = 2, .x = 1};
  ```

### Bitfields

- Store small integers in a struct using specific bit widths.
- Example:
  ```c
  struct Flags {
      unsigned int a:1;
      unsigned int b:2;
      unsigned int c:5;
  };
  ```
- Useful for compact data representation.

### `setjmp` / `longjmp`

- Non-local jumps for error handling or recovery.
- Use rarely and with care.
- `setjmp` saves program state; `longjmp` restores it.

---

## Standard Library and Useful Functions

### Common Headers

- `<stdio.h>` : I/O functions
- `<stdlib.h>` : memory allocation, process control, conversion
- `<string.h>` : string and memory functions
- `<math.h>` : math functions
- `<ctype.h>` : character classification
- `<limits.h>` : type limits
- `<stdint.h>` : fixed-width integer types

### Useful Functions

- `printf`, `scanf`
- `malloc`, `calloc`, `realloc`, `free`
- `strlen`, `strcpy`, `strncpy`, `strcat`, `strcmp`
- `memcpy`, `memmove`, `memcmp`, `memset`
- `fopen`, `fclose`, `fgets`, `fputs`, `fread`, `fwrite`
- `atoi`, `atof`, `strtol`, `strtod`

### Practical Tips

- Prefer `fgets` over `gets`.
- Prefer `strncpy`/`snprintf` for bounded copies.
- Use `sizeof` with array names, not pointer variables.
- Use `calloc` when you need zero-initialized memory.

---

## C vs C++ Notes

### What C Does Not Have

- No classes or objects
- No templates or generics
- No namespaces
- No function overloading
- No operator overloading
- No exceptions
- No `new` and `delete` (use `malloc`/`free` instead)

### What C Shares with C++

- Basic syntax and operators
- `if`, `for`, `while`, `switch`
- Pointers and arrays
- `struct`, `enum`, `union`
- Most of the standard C library

---

## Quick Reference

### Escape Sequences

- `\n` newline
- `\t` tab
- `\0` null terminator
- `\"` double quote
- `\'` single quote
- `\\` backslash

### Format Specifiers

- `%d`, `%i` : `int`
- `%u` : `unsigned int`
- `%f` : `float`
- `%lf` : `double`
- `%c` : `char`
- `%s` : string
- `%lld` : `long long`
- `%zu` : `size_t`
- `%p` : pointer address

### `fopen` Modes

- `r`, `w`, `a`, `r+`, `w+`, `a+`, `rb`, `wb`

### Common Keywords

- `if`, `else`, `switch`, `case`, `default`
- `for`, `while`, `do`, `break`, `continue`, `goto`
- `struct`, `union`, `enum`, `typedef`, `sizeof`
- `static`, `extern`, `const`, `volatile`, `register`

---

## Remember When You Return

- Always initialize variables.
- Keep memory ownership clear: stack vs heap.
- Check return values from I/O and allocation functions.
- Use `const` to protect values that should not change.
- Prefer simple, readable code over clever tricks.
- Think about undefined behavior before you write a risky expression.

---
