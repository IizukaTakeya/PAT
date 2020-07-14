#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	string s;
	vector<int> v;
	for (int i = 0; i < count; i++)
	{
		cin >> s;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			sum += s[i] - '0';
		}
		v.push_back(sum);
	}
	set<int>e(v.begin(), v.end());
	v.assign(e.begin(), e.end());
	cout << v.size() << endl;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
		{
			cout << " ";
		}
	}
	return 0;
}