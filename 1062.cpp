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
	string id;
	int virtue = 0;
	int talent = 0;
};

student stu;

bool cmp(student a, student b);

int main()
{
	int count = 0;
	int cnt = 0;
	int lowBase = 0;
	int highBase = 0;
	vector<student> s1;
	vector<student> s2;
	vector<student> s3;
	vector<student> s4;
	scanf("%d %d %d", &count, &lowBase, &highBase);
	for (int i = 0; i < count; ++i)
	{
		cin >> stu.id >> stu.virtue >> stu.talent;
		if (stu.virtue >= lowBase && stu.talent >= lowBase)
		{
			if (stu.virtue >= highBase && stu.talent >= highBase)
			{
				s1.push_back(stu);
				//cout << endl << 1 << endl;
				++cnt;
			}
			else if (stu.virtue >= highBase && stu.talent < highBase)
			{
				s2.push_back(stu);
				//cout << endl << 2 << endl;
				++cnt;
			}
			else if (stu.virtue >= stu.talent && stu.virtue < highBase && stu.talent < highBase)
			{
				s3.push_back(stu);
				//cout << endl << 3 << endl;
				++cnt;
			}
			else
			{
				s4.push_back(stu);
				//cout << endl << 4 << endl;
				++cnt;
			}
		}
	}
	printf("%d", cnt);
	sort(s1.begin(), s1.end(), cmp);
	sort(s2.begin(), s2.end(), cmp);
	sort(s3.begin(), s3.end(), cmp);
	sort(s4.begin(), s4.end(), cmp);
	for (int i = 0; i < s1.size(); ++i)
	{
		printf("\n%s %d %d", s1[i].id.c_str(), s1[i].virtue, s1[i].talent);
	}
	for (int i = 0; i < s2.size(); ++i)
	{
		printf("\n%s %d %d", s2[i].id.c_str(), s2[i].virtue, s2[i].talent);
	}
	for (int i = 0; i < s3.size(); ++i)
	{
		printf("\n%s %d %d", s3[i].id.c_str(), s3[i].virtue, s3[i].talent);
	}
	for (int i = 0; i < s4.size(); ++i)
	{
		printf("\n%s %d %d", s4[i].id.c_str(), s4[i].virtue, s4[i].talent);
	}
	return 0;
}

bool cmp(student a, student b)
{
	if (a.virtue + a.talent == b.virtue + b.talent)
	{
		if (a.talent == b.talent)
		{
			return a.id < b.id;
		}
		else
		{
			return a.virtue > b.virtue;
		}
	}
	return a.virtue + a.talent > b.virtue + b.talent;
}