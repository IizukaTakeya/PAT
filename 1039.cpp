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
//1039
using namespace std;

unordered_map<string, vector<int>> m;
vector<string> pntOrder;

int main()
{
	int studentCount = 0;
	int courseCount = 0;
	scanf("%d %d", &studentCount, &courseCount);
	pntOrder.resize(studentCount);
	for (int i = 0; i < courseCount; i++)
	{
		int currCourse = 0;
		int currStudent = 0;
		scanf("%d %d", &currCourse, &currStudent);
		for (int j = 0; j < currStudent; j++)
		{
			string s;
			cin >> s;
			if (m.find(s) == m.end())
			{
				m.insert(make_pair(s, 0));
			}
			m.find(s)->second.push_back(currCourse);
		}
	}
	for (int i = 0; i < studentCount; i++)
	{
		cin >> pntOrder[i];
	}
	for (unordered_map<string, vector<int>>::iterator it = m.begin(); it != m.end(); it++)
	{
		sort(it->second.begin(), it->second.end());
	}
	/*for (unordered_map<string, vector<int>>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "    " << it->second.size() << endl;
		for (int j = 0; j < it->second.size(); j++)
		{
			cout << it->second[j] << "    ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < studentCount; i++)
	{
		if (i > 0)
		{
			printf("\n");
		}
		if (m.find(pntOrder[i]) == m.end())
		{
			printf("%s 0", pntOrder[i].c_str());
			continue;
		}
		printf("%s %d", m.find(pntOrder[i])->first.c_str(), m.find(pntOrder[i])->second.size());
		for (int j = 0; j < m.find(pntOrder[i])->second.size(); j++)
		{
			printf(" %d", m.find(pntOrder[i])->second[j]);
		}
	}
	return 0;
}