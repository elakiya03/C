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
List of operators