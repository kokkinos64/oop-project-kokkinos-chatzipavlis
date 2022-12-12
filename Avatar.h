#include "God.h"

class Avatar : public God
{
private:
    int MagicPot = 1; // Magic pot initialize to 1 at the start of the game
    char Team_Selection;

public:
    Avatar(char);   // Constructor
};