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
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		long double a = 0;
		long double b = 0;
		long double c = 0;
		if (i != 0)
		{
			cout << endl;
		}
		cin >> a >> b >> c;
		long double sum = a + b;
		if (a > 0 && b > 0 && sum <= 0)
		{
			cout << "Case #" << i + 1 << ": true";
			continue;
		}
		else if (a < 0 && b < 0 && sum >= 0)
		{
			cout << "Case #" << i + 1 << ": false";
			continue;
		}
		else if (sum > c)
		{
			cout << "Case #" << i + 1 << ": true";
			continue;
		}
		else
		{
			cout << "Case #" << i + 1 << ": false";
			continue;
		}
	}
	return 0;
}