#ifndef STACK_H
#define STACK_H



using namespace std;

class stack
{
private:
	struct item {
		string name;
		int value;
		item* prev;
	};

	item* stackPtr;

public:
	stack();
	~stack();
	void Push(string newname, int age);
	void Pop();
	void ReadItem(item* r);
	void Print();
	void ReadFromFile();
	void StoreToFile();
	void SaveToFile();
};

#endif;
