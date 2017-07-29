#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << 3.14159265358979*r*r << "\n";
	cout.precision(6);
	cout << 2.000000*r*r << "\n";
}