#include <iostream>
#include <vector>
#include "Characters.h"
#include "Map2.h"

using namespace std;

int main(void)
{
	// VARIABLES FOR INPUT
	int x, y;
	char team;

	// MAP CREATION
	cout << "Enter map dimentions (x y): ";
	cin >> x >> y;

	Map M(x, y);

	M.PrintMap();

	// TEAM SELECTION
	cout << "Select your team (w, v): ";
	cin >> team;

	while ((team != 'w') && (team != 'v'))	// Check for invalid input
	{
		cout << "Invalid input. Usage: w for Werewolves, v for Vampires.\n";
		cin >> team;
	}

	// AVATAR CREATION
	Avatar *A = new Avatar(team,&M);			// Dynamcally-created avatar

	// WEREWOLF AND VAMPIRE CREATION
	vector<Werewolves*> WerewolfVector;			//Create pointer vectors with werewolves
	vector<Vampires*> VampireVector;			//Create pointer vectors with vampires

	int MonstersNum = (x * y) / 15;				// Calculate the members of each team, according to the dimentions of the map

	for (int i = 0; i < MonstersNum; i++)
	{
		WerewolfVector.push_back(new Werewolves(&M));
		A->WerewolfCount++;
		VampireVector.push_back(new Vampires(&M));
		A->VampireCount++;
	}

	// STARTING THE GAME
	A->PrintCurrentDayTime();
	A->PrintCurrentTeam();
	M.PrintMap();

	A->Move();

	while (A->VampireCount != 0 || A->WerewolfCount != 0)
	{
		//M.PrintMap();

		// Change the time of day
		if ((A->DaytimeCounter %= 5) == 0) {
			A->isDaytime = !(A->isDaytime);	// Switch daytime
			cout << "Daytime has changed\n";
		}

		// Monster movements
		for (int i = 0; i < MonstersNum; i++)
		{
			// CHECK THE HEALTH OF CURRENT WEREWOLF
			if (WerewolfVector.at(i)->getHealth() == 0)
			{
				delete WerewolfVector.at(i);
				A->WerewolfCount--;
			}

			// CHECK THE HEALTH OF CURRENT VAMPIRE
			if (VampireVector.at(i)->getHealth() == 0)
			{
				delete VampireVector.at(i);
				A->VampireCount--;
			}

			// MOVE CURRENT MONSTERS
			WerewolfVector.at(i)->WerewolfMove();
			VampireVector.at(i)->VampireMove();

			// GET CURRENT MONSTER LOCATIONS
			int WerewolfX = WerewolfVector.at(i)->getX();
			int WerewolfY = WerewolfVector.at(i)->getY();
			int VampireX = VampireVector.at(i)->getX();
			int VampireY = VampireVector.at(i)->getY();
			
			// CHECK IF THEY ARE IN CLOSE PROXIMITY TO EACH OTHER
			if (((WerewolfX == VampireX - 1)) || (WerewolfX == VampireX + 1) || ((WerewolfX == VampireX - 1) && (WerewolfX == VampireY - 1)) || ((WerewolfX == VampireX - 1) && (WerewolfX == VampireY + 1)) || ((WerewolfX == VampireX + 1) && (WerewolfX == VampireY - 1)) || ((WerewolfX == VampireX + 1) && (WerewolfX == VampireY + 1)))
			{
				if (((WerewolfY == VampireY - 1)) || (WerewolfY == VampireY + 1))
				{
					if (WerewolfVector.at(i)->getAttack() > VampireVector.at(i)->getAttack())
					{
						VampireVector.at(i)->HealthDecreaseBy(WerewolfVector.at(i)->getAttack() - VampireVector.at(i)->getDefense());
					}
					else if ((VampireVector.at(i)->getAttack() > WerewolfVector.at(i)->getAttack()))
					{
						WerewolfVector.at(i)->HealthDecreaseBy(VampireVector.at(i)->getAttack() - WerewolfVector.at(i)->getDefense());
					}
				}
			}
		}

		// PRINT MAP & STATS
		M.PrintMap();
		A->PrintCurrentDayTime();
		A->PrintCurrentTeam();

		A->DaytimeCounter++;

		A->Move();
	}

	// TERMINATION
	delete A;	// Memory dislocation for the avatar
	cout << "GAME OVER\n";
	system("timeout 5");
	return 0;
}