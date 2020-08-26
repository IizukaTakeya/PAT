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
//1109
using namespace std;

struct people
{
	string name;
	int height = 0;
};

people peo;
vector<people> v;
bool cmp(people a, people b);
int main()
{
	int count = 0;
	int row = 0;
	scanf("%d %d", &count, &row);
	int* place = new int[row];
	for (int i = 0; i < count; i++)
	{
		cin >> peo.name;
		scanf("%d", &peo.height);
		v.push_back(peo);
	}
	for (int i = 0; i < row; i++)
	{
		if (i < count % row)
		{
			place[i] = count / row + 1;
		}
		else
		{
			place[i] = count / row;
		}
	}
	int peopleCount = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < row; i++)
	{
		int flag = 0;
		string* stand = new string[place[i]];
		if (i > 0)
		{
			printf("\n");
		}
		for (int j = 0; j < place[i]; j++)
		{
			int mark = 0;
			stand[place[i] / 2 + flag] = v[peopleCount].name;
			//cout << place[i] / 2 << "++++" << endl;
			//cout << flag << endl;
			if (flag >= 0)
			{
				flag = (flag + 1) * -1;
			}
			else
			{
				flag *= -1;
			}
			peopleCount++;
		}
		for (int j = 0; j < place[i]; j++)
		{
			if (j > 0)
			{
				printf(" ");
			}
			printf("%s", stand[j].c_str());
		}
	}
	return 0;
}

bool cmp(people a, people b)
{
	if (a.height == b.height)
	{
		return a.name < b.name;
	}
	return a.height > b.height;
}