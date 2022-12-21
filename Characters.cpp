#include <iostream>
#include <conio.h>	// For keyboard input
#include <cstdlib>	// For rand

#include "Characters.h"
#include "Map2.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Q ('q')
#define KEY_P ('p')

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
	Health = 10;
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
	//srand((unsigned)time(NULL));	// Seed for rand

	// Map address
	mp = m;				// Pass through the address of map

	/*for (int i = 1; i <= m->getRows(); i++) {
		for (int j = 1; j <= m->getCols(); j++) {				// κατι τετοιο ελεγα εγω σε φαση να βγουν αυτα στο πρωτο μισο
			LocationX = (m->getRows() / 2) - 1;					// και τα vampire στο αλλο μισο
			LocationY = (m->getCols() / 2) - j;					// ειναι σε πολυ προϊμο σταδιο η σκεψη αλλα ναι
			m->InsertAt(LocationX, LocationY, 'W');
		}
	}*/
	//}
	// Place the wereolf at a random spot on the matrix
	LocationX = rand() % m->getRows();		// Range: [0,Rows]		//επισης μπορουμε να κανουμε ενα if εδω και να πουμε 
	LocationY = rand() % m->getCols();		// Range: [0,Cols]		// οτι αν εκει που παει να το τοποθετησει δεν ειναι *
	m->InsertAt(LocationX, LocationY, 'W');							// τοτε ξανα κανε rand μεχρι να πεσει σε κενο κελι

};

void Werewolves::WerewolfMove(void)
{
	//srand((unsigned)time(NULL));	// Seed for rand

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
	//srand((unsigned)time(NULL));	// Seed for rand

	// Map address
	mp = m;				// Pass through the address of map

	// Place the wereolf at a random spot on the matrix
	LocationX = rand() % m->getRows();		// Range: [0,Rows]
	LocationY = rand() % m->getCols();		// Range: [0,Cols]

	/*LocationX = 9;
	LocationY = 9;*/

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

	mp->PrintMap();
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

	mp->PrintMap();
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

	mp->PrintMap();
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

	mp->PrintMap();
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

	// Reset counters
	VampireCount = WerewolfCount = DaytimeCounter = 0;
	isDaytime = true;	// Daytime at start of game

	while (true) {
		if (DaytimeCounter % 5 == 0) {
			isDaytime = !isDaytime;
			cout << "Daytime has changed";
		}
	}
}

char Avatar::Move(void)
{	

	char key = getch();
	int value = key;

		switch (getch())
		{
		case(KEY_UP):
			MoveUp('A');
			DaytimeCounter++;
			break;

		case(KEY_DOWN):
			MoveDown('A');
			DaytimeCounter++;
			break;

		case(KEY_LEFT):
			MoveLeft('A');
			DaytimeCounter++;
			break;

		case(KEY_RIGHT):
			MoveRight('A');
			DaytimeCounter++;
			break;

		case(KEY_P):
			// PAUSE
			PauseGame(VampireCount, WerewolfCount);
			break;

		default:
			return 'q';
		}
}

void Avatar::PauseGame(int VampireCount, int WerewolfCount){
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