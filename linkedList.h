#include <string>

class Node {

    private:
    
        std::string data;
        Node* nextNode;

    public:

        Node();
        Node(std::string);

        std::string getData();

    friend class LinkedList;

};

class LinkedList {

    private:

        Node* headNode;
        int size;

    public:

        LinkedList();
        ~LinkedList();

        void addToFront(std::string);

        int getSize();
        std::string getValue(std::string);
        bool containsValue(std::string);
        void printValues();

};