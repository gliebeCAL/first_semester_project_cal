#include "Item.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "Enchantment.h"

Item::Item()
{
    //ctor
}

void Item::Generate(int difficulty)
{
    Enchantment decideEnchant;

    srand(time(NULL));

    texture.loadFromFile("sprites/player_sprites/nosprite.png");

    itemType = rand() % 7;

    if (itemType == 0)
    {
        //Weapons
        basedmg = rand() % (difficulty*2) + 1;
        basedef = rand() % (difficulty);

        itemSprite = rand()%7;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true,true,75);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }
                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }
    }
    else if (itemType == 1)
    {
        //Armor (Chest Plate)
        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty*2) + 1;

        itemSprite = rand()%3;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(false, true,100);

                if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }
    }
    else if (itemType == 2)
    {
        //Armor (Greaves)
        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty*2) + 1;

        itemSprite = rand()%4;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, true,50);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }
                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }

    }
    else if (itemType == 3)
    {
        //Armor (Boots)
        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty*2) + 1;

        itemSprite = rand()%4;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, true,50);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }
                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }

    }
    else if (itemType == 4)
    {
        //Armor (Gauntlets)
        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty*2) + 1;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, true,50);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }
                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }

    }
    else if (itemType == 5)
    {
        //Armor (Rings)
        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty);

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, true,100);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }

                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }
    }
    else if (itemType == 6)
    {
        //Armor (Necklace)
        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty);

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, true,100);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }

                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }
    }
    else if (itemType == 7)
    {
        //Armor (Shields)
        basedmg = rand() % (difficulty+5);
        basedef = rand() % (difficulty*2)+3;

        itemSprite = rand()%5;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, true,75);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
                else if (enchantEffects[e].offeffect == 2)
                {
                    vampirism += 1;
                }
                else if (enchantEffects[e].offeffect == 3)
                {
                    bolster += 1;
                }

                else if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }

    }
    else if (itemType == 8)
    {
        //Helmets
        itemSprite = rand()%3;

        basedmg = rand() % (difficulty);
        basedef = rand() % (difficulty*2)+1;

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(false, true,100);

                if (enchantEffects[e].defeffect == 1)
                {
                    bonusdef += enchantEffects[e].defpwr;
                }
                else if (enchantEffects[e].defeffect == 2)
                {
                    bolster += 1;
                }
            }
        }
    }
    /*else if (itemType == 9)
    {
        //Wands

        for (int s;s<spellRoll;s++)
        {
            spellEffect = 1;
        }

        basedmg = rand() % (difficulty);

        if (enchant > 0)
        {
            for(int e;e=0;e++)
            {
                enchantEffects[e].GenerateEnchantments(true, false,100);
                enchantPower[e] = decideEnchant.enPower;

                if (enchantEffects[e].offeffect == 1)
                {
                    bonusdmg += enchantEffects[e].atkpwr;
                }
            }
        }
    }*/

    //GenerateSprite();
    bonusdmg *= bolster;
    vampirism *= bolster;

    totaldmg = basedmg + bonusdmg;
    totaldef = basedef + bonusdef;
}

void Item::GenerateSprite()
{
    if (itemType == 0)
    {
        if (itemSprite == 0)
        {
            texture.loadFromFile("sprites/player_sprites/weapon1.png");
        }
        else if (itemSprite == 1)
        {
            texture.loadFromFile("sprites/player_sprites/weapon2.png");
        }
        else if (itemSprite == 2)
        {
            texture.loadFromFile("sprites/player_sprites/weapon3.png");
        }
        else if (itemSprite == 3)
        {
            texture.loadFromFile("sprites/player_sprites/weapon4.png");
        }
        else if (itemSprite == 4)
        {
            texture.loadFromFile("sprites/player_sprites/weapon5.png");
        }
        else if (itemSprite == 5)
        {
            texture.loadFromFile("sprites/player_sprites/weapon6.png");
        }
        else if (itemSprite == 6)
        {
            texture.loadFromFile("sprites/player_sprites/weapon7.png");
        }

    }
    else if (itemType == 1)
    {
        if (itemSprite == 0)
        {
            texture.loadFromFile("sprites/player_sprites/chestplate1.png");

        }
        else if (itemSprite == 1)
        {
            texture.loadFromFile("sprites/player_sprites/chestplate1.png");

        }
        else if (itemSprite == 2)
        {
            texture.loadFromFile("sprites/player_sprites/chestplate1.png");
        }

    }
    else if (itemType == 2)
    {
        if (itemSprite == 0)
        {
            texture.loadFromFile("sprites/player_sprites/greaves1.png");
        }
        else if (itemSprite == 1)
        {
            texture.loadFromFile("sprites/player_sprites/greaves2.png");
        }
        else if (itemSprite == 2)
        {
            texture.loadFromFile("sprites/player_sprites/greaves3.png");
        }
        else if (itemSprite == 3)
        {
            texture.loadFromFile("sprites/player_sprites/greaves4.png");
        }

    }
    else if (itemType == 3)
    {
        if (itemSprite == 0)
        {
            texture.loadFromFile("sprites/player_sprites/boots1.png");
        }
        else if (itemSprite == 1)
        {
            texture.loadFromFile("sprites/player_sprites/boots2.png");
        }
        else if (itemSprite == 2)
        {
            texture.loadFromFile("sprites/player_sprites/boots3.png");
        }
        else if (itemSprite == 3)
        {
            texture.loadFromFile("sprites/player_sprites/boots4.png");
        }

    }
    else if (itemType == 4 or itemType == 5 or itemType == 6)
    {
        texture.loadFromFile("sprites/player_sprites/nosprite.png");
    }
    else if (itemType == 7)
    {
        if (itemSprite == 0)
        {
            texture.loadFromFile("sprites/player_sprites/shield1.png");
        }
        else if (itemSprite == 1)
        {
            texture.loadFromFile("sprites/player_sprites/shield2.png");
        }
        else if (itemSprite == 2)
        {
            texture.loadFromFile("sprites/player_sprites/shield3.png");
        }
        else if (itemSprite == 3)
        {
            texture.loadFromFile("sprites/player_sprites/shield4.png");
        }
        else if (itemSprite == 4)
        {
            texture.loadFromFile("sprites/player_sprites/shield5.png");
        }

    }
    else if (itemType == 8)
    {
        if (itemSprite == 0)
        {
            texture.loadFromFile("sprites/player_sprites/helmet1.png");
        }
        else if (itemSprite == 1)
        {
            texture.loadFromFile("sprites/player_sprites/helmet2.png");
        }
        else if (itemSprite == 2)
        {
            texture.loadFromFile("sprites/player_sprites/helmet3.png");
        }
    }

    sprite.setTexture(texture);
}
