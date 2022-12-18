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

	//mp->PrintMap();
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
	
	//mp->PrintMap();
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
	
	//mp->PrintMap();
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
	
	//mp->PrintMap();
}

// WEREWOLF MEMBER-FUNCTIONS

Werewolves::Werewolves(Map *m)
{
	srand((unsigned)time(NULL));	// Seed for rand

	// Map address
	mp = m;				// Pass through the address of map

	// Place the wereolf at a random spot on the matrix
	LocationX = rand() % m->getRows();		// Range: [0,Rows]
	LocationY = rand() % m->getCols();		// Range: [0,Cols]
	m->InsertAt(LocationX, LocationY, 'W');

}

void Werewolves::WerewolfMove(void)
{
	srand((unsigned)time(NULL));	// Seed for rand

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
	srand((unsigned)time(NULL));	// Seed for rand

	// Map address
	mp = m;				// Pass through the address of map

	// Place the wereolf at a random spot on the matrix
	LocationX = rand() % m->getRows();		// Range: [0,Rows]
	LocationY = rand() % m->getCols();		// Range: [0,Cols]
	m->InsertAt(LocationX, LocationY, 'V');
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
	
	// Equip magic potion
	MagicPotCount = 1;	// Magic pot initialized to 1 at the start of each game
	
	// Map address
	mp = m;				// Pass through the address of map

	// Place avatar
	LocationX = 2;
	LocationY = 2;
	m->InsertAt(LocationX, LocationY, 'A');
	
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
		MoveUp('A');
		break;

	case(80):
		cout << "DOWN\n";
		MoveDown('A');
		break;

	case(75):
		cout << "LEFT\n";
		MoveLeft('A');
		break;

	case(77):
		cout << "RIGHT\n";
		MoveRight('A');
		break;
	default:
		return inputkey;
		break;
	}

	cout << inputkey << endl;
}

void Avatar::PauseGame(void)
{
	int getch();
	char input;

	system("cls");  // Clear the screen;

	cout << "GAME PAUSED\n\n";
	cout << "Vampires alive:\t\t" << VampireCount << endl;
	cout << "Werewolves alive:\t" << WerewolfCount << endl;
	cout << "You have " << MagicPotCount << " magic potions available in your inventory.\n";

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