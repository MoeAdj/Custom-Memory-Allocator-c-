#include <iostream>
#include "allocator.h"

int main() {
    initAllocator();

    std::cout << "Initial heap:";
    printHeap();

    int* a = (int*)myMalloc(sizeof(int));
    *a = 25;

    std::cout << "\nAfter allocating an int:";
    printHeap();

    char* b = (char*)myMalloc(100);

    std::cout << "\nAfter allocating 100 bytes:";
    printHeap();

    myFree(a);

    std::cout << "\nAfter freeing the int:";
    printHeap();

    double* c = (double*)myMalloc(sizeof(double));
    *c = 3.14;

    std::cout << "\nAfter allocating a double:";
    printHeap();

    myFree(b);
    myFree(c);

    std::cout << "\nAfter freeing everything:";
    printHeap();

    return 0;
}