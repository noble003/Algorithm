#include <iostream>
#include <string.h>

using namespace std;
int main(void)
{
	char arr[101] = { NULL };
	cin >> arr;
	int count[26];
	int order = 0;
	 

	int i ;
	for (i = 0; i < 26; i++)
	{
		count[i] = -1;
	}

	for (i = 0; i < strlen(arr); i++)
	{
		if (count[(int)arr[i] - 97] == -1)
		{
			count[(int)arr[i] - 97] = order++;
		}
		else
		{
			order++;
		}
		
	}

	for (i = 0; i <26; i++)
	{
		cout << count[i] << " ";
		
	}


}