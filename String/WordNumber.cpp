#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	char S[1000001];
	int count = 0;
	cin.getline(S, 1000001);
	
	char *ptr = NULL;
	ptr = strtok(S, " ");
	while (ptr!= NULL)
	{
		
		ptr= strtok(NULL, " ");
		count++;
	}

	cout << count;
	
}