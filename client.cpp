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

	// OBJECT CREATION

	Avatar A(team,&M);
	vector<Werewolves*> WerewolfVector;			//Create pointer vectors with werewolves
	vector<Vampires*> VampireVector;			//Create pointer vectors with vampires

	// Calculate the number of monsters that'll be created
	int MonstersNum = (x * y) / 30;

	for (int i = 0; i < MonstersNum; i++)
	{
		WerewolfVector.push_back(new Werewolves(&M));
		A.WerewolfCount++;
		VampireVector.push_back(new Vampires(&M));
		A.VampireCount++;
	}

	// Starting the game
	M.PrintMap();

	// Create vector iterators, used to traverse the vectors
	/*vector<Werewolves*>::iterator itrW;
	vector<Vampires*>::iterator itrV;*/

	input = A.Move();

	while (input != 'q')
	{
		M.PrintMap();

		// Monster movements
		for (int i = 0; i < MonstersNum; i++)
		{
			WerewolfVector.at(i)->WerewolfMove();
			VampireVector.at(i)->VampireMove();
		}

		M.PrintMap();

		input = A.Move();
	}

	cout << "QUIT\n";
	system("timeout 5");
	return 0;
}