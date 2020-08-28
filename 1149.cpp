#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_set>
#include <map>
#include <climits>
#include <unordered_map>
#include <map>
#pragma warning(disable:4996)
//a-z 97-122
//A-Z 65-90
//1-9 48-57
//_ 95
//1149
using namespace std;

unordered_map<int, set<int>> m;
unordered_set<int> check;
int main()
{
	int groupCount = 0;
	int testCount = 0;
	scanf("%d %d", &groupCount, &testCount);
	for (int i = 0; i < groupCount; i++)
	{
		int s1 = 0;
		int s2 = 0;
		scanf("%d %d", &s1, &s2);
		m[s1].insert(s2);
		m[s2].insert(s1);
		check.insert(s1);
		check.insert(s2);
	}
	for (int i = 0; i < testCount; i++)
	{
		if (i > 0)
		{
			printf("\n");
		}
		int test = 0;
		scanf("%d", &test);
		vector<int> v;
		int flag = 0;
		for (int j = 0; j < test; j++)
		{
			int var1 = 0;
			scanf("%d", &var1);
			if (check.find(var1) != check.end())
			{
				v.push_back(var1);
			}
		}
		/*for (int j = 0; j < v.size(); j++)
		{
			cout << v[j] << endl;
		}*/
		if (v.size() <= 1)
		{
			printf("Yes");
			continue;
		}
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (flag == -1)
			{
				break;
			}
			for (int k = j + 1; k < v.size(); k++)
			{
				//cout << v[j] << "    " << v[k] << endl;
				if (m.find(v[j])->second.find(v[k]) != m.find(v[j])->second.end())
				{
					flag = -1;
					break;
				}
			}
		}
		if (flag == -1)
		{
			printf("No");
		}
		else if (flag == 0)
		{
			printf("Yes");
		}
	}
	return 0;
}