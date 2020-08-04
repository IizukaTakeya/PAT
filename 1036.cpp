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
//1036
using namespace std;

struct student
{
	string name;
	string gender;
	string id;
	int score = 0;
};

student stu;

bool cmp(student a, student b);

int main()
{
	int count = 0;
	scanf("%d", &count);
	int maleMark = 0;
	int femaleMark = 0;
	vector<student> maleGroup;
	vector<student> femaleGroup;
	int flag = 1;
	for (int i = 0; i < count; ++i)
	{
		cin >> stu.name >> stu.gender >> stu.id >> stu.score;
		if (stu.gender == "M")
		{
			maleMark = 1;
			maleGroup.push_back(stu);
		}
		if (stu.gender == "F")
		{
			femaleMark = 1;
			femaleGroup.push_back(stu);
		}
	}
	if (femaleMark == 1)
	{
		sort(femaleGroup.begin(), femaleGroup.end(), cmp);
		printf("%s %s", femaleGroup[femaleGroup.size() - 1].name.c_str(), femaleGroup[femaleGroup.size() - 1].id.c_str());
	}
	else
	{
		flag = 0;
		printf("Absent");
	}
	printf("\n");
	if (maleMark == 1)
	{
		sort(maleGroup.begin(), maleGroup.end(), cmp);
		printf("%s %s", maleGroup[0].name.c_str(), maleGroup[0].id.c_str());
	}
	else
	{
		flag = 0;
		printf("Absent");
	}
	printf("\n");
	if (flag == 1)
	{
		printf("%d", femaleGroup[femaleGroup.size() - 1].score - maleGroup[0].score);
	}
	else
	{
		printf("NA");
	}
	return 0;
}


bool cmp(student a, student b)
{
	return a.score < b.score;
}