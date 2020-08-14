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
//0-9 48-57
using namespace std;
long long fun1(string s, long long n);
int fun2(string s);

int main()
{
	string s1;
	string s2;
	long long var1 = 0;
	//long long var2 = 0;
	int flag = 0;
	long long radix1 = 0;
	long long lowBound = 2;
	long long highBound = 4294967296;
	cin >> s1 >> s2 >> flag >> radix1;
	long long currRa = 0;
	long long Ra = 0;
	int rightFlag = 0;
	if (flag == 1)
	{
		var1 = fun1(s1, radix1);
		lowBound = max(2, fun2(s2));
		//cout << lowBound << endl;
		while (true)
		{
			currRa = ((lowBound + highBound) / 2);
			//cout << currRa << endl;
			if (fun1(s2, currRa) == var1 && Ra != currRa)
			{
				highBound = currRa;
				Ra = currRa;
				rightFlag = 1;
			}
			else if (currRa == lowBound || currRa == highBound)
			{
				if (rightFlag == 0)
				{
					cout << "Impossible";
				}
				else
				{
					cout << Ra;
				}
				return 0;
			}
			if (fun1(s2, currRa) < var1 && fun1(s2, currRa) > 0)
			{
				lowBound = currRa;
				continue;
			}
			if (fun1(s2, currRa) > var1 || fun1(s2, currRa) <= 0)
			{
				highBound = currRa;
				continue;
			}
		}
	}
	else
	{
		var1 = fun1(s2, radix1);
		lowBound = max(2, fun2(s1));
		while (true)
		{
			currRa = ((lowBound + highBound) / 2);
			if (fun1(s1, currRa) == var1 && Ra != currRa)
			{
				highBound = currRa;
				Ra = currRa;
				rightFlag = 1;
			}
			else if ((currRa == lowBound || currRa == highBound))
			{
				if (rightFlag == 0)
				{
					cout << "Impossible";
				}
				else
				{
					cout << Ra;
				}
				return 0;
			}
			if (fun1(s1, currRa) < var1 && fun1(s1, currRa) > 0)
			{
				lowBound = currRa;
				continue;
			}
			if (fun1(s1, currRa) > var1 || fun1(s1, currRa) <= 0)
			{
				highBound = currRa;
				continue;
			}
		}
	}
	//cout << fun1("1b", 16);
	return 0;
}

long long fun1(string s, long long n)
{
	long long var = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int v = 0;
		if (s[i] > 70)
		{
			v = s[i] - 'a' + 10;
		}
		else
		{
			v = s[i] - '0';
		}
		var *= n;
		var += v;
	}
	return var;
}

int fun2(string s)
{
	int n = 0;
	int v = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] > 70)
		{
			v = s[i] - 'a' + 10;
		}
		else
		{
			v = s[i] - '0';
		}
		if (n <= v)
		{
			n = v + 1;
		}
	}
	return n;
}