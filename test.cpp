#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <map>

int main(void){

    std::map<int, int>* m;

    m[1]* = 2;

    std::cout << m.find(1)->second << std::endl;

    if(m.find(1) != m.end()){
        std::cout << "found" << std::endl;
    }

    return 0;
}