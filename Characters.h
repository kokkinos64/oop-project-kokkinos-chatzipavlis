#pragma once
#include "Map2.h"

class Avatar;

class God
{
protected:
    int Health = 10;
    int Meds;
    /*const*/ int Attack;
    /*const*/ int Defense;

    int LocationX, LocationY;   // Its position on the map
    Map *mp;                     // Pointer to map

public:
    God(void);  // Constructor

    // Getters
    int getHealth(void);
    int getAttack(void);
    int getDefense(void);
    int getX(void);
    int getY(void);

    // Move commands (for everyone)
    void MoveUp(void);
    void MoveDown(void);
    void MoveLeft(void);
    void MoveRight(void);

};

class Vampires : public God
{
public:
    void VampireMove(void);

    void MoveUpperLeft(void);       // Vampires only
    void MoveUpperRight(void);      // Vampires only
    void MoveLowerLeft(void);       // Vampires only
    void MoveLowerRight(void);      // Vampires only
};

class Werewolves : public God
{
public:
    void WerewolfMove(void);
};

class Avatar : public God
{
private:
    int MagicPotCount; 
    char Team_Selection;

public:
    Avatar(char, Map*);   // Constructor
    char Move(void);
    void PauseGame(void);
};
