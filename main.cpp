#include<iostream>
#include<assert.h>
#include<string>
#include "LinkedList.h"
//
// CHRISTOPHER APODACA
// Doubly Linked List Full Implementation Test
//

using std::endl;
using std::cout;
using std::string;

//
// NOTE: ASSERTIONS ONLY LOG TO CONSOLE
//       WHEN THEY FAIL!
//
const int TEST_LENGTH = 5;

int main(){

  LinkedList<int> mylist; 
  mylist.listAppend(1);
  mylist.listAppend(2);
  mylist.listAppend(3);
  mylist.listAppend(4);
  mylist.listAppend(5);
  mylist.listAppend(6);

  mylist.printList();
  return 0;
}

