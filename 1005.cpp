#include <iostream>
#include <string>
using namespace std;
int pnt(int n, int flag);
int main()
{
    string s;
    cin >> s;
    int count = 0;
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        count += s[i] - 48;
    }
    if (count >= 100)
    {
        pnt(count / 100, flag);
        count %= 100;
        flag = 1;
    }
    if (count >= 10 || flag == 1)
    {
        pnt(count / 10, flag);
        count %= 10;
        flag = 1;
    }
    pnt(count, flag);
    return 0;
}
int pnt(int n, int flag)
{
    if (flag == 1)
    {
        cout << " ";
    }
    if (n == 0)
    {
        cout << "zero";
    }
    if (n == 1)
    {
        cout << "one";
    }
    if (n == 2)
    {
        cout << "two";
    }
    if (n == 3)
    {
        cout << "three";
    }
    if (n == 4)
    {
        cout << "four";
    }
    if (n == 5)
    {
        cout << "five";
    }
    if (n == 6)
    {
        cout << "six";
    }
    if (n == 7)
    {
        cout << "seven";
    }
    if (n == 8)
    {
        cout << "eight";
    }
    if (n == 9)
    {
        cout << "nine";
    }
    return 0;
}