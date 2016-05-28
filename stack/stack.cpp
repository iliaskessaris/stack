#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"

using namespace std;

stack::stack() {
	stackPtr=NULL;
	
}

stack::~stack() {
	item* p1;
	item*  p2;

	p1 = stackPtr;
	while (p1 != NULL) {
		p2 = p1;
		p1 = p1->prev;
		delete p2;
	}
}

void stack::Push(string newname, int age) {
	item* node = new item;

	node->value = age;
	node->name = newname;
	node->prev = stackPtr;
	stackPtr = node;
}

void stack::Pop() {
	item* p=NULL;
	if (stackPtr == NULL) {
		cout << "The stack is empty\n";
	} else {
		p = stackPtr;
		ReadItem(stackPtr);
		stackPtr = stackPtr->prev;
		delete p;
	}
}


void stack::ReadItem(item* r) {
	cout << "---------------------------\n";
	cout << "Name: " << r->name << endl;
	cout << "Value: " << r->value << endl;
	cout << "---------------------------\n";
}

void stack::Print() {
	item* p=stackPtr;

	while (p != NULL) {
		ReadItem(p);
		p = p->prev;
	}

}