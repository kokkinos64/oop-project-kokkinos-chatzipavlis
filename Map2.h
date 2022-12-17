#pragma once

class Map
{
private:
	int Rows, Cols;
	char** Matrix;
	bool isNight;
	bool isMagicPotPlaced;

public:
	Map(int, int);
	void InsertAt(int, int, char);
	void PrintMap(void);
	~Map(void);
};