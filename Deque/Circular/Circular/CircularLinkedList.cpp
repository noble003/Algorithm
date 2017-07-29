#include <iostream>

using namespace std;
class Node
{	

	public:
		int data;
		Node *PrevLink;
		Node *NextLink;
		
		
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

		else if (Head == Tail)
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

		else if (Head == Tail)
		{
			temp = Head->data;
			Head = NULL;
			Tail = NULL;
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
	int queuenum;
	int popnum;

	cin >> queuenum>>popnum;

	Deque d;
	for (int i = 1; i <= queuenum; i++)
	{
		d.push_back(i);
	}

	Deque tempd1, tempd2;
	
	tempd1 = d;
	tempd2 = d;

	int resultcount = 0;
	for (int j = 0; j < popnum; j++)
	{
		int num;
		cin >> num;

		int count1 = 0;
		int count2 = 0;
		
		while (tempd1.front()!= num)
		{	
			tempd1.push_back(tempd1.pop_front());
			count1++;
	
		}

		while (tempd2.front() != num)
		{
			tempd2.push_front(tempd2.pop_back());
			count2++;
		}
		
		

		if (count1 < count2)
		{
			tempd1.pop_front();
			resultcount += count1;
			tempd2 = tempd1;
			d = tempd1;
		}

		else
		{
			tempd2.pop_front();
			resultcount += count2;
			tempd1 = tempd2;
			d = tempd2;
		}

	
	}

	cout << resultcount << "\n";

}

