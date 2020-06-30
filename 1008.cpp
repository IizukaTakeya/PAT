#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	int currentPos = 0;
	int nextPos = 0;
	int timeCount = 0;
	cin >> count;
	timeCount += count * 5;
	for (int i = 0; i < count; i++)
	{
		cin >> nextPos;
		nextPos > currentPos ? timeCount += 6 * (nextPos - currentPos) : timeCount += 4 * (currentPos - nextPos);
		currentPos = nextPos;
	}
	cout << timeCount;
	return 0;
}