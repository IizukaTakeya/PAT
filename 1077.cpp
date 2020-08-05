#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#pragma warning(disable:4996)
//a-z 97-122
//1082
using namespace std;

int main()
{
	int count = 0;
	scanf("%d", &count);
	getchar();
	string s;
	getline(cin, s);
	for (int i = 1; i < count; ++i)
	{
		string s1;
		getline(cin, s1);
		if (!s.empty() && !s1.empty())
		{
			for (int j = 0; j <= s.size() - 1 && j <= s1.size() - 1; ++j)
			{
				if (s[s.size() - 1 - j] != s1[s1.size() - 1 - j])
				{
					s.erase(0, s.size() - j);
					break;
				}
			}
		}
		else
		{
			printf("nai");
			return 0;
		}
	}
	while (s[0] == ' ')
	{
		s.erase(0, 1);
	}
	printf("%s", s.c_str());
	if (s.size() == 0)
	{
		printf("nai");
	}
	return 0;
}