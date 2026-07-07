# Custom Memory Allocator (C++)

A simple custom memory allocator implemented in C++ that mimics the basic behavior of `malloc()` and `free()`. The allocator manages a fixed-size heap buffer and supports allocating, freeing, splitting, and reusing memory blocks.

---

## Overview

This project demonstrates the fundamentals of dynamic memory management by implementing a custom allocator without relying on the standard library's memory allocation functions.

The allocator maintains a linked list of memory blocks and uses a **first-fit allocation strategy** to efficiently locate available memory.

---

## Features

- Fixed-size heap buffer
- First-fit allocation strategy
- Dynamic memory allocation (`myMalloc`)
- Memory deallocation (`myFree`)
- Reuse of freed memory blocks
- Block splitting to reduce wasted space
- Coalescing (merging) adjacent free blocks
- Block metadata tracking (size, allocation status, next pointer)

---

## Learning Objectives

This project was built to better understand:

- Heap memory management
- Dynamic memory allocation
- Pointer arithmetic
- Linked lists
- Memory fragmentation
- Block splitting and coalescing
- How `malloc()` and `free()` work internally

---

## Project Structure

```
.
├── allocator.cpp
├── allocator.h
├── main.cpp
└── README.md
```

---

## How It Works

1. Initialize a fixed-size heap.
2. Search for a free block using the **First-Fit** algorithm.
3. If the block is larger than requested, split it into two blocks.
4. Return the usable memory to the caller.
5. When memory is freed, mark the block as available.
6. Merge neighboring free blocks to reduce fragmentation.

---

## Build and Run

Compile:

```bash
g++ main.cpp allocator.cpp -o allocator
```

Run:

```bash
./allocator
```

---

## Example

```cpp
int* a = (int*)myMalloc(sizeof(int));
char* b = (char*)myMalloc(100);

myFree(a);

double* c = (double*)myMalloc(sizeof(double));

myFree(b);
myFree(c);
```

---
## terminal output 

<img width="1440" height="900" alt="Screenshot 2026-07-07 at 7 28 01 PM" src="https://github.com/user-attachments/assets/2bf90efd-94f3-4d48-a922-46e08f1faed8" />



## Future Improvements

- Best-fit allocation strategy
- Next-fit allocation strategy
- Memory alignment
- `calloc()` implementation
- `realloc()` implementation
- Heap statistics
- Thread-safe allocator
