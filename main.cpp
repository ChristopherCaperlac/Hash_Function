/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): David Brown, Christopher Caperlac
Your team alias: Key and Value DC
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
#include "linkedList.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    HashTable* DC_Table = new HashTable(k);
    DC_Table->put(texts, n);

    cout << "==== Printing the contents of the first 5 slots ====" << endl;

    for (int i = 0; i < 5; i++) {
        printf("Slot %d: ", i);
        DC_Table->printSlot(i);
        cout << endl;
    }

    cout << "==== Printing the slot lengths ====" << endl;

    for (int i = 0; i < 5; i++) {
        printf("Slot %d: %d\n", i, DC_Table->getSlotSize(i));
    }

    cout << "==== Printing the standard deviation =====" << endl;

    printf("%f\n", DC_Table->getStdDev());

    return 0;
}
