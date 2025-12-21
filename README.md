# Custom-Memory-Allocator (c++)

this project implements a simple custom memory allocator similar to "malloc" and "free".
the allocator manages a fixed size memory buffer and supports allocation, deallocation, and reuse of freed memory blocks.

Core features (MVP) :
1- Allocate memory from a fixed buffer. 
2- Free memory.
3- Reuse freed blocks.
4- track block sizes.

## Goals
understand heap memory management
practice pointer arithmetic
learn how allocators track free and used blocks

## Features
fixed size heap buffer
first fit allocation strategy
block splitting
block reuse

## how to run
g++ main.cpp allocator.cpp -o allocator
/.allocator
