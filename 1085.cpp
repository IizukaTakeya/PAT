#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	unsigned long long total = 0;
	unsigned long long var = 0;
	cin >> total >> var;
	unsigned long long count = 0;
	unsigned long long* numbers = new unsigned long long[total];
	unsigned long long max = 0;
	while (count < total)
	{
		cin >> numbers[count];
		count++;
	}
	sort(numbers, numbers + total);
	count = 0;
	while (count + max < total)
	{
		while (count + max < total && numbers[count + max] <= numbers[count] * var)
		{
			max++;
		}
		count++;
	}
	cout << max;
	return 0;
}