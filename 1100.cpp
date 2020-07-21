#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;
string first[12] = { "jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string second[12] = { "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
int MarsToEarth(string s);
string EarthToMars(int n);
int main()
{
	int count = 0;
	cin >> count;
	getchar();
	for (int i = 0; i < count; ++i)
	{
		string s;
		getline(cin, s);
		if (s[0] <= '9' && s[0] >= '0')
		{
			int n = 0;
			n = stoi(s);
			cout << EarthToMars(n);
		}
		else
		{
			cout << MarsToEarth(s);
		}
		if (i != count - 1)
		{
			cout << endl;
		}
	}
	return 0;
}

int MarsToEarth(string s)
{
	if (s == "tret")
	{
		return 0;
	}
	int n = 0;
	string s1 = s.substr(0, 3);
	for (int i = 0; i < 12; ++i)
	{
		//cout << s.size() << endl;
		if (s.size() == 3)
		{
			if (s1 == first[i])
			{
				n = i + 1;
			}
			else if (s1 == second[i])
			{
				n = 13 * (i + 1);
			}
		}
		else if (s.size() == 7)
		{
			//cout << "test1";
			string s2 = s.substr(4, 3);
			//cout << s1 << "\t" << s2;
			if (s1 == second[i])
			{
				n += 13 * (i + 1);
			}
			if (s2 == first[i])
			{
				n += i + 1;
			}
		}
	}
	return n;
}

string EarthToMars(int n)
{
	string s;
	if (n == 0)
	{
		s = "tret";
		return s;
	}
	if (n > 12)
	{
		s += second[n / 13 - 1];
		if (n % 13 != 0)
		{
			s += " ";
			s += first[n % 13 - 1];
		}
	}
	else
	{
		s += first[n - 1];
	}
	return s;
}