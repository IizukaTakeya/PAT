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
	int numberCount = 0;
	double sum = 0;
	double average = 0;
	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;
		int flag = 0;
		unsigned int j = 0;
		/*if (s[0] == '.' && s.size() == 1)
		{
			cout << "ERROR: " << s << " is not a legal number" << endl;
			continue;
		}
		if (s[0] == '-' && s[1] == '.' && s.size() == 2)
		{
			cout << "ERROR: " << s << " is not a legal number" << endl;
			continue;
		}*/
		if (s[0] == '-')
		{
			if (s.size() < 2)
			{
				cout << "ERROR: " << s << " is not a legal number" << endl;
			}
			j = 1;
		}
		for (; j < s.size(); ++j)
		{
			if (s[j] < '0' || s[j] > '9')
			{
				if (s[j] == '.' && flag == 0 && j + 3 >= s.size())
				{
					flag = 1;
				}
				else
				{
					cout << "ERROR: " << s << " is not a legal number" << endl;
					flag = 2;
					break;
				}
			}
		}
		if (flag < 2)
		{
			long double num = stold(s);
			if (abs(num) <= 1000)
			{
				sum += num;
				numberCount++;
			}
			else
			{
				cout << "ERROR: " << num << " is not a legal number" << endl;
			}
		}
	}
	if (numberCount != 0)
	{
		average = sum / numberCount;
	}
	if (numberCount == 0)
	{
		cout << "The average of 0 numbers is Undefined";
	}
	else if (numberCount == 1)
	{
		cout << "The average of 1 number is " << setiosflags(ios::fixed) << setprecision(2) << average;
	}
	else
	{
		cout << "The average of " << numberCount << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << average;
	}
	return 0;
}
