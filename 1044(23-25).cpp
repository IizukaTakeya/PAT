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
//1044
using namespace std;
int main()
{
	int count = 0;
	int sum = 0;
	scanf("%d %d", &count, &sum);
	//int* diamonds = new int[count + 1];
	vector<int> diamonds;
	vector<int> v;
	diamonds.push_back(0);
	diamonds.resize(count + 1);
	int bestSum = INT_MAX;
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &diamonds[i + 1]);
		diamonds[i + 1] += diamonds[i];
		//cout << diamonds[i + 1] << "    " << i << "    " << var << endl;
	}
	//cout << diamonds.size();
	int flag = 0;
	int n = count;
	int m = 0;
	while (true)
	{
		if (flag == 1)
		{
			m++;
			n = count;
			flag = 0;
		}
		if (m >= count || diamonds[count] - diamonds[m] < sum)
		{
			break;
		}
		if (diamonds[n] - diamonds[m] >= sum)
		{
			if (diamonds[n] - diamonds[m] < bestSum)
			{
				bestSum = diamonds[n] - diamonds[m];
				v.clear();
				v.push_back(m + 1);
				v.push_back(n);
			}
			else if (diamonds[n] - diamonds[m] == bestSum)
			{
				v.push_back(m + 1);
				v.push_back(n);
			}
			if (diamonds[n - 1] - diamonds[m] < sum)
			{
				flag = 1;
				continue;
			}
			n = (m + n) / 2;
		}
		else
		{
			if (diamonds[n + 1] - diamonds[m] > bestSum)//’‚¿Ô”–¥ÌŒÛ
			{
				flag = 1;
				continue;
			}
			n = (count + n) / 2;
		}
	}
	for (int i = 0; i < v.size(); i += 2)
	{
		if (i != 0)
		{
			printf("\n");
		}
		printf("%d-%d", v[i], v[i + 1]);
	}
	return 0;
}