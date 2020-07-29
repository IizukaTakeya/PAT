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
//1088
using namespace std;
string pnt(long long n1, long long n2);
long long gcd(long long n1, long long n2);

int main()
{
	long long v1 = 0;
	long long v2 = 0;
	long long v3 = 0;
	long long v4 = 0;
	scanf("%lld/%lld %lld/%lld", &v1, &v2, &v3, &v4);
	cout << pnt(v1, v2) << " + " << pnt(v3, v4) << " = " << pnt(v1 * v4 + v2 * v3, v2 * v4) << endl;
	cout << pnt(v1, v2) << " - " << pnt(v3, v4) << " = " << pnt(v1 * v4 - v2 * v3, v2 * v4) << endl;
	cout << pnt(v1, v2) << " * " << pnt(v3, v4) << " = " << pnt(v1 * v3, v2 * v4) << endl;
	cout << pnt(v1, v2) << " / " << pnt(v3, v4) << " = ";
	v3 == 0 ? cout << "Inf" : cout << pnt(v1 * v4, v2 * v3);
	return 0;
}

string pnt(long long n1, long long n2)
{
	string s;
	long long i = 1;
	if (n1 == 0)
	{
		s = "0";
		return s;
	}
	if (n2 == 1)
	{
		s = to_string(n1);
		if (s[0] == '-')
		{
			s = "(" + s + ")";
		}
		return s;
	}
	if (n2 == -1)
	{
		s = to_string(n1);
		if (s[0] != '-')
		{
			s = "(-" + s + ")";
		}
		else
		{
			s.erase(0, 1);
		}
		return s;
	}
	int flag = 0;
	if ((n1 < 0 && n2 > 0) || (n1 > 0 && n2 < 0))
	{
		flag = 1;
	}
	n1 = abs(n1);
	n2 = abs(n2);
	long long n3 = 0;
	long long part = 0;
	part = n1 / n2;
	n1 = n1 % n2;
	if (n1 % n2 == 0)
	{
		n3 = part;
		s += to_string(n3);
		if (flag != 0)
		{
			s = "(-" + s + ")";
		}
		return s;
	}
	else
	{
		i = gcd(n1, n2);
	}
	n1 /= i;
	n2 /= i;
	s = to_string(n1) + "/" + to_string(n2);
	if (part != 0)
	{
		s = to_string(part) + " " + s;
	}
	if (flag != 0)
	{
		s = "(-" + s + ")";
	}
	return s;
}

long long gcd(long long n1, long long n2)
{
	return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}