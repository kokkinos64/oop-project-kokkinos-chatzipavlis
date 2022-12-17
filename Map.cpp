#include <iostream>
#include <cstdlib>

#include "Characters.h"
#include "Map.h"
#include "Matrix.h"

using namespace std;

bool Map::getNighttime(void)
{
	return isNight;
}

void Map::setNight(bool dn)
{
	isNight = dn;

	cout << "Daytime changed.\n";
}
//
//void Map::PlaceMagicPot(Matrix& m, int MaxX, int MaxY)
//{
//
//	int MagicPotX =  (int)rand() % MaxX + 1;	// Range: [0,MaxX]
//	int MagicPotY = (int)rand() % MaxY + 1;	// Range: [0, MaxY]
//
//	m.MatrixInsertAt(MagicPotX, MagicPotY, '&');
//}