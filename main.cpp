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

    // std::cin >> i;
    // std::cin >> s;
    // std::cin >> numCrates;
    // std::cin >> loadSize;

    //loadSize must be less than numCrates-1

    i = 12345;
    s = "avalanche";
    numCrates = 10;
    loadSize = 9;

    std::cout << "input: " << i << " " << " " << s << " " << numCrates << " " << loadSize << std::endl;
    std::cout << r.reverseDigit(i) << " " <<  r.reverseString(s) << " " << t.numTrucks(numCrates, loadSize) << " " << et.numTrucks(numCrates, loadSize) << std::endl;


    return 0;
}