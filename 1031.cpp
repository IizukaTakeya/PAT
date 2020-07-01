#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int space(int n);
int main()
{
	string s;
	cin >> s;
	int vertical = 0;
	int horizon = 0;
	vertical = (s.length() + 2) / 3;
	horizon = s.length() - 2 * vertical + 2;
	//cout << vertical;
	//cout << horizon << endl;
	for (int i = 0; i < vertical - 1; i++)
	{
		cout << s[i];
		space(horizon - 2);
		cout << s[s.length() - i - 1] << endl;
	}
	for (int i = vertical - 1; i < s.length() - vertical + 1; i++)
	{
		cout << s[i];
	}
	return 0;
}
int space(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	}
	return 0;
}