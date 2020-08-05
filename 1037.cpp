#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#pragma warning(disable:4996)
//a-z 97-122
//1037
using namespace std;

int main()
{
	int count1 = 0;
	scanf("%d", &count1);
	int* num1 = new int[count1];
	for (int i = 0; i < count1; ++i)
	{
		scanf("%d",&num1[i]);
	}
	sort(num1, num1 + count1);
	int count2 = 0;
	scanf("%d", &count2);
	int* num2 = new int[count2];
	for (int i = 0; i < count2; ++i)
	{
		scanf("%d", &num2[i]);
	}
	sort(num2, num2 + count2);
	int begin1 = 0;
	int begin2 = 0;
	int end1 = count1 - 1;
	int end2 = count2 - 1;
	int result = 0;
	int flag1 = 0;
	int flag2 = 0;
	while (flag1 == 0 || flag2 == 0)
	{
		if (num1[begin1] < 0 && num2[begin2] < 0 && begin1 < count1 && begin2 < count2)
		{
			result += num1[begin1] * num2[begin2];
			begin1++;
			begin2++;
		}
		else
		{
			flag1 = 1;
		}
		if (num1[end1] > 0 && num2[end2] > 0 && end1 >= 0 && end2 >= 0)
		{
			result += num1[end1] * num2[end2];
			end1--;
			end2--;
		}
		else
		{
			flag2 = 1;
		}
	}
	printf("%d", result);
	return 0;
}
