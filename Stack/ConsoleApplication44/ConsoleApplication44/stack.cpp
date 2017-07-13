#include <iostream>

using namespace std;

class Stack 
{
private:
	int a_top = -1;
	int array[10001];
public:

	void push(int number)
	{
		array[++a_top] = number;
		
	}

	int pop()
	{
		if (a_top == -1)
		{
			return -1;
		}

		return array[a_top--];

	}

	int size()
	{
		if (a_top == -1)
		{
			return 0;
		}
		return a_top + 1;
	}


	int empty()
	{
		if (a_top == -1)
		{
			return 1;
		}
		else
			return 0;
	}

	int top()
	{
		if (a_top == -1)
		{
			return -1;
		}

		return array[a_top];
	}
};

int main(void)
{

	int num_case;
	cin >> num_case;
	Stack s;
	for (int i = 0; i < num_case; i++)
	{	
		char operation[10];
		cin >>operation;
		if (!strcmp(operation, "push"))
		{
			int num;
			cin >> num;
			s.push(num);	
		}

		else if (!strcmp(operation, "top"))
		{

			cout<<s.top()<<endl;
		}

		else if (!strcmp(operation, "size"))
		{
			cout<<s.size()<<endl;
		}

		else if (!strcmp(operation, "empty"))
		{
			cout << s.empty() << endl;
		}

		else if (!strcmp(operation, "pop"))
		{
			cout << s.pop() << endl;
		}


	}


}