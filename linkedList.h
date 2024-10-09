#include <string>

class Node {

    private:
    
        std::string data;
        Node* nextNode;

    public:

        Node();
        Node(std::string);

        std::string getData();

};

class LinkedList {

    private:

        Node* headNode;
        int size;

    public:

        LinkedList();
        ~LinkedList();

        void addToFront(std::string);

        std::string getValue(std::string);

};