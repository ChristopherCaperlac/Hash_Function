#include <iostream>
#include <string>
#include <cmath>
#include "hashMap.h"
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

class Hash {
    private:
        HashMap* map;

    public:

        Hash(string[], int, int);
        ~Hash();

        void printSlots();
        void printLengths();
        void standardDeviation();

};