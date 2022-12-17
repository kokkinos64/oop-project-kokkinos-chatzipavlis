#include <iostream>
#include <conio.h>	// For keyboard input
#include <cstdlib>	// For rand

#include "Characters.h"
#include "Map2.h"


using namespace std;

// GLOBALS
int WerewolfCount = 0, VampireCount = 0;    // Global counters for the members of each team, initialized to 0.

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

void God::MoveUp(void)
{
	LocationY--;
}

void God::MoveDown(void)
{
	LocationY++;
}

void God::MoveLeft(void)
{
	LocationX--;
}

void God::MoveRight(void)
{
	LocationX++;
}

void God::PauseGame(void)
{
	int getch();
	char input;

	system("cls");  // Clear the screen;

	cout << "GAME PAUSED\n\n";
	cout << "Vampires alive:\t\t" << VampireCount << endl;
	cout << "Werewolves alive:\t" << WerewolfCount << endl;
	cout << "You have " << Meds << " magic potions available in your inventory.\n";

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

// WEREWOLF MEMBER-FUNCTIONS

void Werewolves::WerewolfMove(void)
{
	srand((unsigned)time(NULL));	// Seed for rand

	int direction = rand() % 5;		// Range: [0,4]

	switch (direction)
	{
	case(0):		// up
		MoveUp();
		break;
	case(1):		// down
		MoveDown();
		break;
	case(2):		// left
		MoveLeft();
		break;
	case(3):		// right
		MoveRight();
		break;
	}
}

// VAMPIRE MEMBER-FUNCTIONS

void Vampires::VampireMove(void)
{
	srand((unsigned)time(NULL));	// Seed for rand

	int direction = rand() % 8;		// Range: [0,7]

	switch (direction)
	{
	case(0):		// up
		MoveUp();
		break;
	case(1):		// down
		MoveDown();
		break;
	case(2):		// left
		MoveLeft();
		break;
	case(3):		// right
		MoveRight();
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
	LocationX--;
	LocationY--;
}

void Vampires::MoveUpperRight(void)
{
	LocationX++;
	LocationY--;
}

void Vampires::MoveLowerLeft(void)
{
	LocationX--;
	LocationY++;
}

void Vampires::MoveLowerRight(void)
{
	LocationX++;
	LocationY++;
}

// AVATAR MEMBER-FUNCTIONS

// Constructor
Avatar::Avatar(char t) : Team_Selection(t)
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
}

char Avatar::Move(void)
{
	int getch();
	char inputkey;

	inputkey = getch();

	switch (inputkey)
	{
	case(72):
		cout << "UP\n";
		return 'u';
		break;

	case(80):
		cout << "DOWN\n";
		return 'd';
		break;

	case(75):
		cout << "LEFT\n";
		return 'l';
		break;

	case(77):
		cout << "RIGHT\n";
		return 'r';
		break;
	default:
		return inputkey;
		break;
	}

	cout << inputkey << endl;
}


