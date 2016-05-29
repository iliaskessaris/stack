#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"

using namespace std;

//The constructor of the class stack.
stack::stack() {
	stackPtr=NULL;
}

//The deconstructor of the class stack.
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

//Adds an item into the stack.
void stack::Push(string newname, int age) {
	item* node = new item;

	node->value = age;
	node->name = newname;
	node->prev = stackPtr;
	stackPtr = node;
}

//Removes an item from the stack.
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

//Displays an item from the stack.
void stack::ReadItem(item* r) {
	cout << "---------------------------\n";
	cout << "Name: " << r->name << endl;
	cout << "Value: " << r->value << endl;
	cout << "---------------------------\n";
}

//Displays the contents of the stack.
void stack::Print() {
	item* p=stackPtr;

	while (p != NULL) {
		ReadItem(p);
		p = p->prev;
	}
}

//Builds up a stack from file.
void stack::ReadFromFile() {
	ifstream StackFile("StackFile.txt");
	int age;
	string newname;
	if (StackFile.is_open()) {
		while (!StackFile.eof()) {
			StackFile >> newname >> age;
			Push(newname, age);
		}
		StackFile.close();
	}
}

//Store stack in a file.
void stack::StoreToFile() {
	ofstream StackFile("StackFile.txt");

	while (stackPtr != NULL) {
		StackFile << stackPtr->name << " " << stackPtr->value;
		stackPtr = stackPtr->prev;
		if (stackPtr != NULL) {
			StackFile << endl;
		}
	}
	StackFile.close();
}

//Store stack in a file with the correct order.
void stack::SaveToFile() {
	StoreToFile();
	ReadFromFile();
	StoreToFile();
}