#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
//#pragma warning(disable:4996)
using namespace std;
int main()
{
	long long number = 0;
	long long powBase = 0;
	long long powCount = 0;
	cin >> number;
	cout << number << "=";
	int i = 2;
	if (number < 2)
	{
		cout << number;
		return 0;
	}
	while (number > 1)
	{
		if (number % i == 0)
		{
			number /= i;
			if (i == powBase)
			{
				powCount += 1;
			}
			else
			{
				if (powCount > 1)
				{
					cout << powBase << "^" << powCount << "*";
				}
				else if (powCount != 0)
				{
					cout << powBase << "*";
				}
				powBase = i;
				powCount = 1;
			}
			continue;
		}
		i += 1;
	}
	if (powCount > 1)
	{
		cout << powBase << "^" << powCount;
	}
	else
	{
		cout << powBase;
	}
	return 0;
}
