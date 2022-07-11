#include "SortedLinkedList.h"
#include<stdio.h>

bool SortedLinkedList::find(int x)
{
	LinkedListNode* p=head;
	while (p != NULL) {
		if (p->value == x)return true;
		p = p->next;
	}
	return false;
}

void SortedLinkedList::print()
{
	printf("List items: [");
	LinkedListNode* p = head;
	while (p != NULL) {
		printf("%d, ", p->value);
		p = p->next;
	}
	if (head != NULL) printf("\b\b");
	printf("]\n");
}

void SortedLinkedList::add(int x)
{
	// Allocate the new node
	LinkedListNode* node = new LinkedListNode();
	node->value = x;
	node->next = NULL;
	// Find the location where we should insert x
	LinkedListNode* q = NULL;
	LinkedListNode* p = head;
	while (p != NULL and x > p->value) {
		q = p;
		p = p->next;
	}
	// if the node inserted at the beginning
	if (q == NULL) {
		node->next = head;
		head = node;
	}
	else {
		node->next = q->next;
		q->next = node;
	}
}

// Add x to the list with double indirect pointer
//void SortedLinkedList::add(int x)
//{
//	// Allocate the new node
//	LinkedListNode* node = new LinkedListNode();
//	node->value = x;
//	node->next = NULL;
//	
//	LinkedListNode** p= &head;
//	while ((*p) != NULL and x > (*p)->value) {
//		p =&((*p)->next);
//	}
//	node->next = *p;
//	*p = node;
//}


void SortedLinkedList::remove(int x)
{ 
	// Walk over the list until we find the node that contains x
	LinkedListNode* q = NULL;
	LinkedListNode* p = head;

	while (p != NULL and p->value != x) {
		q = p;
		p = p->next;
	}
	if (p == NULL) { return ; } // x does not exist
	 // Remove p from the list
	if (q == NULL) head = p->next;
	else q->next = p->next;

	delete p; // To avoid memory leaks
}

// Remove x from the list with double indirect pointer
//void SortedLinkedList::remove(int x)
//{
//	// Walk over the list until we find the node that contains x
//	LinkedListNode** p = &head;
//
//	while (p != NULL and (*p)->value != x) {
//		p = &(*p)->next;
//	}
//	if (p == NULL) { return; } // x does not exist
//	 // Remove p from the list
//	LinkedListNode* tmp = *p;
//	*p = (*p)->next;
//
//	delete tmp; // To avoid memory leaks
//}