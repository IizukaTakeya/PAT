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
//a-z 97-122
//1080
//和录取最后一名排名相同即可
//填好录取学校之后再填志愿
struct student
{
	int id = 0;
	int EScore = 0;
	int IScore = 0;
	int totalScore = 0;
	int rank = 0;
	int application[5] = { -1,-1,-1,-1,-1 };
	int acceptedApp = -1;
};
student stu;
bool cmp1(student a, student b);
bool cmp2(student a, student b);
int main()
{
	vector<student> v;
	int currStu = 0;
	int studentCount = 0;
	int schoolCount = 0;
	int applicantCount = 0;
	scanf("%d%d%d", &studentCount, &schoolCount, &applicantCount);
	int* quota = new int[schoolCount];
	int school[100] = { 0 };
	int schoolRank[100] = { 0 };
	fill(schoolRank, schoolRank + 100, -1);
	for (int i = 0; i < schoolCount; ++i)
	{
		scanf("%d", &quota[i]);
	}
	for (int i = 0; i < studentCount; ++i)
	{
		stu.id = i;
		scanf("%d %d", &stu.EScore, &stu.IScore);
		stu.totalScore = stu.EScore + stu.IScore;
		for (int j = 0; j < applicantCount; ++j)
		{
			scanf("%d", &stu.application[j]);
		}
		v.push_back(stu);
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < v.size(); ++i)
	{
		if (i >= 1 && v[i].EScore == v[i - 1].EScore && v[i].IScore == v[i - 1].IScore)
		{
			v[i].rank = v[i - 1].rank;
		}
		else
		{
			v[i].rank = i;
		}
	}
	/*for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].rank << " " << v[i].id << " " << v[i].totalScore << endl;
	}*/
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < applicantCount; ++j)
		{
			if (school[v[i].application[j]] < quota[v[i].application[j]] || v[i].rank == schoolRank[v[i].application[j]])
			{
				++school[v[i].application[j]];
				v[i].acceptedApp = v[i].application[j];
				schoolRank[v[i].application[j]] = v[i].rank;
				break;
			}
		}
	}
	sort(v.begin(), v.end(), cmp2);
	/*for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].acceptedApp != -1)
		{
			break;
		}
		if (i == v.size() - 1)
		{
			return 0;
		}
	}*/
	for (int i = 0; i < schoolCount; ++i)
	{
		int flag = 0;
		if (i > 0)
		{
			printf("\n");
		}
		for (int j = currStu; j < studentCount; ++j)
		{
			if (flag == 1 && v[j].acceptedApp == i)
			{
				printf(" ");
			}
			if (v[j].acceptedApp == i)
			{
				printf("%d", v[j].id);
				flag = 1;
			}
			else if (v[j].acceptedApp > i)
			{
				break;
			}
		}
	}
	cout << endl;
	//为什么最后一行要输出换行？？？
	return 0;
}

bool cmp1(student a, student b)
{
	if (a.totalScore == b.totalScore)
	{
		return a.EScore > b.EScore;
	}
	return a.totalScore > b.totalScore;
}
bool cmp2(student a, student b)
{
	if (a.acceptedApp == b.acceptedApp)
	{
		return a.id < b.id;
	}
	return a.acceptedApp < b.acceptedApp;
}