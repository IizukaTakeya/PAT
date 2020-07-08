#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int flag = 0;
	string str1;
	string str2;
	string str3;
	string str4;
	cin >> str1 >> str2 >> str3 >> str4;
	unsigned count = 0;
	while (true)
	{
		if (flag == 1 && str1[count] == str2[count])
		{
			if (str1[count] >= 'A' && str1[count] <= 'N')
			{
				cout << (int)str1[count] - 55 << ":";
				break;
			}
			else if (str1[count] >= '0' && str1[count] <= '9')
			{
				cout << "0" << (int)str1[count] - 48 << ":";
				break;
			}
		}
		if (flag == 0 && str1[count] >= 'A' && str1[count] <= 'G' && str1[count] == str2[count])
		{
			flag = 1;
			switch ((int)str1[count] - 64)
			{
			case 1:
				cout << "MON ";
				break;
			case 2:
				cout << "TUE ";
				break;
			case 3:
				cout << "WED ";
				break;
			case 4:
				cout << "THU ";
				break;
			case 5:
				cout << "FRI ";
				break;
			case 6:
				cout << "SAT ";
				break;
			case 7:
				cout << "SUN ";
				break;
			}
			count++;
			continue;
		}
		count++;
	}
	count = 0;
	while (true)
	{
		if (str3[count] == str4[count])
		{
			if ((str3[count] >= 'a' && str3[count] <= 'z') || (str3[count] >= 'A' && str3[count] <= 'Z'))
			{
				if (count < 10)
				{
					cout << "0";
				}
				cout << count;
				break;
			}
		}
		count++;
	}
	return 0;
}