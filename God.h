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