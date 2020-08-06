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

string hanzi[10] = { "","yi","er","san","si","wu","liu","qi","ba","jiu" };
string digit[6] = { "","Shi","Bai","Qian"};
string large[3] = { "","Wan","Yi" };

int main()
{
	string s;
	string s1;
	cin >> s;
	vector<string> v;
	int negativeFlag = 0;
	if (s[0] == '-')
	{
		negativeFlag = 1;
		s.erase(0, 1);
	}
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	if (s.empty())
	{
		printf("ling");
		return 0;
	}
	else if (negativeFlag == 1)
	{
		printf("Fu ");
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i)
	{
		if (i % 4 == 0 && i > 0)
		{
			s1 = " " + s1;
			s1 = large[i / 4] + s1;
		}
		if (s[i] != '0')
		{
			if (i % 4 != 0)
			{
				s1 = " " + s1;
				s1 = digit[i % 4] + s1;
			}
			if (i != 0)
			{
				s1 = " " + s1;
			}
			s1 = hanzi[s[i] - '0'] + s1;
			//beginFlag = 1;
		}
		if (i < s.size() - 1 && s[i + 1] == '0' && s[i] != '0')
		{
			s1 = "ling " + s1;
		}
	}
	if (s1[s1.size() - 1] == ' ')
	{
		s1.pop_back();
	}
	cout << s1;
	return 0;
}