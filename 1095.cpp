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
//1095

struct cars
{
	string id;
	int status = -1;
	int time = 0;
};
cars car;
bool cmpByCar(cars a, cars b);
bool cmpByTime(cars a, cars b);
int main()
{
	vector<string> sCars;
	vector<cars> v;
	int count1 = 0;
	int count2 = 0;
	int maxDiffTime = 0;
	int currDiffTime = 0;
	int currDiffSumTime = 0;
	scanf("%d %d", &count1, &count2);
	for (int i = 0; i < count1; ++i)
	{
		string stus;
		int var1 = 0;
		int var2 = 0;
		int var3 = 0;
		cin >> car.id;
		scanf("%d:%d:%d", &var1, &var2, &var3);
		cin >> stus;
		car.time = var1 * 60 * 60 + var2 * 60 + var3;
		stus == "in" ? car.status = 0 : car.status = 1;
		v.push_back(car);
	}
	sort(v.begin(), v.end(), cmpByCar);
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].status == 0)
		{
			if (i == v.size() - 1 || v[i + 1].status != 1 || v[i + 1].id != v[i].id)
			{
				v.erase(v.begin() + i);
				--i;
			}
		}
		else
		{
			if (i == 0 || v[i - 1].status != 0 || v[i - 1].id != v[i].id)
			{
				v.erase(v.begin() + i);
				--i;
			}
		}
	}
	/*for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].id << " " << v[i].time << " " << v[i].status << endl;
	}*/
	for (int i = 0; i < v.size(); i += 2)
	{
		currDiffTime = v[i + 1].time - v[i].time;
		if (i > 0 && v[i].id == v[i - 2].id)
		{
			currDiffSumTime += currDiffTime;
		}
		else
		{
			currDiffSumTime = currDiffTime;
		}
		if (currDiffSumTime > maxDiffTime)
		{
			sCars.clear();
			maxDiffTime = currDiffSumTime;
			sCars.push_back(v[i].id);
		}
		else if (currDiffSumTime == maxDiffTime)
		{
			sCars.push_back(v[i].id);
		}
	}
	sort(v.begin(), v.end(), cmpByTime);
	int j = 0;
	int currCount = 0;
	for (int i = 0; i < count2; ++i)
	{
		int var1 = 0;
		int var2 = 0;
		int var3 = 0;
		scanf("%d:%d:%d", &var1, &var2, &var3);
		int currTime = 0;
		currTime = var1 * 60 * 60 + var2 * 60 + var3;
		//对车辆数按时间递增记录
		for (; j < v.size(); j++)
		{
			if (v[j].time <= currTime)
			{
				if (v[j].status == 0)
				{
					currCount++;
				}
				else if (v[j].status == 1)
				{
					currCount--;
				}
			}
			else
			{
				break;
			}
		}
		printf("%d\n", currCount);
	}
	for (int i = 0; i < sCars.size(); ++i)
	{
		//cout << sCars[i] << " ";
		printf("%s ", sCars[i].c_str());
	}
	//cout << maxDiffTime / 60 / 60 << ":" << (maxDiffTime - maxDiffTime / 60 / 60 * 60 * 60) / 60 << ":" << maxDiffTime % 60;
	printf("%02d:%02d:%02d", maxDiffTime / 3600, (maxDiffTime - maxDiffTime / 3600 * 3600) / 60, maxDiffTime % 60);
	return 0;
}

bool cmpByCar(cars a, cars b)
{
	if (a.id == b.id)
	{
		return a.time < b.time;
	}
	return a.id < b.id;
}
bool cmpByTime(cars a, cars b)
{
	return a.time < b.time;
}