#pragma once

#ifndef HASHMAP_H
#define HASHMAP_H
#include "linkedList.h"

class HashMap {

  private:
    
    LinkedList** slotList;
    int numOfSlots;
    int hashFunction(std::string);

  public:
    
    HashMap(int);
    ~HashMap();

    void put(std::string);
    void put(std::string[], int);

    void printSlot(int);
    
    int getSlotSize(int);
    double getStdDev();

};

#endif