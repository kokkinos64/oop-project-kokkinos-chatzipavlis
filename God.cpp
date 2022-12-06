#include <iostream>

using namespace std;

class God {
    private:
        int Health;
        int Meds;
        const int Attack;
        const int Defense;

    public:
        int getHealth(void)
        {
            return Health;
        }

        int getAttack(void)
        {
            return Attack;
        }

        int getDefense(void)
        {
            return Defense;
        }
};

// Global counters for the members  of each team, initialized to 0.
int WerewolfCount = 0, VampireCount = 0;