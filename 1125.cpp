#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	if (count < 2)
	{
		cout << "0";
		return 0;
	}
	int d = 0;
	vector<int> v;
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> d;
		v.push_back(d);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < count; i++)
	{
		result += v[i];
		if (i > 0)
		{
			result /= 2;
		}
	}
	cout << result;
	return 0;
}