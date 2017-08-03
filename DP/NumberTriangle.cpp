#include <iostream>


int max(int a, int b) {
	return (a>b) ? a : b;
}
void TriangleSumSave(int Maxfloor, int triangle[][501], int trianglesum[][501]);
int MaxNum(int Maxfloor, int trianglesum[][501]);
using namespace std;
int main(void)
{
	int triangle[501][501] = { 0 };
	int trianglesum[501][501] = { 0 };
	int Maxfloor;
	int count = 1;
	cin >> Maxfloor;

	for (int floor = 0; floor < Maxfloor; floor++)
	{
		for (int j = 0 ;j <= floor; j++)
		{
			int num;
			cin >> num;
			triangle[floor][j] = num;
			
			//cout << triangle[i][floor] << " ";
		}
		//cout << "\n";
		count++;
	
	}

	TriangleSumSave(Maxfloor, triangle, trianglesum);
	cout <<MaxNum(Maxfloor, trianglesum);
}

void TriangleSumSave(int Maxfloor,int triangle[][501],int trianglesum[][501])
{
	
	for (int floor = 0;floor < Maxfloor; floor++)
	{
	
		for (int j = 0; j <= floor; j++)
		{

			if (floor==0)
			{
				trianglesum[floor][j] = triangle[floor][j];
			}
			else if (floor != 0 && j == 0)
			{
				trianglesum[floor][j] = trianglesum[floor-1][j]+triangle[floor ][j];
			}
			else if (floor != 0 && j == floor)
			{
				trianglesum[floor][j] = trianglesum[floor - 1][j-1] + triangle[floor][j];
			}
			else
			{
				trianglesum[floor][j] = max(trianglesum[floor - 1][j - 1], trianglesum[floor - 1][j]) + triangle[floor][j];
			}
			//cout << trianglesum[floor][j]<<" ";
		}
		//cout << "\n";
	}
}

int MaxNum(int Maxfloor, int trianglesum[][501])
{	
	int Max =trianglesum[Maxfloor-1][0];
	int count = 0;
	for(int i=0; i<Maxfloor;i++)
	{
	
		if (Max < trianglesum[Maxfloor-1][i])
			Max = trianglesum[Maxfloor-1][i];
	
	}

	return Max;
}