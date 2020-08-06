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
using namespace std;
//a-z 97-122
//1055
struct people
{
	string name;
	int age = 0;
	int money = 0;
};

people person;
bool cmp(people a, people b);
int main()
{
	int count1 = 0;
	int count2 = 0;
	vector<people> s;
	vector<people> s1;
	int ageCount[201] = { 0 };
	cin >> count1 >> count2;
	for (int i = 0; i < count1; ++i)
	{
		cin >> person.name;
		//cin >> person.name >> person.age >> person.money;
		scanf("%d%d", &person.age, &person.money);
		s.push_back(person);
	}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < s.size(); ++i)
	{
		if (ageCount[s[i].age] < 100)
		{
			s1.push_back(s[i]);
			++ageCount[s[i].age];
		}
	}
	sort(s1.begin(), s1.end(), cmp);
	for (int i = 0; i < count2; ++i)
	{
		int count3 = 0;
		int lowBound = 0;
		int highBound = 0;
		int flag = 0;
		int richCount = 0;
		//cin >> count3 >> lowBound >> highBound;
		scanf("%d%d%d", &count3, &lowBound, &highBound);
		printf("Case #%d:", i + 1);
		for (int j = 0; j < s1.size(); ++j)
		{
			if (s1[j].age >= lowBound && s1[j].age <= highBound && richCount < count3)
			{
				//cout << endl << s[j].name << " " << s[j].age << " " << s[j].money;
				printf("\n%s %d %d", s1[j].name.c_str(), s1[j].age, s1[j].money);
				++richCount;
			}
		}
		if (richCount == 0)
		{
			printf("\nNone");
		}
		printf("\n");
	}
	return 0;
}

bool cmp(people a, people b)
{
	if (a.money == b.money)
	{
		if (a.age == b.age)
		{
			return a.name < b.name;
		}
		else
		{
			return a.age < b.age;
		}
	}
	return a.money > b.money;
}