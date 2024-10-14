#include "hashMap.h"
#include <cmath>


HashMap::HashMap(int numOfSlots) {
  this->slotList = new LinkedList*[numOfSlots];
  for (int i = 0; i < numOfSlots; i++) {
    this->slotList[i] = new LinkedList();
  }
  this->numOfSlots = numOfSlots;
}

HashMap::~HashMap() {
  for (int i = 0; i < numOfSlots; i++) {
    if(this->slotList[i] != nullptr) {
      delete this->slotList[i];
    }
  }
  delete[] this->slotList;
  this->slotList = nullptr;
}

int HashMap::hashFunction(std::string text) {
  unsigned long hashValue = 17;

  for (char c : text) {
    hashValue = hashValue ^ c;
  }

  int textLength = text.size();
  hashValue += (13 * textLength);

  return hashValue % numOfSlots;
}

void HashMap::put(std::string inputString) {
  int slotIndex = this->hashFunction(inputString);
  LinkedList* slot = this->slotList[slotIndex];
  slot->addToFront(inputString);
}

void HashMap::printSlot(int slotIndex) {
  LinkedList* slot = this->slotList[slotIndex];
  slot->printValues();
}

int HashMap::getSlotSize(int slotIndex) {
  LinkedList* slot = this->slotList[slotIndex];
  return slot->getSize();
}

double HashMap::getStdDev() {
  double mean = 0;
  double variance = 0;
  double stdDev = 0;

  // Calculating Mean of Slots
  for(int i = 0; i < numOfSlots; ++i){
    mean += double(getSlotSize(i));
  }
  mean /= numOfSlots;

  // Variance
  for(int i = 0; i < numOfSlots; ++i){
    variance += pow(getSlotSize(i) - mean, 2.0);
  }
  variance /= numOfSlots;
  // Standard Deviation
  stdDev = sqrt(variance);

  return stdDev;
}