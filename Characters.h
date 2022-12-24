#pragma once
#include "Map2.h"

class Avatar;

class God
{
protected:
    inline static int Health = 10;
    int Meds;
    /*const*/ int Attack;
    /*const*/ int Defense;

    int LocationX, LocationY;   // Its position on the map
    Map *mp;                     // Pointer to map

public:
    God(void);  // Constructor

    // Getters
    int getHealth(void);
    int getMeds(void);
    int getAttack(void);
    int getDefense(void);
    int getX(void);
    int getY(void);

    // Adjustment functions
    void HealthDecreaseBy(int);
    void HealthIncrease(void);
    void MedsDecrease(void);

    // Move commands (for everyone)
    void MoveUp(char c);
    void MoveDown(char c);
    void MoveLeft(char c);
    void MoveRight(char c);

};

class Vampires : public God
{
public:
    Vampires(Map*);
    static void HealthRestore(void);
    void VampireMove(void);
    void MoveUpperLeft(void);       // Vampires only
    void MoveUpperRight(void);      // Vampires only
    void MoveLowerLeft(void);       // Vampires only
    void MoveLowerRight(void);      // Vampires only
};

class Werewolves : public God
{
public:
    Werewolves(Map*);
    static void HealthRestore(void);
    void WerewolfMove(void);
};

class Avatar : public God
{
private:
    char Team_Selection;
    inline static int MagicPotCount = 1;    // Magic potion counter is initialized to 1, at the start of every game

public:
    Avatar(char, Map*);   // Constructor
    void Move(void);
    void PauseGame(int, int);
    void PrintCurrentDayTime(void);
    void PrintCurrentTeam(void);
    void UseMagicPot(void);
    static void IncreaseMagicPotCount(void);

    // Variables for the turn-based game
    
    int VampireCount, WerewolfCount, DaytimeCounter;
    bool isDaytime;
};
