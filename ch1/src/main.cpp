#include <iostream>

#include "mylib.h"
#include "CIRCLE.h"



int main() {
    // mylib.h
    std::cout << addNum(3, 4) << std::endl;
    // CIRCLE.h
    CIRCLE c(2);
    c.GetArea();
    c.SetRadius(5);
    c.GetArea();
    return 0;  
}