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
//1105
using namespace std;
bool cmp(int a, int b);
int main()
{
	int count = 0;
	scanf("%d", &count);
	int var2 = sqrt(count);
	int var1 = 0;
	int* number = new int[count];
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &number[i]);
	}
	sort(number, number + count, cmp);
	while (true)
	{
		if (count % var2 == 0)
		{
			var1 = count / var2;
			break;
		}
		else
		{
			var2--;
		}
	}//var1>=var2
	//cout << var1 << " " << var2;
	int** mat = new int* [var1];
	for (int i = 0; i < var1; i++)
	{
		mat[i] = new int[var2];
	}
	//row 行 column 列
	int currRow = 0;
	int currCol = -1;
	int rowCount = var1 - 1;//每次移动多少行
	int colCount = var2;//每次移动多少列
	int flag1 = 1;//换列不换行 -1左移，1右移
	int flag2 = 0;//换行不换列 -1上移，1下移
	int var = 0;
	//cout << rowCount << "   " << colCount << endl;
	while (true)
	{
		if (flag2 == 0)
		{
			for (int i = 0; i < colCount; i++)
			{
				if (flag1 == 1)//右移
				{
					currCol++;
				}
				else if (flag1 == -1)//左移
				{
					currCol--;
				}
				mat[currRow][currCol] = number[var];
				//cout /*<< mat[currRow][currCol] << "***" */ << currRow << "***" << currCol << "***" << flag1 << "***" << flag2 << endl;
				var++;
			}
			colCount--;
			if (flag1 == 1)
			{
				flag2 = 1;
				flag1 = 0;
			}
			else if (flag1 == -1)
			{
				flag2 = -1;
				flag1 = 0;
			}
		}
		else if (flag1 == 0)
		{
			for (int i = 0; i < rowCount; i++)
			{
				if (flag2 == 1)//下移
				{
					currRow++;
				}
				else if (flag2 == -1)//上移
				{
					currRow--;
				}
				mat[currRow][currCol] = number[var];
				//cout /*<< mat[currRow][currCol] << "^^^" */ << currRow << "^^^" << currCol << "^^^" << flag1 << "^^^" << flag2 << endl;
				var++;
			}
			rowCount--;
			if (flag2 == 1)
			{
				flag1 = -1;
				flag2 = 0;
			}
			else if (flag2 == -1)
			{
				flag1 = 1;
				flag2 = 0;
			}
		}
		if (var == count)
		{
			break;
		}
	}
	for (int i = 0; i < var1; i++)
	{
		if (i > 0)
		{
			printf("\n");
		}
		for (int j = 0; j < var2; j++)
		{
			if (j > 0)
			{
				printf(" ");
			}
			printf("%d", mat[i][j]);
		}
	}
	return 0;
}

bool cmp(int a, int b)
{
	return a > b;
}