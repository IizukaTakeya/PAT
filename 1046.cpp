#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int exitCount = 0;
	cin >> exitCount;
	int dist;
	int total = 0;
	int* distance = new int[exitCount + 1];
	distance[0] = 0;
	for (int i = 0; i < exitCount; i++)
	{
		distance[i + 1] = 0;
		cin >> dist;
		total += dist;
		distance[i + 1] = total;
	}
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int begin = 0;
		int end = 0;
		cin >> begin >> end;
		int clkwise = 0;
		clkwise = abs(distance[begin - 1] - distance[end - 1]);
		cout << min(clkwise, total - clkwise) << endl;
	}
	return 0;
}