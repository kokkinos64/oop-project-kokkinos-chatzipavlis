#pragma once

class God
{
private:
    int Health = 10;
    int Meds;
    /*const*/ int Attack;
    /*const*/ int Defense;

    int LocationX, LocationY;   // Its position on the map

public:
    int getHealth(void);
    int getAttack(void);
    int getDefense(void);
    int getX(void);
    int getY(void);
    God(void);  // Constructor

};

class Vampires : public God
{

};

class Werewolves : public God
{

};

class Avatar : public God
{
private:
    int MagicPot = 1; // Magic pot initialize to 1 at the start of the game
    char Team_Selection;

public:
    Avatar(char);   // Constructor
    char Move(void);
};
