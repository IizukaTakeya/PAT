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
//1060
using namespace std;

string convert(string s, int n);

int main()
{
	int count = 0;
	scanf("%d", &count);
	string s1;
	string s2;
	cin >> s1 >> s2;
	s1 = convert(s1, count);
	s2 = convert(s2, count);
	if (s1 == s2)
	{
		printf("YES %s", s1.c_str());
	}
	else
	{
		printf("NO %s %s", s1.c_str(), s2.c_str());
	}
	return 0;
}

string convert(string s, int n)
{
	int exponent = 0;
	string sv = "0.";
	string base;
	//cout << expon;
	int zeroFlag = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '0' && s[i] != '.')
		{
			zeroFlag = 1;
			break;
		}
	}
	//cout << zeroFlag;
	if (zeroFlag == 0)
	{
		for (int i = 0; i < n; i++)
		{
			sv += '0';
		}
		sv += "*10^0";
		return sv;
	}
	//判断为0
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	//去除小数点前0
	if (s[0] != '.')
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.')
			{
				s.erase(i, 1);
				exponent = i;
				break;
			}
			if (i == s.size() - 1)
			{
				exponent = s.size();
			}
		}
	}
	else
	{
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != '0')
			{
				exponent = -i + 1;
				break;
			}
		}
		s.erase(0, -exponent + 1);
	}
	//排除小数点,判断位数
	while (s.size() < n)
	{
		s = s + '0';
	}
	if (s.size() > n)
	{
		s = s.substr(0, n);
	}
	string expon = "*10^" + to_string(exponent);
	sv = sv + s + expon;
	return sv;
}