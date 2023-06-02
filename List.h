using namespace std;
class List
{
public:
	List()
	{
		size = 0;
		head = nullptr;
	}
	void Add(int data);
	void AddIndex(int index, int data);
	void Del();
	void DelIndex(int index);
	int& operator[](const int index)
	{
		int count = 0;
		Node* current = this->head;
		while (current != nullptr)
		{

			if (count == index) {
				return current->node;
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
