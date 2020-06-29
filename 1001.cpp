#include<iostream>
#include<cmath>
using namespace std;
int pnt(int n)
{
    int part1 = 0;
    int part2 = 0;
    int part3 = 0;
    if (n < 0)
    {
        cout << "-";
    }
    n = abs(n);
    if (n < 1000)
    {
        cout << n;
        return 0;
    }
    if (n > 999 && n < 1000000)
    {
        part1 = n % 1000;
        part2 = (n / 1000);
        cout << part2 << ",";
        if (part1 < 100)
        {
            cout << "0";
        }
        if (part1 < 10)
        {
            cout << "0";
        }
        cout << part1;
        return 0;
    }
    if (n > 999999)
    {
        part1 = n % 1000;
        part2 = (n % 1000000 - part1) / 1000;
        part3 = (n / 1000000);
        cout << part3 << ",";
        if (part2 < 100)
        {
            cout << "0";
        }
        if (part2 < 10)
        {
            cout << "0";
        }
        cout << part2 << ",";
        if (part1 < 100)
        {
            cout << "0";
        }
        if (part1 < 10)
        {
            cout << "0";
        }
        cout << part1;
        return 0;
    }
    return 1;
}
int main()
{
    int var1 = 0;
    int var2 = 0;
    cin >> var1;
    cin >> var2;
    int var3 = 0;
    var3 = var1 + var2;
    pnt(var3);
    return 0;
}
