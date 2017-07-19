#include <iostream>
using namespace std;
class Stack
{
private:
	int a_top = -1;
	int array[100001];
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

class queue
{
private:
	int array[100001];
	int head = 0, rear = 0;

public:
	void push(int num) {
		array[rear++] = num;
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

		return rear - head;
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
		return array[rear - 1];
	}

	int pull()
	{
		if (head == rear)
			return -1;

		return array[head++];
	}

};
//void DFS(int vv[][1001], bool c[], int vnum, int startvnum);
void DFS(int vv[][1001], int vnum, int startvnum);//깊이 우선 탐색
void BFS(int vv[][1001],int vnum, int startvnum);//넓이 우선 탐색

int main()
{
	int vnum;//정점의 개수
	int bnum;//간선의 개수
	int startvnum;//시작 정점
	bool c[10001] = { false, };
	int vv[1001][1001];//인접행렬
	cin >> vnum >> bnum >> startvnum;
	int a, b;//정점을 받아올 변수
	for (int i = 0; i < bnum; i++) {
		cin >> a >> b;
		vv[a][b] = 1;
		vv[b][a] = 1;
	}
	DFS(vv,vnum, startvnum);
	BFS(vv, vnum, startvnum);



}
/*void DFS(int vv[][1001],bool c[] ,int vnum, int startvnum)
{
	c[startvnum] = true;
	cout << startvnum << "\n";

	for (int i = 1; i <= vnum; i++)
	{
		if (vv[startvnum][i] == 1 && !c[i])
		{
			DFS(vv, c,vnum,i);
		}
	}
}
*/

void DFS(int vv[][1001],int vnum,int startvnum)
{
	Stack s;
	int v = startvnum;
	bool c1[10001] = { false, };
	s.push(v);
	c1[v] = true;
	cout << v << "\n";

	while (!s.empty()) {
		
		v = s.top();
		bool flag = false;
		for (int i = 1; i <= vnum; i++)
		{
			if (vv[v][i] == 1 && !c1[i])
			{
				s.push(i);
				cout << i << "\n";
				c1[i] = true;
				flag = true;
				break;
			}

		}
		if (!flag)
		{
			s.pop();
		}

	}
}


void BFS(int vv[][1001], int vnum, int startvnum) {
	int v = startvnum;
	bool c2[10001] = { false, };
	
	queue q;
	q.push(v);
	c2[v] = true;

	while (!q.empty())
	{	
		v = q.pull();
		cout << v << "\n";
		for (int i = 1; i <= vnum; i++)
		{
			if (vv[v][i] == 1 && !c2[i])
			{
				q.push(i);
				c2[i] = true;
			}
		}
	}
}
