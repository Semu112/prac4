#include "Reverse.h"
#include "Truckloads.h"
#include "EfficientTruckloads.h"
#include <iostream>

int main(void){

    Truckloads t;
    EfficientTruckloads et;
    Reverse r;

    std::cout << t.numTrucks(10, 4) << std::endl;

    std::cout << r.reverseDigit(-123) << std::endl;
    std::cout << r.reverseString("asdfghjklqwertyuiopzxcvbnm") << std::endl;

    std::cout << et.numTrucks(1024, 5) << std::endl;


    return 0;
}