#include "DoublyLinkedList.h"
#include <stdexcept>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer; trailer.prev = &header;
  if (!dll.isEmpty()) {
	  DListNode* node;
	  node = dll.getFirst();
	  while (node != dll.getAfterLast()) {
		  insertLast(node->obj);//insert new element
		  node = node->next;//set node to next node
	  }
  }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list
	DListNode *prev_node, *node = header.next;
	while (node != &trailer) {
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
	// Copy from dll

	if (!dll.isEmpty()) {
		node = dll.getFirst();
		while (node != dll.getAfterLast()) {
			insertLast(node->obj);//insert new element
			node = node->next;//set node to next node
		}
	}
	return *this;
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{ 
	DListNode *newNode = new DListNode(newobj, &header,
		header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
	DListNode *newNode = new DListNode(newobj, trailer.prev,
		&trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{ 
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = header.next;
	node->next->prev = &header;
	header.next = node->next;
	int obj = node->obj;
	delete node;
	return obj;
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	int obj = node->obj;
	delete node;
	return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
	DListNode *prev_node, *node = header.next;
	while (node != &trailer) {
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const
{ 
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	return header.next->obj;
}

// return the last object
int DoublyLinkedList::last() const
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	return trailer.prev->obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(const DListNode &p, int newobj) {	
	DListNode *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	DListNode *newNode = new DListNode(newobj, node,
		node->next);
	node->next->prev = newNode;
	node->next = newNode;
	
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(const DListNode &p, int newobj)
{
	DListNode *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	DListNode *newNode = new DListNode(newobj, node->prev,
		node);
	node->prev->next = newNode;
	node->prev = newNode;
}

// remove the node after the node p
int DoublyLinkedList::removeAfter(const DListNode &p)
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	node = node->next;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	int obj = node->obj;
	delete node;
	return obj;
}

// remove the node before the node p
int DoublyLinkedList::removeBefore(const DListNode &p)
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = header.next;
	while (node != &p) {
		node = node->next;
	}
	node = node->prev;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	int obj = node->obj;
	delete node;
	return obj;
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
	DListNode *current = dll.getFirst();
	int count = 0;
	while (current != dll.getAfterLast()) {
		count++;
		current = current->next; //iterate
	}
	return count;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
	DListNode* temp = dll.getFirst();
	while (temp != dll.getAfterLast()) {//use address to compare pointers
		out << temp->obj << " ";
		temp = temp->next;
	}
  return out;
}
