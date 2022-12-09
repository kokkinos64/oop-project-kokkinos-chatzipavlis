#include <iostream>
#include "God.h"

using namespace std;

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




// Global counters for the members  of each team, initialized to 0.
int WerewolfCount = 0, VampireCount = 0;