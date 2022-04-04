#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H
#include <map>

class EfficientTruckloads {

    public:
        int numTrucks(int numCrates, int loadSize);
        int numTrucksHelper(int numCrates, int loadSize, std::map<int, int>* lookupMapPtr);
};

#endif
