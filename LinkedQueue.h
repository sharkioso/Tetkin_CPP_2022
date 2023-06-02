#pragma once
#include <iostream>;
using namespace std;
class LinkedQueue
{
public:
	LinkedQueue()
	{
		head = nullptr;
	}
	void enqueue(int data);
	int dequeue();
	int getFirst();
	void Print();
private:
	class Node
	{
	public:
		int val;
		Node* nextPointer;
		Node(int val, Node* nextPointer = nullptr)
		{
			this->nextPointer = nextPointer;
			this->val = val;
		}
	};
	Node* head;
};