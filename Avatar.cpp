#include <iostream>
#include "God.h"
#include "Avatar.h"

using namespace std;

Avatar::Avatar(char t) : Team_Selection(t)
{
    // Team_Selection = t;
    cout << "Avatar created.\n";
}