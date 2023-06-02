#include "List.h"

void List::Add(int data)
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

void List::AddIndex(int index, int data)
{
	int i = 0;
	Node* add = new Node(data);
	Node* previousAdd = head;
	if (index > 0)
	{
		while (i != index - 1)
		{
			previousAdd = previousAdd->nextPointer;
			i++;
		}
		add->nextPointer = previousAdd->nextPointer;
		previousAdd->nextPointer = add;
	}
	if (index == 0)
	{
		Add(data);
	}
	size++;
}

void List::Del()
{
	Node* forDel = new Node(head->node);
	forDel->nextPointer = head->nextPointer;
	delete head;
	head = forDel->nextPointer;
	delete forDel;
}

void List::DelIndex(int index)
{
	if (index > 0)
	{
		Node* previousDel = head;
		int i = 0;
		while (i != index - 1)
		{
			previousDel = previousDel->nextPointer;
		}
		Node* forDel = previousDel->nextPointer;
		previousDel->nextPointer = forDel->nextPointer;
		delete forDel;
	}
	else
	{
		Del();
	}
}

