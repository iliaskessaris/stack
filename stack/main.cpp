#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"

using namespace std;

//Displays the basic menu.
void MenuScreen() {
	cout << "To push an item to stack press: 1\n";
	cout << "To pop item from stack press: 2\n";
	cout << "To display the stack press: 3\n";
	cout << "To exit press any other key\n";
}

//Uses the basic operations for sustaining the stack.
void MainMenu() {
	stack* data=new stack;
	int age;
	string newname;
	char choice;

	data->ReadFromFile();
	MenuScreen();

	cin >> choice;
	while (choice == '1' || choice == '2' || choice == '3') {
		switch (choice) {
			case '1':
				cout << "Type the name.\n";
				cin >> newname;
				cout << "Type the age.\n";
				cin >> age;
				data->Push(newname, age);
				break;
			case '2':
				data->Pop();
				break;
			default:
				data->Print();
				break;
			}
		MenuScreen();
		cin >> choice;
	}
	data->SaveToFile();
}


void main() {
	MainMenu();
	system("Pause");
}