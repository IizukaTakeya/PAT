#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int prime(int n);
int main()
{
	int flag = 0;
	while (true)
	{
		vector<int> v;
		long long int number = 0;
		int radix = 0;
		cin >> number;
		if (number < 0)
		{
			return 0;
		}
		cin >> radix;
		if (flag == 1)
		{
			cout << endl;
		}
		if (prime(number) == false)
		{
			cout << "No";
			flag = 1;
			continue;
		}
		while (number > 0)
		{
			v.push_back(number % radix);
			number /= radix;
		}
		number = 0;
		for (unsigned int i = 0; i < v.size(); i++)
		{
			number *= radix;
			number += v[i];
		}
		flag = 1;
		prime(number) == true ? cout << "Yes" : cout << "No";
	}
	return 0;
}
int prime(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}