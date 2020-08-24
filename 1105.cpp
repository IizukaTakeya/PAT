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
	//row �� column ��
	int currRow = 0;
	int currCol = -1;
	int rowCount = var1 - 1;//ÿ���ƶ�������
	int colCount = var2;//ÿ���ƶ�������
	int flag1 = 1;//���в����� -1���ƣ�1����
	int flag2 = 0;//���в����� -1���ƣ�1����
	int var = 0;
	//cout << rowCount << "   " << colCount << endl;
	while (true)
	{
		if (flag2 == 0)
		{
			for (int i = 0; i < colCount; i++)
			{
				if (flag1 == 1)//����
				{
					currCol++;
				}
				else if (flag1 == -1)//����
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
				if (flag2 == 1)//����
				{
					currRow++;
				}
				else if (flag2 == -1)//����
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