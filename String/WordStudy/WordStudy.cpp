#include <iostream>
#include <string.h>
using namespace std;


int main(void)
{
	int count[128] = { 0, };
	char S[1000001];
	cin >> S;
	int lenS = strlen(S);

	for (int i = 0; i < lenS; i++)
	{   if((int)S[i]>96)
        count[(int)(S[i]-32)]++;
        else
		count[(int)S[i]]++;
	}
	int max = 0;
	int a = 0; //물음표 출력

	for (int j = 0; j < 128; j++)
	{
		if (count[j] > count[max])
			max = j;
	}

	for (int k = 0; k < 128; k++)
	{
		if (count[max] == count[k] && max != k)
		{
			cout << "?";
			return 0;
		}
	}

		cout << (char)max;
}