#include "hash.h"
#include <cmath>


HashTable::HashTable(int numOfSlots) {

  this->slotList = new LinkedList*[numOfSlots];
  for (int i = 0; i < numOfSlots; i++) {
    this->slotList[i] = new LinkedList();
  }
  this->numOfSlots = numOfSlots;

}

HashTable::~HashTable() {

  for (int i = 0; i < numOfSlots; i++) {
    delete this->slotList[i];
  }
  delete[] this->slotList;

}

int HashTable::hashFunction(std::string text) {

  unsigned long hashValue = 17;

  for (char c : text) {
    hashValue = hashValue ^ c;
  }

  int textLength = text.size();
  hashValue += (13 * textLength);

  return hashValue % numOfSlots;
  
}

void HashTable::put(std::string inputString) {
  int slotIndex = this->hashFunction(inputString);
  LinkedList* slot = this->slotList[slotIndex];
  slot->addToFront(inputString);
}

void HashTable::put(std::string tokens[], int numOfTokens) {
  for (int i = 0; i < numOfTokens; i++) {
      this->put(tokens[i]);
  }
}

void HashTable::printSlot(int slotIndex) {
  LinkedList* slot = this->slotList[slotIndex];
  slot->printValues();
}

int HashTable::getSlotSize(int slotIndex) {
  LinkedList* slot = this->slotList[slotIndex];
  return slot->getSize();
}

double HashTable::getStdDev() {

  double mean = 0;
  double variance = 0;
  double stdDev = 0;

  // Calculating Mean of Slots
  for (int i = 0; i < numOfSlots; i++) {
    mean += double(getSlotSize(i));
  }
  mean /= numOfSlots;

  // Variance
  for (int i = 0; i < numOfSlots; i++) {
    variance += pow(getSlotSize(i) - mean, 2.0);
  }
  variance /= numOfSlots;
  // Standard Deviation
  stdDev = sqrt(variance);

  return stdDev;

}