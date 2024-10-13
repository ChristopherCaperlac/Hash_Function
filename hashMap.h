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

    void printSlot(int);
    
    int getSlotSize(int);
    double getStdDev();

};