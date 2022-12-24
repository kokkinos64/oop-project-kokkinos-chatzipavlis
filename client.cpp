#include <iostream>
#include <vector>
#include <cstdlib>
#include "Characters.h"
#include "Map2.h"

using namespace std;

// CUSTOM CLIENT FUNCTION PROTOTYPES
void Attack(int&, int&, int&, int&, int&, int&, vector<Werewolves*>&, vector<Vampires*>&);

template <typename T> void BuddyHealFunc(T &t, int &i, int &j)
{
	bool BuddyHeal = false;
	
	BuddyHeal = (bool)rand() % 2; // Range: [0,1]

	if (BuddyHeal == true)
	{
		t.at(i)->MedsDecrease();
		t.at(j)->HealthIncrease();
	}
}

// MAIN FUNCTION
int main(void)
{
	// VARIABLES FOR INPUT
	int x, y, i ,j;
	char team;
	int WerewolfX, WerewolfX2, WerewolfY, WerewolfY2, WerewolfHealth, WerewolfHealth2, WerewolfMeds, WerewolfAttack, WerewolfDefense;
	int VampireX, VampireX2, VampireY, VampireY2, VampireHealth, VampireHealth2, VampireMeds, VampireAttack, VampireDefense;
	bool BuddyHeal;

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

	for (i = 0; i < MonstersNum; i++)
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
		for (i = 0; i < MonstersNum; i++)
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
			 WerewolfX = WerewolfVector.at(i)->getX();
			 WerewolfY = WerewolfVector.at(i)->getY();
			 WerewolfHealth = WerewolfVector.at(i)->getHealth();
			 WerewolfAttack = WerewolfVector.at(i)->getAttack();
			 WerewolfDefense = WerewolfVector.at(i)->getDefense();

			for (j = 0; j < MonstersNum; j++)
			{
				// GET COORDINATES OF CURRENT VAMPIRE
				 VampireX = VampireVector.at(j)->getX();
				 VampireY = VampireVector.at(j)->getY();
				 VampireHealth = VampireVector.at(i)->getHealth();
				 VampireAttack = VampireVector.at(j)->getAttack();
				 VampireDefense = VampireVector.at(j)->getDefense();

				// VAMPIRE IS UP
				if (WerewolfX == VampireX - 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefense, VampireDefense, WerewolfVector, VampireVector);
				}
				// VAMPIRE IS DOWN
				else if (WerewolfX = VampireX + 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefense, VampireDefense, WerewolfVector, VampireVector);
				}
				// VAMPIRE IS LEFT
				else if (WerewolfY = VampireY - 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefense, VampireDefense, WerewolfVector, VampireVector);
				}
				// VAMPIRE IS RIGHT
				else if (WerewolfY = VampireY + 1)
				{
					Attack(i, j, WerewolfAttack, VampireAttack, WerewolfDefense, VampireDefense, WerewolfVector, VampireVector);
				}
			}
		}

		// CHECK IF A FELLOW TEAMMATE IS LOW ON HEALTH

		// WEREWOLVES
		for (i = 0; i < MonstersNum; i++)
		{
			 WerewolfX = WerewolfVector.at(i)->getX();
			 WerewolfY = WerewolfVector.at(i)->getY();
			 WerewolfMeds = WerewolfVector.at(i)->getMeds();
			
			for (j = 0; j < MonstersNum; j++)
			{
				 WerewolfX2 = WerewolfVector.at(j)->getX();
				 WerewolfY2 = WerewolfVector.at(j)->getY();
				 WerewolfHealth2 = WerewolfVector.at(j)->getHealth();

				// IF FELLOW WEREWOLF HAS HEALTH LESS THAN 10
				if (WerewolfHealth2 < 10)
				{
					// IF FELLOW WEREWOLF IS UP
					if (WerewolfX == WerewolfX2 - 1)
					{
						BuddyHealFunc <vector<Werewolves*>>(WerewolfVector, i, j);
					}
					// IF FELLOW WEREWOLF IS DOWN
					else if (WerewolfX == WerewolfX2 + 1)
					{
						BuddyHealFunc <vector<Werewolves*>>(WerewolfVector, i, j);
					}
					// IF FELLOW WEREWOLF IS LEFT
					else if (WerewolfY == WerewolfY2 - 1)
					{
						BuddyHealFunc <vector<Werewolves*>>(WerewolfVector, i, j);
					}
					// IF FELLOW WEREWOLF IS RIGHT
					else if (WerewolfY == WerewolfY2 + 1)
					{
						BuddyHealFunc <vector<Werewolves*>>(WerewolfVector, i, j);
					}
				}
				
			}
		}

		// VAMPIRES
		for (i = 0; i < MonstersNum; i++)
		{
			 VampireX = VampireVector.at(i)->getX();
			 VampireY = VampireVector.at(i)->getY();
			 VampireMeds = VampireVector.at(i)->getMeds();

			for (j = 0; j < MonstersNum; j++)
			{
				 VampireX2 = VampireVector.at(j)->getX();
				 VampireY2 = VampireVector.at(j)->getY();
				 VampireHealth2 = VampireVector.at(j)->getHealth();

				// IF FELLOW WEREWOLF HAS HEALTH LESS THAN 10
				if (VampireHealth2 < 10)
				{
					// IF FELLOW WEREWOLF IS UP
					if (VampireX == VampireX2 - 1)
					{
						BuddyHealFunc <vector<Vampires*>>(VampireVector, i, j);
					}
					// IF FELLOW WEREWOLF IS DOWN
					else if (VampireX == VampireX2 + 1)
					{
						BuddyHealFunc <vector<Vampires*>>(VampireVector, i, j);
					}
					// IF FELLOW WEREWOLF IS LEFT
					else if (VampireY == VampireY2 - 1)
					{
						BuddyHealFunc <vector<Vampires*>>(VampireVector, i, j);
					}
					// IF FELLOW WEREWOLF IS RIGHT
					else if (VampireY == VampireY2 + 1)
					{
						BuddyHealFunc <vector<Vampires*>>(VampireVector, i, j);
					}
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
void Attack(int& i, int& j, int& WerewolfAttack, int& VampireAttack, int& WerewolfDefense, int& VampireDefense, vector<Werewolves*>& WerewolfVector,vector<Vampires *>& VampireVector)
{
	//cout << "Encounter!\n"; // When using the stack to store the map, this results in STACK SMASHING at the RemoveFrom() function. On the other hand, when using the heap, it works perfectly fine.

	if (WerewolfAttack > VampireAttack)	// Werewolf is stronger and attacks
	{
		VampireVector.at(j)->HealthDecreaseBy(WerewolfAttack - VampireDefense);	// Vampire's health decreases
	}
	else if (VampireAttack > WerewolfAttack) // Vampire is stronger and attacks
	{
		WerewolfVector.at(i)->HealthDecreaseBy(VampireAttack - WerewolfDefense);
	}
	else // Attack levels are the same, do nothing
	{
		return;
	}
}