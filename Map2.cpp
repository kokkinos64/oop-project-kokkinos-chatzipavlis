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
	MagicPotX = rand() % Rows + 1;	// Range: [0,Rows]
	MagicPotY = rand() % Cols + 1;	// Range: [0, Cols]
	Matrix[MagicPotX][MagicPotY] = '&';
	isMagicPotPlaced = true;
}

void Map::InsertAt(int i, int j, char c)
{
	if (Matrix[i][j] == '*')    // If the selected spot on the matrix is just ground
	{
		Matrix[i][j] = c;       // Insert the given character there
	}
}

void Map::PrintMap(void)
{

	int i, j;

	cout << "\033[2J\033[1;5H"; // Reset terminal

	for (i = 0; i < Rows; i++)
	{
		cout << "matrix[" << i << "]: "; // Print the number of the current row

		for (j = 0; j < Cols; j++)
		{
			cout << " " << Matrix[i][j];
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