#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
//#pragma warning(disable:4996)
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	for (int k = 0; k < count; ++k)
	{
		if (k > 0)
		{
			cout << endl;
		}
		int number = 0;
		cin >> number;
		if (number < 1)
		{
			cout << "NO";
			continue;
		}
		int* queen = new int[number];
		int mark = 0;
		for (int i = 0; i < number; i++)
		{
			cin >> queen[i];
		}
		for (int i = 0; i < number; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (queen[i] < 1 || queen[i] > number || queen[j] == queen[i] || queen[j] + i == queen[i] + j || queen[i] + i == queen[j] + j)
				{
					mark = 1;
					cout << "NO";
					break;
				}
			}
			if (mark == 1)
			{
				break;
			}
			if (i == number - 1)
			{
				cout << "YES";
			}
		}
		delete[] queen;
	}
	return 0;
}
/*int main()
{
	int number[8] = { 4,6,8,2,7,1,3,5 };
	int num[9] = { 4,6,7,2,8,1,9,5,3 };
	int mark = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < i; j++)
			if (number[j] == number[i] || number[j] + i == number[i] + j || number[i] + i == number[j] + j)
			{
				cout << "no" << endl;
				break;
			}
	}
	for (int i = 0; i < 9; i++)
	{
		if (mark == 1)
		{
			break;
		}
		for (int j = 0; j < i; j++)
			if (num[j] == num[i] || num[j] + i == num[i] + j || num[i] + i == num[j] + j)
			{
				cout << "no" << endl;
				mark = 1;
				break;
			}
	}
	return 0;
}*/