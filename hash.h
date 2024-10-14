#pragma once

#ifndef HASH_H
#define HASH_H
#include "linkedList.h"

class HashTable {

  private:
    
    LinkedList** slotList;
    int numOfSlots;
    int hashFunction(std::string);

  public:
    
    HashTable(int);
    ~HashTable();

    void put(std::string);
    void put(std::string[], int);

    void printSlot(int);
    
    int getSlotSize(int);
    double getStdDev();

};

#endif