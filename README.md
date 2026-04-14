- **`#include <stdio.h>`**: Includes the standard input/output library, providing functions like `printf` and `scanf`.
- Below program will compile without any issues. without `#include <stdio.h>`
- A blank line. C ignores extra spaces and blank lines, but we use them to make the code easier to read.

```c
int main()
{
    return 0;
}
```

## Compilation and Running

- Compile: `gcc helloworld.c -o helloworld`
- Run: `./helloworld`

### Why `main()` is Special:

- **Entry Point**: In C, `main()` is the predefined starting point of every executable program. When you run the program (e.g., `./helloworld`), the operating system automatically calls `main()` first. Without it, the compiler/linker won't know where to begin execution, and you'll get an error like "undefined reference to main".
- **Required by Standard**: The C language standard (ISO C) mandates `main()` as the entry function. It's not just any function—you can't rename it or omit it for console applications.
- **Curly Brackets `{}`**: These define the function body (scope). Code inside them runs sequentially when `main()` is called. The `return 0;` at the end signals successful execution to the OS.
- **Variants**: `main()` can take arguments (`int main(int argc, char *argv[])`) for command-line inputs, but the basic `int main()` works for simple programs.

### Why `return 0;`?

- **Convention for Success**: In C (and Unix-like systems), `0` means the program ran successfully without errors. The OS uses this to know if everything went well.
- **Required by `main()`**: `main()` must return an `int` (as per the C standard). If you omit `return 0;`, some compilers add it automatically, but it's good practice to include it explicitly.
- **Error Handling**: You can return non-zero values (e.g., `return 1;`) to indicate failures, which scripts or other programs can check.
- **No `return` at All**: If `main()` reaches the end without a `return`, it implicitly returns `0` in C99+, but always including it makes your code clear and portable.

## Escape Sequences

### What is `\n`?

The newline character (`\n`) is called an **escape sequence**, and it forces the cursor to change its position to the beginning of the next line on the screen. This results in a new line. For example:

```c
printf("Hello\nWorld");
```

This will output:

```
Hello
World
```

Without `\n`, both texts would appear on the same line.

ASCII value

### Keywords
1. break
2. switch
3. default
4. case
5. continue
6. do
7. while
8. if
9. else
10. goto
11. for
12. return
13. enum
14. signed
15. unsigned
16. static
17. struct
18. typedef
19. sizeof
20. void
21. union

### Data types

1. int - 4b
2. char - 1b
3. float - 4b
4. double - 8b
5. short - 2b
6. long - 8b

### Operators

1. Arithmetic - `+ - * / % ++ --`
2. Relational = `> < >= <= == !=`
3. Logical - `&& || !`
4. Assignement - ` += -= *= /= %= &= |= ^= <<= >>=`
5. Bitwise - `& | ^ ~ >> <<`
6. ternary, sizeof, comma

### Precedence

1.  () [] -> . (postfix)
2.  ! ~ ++ -- (cast) (unary)
3.  - / % (mult)
4.  - - (add)
5.  << >> (shift)
6.  < <= > >= (relational)
7.  == != (equality)
8.  & (bitwise AND)
9.  ^ (bitwise XOR)
10. | (bitwise OR)
11. && (logical AND)
12. || (logical OR)
13. ?: (ternary)
14. = += -= ... (assignment)

### Format Specifiers

1. %d - int
2. %i - int
3. %f - float
4. %c - char
5. %u - unsigned num
6. %s - string
7. %lf - double
8. %zu - size of the Datatype
9. %p - address of the variable

### Control Flow

1. if else
2. switch
3. for
4. while
5. do while
6. break
7. continue
8. goto
9. nested loop

## For Loop

```c
for(expression1; expression2; expression3){}
```

- Expression 1 is executed (one time) before the execution of the code block.
- Expression 2 defines the condition for executing the code block.
- Expression 3 is executed (every time) after the code block has been executed.

# continue

- skip this round but keep looping

### escape characters

1. \n
2. \t
3. \0
4. \"
5. \'
6. \\

### Strings

- When working with strings in scanf(), you must specify the size of the string/array (we used a very high number, but at least then we are certain it will store enough characters for the first name), and you don't have to use the reference operator (&).

```c
scanf("%s", firstName);

```

- However, the scanf() function has some limitations: it considers space (whitespace, tabs, etc) as a terminating character, which means that it can only display a single word (even if you type many words)

```c
gets(name,sizeof(name),stdin);
```

- Remember that strings in C are actually an array of characters, and unfortunately, you can't assign a value to an array like this:

### Pointers

- The memory address of the first element is the same as the name of the array

### Functions

```c
int func(paraneter1,parameter2..){}

int main(){
    func(argument, argument...);
}
```

### Functions

- Note that when you call the function, you only need to use the name of the array when passing it as an argument myFunction(myNumbers). However, the full declaration of the array is needed in the function parameter (int myNumbers[5]).
- An `inline function` is a small function that asks the compiler to insert its code directly where it is called, instead of jumping to it. This can make short, frequently used functions a little faster, because it removes the small delay of a normal function call.
- Function pointers can be passed to other functions - this is called a `callback`. It allows a function to call another function that you provide as input.

### File

# fopen modes

1. r - read only
2. w - write
3. a - append
4. r+ - read+write
5. w+ - write+read
6. a+ - append+read
7. rb - binary read(images)
8. wb - binary write

- `a` - add content to the end of a file without deleteing existing content
- `fgets` returns `NULL` when reached end of the file.

# file functions

1. fopen - open a file
2. fclose - close a file
3. fprintf - printf but to a file
4. fscanf - scanf but for a file
5. fgets -> (safer) read one line from a file into buffer. stops at newline
6. fgetc - read one byte from a file and return it as an int
7. fputs - write a string to a file. does not adda anewline automatically
8. fputc - write a single byte to a file.
9. fwrite - write a raw bytes to a file. Eg. struct, array, images, any raw data
10. fread - read raw bytes from a binary file into a buffer.
11. rewind - moves the cursor back to thte beginning of the file
12. perror - prints your message to stderr
13. fseek - to move a cursor across file
14. ftell - current position

### Structure and Unions

- In a struct, each member has its own memory.
- In a union, all members share the same memory, which means you can only use one of the values at a time.
- The size of a union will always be the same as the size of its largest member
- Padding means the compiler sometimes adds empty spaces inside a struct to keep things fast and properly aligned in memory.
- he compiler adds padding bytes so that the int member starts at a memory address that's a multiple of 4. This helps the CPU read it faster.
- Padding depends on the order of members in the struct. If you group larger types first, you can make the struct smaller.
- Unions store all members in the same memory location, so there is no padding between members

### Enum

- If assign a value to one specific item, next item will update their numbers accordingly
- Enum are often used in switch statements
- First item of enum has the value 0. The second has the value 1. and can easily change them

### MEMORY

- `Static memory` is memory that is reserved for variables `before` the program runs. Allocation of static memory is also known as `compile time `memory allocation.
- `Dynamic memory` is memory that is allocated `after` the program starts running. Allocation of dynamic memory can also be referred to as `runtime` memory allocation.
- A `memory leak` happens when dynamic memory is allocated but never freed.

1. malloc - allocation memory which measured in bytes. malloc() allocates uninitialized memory. The content will be undefined until you assign values. If you want memory initialized to zero, you can use calloc().
2. calloc - (allocation) automatically initializes the allocated memory to zero which is less efficient than malloc
3. realloc - reallocation
4. free - deallocation

# Stack Memory

- Stack memory is a type of dynamic memory which is reserved for variables that are declared inside function.
- when a function is called, stack memory is allocated for the varibales in the function. when the function returns stack memory is freed.
- Recursion that repeats itself too many times may take up too much stack memory. when that happens it is called `Stack oveflow`.

### Error

1. # Compile time error

- missing semicolon
- using undeclared variables
- mismatched data types

2. # run time error

- Dividing by zero
- accessing out of bounds array elements
- using freed memory

### Storage class

- Scope defines where a variable can be used, and storage classes define how long it lasts and where it's stored.

1. `auto` - The auto keyword is used for `local variables`. It is `default` for variables declared inside functions, so it's rarely
   used explicitly.

```c
auto int x = 50;  // Same as just: int x = 50;
```

2. `static` - Static local variables keep their value between function calls.
3. `register` - The register keyword suggests that the variable should be stored in a CPU register (for faster access)
4. `extern` - The extern keyword tells the compiler that a variable or function is defined in another file. It is commonly used when working with multiple source files.
