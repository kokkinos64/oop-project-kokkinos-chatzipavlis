#pragma once

class God
{
protected:
    int Health = 10;
    int Meds;
    /*const*/ int Attack;
    /*const*/ int Defense;

    int LocationX, LocationY;   // Its position on the map

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
    void VampireMove(int direction);
    int RandomNumber(void);

    void MoveUpperLeft(void);       // Vampires only
    void MoveUpperRight(void);      // Vampires only
    void MoveLowerLeft(void);       // Vampires only
    void MoveLowerRight(void);      // Vampires only
};

class Werewolves : public God
{
public:
    void WerewolfMove(int direction);
    int RandomNumber(void);
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
