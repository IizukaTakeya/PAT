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
//_ 95
//1112
using namespace std;
int numFlag[10] = { 0 };
int alphaFlag[26] = { 0 };
int lineFlag = 0;
set<char> v;
set<char> negative;
string pnt;
int main()
{
	int stuckCount = 0;
	scanf("%d", &stuckCount);
	string s;
	cin >> s;
	int times = 1;
	char curr = s[0];
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == curr || times == 0)
		{
			times++;
		}
		else
		{
			//cout << curr << "    " << times << endl;
			if (times % stuckCount == 0)
			{
				if (v.find(curr) == v.end())
				{
					//printf("%c", curr);
					pnt = pnt + curr;
				}
				v.insert(curr);
			}
			else
			{
				negative.insert(curr);
				//cout << curr << endl;
			}
			times = 1;
		}
		curr = s[i];
	}
	if (times % stuckCount == 0)
	{
		if (v.find(curr) == v.end())
		{
			//printf("%c", curr);
			pnt = pnt + curr;
		}
		v.insert(curr);
	}
	else
	{
		negative.insert(curr);
		//cout << curr << endl;
	}
	for (int i = 0; i < pnt.size(); i++)
	{
		if (negative.find(pnt[i]) != negative.end())
		{
			pnt.erase(i, 1);
			i--;
		}
	}
	printf("%s\n", pnt.c_str());
	int printCount = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (pnt.find(s[i]) == string::npos)
		{
			printf("%c", s[i]);
		}
		else
		{
			printCount++;
			if (printCount % stuckCount == 0)
			{
				printf("%c", s[i]);
				printCount = 0;
			}
		}
	}
	return 0;
}