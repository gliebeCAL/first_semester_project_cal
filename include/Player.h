#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Item.h";

class Player
{
    public:
        Player(int xSize,int ySize);
        void Spawn(int spawnX,int spawnY);
        //Should just be X's and Y's

        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        //These move it.
        void GenerateItemSprite(Item equipment,int xpos,int ypos,int itemnum);
        //Generates the item's sprite.

        int Attack(int eHealth);

        void Equip(Item equipment);
        //Make an item class, so that I can make an inventory array.

        sf::Sprite sprite;
        int posX,posY;

        int maxHealth,currHealth;
        //I'll probably need more things, like stats and inventory. But for now, this'll do.
        Item playerEquipment[9];
        sf::Sprite gearSprite[8];
    protected:
    private:
        sf::Texture texture;
        int attackpwr;
        int damageReduction;

        bool weaponEquipped = false;
        bool shieldEquipped = false;
        bool chestplateEquipped = false;
        bool gauntletEquipped = false;
        bool greavesEquipped = false;
        bool bootsEquipped = false;
        bool helmetEquipped = false;
        bool necklaceEquipped = false;
        bool ringEquipped = false;
};

#endif // PLAYER_H
