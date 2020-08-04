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
//1029
using namespace std;
int main()
{
	vector<int> v;
	int count1 = 0;
	cin >> count1;
	for (int i = 0; i < count1; ++i)
	{
		int var = 0;
		scanf("%d", &var);
		v.push_back(var);
	}
	int count2 = 0;
	cin >> count2;
	for (int i = 0; i < count2; ++i)
	{
		int var = 0;
		scanf("%d", &var);
		v.push_back(var);
	}
	sort(v.begin(), v.end());
	cout << v[(count1 + count2 - 1) / 2];
	return 0;
}