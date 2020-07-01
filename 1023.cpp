#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int mark[10] = { 0 };
	char number1[21] = { 0 };
	int number2[21] = { 0 };
	cin >> number1;
	if (number1[0] - 48 >= 5)
	{
		cout << "No" << endl;
		for (int i = 0; i < strlen(number1); i++)
		{
			number2[i] += (number1[i] - 48) / 5;
			//cout << number2[i] << endl;
			number2[i + 1] += (number1[i] - 48) * 2 % 10;
			//cout << number2[i + 1] << endl;
		}
		for (int i = 0; i < strlen(number1) + 1; i++)
		{
			cout << number2[i];
		}
	}
	else
	{
		for (int i = 0; i < strlen(number1); i++)
		{
			mark[number1[i] - 48] += 1;
			if (i > 0)
			{
				number2[i - 1] += (number1[i] - 48) / 5;
				mark[number2[i - 1]] -= 1;
			}
			number2[i] += (number1[i] - 48) * 2 % 10;
		}
		mark[number2[strlen(number1) - 1]] -= 1;
		for (int i = 0; i < 10; i++)
		{
			if (mark[i] != 0)
			{
				cout << "No" << endl;;
				break;
			}
			if (i == 9)
			{
				cout << "Yes" << endl;
			}
		}
		for (int i = 0; i < strlen(number1); i++)
		{
			cout << number2[i];
		}
	}
	return 0;
}