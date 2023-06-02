#include <iostream>;
#include "LinkedQueue.h"
using namespace std;
void LinkedQueue::enqueue(int data)
{
	if (head == nullptr) {
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while(current->nextPointer!=nullptr)
		{
			current = current->nextPointer;
		}
		current->nextPointer = new Node(data);
	}

}

int LinkedQueue::dequeue()
{
	Node* forDel = new Node(head->val);
	forDel->nextPointer = head->nextPointer;
	int forReturn = head->val;
	delete head;
	head = forDel->nextPointer;
	delete forDel;
	return forReturn;
}

int LinkedQueue::getFirst()
{
	return(head->val);
}

void LinkedQueue::Print()
{
	Node* current = this->head;
	while (current != nullptr) {
		cout << current->val << " ";
		current = current->nextPointer;
	}
	cout << endl;
}

