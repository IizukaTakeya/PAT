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
//1047
using namespace std;

unordered_map<int, vector<string>> m;

int main()
{
	int studentCount = 0;
	int courseCount = 0;
	scanf("%d %d", &studentCount, &courseCount);
	for (int i = 1; i <= courseCount; i++)
	{
		m.insert(make_pair(i, 0));
	}
	for (int i = 0; i < studentCount; i++)
	{
		string currStudent;
		cin >> currStudent;
		int currCourse = 0;
		scanf("%d", &currCourse);
		for (int j = 0; j < currCourse; j++)
		{
			int var = 0;
			scanf("%d", &var);
			m.find(var)->second.push_back(currStudent);
		}
	}
	for (unordered_map<int, vector<string>>::iterator it = m.begin(); it != m.end(); it++)
	{
		sort(it->second.begin(), it->second.end());
	}
	for (int i = 1; i <= courseCount; i++)
	{
		if (i > 1)
		{
			printf("\n");
		}
		printf("%d %d", i, m.find(i)->second.size());
		for (int j = 0; j < m.find(i)->second.size(); j++)
		{
			printf("\n%s", m.find(i)->second[j].c_str());
		}
	}
	return 0;
}