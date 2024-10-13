#include "linkedList.h"

Node::Node() {
  this->data = nullptr;
  this->nextNode = nullptr;
}

Node::Node(std::string inputString) {
  this->data = inputString;
  this->nextNode = nullptr;
}

std::string Node::getData() {
  return this->data;
}

LinkedList::LinkedList() {
  this->headNode = nullptr;
  size = 0;
}

LinkedList::~LinkedList() {

  Node* currentNode = this->headNode;
  for (int i = 0; i < size; i++) {
    Node* nextNode = currentNode->nextNode;
    delete currentNode;
    currentNode = nextNode;
  }

}

void LinkedList::addToFront(std::string inputString) {
  
  Node* newHeadNode = new Node(inputString);

  if (size != 0)
    newHeadNode->nextNode = this->headNode;
  
  this->headNode = newHeadNode;
  size++;

}

std::string LinkedList::getValue(std::string keyString) {

  Node* currentNode = this->headNode;
  std::string valueString = nullptr;

  for (int i = 0; i < size; i++) {
    valueString = currentNode->data;
    if (keyString == valueString)
      return valueString;
    currentNode = currentNode->nextNode;
  }

  return nullptr;

}

bool LinkedList::containsValue(std::string keyString) {

  Node* currentNode = this->headNode;
  std::string valueString = nullptr;

  for (int i = 0; i < size; i++) {
    valueString = currentNode->data;
    if (keyString == valueString)
      return true;
    currentNode = currentNode->nextNode;
  }

  return false;

}