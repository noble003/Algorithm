#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

class Stack
{
private:
	int a_top = -1;
	int array[20001];
public:

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
		if (a_top <= -1)
		{
			return 1;
		}
		else
			return 0;
	}

	int top()
	{
		if(a_top<=-1)
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
	char pm[200001];
	int start = 0;
	int count = 0;
		for (int i =0; i<num_case; i++)
		{
			int num;
			cin >> num;
	
				
			while (start < num)
			{
				s.push(++start);
				pm[count++] = '+';

			}
			

			if (start >= num)
			{	
				if(s.top()!=num || s.empty())
				{
				cout << "NO\n";
				return 0;
				}
				s.pop();
				pm[count++] = '-';

			}


		}
	
		for (int last = 0; last < count; last++)
		{
			cout << pm[last] << "\n";
		}
		


}

//입 출력을 자주 드나들면 안좋다.
