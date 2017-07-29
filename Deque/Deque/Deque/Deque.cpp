#include<iostream>
#include<string.h>

using namespace std;
class Node
{
public:
	int data;
	Node* NextLink;
	Node* PrevLink;

};

class Deque
{
public:
	Node* Head;
	Node* Tail;
	int n_size = 0;

	Deque()
	{
		Head = NULL;
		Tail = NULL;
	}
	void push_back(int data)
	{
		Node * newnode = new Node();
		newnode->data = data;
		newnode->PrevLink = NULL;
		newnode->NextLink = NULL;

		if (Head != NULL)
		{
			Tail->NextLink = newnode;
			newnode->PrevLink = Tail;
			Tail = newnode;
		}

		else
		{
			Head = Tail = newnode;
		}

		n_size++;
	}

	void push_front(int data)
	{
		Node *newnode = new Node();
		newnode->data = data;
		newnode->NextLink = NULL;
		newnode->PrevLink = NULL;

		if (Head != NULL)
		{
			Head->PrevLink = newnode;
			newnode->NextLink = Head;
			Head = newnode;
		}
		else
		{
			Head = Tail = newnode;
		}

		n_size++;
	}

	int pop_back()
	{
		
		
		int temp;
		if (Head == NULL && Tail == NULL)
			return -1;

		if (Head == Tail)
		{
			temp = Head->data;
			Head = NULL;
			Tail = NULL;
			n_size--;
			return temp;
		}

		else
		{
			temp = Tail->data;
			Tail = Tail->PrevLink;
			n_size--;
			return temp;
		}

	
	}

	int pop_front()
	{


		int temp;
		if (Head == NULL && Tail == NULL)
			return -1;

		if (Head == Tail)
		{
			temp = Head->data;
			Head=NULL;
			Tail=NULL;
			n_size--;
			return temp;
		}

		else
		{
			temp = Head->data;
			Head = Head->NextLink;
			n_size--;
			return temp;
		}

		
		else
			return -1;
	}

	int empty()
	{
		if (Head == NULL && Tail == NULL)
		{
			return 1;
		}
		else
			return 0;
	}

	int front()
	{
		if (empty())
			return-1;

		int temp = Head->data;

		return temp;
	}

	int back()
	{
		if (empty())
			return-1;

		int temp = Tail->data;
		return temp;
	}

	int size()
	{
		return this->n_size;
	}
};


int main()
{
	int num_case;

	cin >> num_case;
	Deque d;
	for (int i = 0; i < num_case; i++)
	{
		
		char order[15];
		cin >> order;
		if (!(strcmp(order, "push_back")))
		{
			int num;
			cin >> num;
			d.push_back(num);

		}

		else if (!(strcmp(order, "push_front")))
		{
			int num;
			cin >> num;
			d.push_front(num);

		}

		else if (!(strcmp(order, "front")))
		{
			
			cout<<d.front()<<"\n";

		}
		else if (!(strcmp(order, "back")))
		{

			cout<<d.back()<<"\n";

		}

		else if (!(strcmp(order, "size")))
		{

			cout<<d.size()<<"\n";

		}

		else if (!(strcmp(order, "empty")))
		{

			cout<<d.empty()<<"\n";

		}

		else if (!(strcmp(order, "pop_front")))
		{

			cout<<d.pop_front()<<"\n";

		}
		else if (!(strcmp(order, "pop_back")))
		{

			cout<<d.pop_back()<<"\n";

		}
	}
}