#include <iostream>
// #include <conio.h>

using namespace std;

int main(void)
{
    char ch = 1;

    while(ch != 0)
    {
        ch = getchar();
        cout << ch << endl;
        
        if (ch == '^[[A')
        {
            cout << "UP\n";
        }

    }

    return 0;
}