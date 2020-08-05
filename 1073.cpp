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
//1082
using namespace std;

int main()
{
	string s;
	cin >> s;
	string s1;
	int negativeFlag = 0;
	int exponFlag = 0;
	int exponent = 0;
	if (s[0] == '-')
	{
		negativeFlag = 1;
	}
	s.erase(0, 1);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != '.' && s[i] != 'E')
		{
			s1 = s1 + s[i];
		}
		if (s[i] == 'E')
		{
			s.erase(0, i + 1);
			break;
		}
	}
	//cout << s1 << endl;
	if (s[0] == '-')
	{
		exponFlag = 1;
	}
	s.erase(0, 1);
	exponent = stoi(s);
	s.clear();
	//cout << exponent << endl;
	if (exponFlag == 1)
	{
		for (int i = 0; i < exponent; ++i)
		{
			s = s + '0';
			if (i == 0)
			{
				s = s + '.';
			}
			//cout << s << endl;
		}
		//cout << s << " " << s1 << endl;
		s = s + s1;
	}
	else
	{
		if (s1.size() > exponent + 1)
		{
			s = s1.insert(exponent + 1, ".");
		}
		else
		{
			s = s + s1;
			for (int i = 0; i < exponent + 1 - s1.size(); ++i)
			{
				s = s + '0';
			}
		}
	}
	if (negativeFlag == 1)
	{
		s = '-' + s;
	}
	printf("%s", s.c_str());
	return 0;
}