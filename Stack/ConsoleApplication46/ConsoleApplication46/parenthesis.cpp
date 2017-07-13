#include <iostream>
#include <string.h>

using namespace std;

class Stack
{
private:
	int a_top = -1;
	int array[20001];
public:
	Stack() {};
	void push(int number)
	{
		array[++a_top] = number;

	}

	int pop()
	{
		if (a_top <= -1)
		{
			return -1;
		}

		return array[a_top--];

	}

	int size()
	{
		if (a_top <= -1)
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
		if (a_top <= -1)
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
	int count = 0;
	int c[10001];
	for (int i = 0; i < num_case; i++)
	{
		Stack s;
		char a[51];

		cin >> a;
		int flag = 0;

		for (int j = 0; j < strlen(a); j++)
		{
			if (a[j] == '(')
			{
				s.push(0);
			}

			if (a[j] == ')')
			{
				if (s.empty())
				{
					c[count++] = 0;
					flag = 1;
					break;
				}
				s.pop();
			}


		}
		if (s.empty() && flag == 0)
		{
			c[count++] = 1;
			
		}
		else if(!s.empty() && flag==0)
		{
			c[count++] = 0;
			
		}

	}
	for (int k = 0; k < num_case; k++)
	{
		if (c[k] == 1)
		{
			cout << "YES\n";
		}

		else if (c[k] == 0)
		{
			cout << "NO\n";
		}
	}
}