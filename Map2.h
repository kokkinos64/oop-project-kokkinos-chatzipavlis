#pragma once
#include "Characters.h"

class Map
{
private:
	int Rows, Cols;
	char** Matrix;
	bool isNight;
	bool isMagicPotPlaced;

public:
	Map(int, int);
	bool InsertAt(int, int, char);
	bool InsertAt(int, int, char, Avatar&);
	void RemoveFrom(int, int);
	void PrintMap(void);
	int getRows(void);
	int getCols(void);
	~Map(void);
};