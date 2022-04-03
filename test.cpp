#include <string>
#include <iostream>
#include <vector>
#include <array>

int main(void){

    std::vector<std::array<int, 2>> v {
        {0, 0},
        {0, 0},
        {0, 0}
    };

    v[0] = {0, 1};
    v[3][0] = 0;

    std::cout << v.size();

    std::cout << v[0][0];
    std::cout << v[0][1];
    std::cout << v[3][0];
    //std::cout << v[3][1];

    return 0;
}