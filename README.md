# C Programming Guide: From Basics to Advanced

This guide is a complete C reference for study and practical use. It preserves your existing notes and adds deeper coverage of core concepts, memory, the standard library, and advanced C techniques.

## Table of Contents

1. [Introduction to C](#introduction-to-c)
2. [Basic Syntax and Structure](#basic-syntax-and-structure)
3. [Compilation and Running](#compilation-and-running)
4. [Input and Output](#input-and-output)
5. [Data Types](#data-types)
6. [Operators and Precedence](#operators-and-precedence)
7. [Control Structures](#control-structures)
8. [Type Conversion and Casting](#type-conversion-and-casting)
9. [Functions](#functions)
10. [Arrays and Strings](#arrays-and-strings)
11. [Pointers](#pointers)
12. [Memory Management](#memory-management)
13. [Structures, Unions, and Enums](#structures-unions-and-enums)
14. [Preprocessor and Macros](#preprocessor-and-macros)
15. [File I/O](#file-io)
16. [Modular Programming](#modular-programming)
17. [Storage Classes and Scope](#storage-classes-and-scope)
18. [Error Types and Debugging](#error-types-and-debugging)
19. [Advanced C Concepts](#advanced-c-concepts)
20. [Standard Library and Useful Functions](#standard-library-and-useful-functions)
21. [Naming Conventions](#naming-conventions)
22. [C vs C++ Notes](#c-vs-c-notes)
23. [Quick Reference](#quick-reference)
24. [Remember When You Return](#remember-when-you-return)

---

## Introduction to C

C is a `procedural programming language` designed for systems programming and low-level tasks. It gives you direct control over memory and hardware while remaining efficient and portable.

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

## Input and Output

The `<stdio.h>` header provides standard input and output functions. These functions can be grouped into formatted I/O, which uses format specifiers, and character/string I/O, which reads or writes characters and text directly.

### Formatted I/O

Formatted functions interpret conversion specifiers such as `%d` and `%s`.

#### Formatted output

- `printf(format, ...)` writes formatted output to `stdout`.
- `fprintf(stream, format, ...)` writes formatted output to a file stream.
- `sprintf(buffer, format, ...)` writes formatted output to a string buffer; prefer `snprintf` to limit the number of bytes written.

```c
int score = 95;
printf("Score: %d\n", score);
```

#### Formatted input

- `scanf(format, ...)` reads formatted input from `stdin`.
- `fscanf(stream, format, ...)` reads formatted input from a file stream.
- `sscanf(string, format, ...)` reads formatted input from a string.

Pass the address of each destination variable (for example, `&age`), except for character arrays used with `%s`. Check the return value to confirm how many items were successfully read.

```c
int age;
if (scanf("%d", &age) == 1) {
    printf("Age: %d\n", age);
}
```

Common conversion specifiers include `%d` for `int`, `%u` for `unsigned int`, `%c` for a character, `%s` for a string, `%f` for `float` output, and `%lf` for `double` input. For `printf`, `%f` is used for both `float` and `double` arguments.

### Unformatted I/O (Characters and Strings)

These functions read or write characters and strings without using format strings.

- `getchar()` reads one character from `stdin`
- `putchar(character)` writes one character to `stdout`.

- `fgetc(stream)` reads one character from a stream
- `fputc(character, stream)` writes one character.

- `fgets(buffer, size, stream)` reads at most `size - 1` characters and adds a terminating null character when successful. It can retain the newline if one fits.
- `puts(string)` writes a string to `stdout` and appends a newline.
- `fputs(string, stream)` writes a string without adding a newline.

- `fread(buffer, size, count, stream)` and `fwrite(buffer, size, count, stream)` read and write blocks of data, commonly for binary files.
- When using `%s` with `scanf`, specify a maximum field width that leaves room for the terminating null character (for example, `%49s` for a 50-byte array).

```c
char name[50];
if (fgets(name, sizeof name, stdin) != NULL) {
    puts(name);
}
```

Avoid `gets()`: it cannot limit input to the destination buffer size and was removed from the C standard.

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

### `size_t` for Sizes and Indexes

`size_t` is an unsigned integer type defined by the standard library, suitable for representing the size of any object. Its width is platform-dependent, so it can represent larger object sizes on platforms that support them. It is not guaranteed to be a particular type such as `unsigned int` or `unsigned long long`.

Use `size_t` for object sizes and array indexes, and include `<stddef.h>` when you need its definition directly. The `sizeof` operator and functions such as `strlen()` return `size_t`. Use `%zu` to print a `size_t` value with `printf`.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char message[] = "Hello";
    size_t length = strlen(message);

    for (size_t i = 0; i < length; i++) {
        printf("Index %zu: %c\n", i, message[i]);
    }

    size_t array_size = sizeof message;
    printf("Array size: %zu bytes\n", array_size);
    return 0;
}
```

Because `size_t` is unsigned, decrementing zero wraps to a large positive value. Avoid conditions such as `i >= 0` in a countdown loop. To process an array backwards, test before decrementing and use `i - 1` as the index:

```c
for (size_t i = length; i > 0; i--) {
    printf("%c", message[i - 1]);
}
```

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

####  `for` Loop Patterns

C has one `for` statement form: `for (initialization; condition; update)`. Any of its three expressions can be omitted, and these examples show common ways to use that form:

```c
// 1. Standard counter loop
for (int i = 1; i <= 5; i++) {
    printf("%d ", i);
}

// 2. Infinite loop; exit when the required condition is met
for (;;) {
    if (should_stop) {
        break;
    }
}

// 3. Multiple variables, separated by comma operators
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i: %d, j: %d\n", i, j);
}

// 4. Initialization and update handled outside the loop header
int i = 1;
for (; i <= 3;) {
    printf("%d ", i);
    i++;
}

// 5. Nested loops, often used to visit rows and columns
for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 3; col++) {
        printf("(%d, %d) ", row, col);
    }
    printf("\n");
}
```

The infinite form has no stopping condition in its header, so it continues until the body exits it (for example, with `break` or `return`). A nested loop is a loop inside another loop, not a different `for` syntax. C does not have a built-in range-based `for-each` loop.

### Loop Control

- `break` exits the nearest loop or `switch`.
- `continue` skips to the next iteration.
- `goto` jumps to a label and should be used sparingly.
- C does not support labeled `break` or `continue`; these statements affect only the innermost applicable loop.

To leave multiple nested loops at once, one option is `goto` to a label later in the same function. A flag or returning from the function may be clearer in some cases.

```c
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) {
            goto loops_done;
        }
    }
}

loops_done:
printf("Finished the nested loops.\n");
```

#### `break` vs. `return`

- `break` exits the nearest enclosing loop or `switch`, then execution continues after it.
- `return` exits the current function immediately, skipping the rest of its body and returning control to its caller. A non-`void` function can return a value.

```c
void check_numbers(void) {
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            break; // Exits the loop; execution continues in this function.
        }
        printf("%d ", i);
    }
    printf("\nLoop ended; the function is still running.\n");
}
```

Use `break` when only the loop should stop; use `return` when the function's work is finished and it should exit.

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
int add(int a, int b); // declaration (prototype)

int add(int a, int b) {
    return a + b;
}
```

- A declaration tells the compiler the function's name, return type, and parameter types.
- A definition provides the function body. A definition also serves as a declaration.
- Function definitions are not called “initializations”; initialization gives an object its initial value.

### Function Layouts

The definition can appear before `main`, in which case a separate prototype is not needed:

```c
int add(int a, int b) {
    return a + b;
}

int main(void) {
    return add(5, 3) == 8 ? 0 : 1;
}
```

Alternatively, place a prototype before `main` and the definition later. This is useful when organizing larger source files:

```c
int add(int a, int b); // Prototype

int main(void) {
    return add(5, 3) == 8 ? 0 : 1;
}

int add(int a, int b) { // Definition
    return a + b;
}
```

Parameter names may be omitted from a prototype; only the parameter types are required:

```c
int add(int, int);
```

This is still a prototype, not a distinct kind of function definition.

### Function Types by Parameters and Return Value

Functions can be grouped by whether they take parameters and return a value:

```c
void greet(void);              // No parameters, no return value
void print_square(int value);  // Parameters, no return value
int get_answer(void);          // No parameters, returns a value
int max(int a, int b);         // Parameters and returns a value
```

For example:

```c
void greet(void) {
    printf("Hi\n");
}

void print_square(int value) {
    printf("%d\n", value * value);
}

int get_answer(void) {
    return 42;
}

int max(int a, int b) {
    return a > b ? a : b;
}
```

Use `(void)` to explicitly declare that a function takes no parameters, such as `int get_answer(void);`. In C versions before C23, an empty parameter list in a declaration such as `int get_answer();` does not provide a prototype specifying that there are no parameters.

- A function cannot return an array directly. It can return a pointer, but do not return a pointer to a local array because that array's lifetime ends when the function returns.

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

A function pointer stores the address of a function with a matching return type and parameter types.

```c
int add(int a, int b) {
    return a + b;
}

int (*func_ptr)(int, int) = add;
printf("%d\n", func_ptr(5, 2));
```

The `&` operator is optional when taking a function's address, and a function pointer can be called like a function:

```c
int apply(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int result = apply(5, 2, add);
```

- Function pointers are useful for callbacks, such as passing a comparison function to `qsort`, and for selecting behavior at runtime.
- The pointed-to function's signature must be compatible with the pointer's type.

### Inline Functions

In C99 and later, `inline` is a function specifier that permits (but does not require) the compiler to substitute a function's body at a call site. The compiler decides whether to inline it; it may also inline functions without the keyword.

```c
static inline int square(int value) {
    return value * value;
}
```

- `inline` does not guarantee faster code or eliminate function-call overhead. Measure performance before optimizing.
- It is most often useful for small functions in headers. `static inline` gives each translation unit its own internal-linkage definition and avoids the external-linkage rules that apply to plain `inline` definitions in C.

---

## Arrays and Strings

### Arrays

```c
int arr[5];                  // Fixed size; elements are uninitialized
int a[5] = {1, 2, 3, 4, 5}; // Initialize every element
int b[] = {1, 2, 3};         // Size is inferred as 3
int c[5] = {1, 2};           // Remaining elements are initialized to 0
int d[5] = {0};              // Initialize every element to 0
int e[] = {0};               // One element, with value 0
```

- A fixed-size array has its size determined at its declaration.
- The array name decays to a pointer to the first element.
- Valid indices: `0` to `size - 1`.
- Out-of-bounds access is undefined.

- Arrays with static storage duration, such as a static array or a file-scope array, are initialized to zero if no explicit initializer is provided. Otherwise, local arrays contain garbage values.

- Accessing elements outside of array bounds leads to undefined behaviour. The program may crash, produce garbage values, memory corruption...

- When partially initializing array, the remaining elements are automatically set to zero.

### Multidimensional Arrays

```c
int matrix[3][4];
```

- C supports 2D and 3D arrays.
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
int n = 5;
int *arr = malloc(n * sizeof *arr);

if (arr != NULL) {
    arr[0] = 42;
    free(arr);
}
```

- `malloc(size)` allocates memory whose contents are uninitialized.
- `calloc(count, size)` allocates memory initialized to zero:
  ```c
  int n = 5;
  int *arr = calloc(n, sizeof *arr);
  if (arr != NULL) {
      /* Use arr[0] through arr[n - 1]. */
      free(arr);
  }
  ```
- Include `<stdlib.h>` to use `malloc`, `calloc`, `realloc`, and `free`.
- Check allocation results for `NULL` and release allocated memory with `free()` when no longer needed.
- Use dynamic allocation when the array size is determined at runtime or is too large for automatic storage.

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
- A local static array has static storage duration and is initialized to zero if no initializer is provided:
  ```c
  void example(void) {
      static int arr[5]; // initialized to zero
  }
  ```
- An array defined at file scope also has static storage duration and is initialized to zero if no initializer is provided:
  ```c
  int arr[5]; // global array
  ```

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

- A VLA's size is determined at runtime and its lifetime is limited to its block.
- Allowed in C99; support is optional in C11 and later, so not every C compiler supports VLAs.
- Example:
  ```c
  void example(int n) {
      int arr[n];
  }
  ```
- Use only with a valid positive size, and keep in mind that VLAs are typically allocated on the stack and large ones can exhaust it.

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

## Naming Conventions

C does not require one naming style for identifiers or files. Follow the conventions already used by a project; when starting a project, choose a consistent style. A common C style is:

| Item | Common convention | Examples |
|---|---|---|
| Source and header files | `snake_case` or `flatcase`; choose one and use it consistently | `array_utils.c`, `arrayutils.h` |
| Folders | `flatcase` | `src/`, `systemprogramming/` |
| Variables | `snake_case` | `item_count`, `buffer_size` |
| Functions | `snake_case` | `read_file()`, `calculate_total()` |
| Constants and macros | `UPPER_CASE`, with underscores between words | `MAX_BUFFER_SIZE`, `PI` |
| `struct` and `enum` tags | `snake_case` is a common C convention | `struct linked_list`, `enum file_mode` |
| Enumeration constants | `UPPER_CASE` is common, though project styles vary | `FILE_MODE_READ`, `FILE_MODE_WRITE` |

There is no single C standard that mandates `snake_case` for structure or enumeration tags; some projects use `PascalCase` instead. Match the surrounding codebase, and avoid mixing styles without a reason.

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
