#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    double arr[1001] = { 0 };
    int count = 0;
    int flag = 0;
    for (int i = 0; i < 2; i++)
    {
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            int a = 0;
            double b = 0;
            cin >> a >> b;
            arr[a] += b;
        }
    }
    count = 0;
    for (int i = 1000; i >= 0; i--)
    {
        if (arr[i] != 0)
            count++;
    }
    cout << count;
    for (int i = 1000; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << arr[i];
            flag = 1;
        }
    }
    /*if (flag==0)
    {
        cout<<" 0 0";
    }*/
    return 0;
}