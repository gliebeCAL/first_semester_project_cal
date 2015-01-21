#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "Enchantment.h"
#include <SFML/Graphics.hpp>

class Item
{
    public:
        Item();
        void Generate(int difficulty);

        void NameItem(int difficulty);
        void GenerateSprite();
        void GenerateEffects();
        //Shouldn't need to specify if it hurts you or not
        void GenerateSpells(bool offensive);
        //So damage (Fireball, etc) or buffs (Heal, more power, etc)
        //Should I make a class for enchantments and spells?


        std::string namePrefix1;
        std::string namePrefix2;
        std::string namePrefix3;
        std::string namePrefix4;
        std::string namePrefix5;
        std::string namePrefix6;
        std::string namePrefix7;
        //Stuff like Flaming,Frozen, Giant, Powerful, etc
        //Over 8 gets special prefixes, like Epic, Legendary, Master, Godly, etc
        std::string nameItem;
        //Sword, Axe, Spear, etc
        //Maybe some special types for bad weapons (Ex: if you should get 5-10 weapons and get a 0, call it a stick)
        std::string nameSuffix;
        //Of X

        int itemType;

        int totaldmg = 0;
        int totaldef = 0;
        //Total Stats

        int itemSprite;
        int enchant = 0;
        int enchantRoll;
        Enchantment enchantEffects[30];
        int enchantPower[30];
        int vampirism = 0;
        int bolster = 1;

        int spell = 1;
        int spellRoll;
        int spellEffect;

        sf::Sprite sprite;
        sf::Texture texture;
    protected:
    private:
        int basedmg = 0;
        int basedef = 0;
        //Base stats
        int bonusdmg = 0;
        int bonusdef = 0;
        //Bonus stats
};

#endif // ITEM_H
