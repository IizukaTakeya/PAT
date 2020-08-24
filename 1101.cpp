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
//1101
//1 3 4 2 5对不上
using namespace std;
int main()
{
	int count = 0;
	scanf("%d", &count);
	//vector <int> v1;
	int* v1 = new int[count];
	//vector <int> v2;
	int* v2 = new int[count];
	int* v3 = new int[count];
	int flag = 0;
	int flagCount = 0;
	int sum = count;
	int mark = 0;
	long long checkSum1 = 0;
	long long checkSum2 = 0;
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &v1[i]);
		v2[i] = v1[i];
		v3[i] = 0;
	}
	sort(v1, v1 + count);
	//v1排序后 v2排序前
	for (int i = 0; i < count; i++)
	{
		checkSum1 += v1[i];
		checkSum2 += v2[i];
		if (v1[i] != v2[i] || checkSum1 != checkSum2)
		{
			v3[i] = -1;
			sum--;
		}
		//cout << v3[i] << " " << flagCount << endl;
	}
	printf("%d\n", sum);
	for (int i = 0; i < count; i++)
	{
		if (mark == 1 && v3[i] == 0)
		{
			printf(" ");
		}
		if (v3[i] == 0)
		{
			mark = 1;
			printf("%d", v1[i]);
		}
	}
	printf("\n");
	return 0;
}