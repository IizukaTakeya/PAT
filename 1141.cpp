#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#pragma warning(disable:4996)
//a-z 97-122
//1141
using namespace std;

struct student
{
	string id;
	double score = 0;
	string school;
};
student stu;
bool cmpStudent(student a, student b);
struct schoolRank
{
	int rank = -1;
	string school;
	int totalScore = 0;
	int ns = 0;
};
schoolRank scr;
bool cmpSchool(schoolRank a, schoolRank b);
int main()
{
	vector <student> v1;
	vector <schoolRank> v2;
	int count = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		cin >> stu.id;
		double var1 = 0.0;
		scanf("%lf", &stu.score);
		cin >> stu.school;
		for (unsigned int j = 0; j < stu.school.size(); j++)
		{
			stu.school[j] = tolower(stu.school[j]);
		}
		if (stu.id[0] == 'B')
		{
			stu.score /= 1.5;
		}
		if (stu.id[0] == 'T')
		{
			stu.score *= 1.5;
		}
		v1.push_back(stu);
	}
	sort(v1.begin(), v1.end(), cmpStudent);
	/*for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i].id << " " << v1[i].score << " " << v1[i].school << endl;
	}*/
	double currScore = 0;
	string currSchool;
	int flag = 0;
	for (int i = 0; i < count; i++)
	{
		if (flag == 0)
		{
			flag = 1;
			currScore += v1[i].score;
			currSchool = v1[i].school;
			++scr.ns;
		}
		else
		{
			if (v1[i].school == currSchool)
			{
				currScore += v1[i].score;
				++scr.ns;
			}
			else
			{
				scr.school = currSchool;
				scr.totalScore = currScore;
				v2.push_back(scr);
				currScore = 0;
				flag = 0;
				scr.ns = 0;
				i--;
			}
		}
	}
	scr.totalScore = currScore;
	scr.school = currSchool;
	v2.push_back(scr);
	sort(v2.begin(), v2.end(), cmpSchool);
	/*for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i].school << " " << v2[i].totalScore << " " << endl;
	}*/
	printf("%d", v2.size());
	for (int i = 0; i < v2.size(); i++)
	{
		if (i == 0)
		{
			v2[i].rank = 1;
		}
		else
		{
			if (v2[i].totalScore == v2[i - 1].totalScore)
			{
				v2[i].rank = v2[i - 1].rank;
			}
			else
			{
				v2[i].rank = i + 1;
			}
		}
		printf("\n%d %s %d %d", v2[i].rank, v2[i].school.c_str(), v2[i].totalScore, v2[i].ns);
	}
	return 0;
}
bool cmpStudent(student a, student b)
{
	return a.school < b.school;
}
bool cmpSchool(schoolRank a, schoolRank b)
{
	if (a.totalScore == b.totalScore)
	{
		if (a.ns == b.ns)
		{
			return a.school < b.school;
		}
		return a.ns < b.ns;
	}
	return a.totalScore > b.totalScore;
}