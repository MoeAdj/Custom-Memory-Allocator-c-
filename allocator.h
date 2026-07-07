#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

struct Block {
    size_t size;     // how many usable bytes this block has
    bool free;       // true if available, false if taken
    Block* next;     // next block in the linked list
};

void initAllocator();
void* myMalloc(size_t size);
void myFree(void* ptr);
void printHeap();

#endif