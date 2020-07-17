#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
//#pragma warning(disable:4996)
using namespace std;
int main()
{
	string s;
	cin >> s;
	long long pCnt = 0;
	long long tCnt = 0;
	long long* pCount = new long long[s.size()];
	long long* tCount = new long long[s.size()];
	long long totalCount = 0;
	pCount[0] = 0;
	tCount[s.size() - 1] = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'P')
		{
			++pCnt;
		}
		pCount[i] = pCnt;
		if (s[s.size() - 1 - i] == 'T')
		{
			++tCnt;
		}
		tCount[s.size() - i - 1] = tCnt;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		//cout << pCount[i] << "\t" << tCount[i] << endl;
		if (s[i] == 'A')
		{
			totalCount += pCount[i] * tCount[i];
		}
		if (totalCount >= 1000000007)
		{
			totalCount -= 1000000007;
		}
	}
	delete[] pCount;
	delete[] tCount;
	cout << totalCount;
	return 0;
}
