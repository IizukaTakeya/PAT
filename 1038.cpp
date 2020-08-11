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
//1038
bool cmp(string a, string b);
int main()
{
	vector<string> v;
	string s;
	string str;
	int count = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < count; i++)
	{
		str = str + v[i];
	}
	while (str[0] == '0')
	{
		str.erase(0, 1);
	}
	if (str.size() != 0)
	{
		printf("%s", str.c_str());
	}
	else
	{
		printf("0");
	}
	return 0;
}

bool cmp(string a, string b)
{
	string s1 = a + b;;
	string s2 = b + a;
	return s1 < s2;
}