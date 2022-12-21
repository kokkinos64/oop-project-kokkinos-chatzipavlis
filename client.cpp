#include <iostream>
#include <vector>
#include "Characters.h"
#include "Map2.h"

using namespace std;

int main(void)
{
	int x, y;
	char team;

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
	A.PrintCurrentDayTime();
	A.PrintCurrentTeam();
	M.PrintMap();

	// Create vector iterators, used to traverse the vectors
	/*vector<Werewolves*>::iterator itrW;
	vector<Vampires*>::iterator itrV;*/
	
	A.Move();

		while (A.VampireCount != 0 || A.WerewolfCount != 0)
		{
			M.PrintMap();

			// Change the time of day
			if ((A.DaytimeCounter %= 5) == 0) {
				A.isDaytime = !(A.isDaytime);	// Switch daytime
				cout << "Daytime has changed\n";
			}

			// Monster movements
			for (int i = 0; i < MonstersNum; i++)
			{
				// Check health status
				if (WerewolfVector.at(i)->getHealth() == 0)
				{
					delete WerewolfVector.at(i);
					A.WerewolfCount--;
				}

				if (VampireVector.at(i)->getHealth() == 0)
				{
					delete VampireVector.at(i);
					A.VampireCount--;
				}

				// Move monsters
				WerewolfVector.at(i)->WerewolfMove();
				VampireVector.at(i)->VampireMove();
			}

			M.PrintMap();
			A.PrintCurrentDayTime();
			A.PrintCurrentTeam();

			A.DaytimeCounter++;

			A.Move();
		}
	

		cout << "A team has been eliminated.\n\nGAME OVER\n";
		system("timeout 5");
	return 0;
}