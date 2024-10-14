#include <iostream>
#include <string>
#include "hash.h"

using namespace std;



Hash::Hash(string texts[], int slots, int size){
    map = new HashMap(slots);
    int index = 0;
    for(int i = 0; i < size; ++i){
        if(map!=nullptr){
            map->put(texts[i]);
        }
    }
}

Hash::~Hash(){
    delete map;
}

void Hash::printSlots(){
    for(int i = 0; i <= 4; ++i){
        printf("Slot %d: ", i);
        map->printSlot(i);
        cout << endl;
    }    
}

void Hash::printLengths(){
    for(int i = 0; i <= 4; ++i){
        int len = map->getSlotSize(i);
        printf("Slot %d: %d", i, len);
        cout << endl;
    }
}

void Hash::standardDeviation(){
    double dev = map->getStdDev();
    cout << dev << endl;
}



