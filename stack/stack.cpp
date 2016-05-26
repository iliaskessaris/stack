#include <iostream>
#include "stack.h"
using namespace std;

stack::stack() {
	stackPtr = NULL;
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

void stack::Push(string name, int value) {
	item* node = new item;
	node->name = name;
	node->value = value;
	node->prev = stackPtr;
	stackPtr = node;

}

void stack::Pop() {

}


void stack::ReadItem(item* r) {

}

void stack::Print() {

}