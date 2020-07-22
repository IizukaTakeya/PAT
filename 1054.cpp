#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int var1 = 0;
	int var2 = 0;
	cin >> var1 >> var2;
	map <int, int> color;
	map<int, int>::iterator it;
	int s;
	for (int i = 0; i < var1 * var2; ++i)
	{
		cin >> s;
		if (color.empty() == true)
		{
			color.insert(pair<int, int>(s, 1));
			continue;
		}
		it = color.find(s);
		if (it == color.end())
		{
			if (i < var1 * var2 / 2 + 1)
			{
				color.insert(pair<int, int>(s, 1));
			}
		}
		else
		{
			it->second++;
		}
	}
	for (it = color.begin(); it != color.end(); ++it)
	{
		if (it->second > var1 * var2 / 2)
		{
			cout << it->first;
		}
	}
	return 0;
}
