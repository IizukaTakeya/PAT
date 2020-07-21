#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;
int ran[10000] = { 0 };
int check[10000] = { 0 };
int prime(int n);
int main()
{
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		int number = 0;
		cin >> number;
		ran[number] = i + 1;
	}
	int rewardCount = 0;
	cin >> rewardCount;
	for (int i = 0; i < rewardCount; ++i)
	{
		int reward;
		cin >> reward;
		printf("%04d: ", reward);
		if (ran[reward] == 0)
		{
			printf("Are you kidding?");
		}
		else if (check[reward] == 1)
		{
			printf("Checked");
		}
		else if (ran[reward] == 1)
		{
			printf("Mystery Award");
			check[reward] = 1;
		}
		else if (prime(ran[reward]) == true)
		{
			printf("Minion");
			check[reward] = 1;
		}
		else
		{
			printf("Chocolate");
			check[reward] = 1;
		}
		if (i != rewardCount - 1)
		{
			cout << endl;
		}
	}
	return 0;
}
int prime(int n)
{
	for (int i = 2; i < sqrt(n) + 1; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}