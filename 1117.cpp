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
	if (count == 0)
	{
		cout << "0";
		return 0;
	}
	vector<int> v;
	int n = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < count; i++)
	{
		if (v[i] <= i + 1)
		{
			cout << i;
			break;
		}
		if (i == count - 1)
		{
			cout << min(count, v[i] - 1);
		}
	}
	return 0;
}