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
	int MonstersNum = (x * y) / 15;

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
		//M.PrintMap();

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

			// Combat condition check: WEREWOLF
			int WerewolfX = WerewolfVector.at(i)->getX();
			int WerewolfY = WerewolfVector.at(i)->getY();
			int EnemyX = 0, EnemyY = 0;

			M.ScanArea(WerewolfX, WerewolfY, 'W', EnemyX, EnemyY);

			for (int j = 0; j < MonstersNum; j++)
			{
				// Find the vampire with the exact same coordinates
				if ( (VampireVector.at(j)->getX() == EnemyX) && (VampireVector.at(j)->getY() == EnemyY) )
				{
					if (WerewolfVector.at(i)->getAttack() > VampireVector.at(j)->getAttack())
					{
						VampireVector.at(j)->HealthDecreaseBy(WerewolfVector.at(i)->getAttack() - VampireVector.at(j)->getDefense());
					}
					else if ((VampireVector.at(j)->getAttack() > WerewolfVector.at(i)->getAttack()))
					{
						WerewolfVector.at(i)->HealthDecreaseBy(VampireVector.at(j)->getAttack() - WerewolfVector.at(i)->getDefense());
					}
				}
			}

			// Combat condition check: VAMPIRE
			int VampireX = VampireVector.at(i)->getX();
			int VampireY = VampireVector.at(i)->getY();

			M.ScanArea(VampireX, VampireX, 'W', EnemyX, EnemyY);

			for (int j = 0; j < MonstersNum; j++)
			{
				// Find the werewolf with the exact same coordinates
				if ((VampireVector.at(j)->getX() == EnemyX) && (VampireVector.at(j)->getY() == EnemyY))
				{
					if (WerewolfVector.at(i)->getAttack() > VampireVector.at(j)->getAttack())
					{
						VampireVector.at(j)->HealthDecreaseBy(WerewolfVector.at(i)->getAttack() - VampireVector.at(j)->getDefense());
					}
					else if ((VampireVector.at(j)->getAttack() > WerewolfVector.at(i)->getAttack()))
					{
						WerewolfVector.at(i)->HealthDecreaseBy(VampireVector.at(j)->getAttack() - WerewolfVector.at(i)->getDefense());
					}
				}
			}

			/*if (((WerewolfX == VampireX - 1)) || (WerewolfX == VampireX + 1) || ((WerewolfX == VampireX -1) && (WerewolfX == VampireY - 1)) || ((WerewolfX == VampireX - 1) && (WerewolfX == VampireY + 1)) || ((WerewolfX == VampireX + 1) && (WerewolfX == VampireY - 1)) || ((WerewolfX == VampireX + 1) && (WerewolfX == VampireY + 1))) {
				if (((WerewolfY == VampireY - 1)) || (WerewolfY == VampireY + 1)) {
					if (WerewolfVector.at(i)->getAttack() > VampireVector.at(i)->getAttack()) {
						VampireVector.at(i)->HealthDecreaseBy(WerewolfVector.at(i)->getAttack() - VampireVector.at(i)->getDefense());
					}
					else if ((VampireVector.at(i)->getAttack() > WerewolfVector.at(i)->getAttack())) {
						WerewolfVector.at(i)->HealthDecreaseBy(VampireVector.at(i)->getAttack() - WerewolfVector.at(i)->getDefense());
					}
				}
			}*/
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