#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{

	int getch();
	char inputkey;

	inputkey = getch();

	while (inputkey != '0')
	{
		// !_kbhit() BUFFER ISSUE
		if (false)
		{
			continue;
		}
		else
		{
			if (inputkey == 72)
			{
				cout << "UP\n";
			}
			else if (inputkey == 80)
			{
				cout << "DOWN\n";
			}
			else if (inputkey == 75)
			{
				cout << "LEFT\n";
			}
			else if (inputkey == 77)
			{
				cout << "RIGHT\n";
			}

			inputkey = getch();
		}
	}

	return 0;
}