#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;
string pls(string s1, string s2);
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < 10; i++)
	{
		string sv;
		sv = s;
		reverse(sv.begin(), sv.end());
		if (sv == s)
		{
			cout << s << " is a palindromic number.";
			return 0;
		}
		string n;
		n = pls(s, sv);
		cout << s << " + " << sv << " = " << n << endl;
		s = n;
	}
	cout << "Not found in 10 iterations.";
	return 0;
}
string pls(string s1, string s2)//大整数加法
{
	string s;
	s = s1;
	int bt = 0;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		s[i] = (s1[i] - '0' + s2[i] - '0' + bt) % 10 + '0';
		bt = (s1[i] - '0' + s2[i] - '0' + bt) / 10;
	}
	if (bt == 1)
	{
		s = "1" + s;
	}
	return s;
}