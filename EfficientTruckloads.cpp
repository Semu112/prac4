#include "EfficientTruckloads.h"
#include <math.h>
#include <iostream>

int EfficientTruckloads::numTrucks(int numCrates, int loadSize){

    std::map<int, int> lookupMap;

    if(numCrates < 2){
        std::cout << "Program only set up for number of crates greater than or equal to 2" << std::endl;
        return -1;
    }
    else if(loadSize < 1 || loadSize > numCrates-1){
        std::cout << "Program only set up for loadSize between 1 and numCrates-1 inclusive" << std::endl;
        return -1;
    }
    else{
        return numTrucksHelper(numCrates, loadSize, &lookupMap);
    }
}

int EfficientTruckloads::numTrucksHelper(int numCrates, int loadSize, std::map<int, int>* lookupMap){ 

    /*
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
    */

    //Is it in lookupMap? If so, return that
    std::cout << "@" << numCrates << ": " << lookupMap->find(numCrates)->second << std::endl;
    if(lookupMap->find(numCrates) != lookupMap->end()){
        std::cout << "found " << lookupMap->find(numCrates)->first << " in the map" << std::endl;
        return lookupMap->find(numCrates)->second;
    }
    else{

        std::cout << "couldn't find " << numCrates << " in the map" << std::endl;

        if(numCrates<=loadSize){
            lookupMap->insert({numCrates, 1});
            std::cout << "lookup map at " << numCrates << " updated to 1" << std::endl;
            return 1;
        } 

        //Add to lookupMap
        //If ceil(numCrates/2.0) && floor(numCrates/2.0) are both in lookupMap, add ceil(numCrates/2.0) + floor(numCrates/2.0) as lookupMap[numCrates] entry
        std::cout << "Dividing: " << numCrates << "/2.0" << std::endl;
        int ceil = std::ceil(numCrates/2.0);
        int floor = std::floor(numCrates/2.0);
        std::cout << "at ceil(" << ceil << "): " << lookupMap->find(ceil)->second << std::endl;
        std::cout << "at floor(" << floor << "): " << lookupMap->find(floor)->second << std::endl;
        if((lookupMap->find(ceil) != lookupMap->end()) && (lookupMap->find(floor) != lookupMap->end())){
            std::cout << "found " << lookupMap->find(ceil)->first << " and " << lookupMap->find(floor)->first << " in the map" << std::endl;
            lookupMap->insert({numCrates, lookupMap->find(ceil)->second + lookupMap->find(floor)->second});
            std::cout << "updated " << numCrates << " to " << lookupMap->find(ceil)->second << " + " << lookupMap->find(floor)->second << std::endl;
            return lookupMap->find(numCrates)->second;
        }
        else{
            std::cout << "numCrates: " << numCrates << std::endl;
            return numTrucksHelper(ceil, loadSize, lookupMap) + numTrucksHelper(floor, loadSize, lookupMap);
        }
    }
}