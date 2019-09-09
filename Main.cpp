#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList dll;
  cout << "list: " << dll << endl << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertLast(i);
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl << endl;

  // more testing...
  // Insert a node after a speific node with value 1212
  cout << "Insert a node after the second node with value 1212" << endl;
  DoublyLinkedList dll_ia(dll2);
  cout << "list: " << dll_ia << endl;
  DListNode *node1 = dll_ia.getFirst()->next;
  dll_ia.insertAfter(*node1, 1212);
  cout << "list: " << dll_ia << endl << endl;
  
  //insertBefore
  // Insert a node after a speific node with value 1313
  cout << "Insert a node before the second node with value 1313" << endl;
  DoublyLinkedList dll_ib(dll2);
  cout << "list: " << dll_ib << endl;
  DListNode *node2 = dll_ib.getFirst()->next;
  dll_ib.insertBefore(*node2, 1313);
  cout << "list: " << dll_ib << endl << endl;

  // removeAfter
  cout << "Remove node after second node" << endl;
  DoublyLinkedList dll_ra(dll2);
  cout << "list: " << dll_ra << endl;
  DListNode *node3 = dll_ra.getFirst()->next;
  dll_ra.removeAfter(*node3);
  cout << "list: " << dll_ra << endl << endl;

  //removeBefore
  cout << "Remove node before second node" << endl;
  DoublyLinkedList dll_rb(dll2);
  cout << "list: " << dll_rb << endl;
  DListNode *node4 = dll_rb.getFirst()->next;
  dll_rb.removeBefore(*node4);
  cout << "list: " << dll_rb << endl << endl;

  // add tests for DoublyLinkedListLength
  cout << "Display the length of a DLL (dll3 in this case)" << endl;
  cout << "Length: " << DoublyLinkedListLength(dll3) << endl;
  
  cin.get();

  return 0;
}
