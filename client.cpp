// This is the client code to test the game

#include <iostream>
#include "God.h"
#include "Werewolf.h"
#include "Vampire.h"
#include "Matrix.h"

using namespace std;

int main(void)
{
    // VARIABLES
    int x, y;
    char team;

    // INPUT: MAP DIMENTIONS
    cout << "Enter the map dimentions: ";
    cin >> x >> y;
    Matrix Map(x,y);    // Create the matrix
    

    // INPUT: TEAM SELECTION
    cout << "Select a side (w,v): ";
    cin >> team;

    while (team != 'w' || team != 'v')
    {
        cout << "Invalid input. Usage: w for Werewolves, v for Vampires.\n";
        cin >> team;
    }






    return 0;
}

