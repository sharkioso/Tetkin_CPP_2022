#include "LinkedStack.h"

void stak::push(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* node = new Node(data);
		node->nextPointer = head;
		head = node;
	}
	size++;
}

int stak::pop()
{
	Node* forDel = new Node(head->val);
	forDel->nextPointer = head->nextPointer;
	int forReturn = head->val;
	delete head;
	head = forDel->nextPointer;
	delete forDel;
	return forReturn;
}

int stak::getTop()
{
	return (head->val);
}

void stak::Print()
{
	Node* current =this-> head;
	while (current != nullptr) {
		cout << current->val << " ";
		current = current->nextPointer;
	}
	cout << endl;
}
