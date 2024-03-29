#include <iostream>
#include <vector>
#include "Characters.h"
#include "Map2.h"

using namespace std;

// CUSTOM CLIENT FUNCTION PROTOTYPES
void Attack(int&, int&, int&, int&, int&, int&, vector<Werewolves*>&, vector<Vampires*>&);

// MAIN FUNCTION
int main(void)
{
	// VARIABLES FOR INPUT
	int x, y;
	char team;

	// MAP CREATION
	cout << "Enter map dimentions (x y): ";
	cin >> x >> y;

	Map *M = new Map(x, y);	// Dynamically-created map

	M->PrintMap();

	// TEAM SELECTION
	cout << "Select your team (w, v): ";
	cin >> team;

	while ((team != 'w') && (team != 'v'))	// Check for invalid input
	{
		cout << "Invalid input. Usage: w for Werewolves, v for Vampires.\n";
		cin >> team;
	}

	// AVATAR CREATION
	Avatar *A = new Avatar(team,M);			// Dynamcally-created avatar

	// WEREWOLF AND VAMPIRE CREATION
	vector<Werewolves*> WerewolfVector;			//Create pointer vectors with werewolves
	vector<Vampires*> VampireVector;			//Create pointer vectors with vampires

	int MonstersNum = (x * y) / 15;				// Calculate the members of each team, according to the dimentions of the map

	for (int i = 0; i < MonstersNum; i++)
	{
		WerewolfVector.push_back(new Werewolves(M));
		A->WerewolfCount++;
		VampireVector.push_back(new Vampires(M));
		A->VampireCount++;
	}

	// STARTING THE GAME
	A->PrintCurrentDayTime();
	A->PrintCurrentTeam();
	M->PrintMap();

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

			// CHECK IF CURRENT WEREWOLF IS ANY CLOSE TO A VAMPIRE
			int WerewolfX = WerewolfVector.at(i)->getX();
			int WerewolfY = WerewolfVector.at(i)->getY();
			int WerewolfHealth = WerewolfVector.at(i)->getHealth();
			int WerewolfAttack = WerewolfVector.at(i)->getAttack();
			int WerewolfDefence = WerewolfVector.at(i)->getDefense();

			for (int j = 0; j < MonstersNum; j++)
			{
				// GET COORDINATES OF CURRENT VAMPIRE
				int VampireX = VampireVector.at(j)->getX();
				int VampireY = VampireVector.at(j)->getY();
				int vampireHealth = VampireVector.at(i)->getHealth();
				int VampireAttack = VampireVector.at(j)->getAttack();
				int VampireDefence = VampireVector.at(j)->getDefense();

				// VAMPIRE IS UP
				if (WerewolfX == VampireX - 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefence, VampireDefence, WerewolfVector, VampireVector);
				}
				// VAMPIRE IS DOWN
				else if (WerewolfX = VampireX + 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefence, VampireDefence, WerewolfVector, VampireVector);
				}
				// VAMPIRE IS LEFT
				else if (WerewolfY = VampireY - 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefence, VampireDefence, WerewolfVector, VampireVector);
				}
				// VAMPIRE IS RIGHT
				else if (WerewolfY = VampireY + 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefence, VampireDefence, WerewolfVector, VampireVector);
				}
			}
		}

		// PRINT MAP & STATS
		M->PrintMap();
		A->PrintCurrentDayTime();
		A->PrintCurrentTeam();

		A->DaytimeCounter++;

		A->Move();
	}

	// TERMINATION
	delete M;	// Memory dislocation fot the map
	delete A;	// Memory dislocation for the avatar
	cout << "GAME OVER\n";
	system("timeout 5");
	return 0;
}

// CUSTOM CLIENT FUNCTIONS
void Attack(int& i, int& j, int& WerewolfAttack, int& VampireAttack, int& WerewolfDefence, int& VampireDefence, vector<Werewolves*>& WerewolfVector,vector<Vampires *>& VampireVector)
{
	//cout << "Encounter!\n"; // When using the stack to store the map, this results in STACK SMASHING at the RemoveFrom() function. On the other hand, when using the heap, it works perfectly fine.

	if (WerewolfAttack > VampireAttack)	// Werewolf is stronger and attacks
	{
		VampireVector.at(j)->HealthDecreaseBy(WerewolfAttack - VampireDefence);	// Vampire's health decreases
	}
	else if (VampireAttack > WerewolfAttack) // Vampire is stronger and attacks
	{
		WerewolfVector.at(i)->HealthDecreaseBy(VampireAttack - WerewolfDefence);
	}
	else // Attack levels are the same, do nothing
	{
		return;
	}
}