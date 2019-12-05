#include "LinkedList.h"
#include<iostream>

// NODE
// Implements a simple Data Node for LL()
//
template<typename T>
Node<T>::Node(){
  this->data = NULL;
  this->next = nullptr;
  this->prev = nullptr;
}

template<typename T>
Node<T>::Node( T value, Node<T>* prevNode, Node<T>* nextNode){
  this->data = value;
  this->next = nextNode;
  this->prev = prevNode;
}


// LINKED_LIST
// Implements a simple LL
//
template<typename T>
LinkedList<T>::LinkedList(){
  this->head = nullptr;
  this->tail = nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::getHead() const{
  return this->head;
}

template<typename T>
Node<T>* LinkedList<T>::getTail() const{
  return this->tail;
}

template<typename T>
Node<T>* LinkedList<T>::search( T value ) const{

  Node<T> * current = this->head;
  bool isFound = false;

  while( current != nullptr ){
    if( current->data == value ){
      isFound = true;
      break;
    }
    current = current->next;
  }

  return (isFound) ? current : NULL;
}

template<typename T>
int LinkedList<T>::getLength() const{
   Node<T>* current = this->head;
   int count = 0;

   while( current != NULL ){
     count++;
     current = current->next;
   }

   return count;
}

template<typename T>
void LinkedList<T>::listAppend( T value ){
   Node<T> *newborn = new Node<T>( value, nullptr, nullptr );

   if( this->head == nullptr ){
     this->head = newborn;
     this->tail = newborn;
     return;
   }

   newborn->prev = this->tail;
   this->tail->next = newborn;
   this->tail = newborn;
}

template<typename T>
void LinkedList<T>::listPrepend( T value ){

  Node<T>* newborn = new Node<T>( value, nullptr, nullptr ); 

  if( this->head == nullptr ){
    this->tail = newborn;
  }else{
    this->head->prev = newborn;
  }

  newborn->next = this->head;
  this->head = newborn;
}

template<typename T>
void LinkedList<T>::insertAfter( Node<T>* node, T value ){

  Node<T>* newborn = new Node<T>( value, nullptr, nullptr ); 

  //Traverse list, find node, insert newborn
  //if newborn is new tail, update tail
  //if we reach tail, we are done
  Node<T>* current = this->head;
  bool isFound = false;

  while( current != nullptr ){
    if( current == node ){
      isFound = true;
      break;
    }
    current = current->next;
  }
   
  if( isFound ){
    if( current == this->tail ){
     this->listAppend( value );
    }else{
      newborn->next = current->next;
      current->next = newborn;
      newborn->next->prev = newborn;
      newborn->prev = current;
    }
  }
}

template<typename T>
void LinkedList<T>::removeAfter( Node<T>* node ){
  Node<T>* current = this->head;
  bool isFound = false;

  while( current != nullptr ){
    if( current == node ){
      isFound = true;
      break;
    }
    current = current->next;
  }

  if( isFound ){
    if( this->getLength() > 1 && current != this->tail ){
      if( current->next == this->tail ){
        current->next    = nullptr;
        this->tail->prev = nullptr;
        this->tail       = current;
      }else
        current->next = current->next->next;
        current->next->prev = current;
    }
  }
}

template<typename T>
void LinkedList<T>::removeHead(){

  if( this->head == nullptr )
    return;

  if( this->head == this->tail )
    this->head = this->tail = nullptr;
  else{
    this->head = this->head->next;
    this->head->prev = nullptr;
  }
}

template<typename T>
void LinkedList<T>::removeTail(){

  if( this->head == nullptr )
    return;

  if( this->head == this->tail ){
    this->head = this->tail = nullptr;
    return;
  }

  Node<T> * current = this->head;
  while( current->next != this->tail ){
    current = current->next;
  }

  this->tail = current;
  current->next = nullptr;
}

template<typename T>
void LinkedList<T>::printList() const{
  Node<T> * current = this->head;

  while( current != nullptr ){
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}





