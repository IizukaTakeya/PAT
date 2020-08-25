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
//1122
//首尾相接 从头到尾 连接不为空
using namespace std;
int main()
{
	int count = 0;
	int route = 0;
	scanf("%d %d", &count, &route);
	int** v = new int* [count + 1];
	for (int i = 0; i <= count; i++)
	{
		v[i] = new int[count + 1];
	}
	for (int i = 0; i <= count; i++)
	{
		for (int j = 0; j <= count; j++)
		{
			v[i][j] = 0;
		}
	}
	for (int i = 0; i < route; i++)
	{
		int var1 = 0;
		int var2 = 0;
		scanf("%d %d", &var1, &var2);
		v[var1][var2] = 1;
		v[var2][var1] = 1;
	}
	/*for (int i = 0; i <= count; i++)
	{
		cout << endl;
		for (int j = 0; j <= count; j++)
		{
			cout << v[i][j] << "    ";
		}
	}*/
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		if (i > 0)
		{
			printf("\n");
		}
		int flag = 0;
		int var = 0;
		scanf("%d", &var);
		if (var != count + 1)
		{
			flag = 1;
		}
		int* testArr = new int[var];
		for (int j = 0; j < var; j++)
		{
			scanf("%d", &testArr[j]);
		}
		if (testArr[0] != testArr[var - 1])
		{
			flag = 1;
		}
		else
		{
			for (int j = 0; j < var - 1; j++)
			{
				if (v[testArr[j]][testArr[j + 1]] != 1)
				{
					flag = 1;
					break;
				}
			}
			sort(testArr, testArr + var - 1);
			for (int j = 0; j < var - 1; j++)
			{
				//cout << testArr[j] << "    ";
				if (testArr[j] != j + 1)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
		{
			printf("NO");
		}
		else
		{
			printf("YES");
		}
		delete[]testArr;
	}
	return 0;
}