#include <iostream>

int main (void)
{
	int a1, a2, a3, a4;
	for (int i = 0; i < 3; i++)
	{
		std::cin >> a1 >> a2 >> a3 >> a4;

		if (a1 + a2 + a3 + a4 == 4)
			std::cout << "E"<<"\n";
		else if (a1 + a2 + a3 + a4 == 3)
			std::cout << "A" << "\n";
		else if (a1 + a2 + a3 + a4 == 2)
			std::cout << "B" << "\n";
		else if (a1 + a2 + a3 + a4 == 1)
			std::cout << "C" << "\n";
		else if (a1 + a2 + a3 + a4 == 0)
			std::cout << "D" << "\n";
	}
	
}