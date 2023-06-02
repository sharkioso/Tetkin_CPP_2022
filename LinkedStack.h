#pragma once
#include <iostream>
using namespace std;
class stak
{
public:
	stak()
	{
		size = 0;
		head = nullptr;
	}
	void push(int data);
	int pop();
	int getTop();
	void Print();
private:
	class Node 
	{
	public:
		int val;
		Node* nextPointer;
		Node(int val,Node* nextPointer=nullptr)
		{
			this->nextPointer = nextPointer;
			this->val = val;
		}
	};
	int size;
	Node* head;
};