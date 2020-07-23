#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
//#pragma warning(disable:4996)
//a-z 97-122
using namespace std;
int main()
{
	string s1;
	string s2;
	int missCount = 0;
	int extraCount = 0;
	int missFlag = 0;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int j = 0;
	//cout << s1 << endl << s2 << endl;
	for (int i = 0; i < s2.size(); ++i)
	{
		for (; j < s1.size(); ++j)
		{
			if (s2[i] == s1[j])
			{
				++j;
				break;
			}
			if (s2[i] < s1[j])
			{
				++missFlag;
				//cout << "a";
				break;
			}
		}
		if (j == s1.size())
		{
			//cout << "b";
			missFlag += s2.size() - i - 1;
			if (s2[i] != s1[j - 1])
			{
				missFlag += 1;
			}
			break;
		}
	}
	if (missFlag == 0)
	{
		cout << "Yes " << s1.size() - s2.size();
	}
	else
	{
		cout << "No " << missFlag;
	}
	return 0;
}