#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	int n, k,i;
	cin >> n >> k;
	int coin[101] = { 0 };
	int dp[10001] = { 0 };

	for (i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		coin[i] = num;
	}
	

	dp[0] = 1;
	int j, l;
	for (j = 0; j < n; j++)
	{
		for (l=coin[j];l<=k;l++)
		{
		
			dp[l] += dp[l - coin[j]];
			
		}
	
	
	}
	


	cout<<dp[k];

}