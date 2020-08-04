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
//1029
using namespace std;

struct student
{
	string id;
	string name;
	int score;
};
student stu;
bool cmp1(student a, student b);
bool cmp2(student a, student b);
bool cmp3(student a, student b);
int main()
{
	int count = 0;
	int standard = 0;
	scanf("%d %d", &count, &standard);
	vector<student> s;
	for (int i = 0; i < count; ++i)
	{
		cin >> stu.id >> stu.name >> stu.score;
		s.push_back(stu);
	}
	if (standard == 1)
	{
		sort(s.begin(), s.end(), cmp1);
	}
	if (standard == 2)
	{
		sort(s.begin(), s.end(), cmp2);
	}
	if (standard == 3)
	{
		sort(s.begin(), s.end(), cmp3);
	}
	for (int i = 0; i < count; ++i)
	{
		if (i != 0)
		{
			printf("\n");
		}
		printf("%s %s %d", s[i].id.c_str(), s[i].name.c_str(), s[i].score);
	}
	return 0;
}

bool cmp1(student a, student b)
{
	return a.id < b.id;
}
bool cmp2(student a, student b)
{
	if (a.name == b.name)
	{
		return a.id < b.id;
	}
	else
	{
		return a.name < b.name;
	}
}
bool cmp3(student a, student b)
{
	if (a.score == b.score)
	{
		return a.id < b.id;
	}
	else
	{
		return a.score < b.score;
	}
}