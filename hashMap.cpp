#include "hashMap.h"

HashMap::HashMap(int numOfSlots) {
  this->slotList = new LinkedList*[numOfSlots];
  for (int i = 0; i < numOfSlots; i++) {
    this->slotList[i] = new LinkedList();
  }
  this->numOfSlots = numOfSlots;
}

HashMap::~HashMap() {
  for (int i = 0; i < numOfSlots; i++) {
    delete[] this->slotList[i];
  }
  delete[] this->slotList;
}

int HashMap::hashFunction(std::string inputString) {
  // TODO: Implement function
  return 0;
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
  // TODO: Implement function
  return 0;
}