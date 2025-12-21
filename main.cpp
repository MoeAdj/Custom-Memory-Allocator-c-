#include <iostream>
#include "allocator.h"

int main() {
    initALLOCATOR();
    if (head != nullptr){
        printBlock(head);
    } else {
        std::cout << " No blocks yet!" << std::endl;
    }
  return 0;
    
}
