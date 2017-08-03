#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	int num_case;
	int repeatnum;
	char S[21];
	char R[200];
	cin >> num_case;
	for (int i = 0; i < num_case; i++)
	{	
		cin >> repeatnum;
		cin >> S;
		for (int k = 0; k < strlen(S); k++)
		{


			for (int j = 0; j < repeatnum; j++)
			{
				cout << S[k];
			}
		}
		cout << "\n";
	}
}