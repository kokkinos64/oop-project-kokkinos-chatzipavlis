#include <iostream>
#include <conio.h>	// For keyboard input
#include <cstdlib>	// For rand

#include "Characters.h"
#include "Map2.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Q 17
#define KEY_P ('p')
#define KEY_H 104

using namespace std;

// GOD MEMBER-FUNCTIONS

int God::getHealth(void)
{
    return Health;
}

int God::getAttack(void)
{
    return Attack;
}

int God::getDefense(void)
{
    return Defense;
}

God::God(void)
{
	//Health = 10;
	Meds = rand() % 3;			// Range = [0,2]
	Attack = (rand() % 3) + 1;	// Range = [1,3]
	Defense = (rand() % 2) + 1;	// Range = [1,2]
    cout << "God's constructor activated.\n";
}

int God::getX(void)
{
    return LocationX;
}

int God::getY(void)
{
    return LocationY;
}

void God::HealthDecreaseBy(int x)
{
	Health = Health - x;
}

void God::MoveUp(char c)
{	
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationX--;	// Change location
	s = mp->InsertAt(LocationX, LocationY, c);

	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationX++;
		mp->InsertAt(LocationX, LocationY, c);
	}

}

void God::MoveDown(char c)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationX++;								// Change location
	s = mp->InsertAt(LocationX, LocationY, c);		// Place the character at the new spot
	
	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationX--;
		mp->InsertAt(LocationX, LocationY, c);
	}
	
}

void God::MoveLeft(char c)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationY--;								// Change location
	s = mp->InsertAt(LocationX, LocationY, c);		// Place the character at the new spot
	
	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationY++;
		mp->InsertAt(LocationX, LocationY, c);
	}
	
}

void God::MoveRight(char c)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationY++;								// Change location
	s = mp->InsertAt(LocationX, LocationY, c);		// Place the character at the new spot
	
	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationY--;
		mp->InsertAt(LocationX, LocationY, c);
	}
	
}

// WEREWOLF MEMBER-FUNCTIONS

Werewolves::Werewolves(Map *m)
{


	// Map address
	mp = m;				// Pass through the address of map

	// Place the wereolf at a random spot on the matrix
	LocationX = rand() % m->getRows();		// Range: [0,Rows]		
	LocationY = rand() % m->getCols();		// Range: [0,Cols]
	m->InsertAt(LocationX, LocationY, 'W');							

};

void Werewolves::HealthRestore(void)
{
	Health = 10;
}

void Werewolves::WerewolfMove(void)
{
	

	int direction = rand() % 4;		// Range: [0,3]

	switch (direction)
	{
	case(0):		// up
		MoveUp('W');
		break;
	case(1):		// down
		MoveDown('W');
		break;
	case(2):		// left
		MoveLeft('W');
		break;
	case(3):		// right
		MoveRight('W');
		break;
	}
}

// VAMPIRE MEMBER-FUNCTIONS

Vampires::Vampires(Map* m)
{
	

	// Map address
	mp = m;				// Pass through the address of map

	// Place the wereolf at a random spot on the matrix
	LocationX = rand() % m->getRows();		// Range: [0,Rows]
	LocationY = rand() % m->getCols();		// Range: [0,Cols]


	m->InsertAt(LocationX, LocationY, 'V');
}

void Vampires::HealthRestore(void)
{
	Health = 10;
}

void Vampires::VampireMove(void)
{
	
	srand((unsigned)time(NULL));	// Seed for rand

	int direction = rand() % 8;		// Range: [0,7]

	switch (direction)
	{
	case(0):		// up
		MoveUp('V');
		break;
	case(1):		// down
		MoveDown('V');
		break;
	case(2):		// left
		MoveLeft('V');
		break;
	case(3):		// right
		MoveRight('V');
		break;
	case(4):		// upper left
		MoveUpperLeft();
		break;
	case(5):		// upper right
		MoveUpperRight();
		break;
	case(6):		// lower left
		MoveLowerLeft();
		break;
	case(7):		// lower right
		MoveLowerRight();
		break;
	}
}

void Vampires::MoveUpperLeft(void)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationX--;
	LocationY--;	// Change location
	s = mp->InsertAt(LocationX, LocationY, 'V');

	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationX++;
		LocationY++;
		mp->InsertAt(LocationX, LocationY, 'V');
	}
}

void Vampires::MoveUpperRight(void)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationY++;
	LocationX--;	// Change location
	s = mp->InsertAt(LocationX, LocationY, 'V');

	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationX++;
		LocationY--;
		mp->InsertAt(LocationX, LocationY, 'V');
	}
}

void Vampires::MoveLowerLeft(void)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationX--;
	LocationY++;	// Change location
	s = mp->InsertAt(LocationX, LocationY, 'V');

	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationX++;
		LocationY--;
		mp->InsertAt(LocationX, LocationY, 'V');
	}
}

void Vampires::MoveLowerRight(void)
{
	bool s = true;

	mp->RemoveFrom(LocationX, LocationY);		// Remove the previous character
	LocationX++;
	LocationY++;	// Change location
	s = mp->InsertAt(LocationX, LocationY, 'V');

	// If placement was unsucessful, go back
	if (s == false)
	{
		LocationX--;
		LocationY--;
		mp->InsertAt(LocationX, LocationY, 'V');
	}
}

// AVATAR MEMBER-FUNCTIONS

// Constructor
Avatar::Avatar(char t, Map *m) : Team_Selection(t)
{
	// Team_Selection = t;
	cout << "Avatar created.\n" << "Your team: ";

	switch (t)
	{
	case 'w':
		cout << "Werewolves";
		break;
	case 'v':
		cout << "Vampires";
		break;
	}
	cout << endl;

	// Map address
	mp = m;				// Pass through the address of map

	// Place avatar
	LocationX = 2;
	LocationY = 2;
	m->InsertAt(LocationX, LocationY, 'A');

	// Reset counters
	VampireCount = WerewolfCount = DaytimeCounter = 0;
	isDaytime = true;	// Daytime at start of game
}

char Avatar::Move(void)
{
	char key = getch();
	int value = key;

		switch (getch())
		{
		case(KEY_UP):
			MoveUp('A');
			break;

		case(KEY_DOWN):
			MoveDown('A');
			break;

		case(KEY_LEFT):
			MoveLeft('A');
			break;

		case(KEY_RIGHT):
			MoveRight('A');
			break;

		case(KEY_P):
			// PAUSE
			PauseGame(VampireCount, WerewolfCount);
			break;

		case(KEY_H):
			// HEALTH RESTORE
			UseMagicPot();
			system("timeout 2");
			break;

		default:
			cout << "QUIT\n";
			system("timeout 5");
			exit(0);
		}
}

void Avatar::PauseGame(int VampireCount, int WerewolfCount){
	int getch();
	char input;

	system("cls");  // Clear the screen;

	cout << "GAME PAUSED\n\n";
	cout << "\033[0;31mVampires alive:\t\t" << VampireCount << "\033[0m\n";
	cout << "\033[0;35mWerewolves alive:\t" << WerewolfCount << "\033[0m\n";
	cout << "\033[0;33mYou have " << MagicPotCount << " magic potions available in your inventory.\033[0m\n";

	cout << "\nDO YOU WANT TO CONTINUE? (y/n): ";
	input = getch();

	// Check for invalid input
	while (input != 'y' && input != 'n')
	{
		cout << "\nInvalid input, try again (y/n): ";
		input = getch();
	}

	// In case of valid input
	if (input == 'y')
	{
		return;
	}
	else if (input == 'n')
	{
		cout << "GAME OVER\n";
		system("timeout 5");
		exit(0);
	}
}

void Avatar::PrintCurrentDayTime(void)
{
	cout << "Current time: ";

	if (isDaytime == true)
	{
		cout << "DAY" << endl;
	}
	else
	{
		cout << "NIGHT" << endl;
	}
}

void Avatar::PrintCurrentTeam(void)
{
	cout << "Your team is ";

	if (Team_Selection == 'w')
	{
		cout << "Werewolves\n";
	}
	else
	{
		cout << "Vampires\n";
	}
}

void Avatar::IncreaseMagicPotCount(void)
{
	MagicPotCount++;
}

void Avatar::UseMagicPot(void)
{	
	if (MagicPotCount > 0)
	{
		if (Team_Selection == 'w' && isDaytime == false)
		{
			cout << "Using magic potion on Werewolves.\n";
			Werewolves::HealthRestore();
			MagicPotCount--;
		}
		else if (Team_Selection == 'v' && isDaytime == true)
		{
			cout << "Using magic potion on Vampires.\n";
			Vampires::HealthRestore();
			MagicPotCount--;
		}
		else
		{
			cout << "Cannot use magic potion at this time.\n";
		}
	}
	else
	{
		cout << "You do not have any magic potions left.\n";
	}
}
