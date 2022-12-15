// This is the client code to test the game

#include <iostream>
#include <cstdlib>
#include "Characters.h"
#include "Map.h"
#include "Matrix.h"

using namespace std;

int main(void)
{
    srand((unsigned)time(NULL));    // Used by rand later

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

    // Check for invalid input
    while ((team != 'w') && (team != 'v'))
    {
        cout << "Invalid input. Usage: w for Werewolves, v for Vampires.\n";
        cin >> team;
    }
    
    // In case of valid input,
    cout << "Your team: ";

    switch (team)
    {
    case 'w':
        cout << "Werewolves";
        break;
    case 'v':
        cout << "Vampires";
        break;
    }

    cout << endl;


    // Objects
    Avatar a(team); // Create the avatar, pass thru the team selection
    
    Map.MatrixGroundFill();

    Map.MatrixPrint();

    Map.MatrixInsertAt(5, 5, 'x');

    Map.MatrixPrint();

    Map.MatrixDelete();  // Delete the matrix
    return 0;
}

