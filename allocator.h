#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

struct Block {
    size_t size;
    bool free;
    Block* next;
};

void initALLOCATOR();
void printBlock(Block* b);



#endif
