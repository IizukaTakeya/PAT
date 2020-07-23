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
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	int* num = new int[count];
	int maxSum = 0;
	int currSum = 0;
	int maxBegin = 0;
	int currBegin = 0;
	int maxEnd = 0;
	int reset = 0;
	int flag = 0;
	for (int i = 0; i < count; ++i)
	{
		cin >> num[i];
		if (num[i] >= 0)
		{
			flag = 1;
		}
	}
	for (int i = 0; i < count; ++i)
	{
		if (reset == 0)
		{
			currBegin = i;
			reset = 1;
			currSum = 0;
		}
		currSum += num[i];
		if (currSum < 0)
		{
			reset = 0;
		}
		if (currSum > maxSum)
		{
			maxEnd = i;
			maxSum = currSum;
			maxBegin = currBegin;
		}
	}
	if ((num[maxBegin] < 0 || num[maxEnd] < 0) && flag != 0)
	{
		cout << "0 0 0";
		return 0;
	}
	if (flag != 0)
	{
		cout << maxSum << " " << num[maxBegin] << " " << num[maxEnd];
	}
	else
	{
		cout << "0 " << num[0] << " " << num[count - 1];
	}
	return 0;
}