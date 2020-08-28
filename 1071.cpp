#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#include <unordered_map>
#include <map>
#pragma warning(disable:4996)
//a-z 97-122
//A-Z 65-90
//1-9 48-57
//_ 95
//1071
using namespace std;

map<string, int> m;

int main()
{
	string s;
	getline(cin, s);
	//cout << s;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
		}
	}
	//cout << s;
	string s1;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalnum(s[i]))
		{
			s1 = s1 + s[i];
		}
		else
		{
			if (m.find(s1) == m.end())
			{
				if (!s1.empty())
				{
					m.insert(make_pair(s1, 1));
				}
			}
			else
			{
				m.find(s1)->second++;
			}
			s1.clear();
		}
	}
	if (m.find(s1) == m.end())
	{
		if (!s1.empty())
		{
			m.insert(make_pair(s1, 1));
		}
	}
	else
	{
		m.find(s1)->second++;
	}
	int maxNum = -1;
	string pntS;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second > maxNum)
		{
			pntS = it->first;
			maxNum = it->second;
		}
	}
	printf("%s %d", pntS.c_str(), maxNum);
	return 0;
}