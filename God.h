class God
{
    private:
        int Health = 10;
        int Meds;
        /*const*/ int Attack;
        /*const*/ int Defense;

    public:
        int getHealth(void);
        int getAttack(void);
        int getDefense(void);
        God(void);
};