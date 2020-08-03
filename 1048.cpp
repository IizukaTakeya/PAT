#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
//#pragma warning(disable:4996)
//a-z 97-122
//1048
using namespace std;
int main()
{
	int count = 0;
	int sum = 0;
	cin >> count >> sum;
	vector<int> num;
	for (int i = 0; i < count; ++i)
	{
		int v = 0;
		cin >> v;
		if (v < sum)
		{
			num.push_back(v);
		}
	}
	sort(num.begin(), num.end());
	if (num.size() < 2)
	{
		cout << "No Solution";
		return 0;
	}
	if (num[num.size() - 2] + num[num.size() - 1] < sum)
	{
		//cout << num[num.size() - 2] << endl << num[num.size() - 1];
		cout << "No Solution";
		return 0;
	}
	int i = 0;
	int j = num.size() - 1;
	//cout << i << endl << j;
	//cout << num[i] << endl << num[j] << endl << num[i] + num[j];
	while (i < j)
	{
		//cout << i << endl << j;
		if (num[i] + num[j] > sum)
		{
			--j;
			continue;
		}
		else if (num[i] + num[j] == sum)
		{
			cout << num[i] << " " << num[j];
			return 0;
		}
		else if (num[i] + num[j] < sum)
		{
			if (j != num.size() - 1)
			{
				++j;
			}
			++i;
			continue;
		}
	}
	cout << "No Solution";
	return 0;
}