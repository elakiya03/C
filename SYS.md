### Functions have memory address

1. function code - text segment
2. function local variables - stack
3. stack memory grow downwards

### Stack

1. local variables dies after function ends

### heap

1. Memory statys even after function ends. must freed.

### Segmentation fault (crash )

# p points to garbage -> invalid memory

```c
int *p;
*p = 10;   // ❌ crash
```

# NULL cannot be accessed

```c
int *p = NULL;
*p = 10;   // ❌ crash
```

# Using freed memory

```c
int *p = malloc(sizeof(int));
free(p);
*p = 10;   // ❌ crash
```

### Memory Leak

- memory still exists but cant access it - leak

  ```c
  int *p = malloc(sizeof(int));
  p = NULL;   // ❌ lost reference
  ```

  System Calls

  A system call is how program talks to OS

  code -> sys call -> os(kernel mode) -> hardware

Flags
1. O_CREAT   → create file if not exists  
2. O_WRONLY  → open for writing  
3. O_TRUNC   → clear file if already exists  
4. O_APPEND
