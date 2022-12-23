#pragma once

class Map
{
private:
	int Rows, Cols;
	char** Matrix;
	bool isMagicPotPlaced;

public:
	Map(int, int);
	bool InsertAt(int, int, char);
	void RemoveFrom(int, int);
	void PrintMap(void);
	int getRows(void);
	int getCols(void);
	bool ScanArea(int, int, char, int&, int&);
	~Map(void);
};