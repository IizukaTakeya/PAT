#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	string s;
	string d;
	getline(cin, s);
	getline(cin, d);
	string::iterator it;
	for (int i = 0; i < d.size(); i++)
	{
		for (it = s.begin(); it < s.end(); it++)
		{
			if (*it == d[i])
			{
				s.erase(it);
				it--;
			}
		}
	}
	cout << s;
	return 0;
}