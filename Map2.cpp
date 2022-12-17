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
	isNight = false;

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
	for (i = 0; i < rand() % (Rows * Cols) / 10; i++)
	{
		InsertAt(rand() % Rows, rand() % Cols, '~');
	}

	// Place trees
	for (i = 0; i < rand() % (Rows * Cols) / 10; i++)
	{
		InsertAt(rand() % Rows, rand() % Cols, '#');
	}

}

void Map::InsertAt(int i, int j, char c)
{
	if (Matrix[i][j] == '*')    // If the selected spot on the matrix is just ground
	{
		Matrix[i][j] = c;       // Insert the given character there
	}
}

void Map::RemoveFrom(int i, int j)
{
	if (Matrix[i][j] != '*')    // If the selected spot on the matrix is NOT ground
	{
		Matrix[i][j] = '*';		// Replace it with ground
	}
}


void Map::PrintMap(void)
{

	int i, j;

	system("cls");	// Reset terminal

	cout << "Tip: You can press (p) to pause the game at any time.\n\n";

	for (i = 0; i < Rows; i++)
	{
		cout << "matrix[" << i << "]: "; // Print the number of the current row

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
			case('w'):
				cout << "\033[0;35m";	// Purple
				break;
			case('v'):
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