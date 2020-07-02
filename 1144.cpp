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
	int count = 0;
	cin >> count;
	int* num = new int[count];
	int flag = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> num[i];
	}
	sort(num, num + count);
	for (int i = 1; i < count; i++)
	{
		if (num[i] > num[i - 1] && num[i - 1] > 0)
		{
			flag = 1;
			if (num[i] - num[i - 1] > 1)
			{
				cout << num[i - 1] + 1;
				return 0;
			}
		}
	}
	if (flag == 1)
	{
		cout << num[count - 1] + 1;
		return 0;
	}
	if (num[count - 1] == 1)
	{
		cout << "2";
		return 0;
	}
	cout << "1";
	return 0;
}