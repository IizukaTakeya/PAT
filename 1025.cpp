#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;
struct student
{
	string number;
	int score = -1;
	int total_rank = -1;
	int local_rank = -1;
	int group_number = -1;
}stu[30000];
bool cmp(student a, student b)
{
	if (a.score != b.score)
	{
		return a.score > b.score;
	}
	else
	{
		return a.number < b.number;
	}
}
int main()
{
	int groupCount = 0;
	int totalCount = 0;
	cin >> groupCount;
	for (int j = 0; j < groupCount; ++j) 
	{
		int count = 0;
		cin >> count;
		for (int i = totalCount; i < count + totalCount; ++i)
		{
			cin >> stu[i].number >> stu[i].score;
			stu[i].group_number = j + 1;
		}
		sort(stu + totalCount, stu + totalCount + count, cmp);
		for (int i = totalCount; i < count + totalCount; ++i)
		{
			if (i == totalCount)
			{
				stu[i].local_rank = 1;
				continue;
			}
			else
			{
				if (stu[i].score == stu[i - 1].score)
				{
					stu[i].local_rank = stu[i - 1].local_rank;
				}
				else
				{
					stu[i].local_rank = i - totalCount + 1;
				}
			}
		}
		totalCount += count;
	}
	sort(stu, stu + totalCount, cmp);
	for (int i = 0; i < totalCount; ++i)
	{
		if (i == 0)
		{
			stu[i].total_rank = 1;
			continue;
		}
		else
		{
			if (stu[i].score == stu[i - 1].score)
			{
				stu[i].total_rank = stu[i - 1].total_rank;
			}
			else
			{
				stu[i].total_rank = i + 1;
			}
		}
	}
	cout << totalCount;
	for (int i = 0; i < totalCount; ++i)
	{
		cout << endl << stu[i].number << " " << stu[i].total_rank << " " << stu[i].group_number << " " << stu[i].local_rank;
	}
	return 0;
}
