#include "Reverse.h"
#include "Truckloads.h"
#include "EfficientTruckloads.h"
#include <iostream>

int main(void){

    Truckloads t;
    EfficientTruckloads et;
    Reverse r;

    int i;
    std::string s;
    int numCrates;
    int loadSize;

    std::cin >> i;
    std::cin >> s;
    std::cin >> numCrates;
    std::cin >> loadSize;

    std::cout << r.reverseDigit(i) << " " <<  r.reverseString(s) << " " << t.numTrucks(numCrates, loadSize) << " " << et.numTrucks(numCrates, loadSize);


    return 0;
}