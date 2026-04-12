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

### Data types

1. int - 4b
2. char - 1b
3. float - 4b
4. double - 8b
5. const
6. short - 2b
7. long - 8b

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
