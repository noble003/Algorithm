#include <iostream>


using namespace std;

int max(int a, int b);


int main(void)
{

	int step[301] = { 0, };
	int dp[301] = { 0, };
	int stepnum;

	cin >> stepnum;

	for (int i = 0; i < stepnum; i++)
	{
		int num;
		cin >> num;
		step[i] = num;
	}
	
	dp[0] = step[0];
	dp[1] = max(step[0] + step[1], step[1]);
	dp[2] = max(step[0] + step[2], step[1] + step[2]);


	for (int j = 3; j < stepnum; j++)
	{
		dp[j] = max(step[j] + dp[j - 2], dp[j - 3] + step[j] + step[j - 1]);
	}

	cout << dp[stepnum - 1];
}


int max(int a, int b)
{
	return a >= b ? a : b;
}