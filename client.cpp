#include <iostream>
#include <vector>
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
	/*Werewolves W1(&M);
	Vampires V1(&M);*/

	vector<Werewolves*> WerewolfVector;
	vector<Vampires*> VampireVector;

	// Calculate the number of monsters that'll be created
	int MonstersNum = (x * y) / 30;

	for (int i = 0; i < MonstersNum; i++)
	{
		WerewolfVector.push_back(new Werewolves(&M));
		VampireVector.push_back(new Vampires(&M));
	}

	// Starting the game
	M.PrintMap();

	// Create vector iterators, used to traverse the vectors
	/*vector<Werewolves*>::iterator itrW;
	vector<Vampires*>::iterator itrV;*/

	while ((input = A.Move()) != 'q')
	{
		M.PrintMap();
		// PAUSE
		if (input == 'p')
		{
			A.PauseGame();
		}

		// Monster movements
		for (int i = 0; i < MonstersNum; i++)
		{
			WerewolfVector.at(i)->WerewolfMove();
			VampireVector.at(i)->VampireMove();
		}
		

		/*W1.WerewolfMove();
		V1.VampireMove();*/
		/*M.PrintMap();*/
	}

	cout << "QUIT\n";
	system("timeout 2");
	return 0;
}