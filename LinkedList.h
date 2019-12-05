#pragma once 

template<typename T>
class Node
{
  public:
    Node();
    Node(T value, Node<T>* nextNode);
    T data;            
    Node<T>* next;
};

template<typename T>
class LinkedList
{
  public:
    LinkedList();
    Node<T>* getHead() const;  // return the head pointer
    Node<T>* getTail() const;  // returns the tail pointer
    Node<T>* search( T value ) const; // returns a pointer to the element if found, otherwise returns NULL
    void listAppend(T value);  // inserts an element at the end of the list
    void listPrepend(T value); //inserts a n element at the head of the list
    void insertAfter(Node<T>* curNode, T value); // Insert value after the curNode
    void removeAfter(Node<T>* curNode); // remove Node after CurNode
    void removeHead();  // Removes the first element
    void removeTail();  // removes the last element
    void printList() const;  // print the elements of the linked list

    int getLength() const; // Returns the length of List

  private:
    Node<T>* head; 
    Node<T>* tail;
};

#include "LinkedList.cpp"

