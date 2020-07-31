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
//1121
using namespace std;
int couple[1000000];
int main()
{
	int flag = 0;
	int markCount = 0;
	fill(couple, couple + 1000000, -1);
	int count1 = 0;
	cin >> count1;
	for (int i = 0; i < count1; ++i)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		couple[a] = b;
		couple[b] = a;
	}
	int count2 = 0;
	cin >> count2;
	int* number = new int[count2];
	int* mark = new int[count2];
	for (int i = 0; i < count2; ++i)
	{
		cin >> number[i];
		mark[i] = 0;
	}
	sort(number, number + count2);
	for (int i = 0; i < count2; ++i)
	{
		if (couple[number[i]] != -1)
		{
			int* position = 0;
			position = find(number, number + count2, couple[number[i]]);
			if (position != number + count2)
			{
				markCount -= 1;
				mark[i] = 1;
			}
		}
		markCount += 1;
	}
	cout << markCount;
	if (markCount != 0)
	{
		cout << endl;
	}
	for (int i = 0; i < count2; ++i)
	{
		if (mark[i] == 0)
		{
			if (flag == 1)
			{
				cout << " ";
			}
			printf("%05d", number[i]);
			flag = 1;
		}
	}
	return 0;
}