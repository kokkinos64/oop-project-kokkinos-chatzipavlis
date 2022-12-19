#include <iostream>
#include "Characters.h"
#include "Map2.h"

using namespace std;

int main(void)
{
	int x, y;
	char team, input;

	// Create the map
	cout << "Enter map dimentions (x y): ";
	cin >> x >> y;
	Map M(x, y);
	M.PrintMap();

	// Team selection
	cout << "Select your team (w, v): ";
	cin >> team;

	while ((team != 'w') && (team != 'v'))	// Check for invalid input
	{
		cout << "Invalid input. Usage: w for Werewolves, v for Vampires.\n";
		cin >> team;
	}

	Avatar A(team,&M);
	Werewolves W1(&M);
	//Vampires V1(&M);
	
	system("timeout 3");

	// Starting the game
	M.PrintMap();

	while ((input = A.Move()) != 'q')
	{
		M.PrintMap();
		// PAUSE
		if (input == 'p')
		{
			A.PauseGame();
		}

		W1.WerewolfMove();
		//V1.VampireMove();
		M.PrintMap();
	}

	cout << "QUIT\n";
	system("timeout 2");
	return 0;
}