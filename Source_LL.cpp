#include<iostream>
#include<string>
#include<memory>
#include<exception>
#include<utility>

using namespace std::rel_ops;
using namespace std;

template<typename T>
class Node
{
	T value{};
	int number{ 0 };
	shared_ptr<Node> pNext = nullptr;
	static int total;
public:
	friend class LinkedList;

	Node(T val, int n) : value{val}, number{n}, pNext{nullptr}
	{
		if(n > 0)
			++total;
	}

	inline int showTotal()	{	return total;	}

	inline string showValue() { return value; }

  inline bool operator<(const shared_ptr<Node> aNode) const
	{ return this->number < aNode->number; }

	inline bool operator==(const shared_ptr<Node> aNode) const
	{ return this->number == aNode->number; }
};

template<typename T>
int Node<T>::total{ 0 };

template<typename T1>
class LinkedList
{
	shared_ptr<T1> pHead = nullptr;
	shared_ptr<T1> pCurrent = nullptr;
	
public:
	LinkedList()
	{
		if (!pHead)
		{
			pHead = make_shared<T1>(NULL, 0);
		}
	}

	void AddNode(T val, int num)
	{
		if (pHead)
		{
			pCurrent = pHead;
			do
			{
				if (!pCurrent->pNext)
				{
					pCurrent->pNext = make_shared<Node>(val, num);
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
				cout << "Value: " << pCurrent->value << " is number: " << pCurrent->number << endl;
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

  shared_ptr<Node> searchNode(T val)
	{
	 if(pHead)
	 {
	  pCurrent = pHead;
		while(pCurrent = pCurrent->pNext)
				 if(pCurrent->value == val)
				   return pCurrent;
	 }
	}

 shared_ptr<Node> operator[](size_t index) const
	{
	 shared_ptr<Node> temp = pHead;
	 size_t count{ 0 };
	 do{
	   if(index == count++)
		   return temp;
	 temp = temp->pNext;
	 }while(true);
   return nullptr;
	}
};


int main()
{
	LinkedList<Node> ll;
	ll.AddNode("Martha", 1);
	ll.AddNode("Sam", 2);
	ll.AddNode("Tom", 3);
	ll.AddNode("Sarah", 4);
	ll.AddNode("Monica", 5);
	ll.printNodes();
  cout << endl << "Index 3: " << ll[3]->showValue() << endl << endl;
  if(ll.searchNode("Sam") < ll.searchNode("Monica"))
				cout << "Monica is gt than Sam" << endl;
  if(ll.searchNode("Tom") == ll.searchNode("Tom"))
				cout << "Tom is equal to Tom" << endl;
	if(!(ll.searchNode("Tom") == ll.searchNode("Sam")))
				cout << "TOm is not equal to Sam" << endl;

	ll.removeNode(3);
  ll.printNodes();
	cout << endl << "Index 3: " << ll[3]->showValue() << endl;
	return 0;
}
