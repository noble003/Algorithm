#include <iostream>

using namespace std;

int min(int a, int b);
int main(void)
{
	int num;
	int dp[100001] = { 0, };

	cin >> num;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	int count;
	for (int i = 4; i <= num; i++)
	{
		count = 0;
		if (i % 3 == 0)
			if (i % 2 == 0)
				dp[i] = min(dp[i / 2], min(dp[i / 3], dp[i - 1])) + 1;
			else
				dp[i] = min(dp[i / 3], dp[i - 1]) + 1;

		else if (i % 2 == 0 && i % 3 != 0)
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;

		else if (i % 2 != 0 && i % 3 != 0)
			dp[i] = dp[i - 1] + 1;

		
	}

	cout << dp[num];
	
		
}
int min(int a, int b)
{
	return a < b ? a : b;
}