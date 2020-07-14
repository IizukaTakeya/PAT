#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;
/*int main()
{
	int a, b;
	// char c;
	scanf("%d/%d", &a, &b);
	// cin>>a>>c>>b;
	cout << a << endl << b;
	return 0;
}*/
int main()
{
	int count = 0;
	cin >> count;
	getchar();
	vector<long long> v1;
	vector<long long> v2;
	vector<long long> v3;
	int mark = 0;
	for (int i = 0; i < count; i++)
	{
		long long l1 = 0;
		long long l2 = 0;
		scanf("%lld/%lld", &l1, &l2);
		v1.push_back(l1);
		v2.push_back(l2);
	}
	v3 = v2;
	/*for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << "\t";
	}*/
	sort(v3.begin(), v3.end());
	long long times = v3[v3.size() - 1];
	long long result = 0;
	for (int i = 1;; i++)
	{
		times = v3[v3.size() - 1] * i;
		for (int j = 0; j < v2.size(); j++)
		{
			if (times % v2[j] != 0)
			{
				break;
			}
			if (j == v2.size() - 1)
			{
				mark = 1;
				break;
			}
		}
		if (mark == 1)
		{
			break;
		}
	}
	for (int i = 0; i < count; i++)
	{
		v1[i] *= (times / v2[i]);
		result += v1[i];
	}
	if (result == 0)
	{
		cout << "0";
		return 0;
	}
	for (int i = 2; i < min(abs(result), times); i++)
	{
		if (abs(result) % i == 0 && times % i == 0)
		{
			result /= i;
			times /= i;
			i--;
		}
	}
	if (abs(result) > times)
	{
		cout << result / times;
		if (result % times != 0)
		{
			cout << " ";
		}
	}
	if (result % times != 0)
	{
		cout << result % times << "/" << times;
	}
	return 0;
}