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
//1012
using namespace std;

string subject[4] = { "C","M","E","A" };

struct student
{
	string id;
	int c = 0;
	int m = 0;
	int e = 0;
	int a = 0;
	string bestSubject;
	int bestRank = 0;
	int currRank = 0;
};

student stu;

bool cmp1(student a, student b);
bool cmp2(student a, student b);
bool cmp3(student a, student b);
bool cmp4(student a, student b);
int main()
{
	string s1;
	int count1 = 0;
	int count2 = 0;
	int currRank = 0;
	scanf("%d %d", &count1, &count2);
	vector <student> s;
	for (int i = 0; i < count1; ++i)
	{
		cin >> stu.id >> stu.c >> stu.m >> stu.e;
		stu.a = stu.c + stu.m + stu.e;
		stu.bestSubject = "A";
		s.push_back(stu);
	}
	sort(s.begin(), s.end(), cmp1);
	for (int i = 0; i < count1; ++i)
	{
		if (i >= 1 && s[i].a == s[i - 1].a)
		{
			s[i].bestRank = s[i - 1].bestRank;
		}
		else
		{
			s[i].bestRank = i + 1;
		}
	}
	sort(s.begin(), s.end(), cmp2);
	for (int i = 0; i < count1; ++i)
	{
		if (i >= 1 && s[i].c == s[i - 1].c)
		{
			s[i].currRank = s[i - 1].currRank;
		}
		else
		{
			s[i].currRank = i + 1;
		}
		if (s[i].currRank < s[i].bestRank)
		{
			s[i].bestRank = s[i].currRank;
			s[i].bestSubject = "C";
		}
	}
	sort(s.begin(), s.end(), cmp3);
	for (int i = 0; i < count1; ++i)
	{
		if (i >= 1 && s[i].m == s[i - 1].m)
		{
			s[i].currRank = s[i - 1].currRank;
		}
		else
		{
			s[i].currRank = i + 1;
		}
		if (s[i].currRank < s[i].bestRank)
		{
			s[i].bestRank = s[i].currRank;
			s[i].bestSubject = "M";
		}
	}
	sort(s.begin(), s.end(), cmp4);
	for (int i = 0; i < count1; ++i)
	{
		if (i >= 1 && s[i].e == s[i - 1].e)
		{
			s[i].currRank = s[i - 1].currRank;
		}
		else
		{
			s[i].currRank = i + 1;
		}
		if (s[i].currRank < s[i].bestRank)
		{
			s[i].bestRank = s[i].currRank;
			s[i].bestSubject = "E";
		}
	}
	for (int i = 0; i < count2; ++i)
	{
		cin >> s1;
		for (int j = 0; j < count1; ++j)
		{
			if (s1 == s[j].id)
			{
				cout << s[j].bestRank << " " << s[j].bestSubject;
				break;
			}
			if (j == count1 - 1)
			{
				cout << "N/A";
			}
		}
		if (i != count2 - 1)
		{
			cout << endl;
		}
	}
	return 0;
}

bool cmp1(student a, student b)
{
	if (a.a == b.a)
	{
		return a.id < b.id;
	}
	return a.a > b.a;
}
bool cmp2(student a, student b)
{
	if (a.c == b.c)
	{
		return a.id < b.id;
	}
	return a.c > b.c;
}
bool cmp3(student a, student b)
{
	if (a.m == b.m)
	{
		return a.id < b.id;
	}
	return a.m > b.m;
}
bool cmp4(student a, student b)
{
	if (a.e == b.e)
	{
		return a.id < b.id;
	}
	return a.e > b.e;
}