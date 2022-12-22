#include "Map2.h"
#include "Characters.h"
#include <iostream>

using namespace std;

// Constructor
Map::Map(int x, int y) : Rows(x), Cols(y)
{
	Rows = x;
	Cols = y;

	int i, j, MagicPotX, MagicPotY;

	srand((unsigned)time(NULL));	// Time-based seed for rand()

	isMagicPotPlaced = false;
	// Matrix construction
	Matrix = new char* [Rows];

	// Check if allocation was unsuccessful
	if (Matrix == NULL)
	{
		cout << "Cannot allocate memory (outer matrix)" << endl;
		exit(-1);
	}

	// Create the second dimention
	for (i = 0; i < Rows; i++)
	{
		Matrix[i] = new char[Cols];

		// Check if allocation was unsuccessful
		if (Matrix[i] == NULL)
		{
			cout << "Cannot allocate memory (inner matrix)" << endl;
			exit(-1);
		}
	}

	// Fill the ground (marked as '*')
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Cols; j++)
		{
			Matrix[i][j] = '*';
		}
	}

	// Place the magic potion at a random position (represented as a '&')
	MagicPotX = rand() % Rows;	// Range: [0,Rows]
	MagicPotY = rand() % Cols;	// Range: [0, Cols]
	Matrix[MagicPotX][MagicPotY] = '&';
	isMagicPotPlaced = true;

	// Place lakes
	for (i = 0; i < rand() % ((Rows * Cols) / 10) + 1; i++)
	{
		InsertAt(rand() % Rows, rand() % Cols, '~');
	}

	// Place trees
	for (i = 0; i < rand() % ((Rows * Cols) / 10) + 1; i++)
	{
		InsertAt(rand() % Rows, rand() % Cols, '#');
	}

}

bool Map::InsertAt(int i, int j, char c)
{	
	/* Bottom and Right borders */	/* Top and Left borders */
	if ((i < Rows) && (j < Cols) && (i > -1) && (j > -1)) 	// Check if we are within matrix borders
	{	
		// FOR AVATAR ONLY
		if (c == 'A' && Matrix[i][j] == '&')	// If the Avatar steps onto the Magic Pot
		{
			Matrix[i][j] = c;					// Step onto it
			Avatar::IncreaseMagicPotCount();	// Increase the counter by calling the static member function of Avatar
			return true;
		}

		if (c == 'A' && Matrix[i][j] == '*')
		{
			Matrix[i][j] = c;	// Step onto it
			return true;
		}

		if (c == 'A' && ((Matrix[i][j] == 'W') || (Matrix[i][j] == 'V')))	// The Avatar cannot go over a W or V
		{
			return false;
		}
		
		// FOR EVERYONE
		if (Matrix[i][j] == '#' || Matrix[i][j] == '~')
		{
			return false;
		}

		// FOR WEREWOLF
		if (c == 'W' && (Matrix[i][j] == '#' || Matrix[i][j] == '~' || Matrix[i][j] == 'V' || Matrix[i][j] == 'A' || Matrix[i][j] == '&' || Matrix[i][j] == 'W'))	// Do not cross over anything
		{
			return false;
		}

		if (c == 'W' && Matrix[i][j] == '*')	// The W can go over grass
		{
			Matrix[i][j] = c;
			return true;
		}

		// FOR VAMPIRE
		if (c == 'V' && (Matrix[i][j] == '#' || Matrix[i][j] == '~' || Matrix[i][j] == 'W' || Matrix[i][j] == 'A' || Matrix[i][j] == '&' || Matrix[i][j] == 'V'))	// Do not cross over anything
		{
			return false;
		}

		if (c == 'V' && Matrix[i][j] == '*')	// The V can go over grass
		{
			Matrix[i][j] = c;
			return true;
		}

		// Obsticles
		if (c == '#' || c == '~')
		{
			Matrix[i][j] = c;
			return true;
		}

		//if (Matrix[i][j] == '*')    // If the selected spot on the matrix is just ground
		//{
		//	Matrix[i][j] = c;       // Insert the given character there
		//}
		//else if (Matrix[i][j] == '~' || Matrix[i][j] == '#' || Matrix[i][j] == 'W' || Matrix[i][j] == 'V' || Matrix[i][j] == 'A')	// Check if something else is already there
		//{
		//	return false;	// entity stalls for this move
		//}
	}
	else
	{
		return false;	// We are out of matrix borders, entity stalls for this move
	}
	
}

void Map::RemoveFrom(int i, int j)
{
	if (Matrix[i][j] != '*' && Matrix[i][j] != '#' && Matrix[i][j] != '~')	// If requested spot is not empty
	{
		Matrix[i][j] = '*';		// Make it empty
	}


	//if ((i < Rows) || (j < Cols))	// Check if we are within matrix borders
	//{
	//	if (Matrix[i][j] == '~' || Matrix[i][j] == '#' || Matrix[i][j] == 'W' || Matrix[i][j] == 'V' /*|| Matrix[i][j] == 'A'*/)	// Check if something else is already there
	//	{
	//		return;	// entity stalls for this move
	//	}
	//	else if (Matrix[i][j] == 'A')
	//	{
	//		Matrix[i][j] = '*';		// Replace it with ground
	//	}
	//	else //if (Matrix[i][j] != '*')    // If the selected spot on the matrix is NOT ground
	//	{
	//		Matrix[i][j] = '*';		// Replace it with ground
	//	}
	//}
	//else
	//{
	//	return;
	//}
}

void Map::PrintMap(void)
{

	int i, j;

	system("cls");	// Reset terminal

	cout << "Tip: You can double-press (p) to pause the game at any time.\n" << "Tip: While in-game, you can quit the game on the fly by double-pressing (q)\n\n";

	for (i = 0; i < Rows; i++)
	{
		cout << "matrix[" << i << "]:\t"; // Print the number of the current row

		for (j = 0; j < Cols; j++)
		{
			// Text coloring
			switch (Matrix[i][j])
			{
			case('#'):
				cout << "\033[0;32m";	// Green
				break;
			case('~'):
				cout << "\033[0;36m";	// Blue
				break;
			case('W'):
				cout << "\033[0;35m";	// Purple
				break;
			case('V'):
				cout << "\033[0;31m";	// Red
				break;
			case('A'):
				cout << "\033[0;34m";	// Blue
				break;
			case('&'):
				cout << "\033[0;33m";	// Yellow
				break;
			default:
				cout << "\033[0;37m";	// White
				break;
			}

			cout << " " << Matrix[i][j] << "\033[0m";	// Print out the character and reset terminal back to default colors
		}

		cout << endl;
	}
	cout << endl;
}

int Map::getRows(void)
{
	return Rows;
}

int Map::getCols(void)
{
	return Cols;
}

// Destructor
Map::~Map(void)
{
	int i;

	// Memory dislocation for the second dimention
	for (i = 0; i < Rows; i++)
	{
		delete[] Matrix[i];
	}

	// Final memory dislocation
	delete[] Matrix;
}