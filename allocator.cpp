#include <iostream>
#include "allocator.h"

const size_t HEAP_SIZE = 1024;

// This is our fake heap memory.
static char heap[HEAP_SIZE];

// Head points to the first block in the heap.
static Block* head = nullptr;

// Sets up the heap as one big free block.
void initAllocator() {
    head = (Block*)heap;
    head->size = HEAP_SIZE - sizeof(Block);
    head->free = true;
    head->next = nullptr;
}

// Splits a big free block into one used block and one smaller free block.
void splitBlock(Block* block, size_t size) {
    // Make sure there is enough room for another Block header.
    if (block->size >= size + sizeof(Block) + 1) {
        Block* newBlock = (Block*)((char*)block + sizeof(Block) + size);

        newBlock->size = block->size - size - sizeof(Block);
        newBlock->free = true;
        newBlock->next = block->next;

        block->size = size;
        block->next = newBlock;
    }
}

// Finds space in the heap and returns a pointer to usable memory.
void* myMalloc(size_t size) {
    if (size == 0) {
        return nullptr;
    }

    if (head == nullptr) {
        initAllocator();
    }

    Block* current = head;

    while (current != nullptr) {
        if (current->free && current->size >= size) {
            splitBlock(current, size);
            current->free = false;

            // Return memory after the Block header.
            return (char*)current + sizeof(Block);
        }

        current = current->next;
    }

    // No block was large enough.
    return nullptr;
}

// Combines neighboring free blocks to reduce fragmentation.
void mergeFreeBlocks() {
    Block* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->free && current->next->free) {
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}

// Frees memory that was previously allocated.
void myFree(void* ptr) {
    if (ptr == nullptr) {
        return;
    }

    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->free = true;

    mergeFreeBlocks();
}

// Prints the current heap blocks.
void printHeap() {
    Block* current = head;
    int count = 1;

    std::cout << "\nHeap Blocks:\n";

    while (current != nullptr) {
        std::cout << "Block " << count << "\n";
        std::cout << "Size: " << current->size << " bytes\n";
        std::cout << "Free: " << (current->free ? "Yes" : "No") << "\n";
        std::cout << "-------------------\n";

        current = current->next;
        count++;
    }
}