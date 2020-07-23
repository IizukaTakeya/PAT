#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
//#pragma warning(disable:4996)
double a[1001] = { 0 };
double b[1001] = { 0 };
double ab[2001] = { 0 };
using namespace std;
int main()
{
	int aCount = 0;
	cin >> aCount;
	for (int i = 0; i < aCount; ++i)
	{
		int base = 0;
		double var = 0;
		cin >> base >> var;
		a[base] = var;
	}
	int bCount = 0;
	cin >> bCount;
	for (int i = 0; i < bCount; ++i)
	{
		int base = 0;
		double var = 0;
		cin >> base >> var;
		b[base] = var;
	}
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			if (b[j] != 0 && a[i] != 0)
			{
				ab[i + j] += a[i] * b[j];
			}
		}
	}
	int nonZeroCount = 0;
	for (int i = 2000; i >= 0; --i)
	{
		if (ab[i] != 0)
		{
			++nonZeroCount;
		}

	}
	cout << nonZeroCount;
	for (int i = 2000; i >= 0; --i)
	{
		if (ab[i] != 0)
		{
			cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << ab[i];
		}
	}
	return 0;
}