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
//1067
//0 2 1
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	int times = 0;
	times = count - 2;
	int* num = new int[count];
	int* mark = new int[count];
	int markCount = 0;
	int flag = 0;
	int j = 0;
	for (int i = 0; i < count; ++i)
	{
		cin >> num[i];
		mark[i] = 0;
		if (num[i] != i)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "0";
		return 0;
	}
	for (int i = 0; i < count; ++i)
	{
		if (markCount == count)
		{
			break;
		}
		if (mark[i] == 0)
		{
			if (num[i] == i)
			{
				mark[i] = 1;
				markCount += 1;
				times -= 1;
			}
			else
			{
				j = i;
				while (num[j] != i)
				{
					mark[j] = 1;
					j = num[j];
					markCount += 1;
				}
				mark[j] = 1;
				markCount += 1;
				times += 1;
			}
		}
	}
	if (num[0] == 0)
	{
		times += 2;
	}
	cout << times;
	return 0;
}