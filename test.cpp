#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

int main(void){

    int numCrates = 5;
    int number = numCrates;

    double numberDividedByTwo = number/2.0;

    std::cout << numberDividedByTwo << std::endl;

    int spinOff1 = std::ceil(numberDividedByTwo);
    int spinOff2 = std::floor(numberDividedByTwo);

    std::cout << spinOff1 << std::endl;
    std::cout << spinOff2 << std::endl;

    return 0;
}