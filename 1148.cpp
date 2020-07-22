#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	int* player = new int[count];
	int* statement = new int[count];
	for (int i = 0; i < count; ++i)
	{
		player[i] = 1;
		cin >> statement[i];
	}
	/*for (int i = 0; i < count; ++i)
	{
		cout << statement[count] << endl;
	}*/
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			player[i] = -1;
			player[j] = -1;
			int cnt = 0;
			int id = 0;
			for (int k = 0; k < count; ++k)
			{
				//cout << statement[k] << "\t" << player[abs(statement[k]) - 1] << endl;
				if (statement[k] * player[abs(statement[k]) - 1] < 0)
				{
					++cnt;
					id += player[k];
				}
			}
			if (cnt == 2 && id == 0)
			{
				cout << i + 1 << " " << j + 1;
				return 0;
			}
			player[i] = 1;
			player[j] = 1;
		}
	}
	cout << "No Solution";
	return 0;
}