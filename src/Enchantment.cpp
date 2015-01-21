#include "Enchantment.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>

Enchantment::Enchantment()
{
    //ctor
}

int Enchantment::GenerateEnchantments(bool offensive,bool defensive, int power)
{
    if (offensive == true and defensive == true)
    {
        srand(time(NULL));

        rollOffDef = rand()%2;

        if (rollOffDef == 0)
        {
            rollEnType = rand()%9;
            OffensiveEnchantments(rollEnType, power);
        }
        else
        {
            rollEnType = rand()%2;
            DefensiveEnchantments(rollEnType, power);
        }
    }
    else if (offensive == true)
    {
        rollEnType = rand()%9;
        OffensiveEnchantments(rollEnType, power);
    }
    else if (defensive == true)
    {
        rollEnType = rand()%2;
        DefensiveEnchantments(rollEnType, power);
    }
}

void Enchantment::OffensiveEnchantments(int enNum,int power)
{
    if (enNum == 0)
    {
        //Flaming
        offeffect = 1;
        atkpwr = power;
    }
    else if (enNum == 1)
    {
        //Icy
        offeffect = 1;
        atkpwr = power;

    }
    else if (enNum == 2)
    {
        //Rocky
        offeffect = 1;
        atkpwr = power;


    }
    else if (enNum == 3)
    {
        //Metallic
        offeffect = 1;
        atkpwr = power;

    }
    else if (enNum == 4)
    {
        //Electric
        offeffect = 1;
        atkpwr = power;

    }
    else if (enNum == 5)
    {
        //Poison
        offeffect = 1;
        atkpwr = power;

    }
    else if (enNum == 6)
    {
        //Vampire-y
        offeffect = 2;

    }
    /*else if (enNum == 7)
    {
        //Warping?
        offeffect = 3;

    }*/
    else if (enNum == 7)
    {
        //Giant
        offeffect = 1;
        atkpwr = power;

    }
    else if (enNum == 8)
    {
        //Enchantment Enhancing
        offeffect = 3;

    }
}

void Enchantment::DefensiveEnchantments(int enNum, int power)
{
    if (enNum == 0)
    {
        //Health
        defpwr = 1;
        defpwr = power;
        defeffect = 1;

    }
    /*else if (enNum == 1)
    {
        //Block Chance?
        defeffect = 2;

    }*/
    /*else if (enNum == 2)
    {
        //Dodge?
        defeffect = 3;

    }*/
    /*else if (enNum == 3)
    {
        //Damage Reduction
        defpwr = 1;
        defpwr = power;
        defeffect = 1;

    }*/
    /*else if (enNum == 4)
    {
        //Reflect Damage?
        defeffect = 4;

    }*/
    else if (enNum == 1)
    {
        //Bolsters enchantments
        defeffect = 2;

    }

}
