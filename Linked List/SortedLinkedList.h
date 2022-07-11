#pragma once
#include<stdlib.h>

struct LinkedListNode {
	int value;
	LinkedListNode* next;
};
class SortedLinkedList {
private:
	LinkedListNode* head;
public:
	SortedLinkedList() { head = NULL; }
	bool find(int x);      // Find x in the list
	void print();         // Print the elements of the list
	void add(int x);      // Add x to the list in sorted order
	void remove(int x);   // Remove x from the list (if it exists)

};