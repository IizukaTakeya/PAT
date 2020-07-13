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
	cout << count % 2 << " ";
	vector<int> v;
	int n = 0;
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < count; i++)
	{
		if (i < count / 2)
		{
			result -= v[i];
		}
		else
		{
			result += v[i];
		}
	}
	cout << result;
	return 0;
}