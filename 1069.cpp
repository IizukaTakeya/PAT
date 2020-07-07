#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int standard(int n);
int big(int n);
int small(int n);
int main()
{
	int n = 0;
	cin >> n;
	do
	{
		standard(big(n));
		cout << big(n) << " - ";
		standard(small(n));
		cout << small(n) << " = ";
		standard(big(n) - small(n));
		cout << big(n) - small(n);
		n = big(n) - small(n);
		if (n != 6174 && n != 0)
		{
			cout << endl;
		}
	} while (n != 6174 && n != 0);
	return 0;
}
int standard(int n)
{
	if (n < 1000)
	{
		cout << "0";
		if (n < 100)
		{
			cout << "0";
			if (n < 10)
			{
				cout << "0";
			}
		}
	}
	return 0;
}
int small(int n)
{
	string s = to_string(n);
	sort(s.begin(), s.end());
	return stoi(s);
}
int big(int n)
{
	string s = to_string(n);
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	int m = stoi(s);
	while (m < 1000)
	{
		m *= 10;
	}
	return m;
}