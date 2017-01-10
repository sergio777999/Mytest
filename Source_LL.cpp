#include<iostream>
#include<string>
#include<memory>
#include<exception>

//continue
using namespace std;

class Node
{
	string name{ "" };
	int number{ 0 };
	shared_ptr<Node> pNext = nullptr;
	static int total;
public:
	friend class LinkedList;

	Node(string s, int n) : name{s}, number{n}, pNext{nullptr}
	{
		if(n > 0)
			++total;
	}

	int showTotal()	{	return total;	}

};

int Node::total{ 0 };

class LinkedList
{
	shared_ptr<Node> pHead = nullptr;
	shared_ptr<Node> pCurrent = nullptr;
	
public:
	LinkedList()
	{
		if (!pHead)
		{
			pHead = make_shared<Node>("", 0);
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

  void removeNode(int i)
	{
	 if(pHead)
	 {
	  pCurrent = pHead;
		shared_ptr<Node> temp;
		int num{ 0 };
		do
		{
		 temp = pCurrent->pNext;
		 num = temp->number;
		 if(num == i)
		 {
			pCurrent->pNext = temp->pNext;
			pHead->total--;
			return;
		 }
		}while(pCurrent = pCurrent->pNext);
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
  
	ll.removeNode(3);
  ll.printNodes();
	return 0;
}
