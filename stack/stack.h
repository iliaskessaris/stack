#ifndef STACK_H
#define STACK_H

class stack
{
public:

private:
	struct item {
		string name;
		int value;
		item* prev;
	};
	
	item* stackPtr;

};

#endif;
