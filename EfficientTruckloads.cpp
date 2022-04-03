#include "EfficientTruckloads.h"
#include <math.h>
#include <vector>

int EfficientTruckloads::numTrucks(int numCrates, int loadSize){
    //If numCrates is more than loadSize, splits crates into two piles
    //Returns the number of trucks needed for each pile added together

    std::vector<int[2]> lookupTable;
    if(lookupTable[numCrates][1] != 0){
        return lookupTable[numCrates][1];
    }

    if(numCrates<=loadSize){
        return 1;
    } 
    else{
        return numTrucks(numCrates/2, loadSize) + numTrucks(std::ceil(numCrates/2), loadSize);
    }
}