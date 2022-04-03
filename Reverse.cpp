#include "Reverse.h"

#include <iostream>

std::string Reverse::reverseString(std::string letters){

    return reverseStringHelper(letters, letters.length());

}

std::string Reverse::reverseStringHelper(std::string letters, int n){

    //n should start at string.length then go to 1. Once at one, should return the string

    if(n<=1){
        return letters;
    }

    //for case hithere ---not done like this---
    /*
    returns e
    returns er
    returns ere
    returns ereh
    returns ereht
    returns erehti
    returns erehtih
    */
    //Also could do it like this ---done like this---
    /*
    returns ehither
    returns erhithe
    returns erehith
    returns erehhit
    retutns erehthi
    returns erehtih
    */


    //#3 
    /*
    1. Takes in hithere, 7 
    2. Returns e + (reverseStringHelper(hither, 6)
                3. Takes in hither, 6
                4. Returns r + reverseString helper(hithe, 5)
                                5. Takes in hithe, 5
                                6. Returns e + reverseStringHelper(hith, 4)
                                                7. Returns h + reverseStringHelper(hit, 3)
                                                                8. Returns t + reverseStringHelper(hi, 2)
                                                                                9. Returns i + reverseStringHelper(h, 1)
                                                                                                Returns h
    */

    //I think the 7th character is the null character
    //Note that in string.substr(0, n-1) the substring does not include the n-1th character
    return letters.at(n-1) + reverseStringHelper(letters.substr(0,n-1), n-1);

}

int Reverse::reverseDigit(int value){
    if(value >= 0){
        return stoi(reverseDigitHelper(value));
    }
    else{
        std::cout << "This is not set up to work for negative numbers" << std::endl;
        return -1;
    }
}

std::string Reverse::reverseDigitHelper(int value){

    if (value%10 == value){
        return std::to_string(value);
    }
    //For case 123
    /*
    123%10=3
    123%100-3/10=2
    123-23/100=1
    */

    /*
    1. takes (123)
    2. returns (3 + reverseDigitHelper((123-123%10)/10))
    2. returns (3 + reverseDigitHelper((123-3)/10))
    2. returns (3 + reverseDigitHelper(12)

                    3. returns 2 + reverseDigitHelper((12-12%10)/10)
                    3. returns 2 + reverseDigitHelper(1)

                                    4. returns 1
    */

    return std::to_string(value%10) + reverseDigitHelper((value-value%10)/10);
}