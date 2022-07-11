#include"SortedLinkedList.h"
#include<stdio.h>
void SortedLinkedListTest() {
	SortedLinkedList list;
	printf("Adding 9...\n");
	list.add(9);
	list.print();

	printf("Adding 15...\n");
	list.add(15);
	list.print();

	printf("Adding 3...\n");
	list.add(3);
	list.print();

	printf("Adding 10...\n");
	list.add(10);
	list.print();

	printf("Adding 12...\n");
	list.add(12);
	list.print();

	printf("Adding 1...\n");
	list.add(1);
	list.print();

	printf("Adding 24...\n");
	list.add(24);
	list.print();

	printf("Removing 3...\n");
	list.remove(3);
	list.print();

	printf("Removing 10...\n");
	list.remove(10);
	list.print();

	printf("Removing 24...\n");
	list.remove(24);
	list.print();

	printf("Removing 15...\n");
	list.remove(15);
	list.print();

	printf("Removing 12...\n");
	list.remove(12);
	list.print();

	printf("Removing 1...\n");
	list.remove(1);
	list.print();

	printf("Removing 9...\n");
	list.remove(9);
	list.print();
}