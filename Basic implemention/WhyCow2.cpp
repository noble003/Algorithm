#include <iostream>
#include <string.h>

using namespace std;
int main(void)
{
	int count[128][128] = { 0 };
	char S[53];
	cin >> S;
	int first, last;
	
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = i;; j++)
		{
			if (j == i)
					continue;
			else if (count[(int)S[i]][(int)S[i]] == 1)
					break;
			else if ((int)S[i] == (int)S[j])
			{
					count[(int)S[i]][(int)S[i]]++;
					break;
			}
			else
				count[(int)S[i]][(int)S[j]]++;
		}
	}
	
	int somethingcow = 0;

	for (int k = 'A'; k <= 'Z'; k++)
	{
		
		for (int l = 'A'; l <= 'Z'; l++)
		{
			if (count[k][l] == 1 && k!=l)
				somethingcow++;
		}
	}
	cout << somethingcow/2;
	
}