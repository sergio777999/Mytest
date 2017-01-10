#include<iostream>
#include<string>
#include<memory>
#include<exception>

using namespace std;

class Node
{
	string name{};
	int number{};
	shared_ptr<Node> pNext = nullptr;
	static int total;
public:
	friend class LinkedList;

	Node(string s, int n) : name{s}, number{n}, pNext{nullptr}
	{
		if(n > 0)
			++total;
	}

	int showTotal()
	{
		return total;
	}
};

int Node::total{ 0 };

class LinkedList
{
	shared_ptr<Node> pHead = nullptr;
	shared_ptr<Node> pCurrent = nullptr;
	shared_ptr<Node> pTail = nullptr;

public:
	LinkedList()
	{
		if (!pHead)
		{
			pHead = make_shared<Node>("", 0);
			pCurrent = pTail = pHead;
		}
	}

	void AddNode(string name, int num)
	{
		if (pHead)
		{
			pCurrent = pHead;
			do
			{
				if (!pCurrent->pNext)
				{
					pCurrent->pNext = make_shared<Node>(name, num);
					break;
				}

			} while (pCurrent = pCurrent->pNext);
		}
	}

	
	void printNodes()
	{
		if (pHead)
		{
			pCurrent = pHead;
			while (pCurrent = pCurrent->pNext)
			{
				cout << "Name: " << pCurrent->name << " is number: " << pCurrent->number << endl;
			}
			cout << "Total number of records is: " << pHead->showTotal() << endl;
		}
	}
};

int main()
{
	LinkedList ll;
	ll.AddNode("Martha", 1);
	ll.AddNode("Sam", 2);
	ll.AddNode("Tom", 3);
	ll.AddNode("Sarah", 4);
	ll.AddNode("Monica", 5);
	ll.printNodes();

	return 0;
}