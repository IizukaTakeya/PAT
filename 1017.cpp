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
	long long num = 0;
	long long base = 0;
	cin >> num >> base;
	vector<int> v1;
	vector<int> v2;
	while (num > 0)
	{
		v1.push_back(num % base);
		num /= base;
	}
	v2 = v1;
	reverse(v1.begin(), v1.end());
	if (v1 == v2)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i];
		if (i < v1.size() - 1)
		{
			cout << " ";
		}
	}
	return 0;
}