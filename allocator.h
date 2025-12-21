#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

struct Block {
    size_t size;
    bool free;
    Block* next;

};

Block* getHead();
void initALLOCATOR();
void printBlock(Block* b);



#endif
