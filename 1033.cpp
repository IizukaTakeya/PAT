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
//1033
//和路径内所有的距离的加油站进行价格比较
struct station
{
	double price = 0;
	double position = 0;
};
station sta;
bool cmpBydis(station a, station b);
int main()
{
	vector<station> v;
	double capacity = 0;
	double totalDis = 0;
	double avgDis = 0;
	double stationCount = 0;
	scanf("%lf %lf %lf %lf", &capacity, &totalDis, &avgDis, &stationCount);
	for (int i = 0; i < stationCount; i++)
	{
		scanf("%lf %lf", &sta.price, &sta.position);
		v.push_back(sta);
	}
	sort(v.begin(), v.end(), cmpBydis);
	if (v[0].position != 0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double currCost = 0;
	double gasSpace = 0;
	for (int i = 0; i < v.size();)
	{
		if (i != v.size() - 1)
		{
			if (v[i + 1].position - v[i].position > capacity * avgDis)
			{
				printf("The maximum travel distance = %.2lf", double(v[i].position) + capacity * avgDis);
				return 0;
			}
		}
		else
		{
			if (totalDis - v[i].position > capacity * avgDis)
			{
				printf("The maximum travel distance = %.2lf", double(v[i].position) + capacity * avgDis);
				return 0;
			}
		}
		if (gasSpace * avgDis >= totalDis - v[i].position)
		{
			break;
		}
		//每当有一个更小的值就立刻划水过去
		int j = i + 1;
		int flag = 0;
		for (; j < v.size() && v[j].position - v[i].position <= capacity * avgDis; j++)
		{
			if (v[i].price >= v[j].price)
			{
				//cout << v[i].position << " " << v[j].position << endl;
				currCost += max((v[j].position - v[i].position - gasSpace * avgDis) * v[i].price / avgDis, 0.0);
				gasSpace = max(gasSpace - (v[j].position - v[i].position) / avgDis, 0.0);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			if (capacity * avgDis >= totalDis - v[i].position)
			{
				currCost += max((v[i].price * (totalDis - v[i].position) / avgDis - gasSpace), 0.0);
				break;
			}
			//cout << v[i].position << " " << v[j].position << endl;
			j--;
			currCost += v[i].price * (capacity - gasSpace);
			gasSpace = capacity - (v[j].position - v[i].position) / avgDis;
		}
		i = j;
		//printf("%.2lf %lf %lf\n", currCost, v[i].position, gasSpace);
	}
	printf("%.2lf", currCost);
	return 0;
}

bool cmpBydis(station a, station b)
{
	if (a.position == b.position)
	{
		return a.price < b.price;
	}
	return a.position < b.position;
}