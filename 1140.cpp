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
	string s;
	cin >> s;
	int k = 0;
	int count = 0;
	cin >> count;
	for (int i = 0; i < count - 1; ++i)
	{
		string s1;
		for (int j = 0; j < s.size(); j = k)
		{
			for (k = j; k < s.size() && s[j] == s[k]; ++k);
			s1 += s[j] + to_string(k - j);
		}
		s = s1;
	}
	cout << s;
	return 0;
}