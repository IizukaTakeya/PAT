#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int a1=0, b1=0, c1=0;
	int a2=0, b2=0, c2=0;
	scanf("%d.%d.%d", &a1, &b1, &c1);
	scanf("%d.%d.%d", &a2, &b2, &c2);
	a2 += a1;
	b2 += b1;
	c2 += c1;
	b2 += c2 / 29;
	c2 %= 29;
	a2 += b2 / 17;
	b2 %= 17;
	printf("%d.%d.%d", a2, b2, c2);
	return 0;
}