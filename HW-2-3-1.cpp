#include <iostream>
using namespace std;
class List
{
public:
	List()
	{
		size = 0;
		head = nullptr;
	}
	void Add(int data)
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
	void AddIndex(int index, int data)
	{
		int i = 0;
		Node* add = new Node(data);
		Node* previousAdd = head;
		if (index>0)
		{
			while (i != index-1)
			{
				previousAdd = previousAdd->nextPointer;
				i++;
			}
			add->nextPointer = previousAdd->nextPointer;
			previousAdd->nextPointer = add;
		}
		if(index ==0)
		{
			Add(data);
		}
		size++;
	}
	void Del()
	{
		Node* forDel = new Node(head->node);
		forDel->nextPointer = head->nextPointer;
		delete head;
		head = forDel->nextPointer;
		delete forDel;
	}
	void DelIndex(int index)
	{
		if (index > 0)
		{
			Node* previousDel = head;
			int i = 0;
			while (i!=index-1)
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
	int& operator[](const int index)
	{
		int count = 0;
		Node* current = this->head;
		while (current != nullptr)
		{

			if (count == index) {
				return current-> node;
			}
			current = current->nextPointer;
			count++;
		}
	}
private:
	class Node
	{
	public:
		Node* nextPointer;
		int node;
		Node(int word, Node* nextPointer = nullptr)
		{
			this->nextPointer = nextPointer;
			this->node = word;
		}
	};
	int size;	
	Node* head;
};

int main()
{
	List test;
	test.Add(1);
	test.Add(2);
	test.Add(3);
	test.Add(4);
	cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] <</* " " << test[4] <<*/ endl;
	test.AddIndex(4, 16);
	cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3]<<" "<<test[4] << endl;
	test.Del();
	cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] << endl;
	test.DelIndex(1);
	cout << test[0] << " " << test[1] << " " << test[2] << endl;
}

