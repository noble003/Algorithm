#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int num_case;

	cin >> num_case;
	for (int i = 0; i < num_case; i++)
	{
		int N,K,D;

		int build[10000] = { 0 };
		int pre[10000] = { 0 };
		cin >> N >> K;
		vector<int> suc[10000];
		
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			build[j] = num;

		}

		for (int k = 1; k <= K; k++)
		{
			int x, y;
			cin >> x >> y;
			
			pre[y]++;
			suc[x].push_back(y);

		}
		cin >> D;
		int time[10000] = { 0 };

		queue<int> q;
		for (int l = 1; l <= N; l++)
		{
			if (pre[l] == 0)
				q.push(l);
		}
		

		while (pre[D] > 0)
		{
			int u = q.front();
			q.pop();

			for (int next : suc[u])
			{
				time[next] = max(time[next], time[u] + build[u]);
				if (--pre[next] == 0)
					q.push(next);
			}
		}
		
		cout << time[D] + build[D]<<"\n";
	}
	
}