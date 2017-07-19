#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
class queue
{
private :
	int array[200001];
	int head = 0, rear=0;
	
public:
	void push(int num) {
		array[rear++]=num;
	};
	int pop()
	{
		if (head == rear)
			return -1;

		return array[head++];
	};
	int size()
	{	
		if (head > rear)
			return-1;

		return rear-head;
	};
	int empty()
	{
		if (head == rear)
			return 1;
		else
			return 0;
	}

	int front()
	{
		if (head == rear)
			return -1;

		return array[head];
	}

	int back()
	{	
		if (head == rear)
			return -1;
		return array[rear-1];
	}

};


int main(void)
{
	int num_case;
	cin >> num_case;

	queue q;

	for (int i = 0; i < num_case; i++)
	{
		char order[10];
		cin >> order;
		if (!strcmp(order, "push"))
		{
			int a;
			cin >> a;
			q.push(a);
		}

		else if (!strcmp(order, "pop"))
		{
			cout<<q.pop()<<"\n";
		}
		
		else if (!strcmp(order, "size"))
		{
			cout << q.size() << "\n";
		}
		else if (!strcmp(order, "empty"))
		{
			cout << q.empty() << "\n";
		}
		
		else if (!strcmp(order, "front"))
		{
			cout << q.front() << "\n";
		}
		else if (!strcmp(order, "back"))
		{
			cout << q.back() << "\n";
		}
	}
}
