#include "Truckloads.h"

int TruckLoads::numTrucks(int numCrates, int loadSize){
    //checks if numCrates is less than loadSize
    //If it isn't, returns 1 + numTrucks(numCrates-loadSize, loadSize)


    if(numCrates<=loadSize){
        return 1;
    } 
    else{
        return 1 + numTrucks(numCrates-loadSize, loadSize);
    }
}