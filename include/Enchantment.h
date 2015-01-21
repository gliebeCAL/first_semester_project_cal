#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H


class Enchantment
{
    public:
        Enchantment();
        int GenerateEnchantments(bool offensive,bool defensive, int power);
        void OffensiveEnchantments(int enNum, int power);
        void DefensiveEnchantments(int enNum, int power);

        int enPower;
        int rollOffDef = 0;
        int rollEnType;

        int atkpwr = 0;
        int offeffect = 0;

        int defpwr = 0;
        int defeffect = 0;

        //In hindsight, this should have just been a function of the item class.
    protected:
    private:
};

#endif // ENCHANTMENT_H
