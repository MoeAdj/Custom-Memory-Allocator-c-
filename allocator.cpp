#include <iostream>
#include "allocator.h"

cosnt size_t HEAP_SIZE = 1024;
static char heap[HEAP_SIZE];
static Block* head = nullptr;
Block* getHead() {
    return head;
}

void initALLOCATOR() {
    head = (Block*)heap;
    head->size = HEAP_SIZE - sizeof(Block);
    head->free = true;
    head->next = nullptr;
}

void printBlock(Block* b){
    std::cout <<"Size: " << b->size << std::endl;
    std::cout <<"free: " << b->free << std::endl;
    std::cout <<"next: " << b->next << std::endl;
}
