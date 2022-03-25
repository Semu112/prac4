#ifndef REVERSE_H
#define REVERSE_H

#include <string>

class Reverse {

    public: 

        std::string reverseString(std::string letters);
        int reverseDigit(int value);

    private:
        std::string reverseStringHelper(std::string letters, int n);
        std::string reverseDigitHelper(int value);

};

#endif