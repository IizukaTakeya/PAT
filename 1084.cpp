#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int flag = 0;
	int ch[128] = { 0 };
	for (int i = 0; i + flag < s1.size() - 1; ++i)
	{
		if (s1[i + flag] != s2[i] && abs((int)s1[i + flag] - (int)s2[i]) != 32)
		{
			int temp = 0;
			(int)(s1[i + flag]) > 96 ? temp = (int)(s1[i + flag] - 32) : temp = s1[i + flag];
			if (ch[temp] == 0)
			{
				cout << (char)temp;
			}
			ch[temp] = 1;
			if (i != s1.size() - 1)
			{
				flag++;
				i--;
			}
		}
	}
	return 0;
}