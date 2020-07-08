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
	vector<string> account;
	vector<string> password;
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int mark = 0;
		string a;
		string p;
		cin >> a;
		cin >> p;
		for (int j = 0; j < p.size(); j++)
		{
			switch (p[j])
			{
			case '1':
				p[j] = '@';
				mark = 1;
				break;
			case '0':
				p[j] = '%';
				mark = 1;
				break;
			case 'l':
				p[j] = 'L';
				mark = 1;
				break;
			case 'O':
				p[j] = 'o';
				mark = 1;
				break;
			}
		}
		if (mark == 1)
		{
			account.push_back(a);
			password.push_back(p);
		}
	}
	if (account.size() == 0)
	{
		if (count == 1)
		{
			cout << "There is 1 account and no account is modified";
		}
		else
		{
			cout << "There are " << count << " accounts and no account is modified";
		}
		return 0;
	}
	else
	{
		cout << account.size();
		for (int i = 0; i < account.size(); i++)
		{
			cout << endl << account[i] << " " << password[i];
		}
	}
	return 0;
}