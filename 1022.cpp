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
//1022
using namespace std;

map<string, vector<string>> m;
bool cmp(map<string, vector<string>> a, map<string, vector<string>> b);
int main()
{
	int count = 0;
	scanf("%d", &count);
	//getchar();
	for (int i = 0; i < count; i++)
	{
		string id;
		cin >> id;
		m.insert(make_pair(id, 0));
		for (int j = 0; j < 6; j++)
		{
			string s;
			getline(cin, s);
			m.find(id)->second.push_back(s);
			//cout << s << endl;
		}
	}
	for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++)
	{
		it->second.erase(it->second.begin(), it->second.begin() + 1);
	}
	int findCount = 0;
	scanf("%d", &findCount);
	for (int i = 0; i < findCount; i++)
	{
		int findType = 0;
		string findStr;
		scanf("%d: ", &findType);
		getline(cin, findStr);
		int flag = 0;
		if (i > 0)
		{
			printf("\n");
		}
		printf("%d: %s", findType, findStr.c_str());
		for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++)
		{
			if (findType == 3)
			{
				if (it->second[findType - 1].find(findStr) != it->second[findType - 1].npos)
				{
					flag = 1;
					printf("\n%s", it->first.c_str());
				}
			}
			else
			{
				if (findStr == it->second[findType - 1])
				{
					flag = 1;
					printf("\n%s", it->first.c_str());
				}
			}
		}
		if (flag == 0)
		{
			printf("\nNot Found");
		}
	}
	return 0;
}