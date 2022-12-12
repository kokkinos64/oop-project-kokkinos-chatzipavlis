#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    // Output prompt
    cout << "Press any key to continue..." << endl;

    // Set terminal to raw mode
    system("stty raw");

    // Wait for single character
    char input = getchar();

    // Echo input:
    cout << "--" << input << "--";

    if (input == 'A')
    {
        cout << "UP";
    }

    // Reset terminal to normal "cooked" mode
    system("stty cooked");

    // And we're out of here
    return 0;
}