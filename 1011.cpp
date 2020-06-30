#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
	double gain = 0.65;
	for (int i = 0; i < 3; i++)
	{
		double match[3] = { 0 };
		double maxOdd = 0;
		cin >> match[0] >> match[1] >> match[2];
		maxOdd = max(max(match[0], match[1]), match[2]);
		if (maxOdd == match[0])
		{
			cout << "W";
		}
		if (maxOdd == match[1])
		{
			cout << "T";
		}
		if (maxOdd == match[2])
		{
			cout << "L";
		}
		cout << " ";
		gain *= maxOdd;
	}
	gain = (gain - 1) * 2;
	cout << fixed << setprecision(2) << gain;
	return 0;
}