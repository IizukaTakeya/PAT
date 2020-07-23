#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
//#pragma warning(disable:4996)
using namespace std;
/*int late(string s1, string s2)
{
	if ((stoi(s1.substr(0, 1))) != (stoi(s2.substr(0, 1))))
	{
		if ((stoi(s1.substr(0, 1))) > (stoi(s2.substr(0, 1))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if ((stoi(s1.substr(3, 4))) != (stoi(s2.substr(3, 4))))
	{
		if ((stoi(s1.substr(3, 4))) > (stoi(s2.substr(3, 4))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if ((stoi(s1.substr(6, 7))) != (stoi(s2.substr(6, 7))))
	{
		if ((stoi(s1.substr(6, 7))) > (stoi(s2.substr(6, 7))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}*/
int main()
{
	int count = 0;
	cin >> count;
	string s;
	string lateS;
	string earlyS;
	string lateTime;
	string earlyTime;
	cin >> s >> earlyTime >> lateTime;
	lateS = s;
	earlyS = s;
	for (int i = 1; i < count; ++i)
	{
		string arriveTime;
		string leaveTime;
		cin >> s >> arriveTime >> leaveTime;
		if (earlyTime > arriveTime)
		{
			earlyS = s;
			earlyTime = arriveTime;
		}
		if (leaveTime > lateTime)
		{
			lateS = s;
			lateTime = leaveTime;
		}
	}
	cout << earlyS << " " << lateS;
	return 0;
}