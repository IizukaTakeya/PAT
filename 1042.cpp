#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;
string al[5] = { "S","H","C","D","J" };
int main()
{
	string s[54];
	int count = 0;
	cin >> count;
	int base[54];
	int shuff[54];
	int change[54];
	for (int i = 0; i < 54; ++i)
	{
		base[i] = i + 1;
		cin >> shuff[i];
		shuff[i] -= 1;
		s[i] = s[i] + al[i / 13] + to_string(i % 13 + 1);
	}
	/*for (int i = 0; i < 54; ++i)
	{
		cout << shuff[i] << "\t";
		shuff[i] -= 1;
		cout << s[i] << "\t";
	}*/
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < 54; ++j)
		{
			change[shuff[j]] = base[j];
		}
		for (int j = 0; j < 54; ++j)
		{
			base[j] = change[j];
		}
	}
	for (int i = 0; i < 54; ++i)
	{
		cout << s[base[i] - 1];
		if (i != 53)
		{
			cout << " ";
		}
	}
	return 0;
}