#include "Truckloads.h"
#include <cmath>
#include <iostream>

int Truckloads::numTrucks(int numCrates, int loadSize){
    if(numCrates < 2 || numCrates > 10000){
        std::cout << "Program only set up for number of crates between 2 and 10000 inclusive" << std::endl;
        return -1;
    }
    else if(!(loadSize >= 1) || !(loadSize <= numCrates-1)){
        std::cout << "Program only set up for loadSize between 1 and numCrates-1 inclusive" << std::endl;
        return -1;
    }
    else{
        return numTrucksHelper(numCrates, loadSize);
    }
}

int Truckloads::numTrucksHelper(int numCrates, int loadSize){

    //Old way
    //checks if numCrates is less than loadSize
    //If it isn't, returns 1 + numTrucks(numCrates-loadSize, loadSize)

    //New way
    //checks if numCrates is less than loadSize
    //If it isn't, creates two piles, one rounded to the ceiling and one to the floor
    //Test case: 10 if loadsize is 1
    //                      10
    //                   5          5
    //               3     2     3      2
    //             2  1  1   1  2   1   1   1
    //            1 1          1 1  

    //takes(10, 1)
    //returns: numTrucks(5, 1) + numTrucks(5, 1) = 5 + 5 = 10

    //takes(5, 1) and (5, 1)
    //_EACH (5, 1): 
        //returns: numTrucks(3, 1) + numTrucks(2, 1) = 3 + 2 = 5

        //takes(3, 1) and (2, 1)
        //(2, 1):
        //returns: numTrucks(1, 1) + numTrucks(1, 1) = 1 + 1 = 2
        //(3, 1):
        //returns: numTrucks(2, 1) + numTrucks(1, 1) = numTrucks(2, 1) + 1 = 2 + 1 = 3

        //takes(2, 1)
        //returns: numTrucks(1, 1) + numTrucks(1, 1)
        //returns: 1 + 1=2
    


    if(numCrates<=loadSize){
        return 1;
    } 
    else{
        return numTrucksHelper(std::ceil(numCrates/2.0), loadSize) + numTrucksHelper(std::floor(numCrates/2.0), loadSize);
    }
}