#include <iostream>
#include "Map.h"

using namespace std;

bool MapObject::getNighttime(void)
{
	return isNight;
}

void MapObject::setNight(bool dn)
{
	isNight = dn;

	cout << "Daytime changed.\n";
}