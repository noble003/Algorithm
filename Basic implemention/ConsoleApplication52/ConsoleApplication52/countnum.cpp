#include <iostream>

int main(void)
{
	int a, b, c;
	int result;
	int num[10] = { 0, };
	
	std::cin >> a >> b >> c;
	
	result = a*b*c;
	int i;

	while (result != 0)
	{
		i = result%10;
		num[i]++;
		result /= 10;

	}

	for (int j = 0; j < 10; j++)
	{
		std::cout << num[j]<<"\n";
	}
}