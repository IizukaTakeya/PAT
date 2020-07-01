#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	int* number = new int[count];
	int* flag = new int[count];
	for (int i = 0; i < count; i++)
	{
		flag[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		cin >> number[i];
		flag[number[i]] += 1;
	}
	for (int i = 0; i < count; i++)
	{
		if (flag[number[i]] == 1)
		{
			cout << number[i];
			delete[] number;
			delete[] flag;
			return 0;
		}
	}
	cout << "None";
	delete[] number;
	delete[] flag;
	return 0;
}