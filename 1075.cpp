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
//1075
struct student
{
	int studentId;
	int score[6] = { 0 };
	int flag[6] = { 0 };
	int fullCount = 0;
	int passFlag = 0;
	int totalScore = 0;
	int rank = 0;
};

student stu;

bool cmp(student a, student b);

int main()
{
	int studentCount = 0;
	int questionCount = 0;
	int submission = 0;
	int flag2 = 0;
	cin >> studentCount >> questionCount >> submission;
	int* fullScore = new int[questionCount + 1];
	fullScore[0] = 0;
	vector<student> s;
	for (int i = 0; i < questionCount; ++i)
	{
		cin >> fullScore[i + 1];
	}
	for (int i = 0; i < studentCount + 1; ++i)
	{
		stu.studentId = i;
		s.push_back(stu);
	}
	for (int i = 0; i < submission; ++i)
	{
		int currStudentId = 0;
		int currQuestionNum = 0;
		int currScore = 0;
		cin >> currStudentId >> currQuestionNum >> currScore;
		s[currStudentId].flag[currQuestionNum] = 1;
		if (currScore >= 0)
		{
			s[currStudentId].passFlag = 1;
		}
		if (s[currStudentId].score[currQuestionNum] < currScore)
		{
			s[currStudentId].score[currQuestionNum] = currScore;
			if (currScore == fullScore[currQuestionNum])
			{
				++s[currStudentId].fullCount;
			}
		}
	}
	for (int i = 1; i <= studentCount; ++i)
	{
		for (int j = 1; j <= questionCount; ++j)
		{
			s[i].totalScore += s[i].score[j];
		}
	}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i <= studentCount; ++i)
	{
		if (i > 0 && s[i].totalScore == s[i - 1].totalScore)
		{
			s[i].rank = s[i - 1].rank;
		}
		else
		{
			s[i].rank = i + 1;
		}
	}
	for (int i = 0; i <= studentCount; ++i)
	{
		if (s[i].passFlag != 0)
		{
			if (flag2 == 1)
			{
				cout << endl;
			}
			cout << s[i].rank << " ";
			printf("%05d ", s[i].studentId);
			cout << s[i].totalScore;
			for (int j = 1; j <= questionCount; ++j)
			{
				cout << " ";
				if (s[i].flag[j] != 0)
				{
					cout << s[i].score[j];
				}
				else
				{
					cout << "-";
				}
			}
			flag2 = 1;
		}
	}
	return 0;
}

bool cmp(student a, student b)
{
	if (a.totalScore == b.totalScore)
	{
		if (a.fullCount == b.fullCount)
		{
			return a.studentId < b.studentId;
		}
		else
		{
			return a.fullCount > b.fullCount;
		}
	}
	return a.totalScore > b.totalScore;
}