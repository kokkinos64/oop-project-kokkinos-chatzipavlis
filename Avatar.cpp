#include <iostream>
#include <conio.h>
#include "God.h"
#include "Avatar.h"

using namespace std;

Avatar::Avatar(char t) : Team_Selection(t)
{
    // Team_Selection = t;
    cout << "Avatar created.\n";
}

char Avatar::Move(void)
{
	int getch();
	char inputkey;

	inputkey = getch();

	while (inputkey != '0')
	{
		if (inputkey == 72)
		{
			cout << "UP\n";
			return 'u';
		}
		else if (inputkey == 80)
		{
			cout << "DOWN\n";
			return 'd';
		}
		else if (inputkey == 75)
		{
			cout << "LEFT\n";
			return 'l';
		}
		else if (inputkey == 77)
		{
			cout << "RIGHT\n";
			return 'r';
		}

		inputkey = getch();
	}


	cout << inputkey << endl;
}