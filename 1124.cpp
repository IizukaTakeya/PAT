#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#pragma warning(disable:4996)
//a-z 97-122
//A-Z 65-90
//1-9 48-57
//1124
using namespace std;


int main()
{
	int number = 0;
	int skipNum = 0;
	int firstNum = 0;
	scanf("%d %d %d", &number, &skipNum, &firstNum);
	vector<string> v;
	vector<string> winner;
	v.resize(number);
	for (int i = 0; i < number; i++)
	{
		cin >> v[i];
	}
	if (number < firstNum)
	{
		printf("Keep going...");
		return 0;
	}
	for (int i = firstNum - 1; i < number;)
	{
		if (find(winner.begin(), winner.end(), v[i]) == winner.end())
		{
			winner.push_back(v[i]);
			i += skipNum;
		}
		else
		{
			i++;
		}
	}
	for (int i = 0; i < winner.size(); i++)
	{
		if (i > 0)
		{
			printf("\n");
		}
		printf("%s", winner[i].c_str());
	}
	return 0;
}