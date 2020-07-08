#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int prime(long long n);
int main()
{
	long long number = 0;
	cin >> number;
	int maxCount = 0;
	int maxBegin = 0;
	int currCount = 0;
	int currNumber = number;
	int flag = 0;
	if (prime(number) == true)
	{
		cout << "1" << endl << number;
		return 0;
	}
	for (int i = 2; i <= sqrt(number) + 1; i++)
	{
		int j = i;
		currNumber = number;
		while (currNumber % j == 0)
		{
			currCount++;
			currNumber /= j;
			j++;
		}
		if (currCount > maxCount)
		{
			maxCount = currCount;
			maxBegin = i;
		}
		currCount = 0;
		currNumber = number;
	}
	cout << maxCount << endl;
	for (int i = 0; i < maxCount; i++)
	{
		cout << maxBegin + i;
		if (i < maxCount - 1)
		{
			cout << "*";
		}
	}
	return 0;
}
int prime(long long n)
{
	for (int i = 2; i < sqrt(n) + 1; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}