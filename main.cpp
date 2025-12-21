#include <iostream>
#include "allocator.h"

int main() {
    initALLOCATOR();

    Block* b = getHead();
    if (b != nullptr){
        printBlock(b);
    } else {
        std::cout << " No blocks yet!" << std::endl;
    }
  return 0;
    
}
