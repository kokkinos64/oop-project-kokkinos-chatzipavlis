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

void Avatar::Move(void)
{
	int getch();
	char inputkey;

	inputkey = getch();

	while (inputkey != '0')
	{
		if (!_kbhit())
		{
			continue;
		}
		else
		{
			if (inputkey == 'α')
			{
				cout << "UP\n";
			}
			inputkey = getch();
		}
	}


	cout << inputkey << endl;
}