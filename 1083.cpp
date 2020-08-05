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
//a-z 97-122
//1060
using namespace std;

int main()
{
	vector<student> s;
	int count = 0;
	int flag = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; ++i)
	{
		cin >> stu.name >> stu.id >> stu.grade;
		s.push_back(stu);
	}
	sort(s.begin(), s.end(), cmp);
	int lowBase = 0;
	int highBase = 0;
	scanf("%d %d", &lowBase, &highBase);
	for (int i = 0; i < count; ++i)
	{
		if (s[i].grade >= lowBase && s[i].grade <= highBase)
		{
			if (flag != 0)
			{
				printf("\n");
			}
			flag = 1;
			printf("%s %s", s[i].name.c_str(), s[i].id.c_str());
		}
	}
	if (flag == 0)
	{
		printf("NONE");
	}
	return 0;
}

bool cmp(student a, student b)
{
	return a.grade > b.grade;
}