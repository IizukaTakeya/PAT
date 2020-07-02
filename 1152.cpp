#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int prime(long long n)
{
	if (n < 2)
	{
		return false;
	}
	else
	{
		for (int m = 2; m < (long long)sqrt(n) + 1; m++)
		{
			if (n % m == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int numCount = 0;
	int pntCount = 0;
	cin >> numCount >> pntCount;
	string s;
	cin >> s;
	for (int i = 0; i <= numCount - pntCount; i++)
	{
		long long testNum = stoll(s.substr(i, pntCount));
		long long copy = testNum;
		if (prime(testNum) == true)
		{
			while (copy < pow(10, pntCount - 1))
			{
				cout << "0";
				copy *= 10;
			}
			cout << testNum;
			return 0;
		}
	}
	cout << "404";
	return 0;
}