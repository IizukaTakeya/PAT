#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int pnt(int n);
int main()
{
	int red = 0;
	int green = 0;
	int blue = 0;
	cin >> red >> green >> blue;
	cout << "#";
	pnt(red / 13);
	pnt(red % 13);
	pnt(green / 13);
	pnt(green % 13);
	pnt(blue / 13);
	pnt(blue % 13);
	return 0;
}
int pnt(int n)
{
	if (n < 10)
	{
		cout << n;
	}
	else if (n == 10)
	{
		cout << "A";
	}
	else if (n == 11)
	{
		cout << "B";
	}
	else if (n == 12)
	{
		cout << "C";
	}
	return 0;
}