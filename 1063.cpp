#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
#include <climits>
#pragma warning(disable:4996)
//a-z 97-122
//A-Z 65-90
//1-9 48-57
//1063
using namespace std;

int main()
{
	vector<set<int>> v;
	int setCount = 0;
	scanf("%d", &setCount);
	v.resize(setCount + 1);
	for (int i = 1; i <= setCount; i++)
	{
		int setNum = 0;
		scanf("%d", &setNum);
		for (int j = 0; j < setNum; j++)
		{
			int var = 0;
			scanf("%d", &var);
			v[i].insert(var);
		}
	}
	int testGroup = 0;
	scanf("%d", &testGroup);
	for (int i = 0; i < testGroup; i++)
	{
		if (i > 0)
		{
			printf("\n");
		}
		int set1 = 0;
		int set2 = 0;
		double match = 0;
		scanf("%d %d", &set1, &set2);
		for (set<int>::iterator it = v[set1].begin(); it != v[set1].end(); it++)
		{
			if (v[set2].find(*it) != v[set2].end())
			{
				match++;
			}
		}
		double total = 0;
		total = (double)v[set1].size() + (double)v[set2].size() - match;
		double percent = (match * 100) / total;
		printf("%.1lf%%", percent);
	}
	return 0;
}