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
//1037
//测试点3是全部卖完的情况
using namespace std;

struct mooncake
{
	int id = 0;
	double amount = 0;
	double cost = 0;
};

mooncake moon;

bool cmp(mooncake a, mooncake b);
int main()
{
	vector<mooncake> m;
	int type = 0;
	double total = 0;
	double spent = 0;
	scanf("%d %lf", &type, &total);
	//cout << type << " " << total << endl;
	double* stock = new double[type];
	for (int i = 0; i < type; ++i)
	{
		scanf("%lf", &stock[i]);
	}
	double* money = new double[type];
	for (int i = 0; i < type; ++i)
	{
		scanf("%lf", &money[i]);
	}
	double* price = new double[type];
	for (int i = 0; i < type; ++i)
	{
		price[i] = money[i] / stock[i];
	}
	for (int i = 0; i < type; ++i)
	{
		moon.id = i;
		moon.amount = stock[i];
		moon.cost = price[i];
		m.push_back(moon);
	}
	sort(m.begin(), m.end(), cmp);
	/*for (int i = 0; i < type; ++i)
	{
		cout << m[i].amount << " " << m[i].cost << endl;
	}*/
	int i = 0;
	while (total > 0)
	{
		if (total > m[i].amount)
		{
			spent += m[i].cost * m[i].amount;
			total -= m[i].amount;
			++i;
			if (i == type)
			{
				printf("%.2lf", spent);
				return 0;
			}
			continue;
		}
		else
		{
			spent += m[i].cost * total;
			total = 0;
			printf("%.2lf", spent);
		}
	}
	return 0;
}

bool cmp(mooncake a, mooncake b)
{
	if (a.cost == b.cost)
	{
		return a.id < b.id;
	}
	return a.cost > b.cost;
}