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
//1016
//within a single month?
double charge[24] = { 0 };

struct record
{
	string name;
	int month = 0;
	int day = 0;
	int hour = 0;
	int minute = 0;
	int flag = 0;
};

record rec;
bool cmp(record a, record b);
double cost(int beginMinute, int endMinute);
int main()
{
	vector<record> v;
	for (int i = 0; i < 24; ++i)
	{
		double var1 = 0;
		cin >> var1;
		charge[i] = var1 / 100;
	}
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> rec.name;
		string s;
		scanf("%d:%d:%d:%d", &rec.month, &rec.day, &rec.hour, &rec.minute);
		cin >> s;
		s == "on-line" ? rec.flag = 0 : rec.flag = 1;
		v.push_back(rec);
		
	}
	sort(v.begin(), v.end(), cmp);
	/*for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].name << "-" << v[i].day << "-" << v[i].flag << endl;
	}
	cout << endl << endl;*/
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].flag == 0)
		{
			if (i == v.size() - 1 || v[i + 1].flag != 1 || v[i + 1].name != v[i].name)
			{
				v.erase(v.begin() + i);
				--i;
			}
		}
		else
		{
			if (v[i - 1].flag != 0 || v[i - 1].name != v[i].name)
			{
				v.erase(v.begin() + i);
				--i;
			}
		}
	}
	if (v.size() == 0)
	{
		return 0;
	}
	/*for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].name << "-" << v[i].day << "-" << v[i].flag << endl;
	}*/
	string s1;
	string s2;
	int userFlag = 0;
	double currBill = 0;
	double totalBill = 0;
	int beginMinute = 0;
	int endMinute = 0;
	int diffMinute = 0;
	for (int i = 0; i < v.size(); i += 2)
	{
		if (userFlag == 0)
		{
			s1 = v[i].name;
			userFlag = 1;
			printf("%s %02d", s1.c_str(), v[i].month);
		}
		beginMinute = v[i].day * 24 * 60 + v[i].hour * 60 + v[i].minute;
		endMinute = v[i + 1].day * 24 * 60 + v[i + 1].hour * 60 + v[i + 1].minute;
		diffMinute = endMinute - beginMinute;
		currBill = cost(beginMinute, endMinute);
		if (userFlag == 1 && s1 != v[i].name)
		{
			s1 = v[i].name;
			printf("\nTotal amount: $%.2lf", totalBill);
			printf("\n%s %02d", s1.c_str(), v[i].month);
			totalBill = 0;
		}
		totalBill += currBill;
		printf("\n%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf", v[i].day, v[i].hour, v[i].minute, v[i + 1].day, v[i + 1].hour, v[i + 1].minute, diffMinute, currBill);
	}
	if (v.size() != 2)
	{
		printf("\nTotal amount: $%.2lf", totalBill);
	}
	return 0;
}

bool cmp(record a,record b)
{
	if (a.name == b.name)
	{
		if (a.day == b.day)
		{
			if (a.hour == b.hour)
			{
				return a.minute < b.minute;
			}
			else
			{
				return a.hour < b.hour;
			}
		}
		else
		{
			return a.day < b.day;
		}
	}
	return a.name < b.name;
}

double cost(int beginMinute, int endMinute)
{
	double price = 0;
	for (int i = beginMinute; i < endMinute; ++i)
	{
		price += charge[((i % (24 * 60)) / 60)];
	}
	return price;
}