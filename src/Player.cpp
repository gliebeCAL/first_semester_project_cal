#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(int xSize,int ySize)
{
    texture.loadFromFile("sprites/player_sprites/player.png");
    sprite.setTexture(texture,false);
    //Static texture, so false.
    //Needs to be adjusted so it points to an actual sprite.

    //These two are default-in-case-spawn-doesn't-work.
    posX = 0;
    posY = 0;

    //Sets stats
    attackpwr = 5;
    maxHealth = 20;
    currHealth = maxHealth;
    damageReduction = 0;
}

void Player::Spawn(int spawnX,int spawnY)
{
    sprite.setPosition(sf::Vector2f(spawnX*50,spawnY*50));
    posX = spawnX;
    posY = spawnY;
    //These are what is drawn I think, so these get the actual pixel
    //value.
}

void Player::MoveUp()
{
    sprite.move(0,-50);

    for (int e=0;e<8;e++)
    {
        playerEquipment[e].sprite.move(0,-50);
    }

    posY -= 1;
}

void Player::MoveDown()
{
    sprite.move(0,50);

    for (int e=0;e<8;e++)
    {
        playerEquipment[e].sprite.move(0,50);
    }

    posY += 1;
}

void Player::MoveLeft()
{
    sprite.move(-50,0);

    for (int e=0;e<8;e++)
    {
        playerEquipment[e].sprite.move(-50,0);
    }

    posX -= 1;
}

void Player::MoveRight()
{
    sprite.move(50,0);

    for (int e=0;e<8;e++)
    {
        playerEquipment[e].sprite.move(50,0);
    }

    posX += 1;
}

int Player::Attack(int eHealth)
{
    //Should probably make Current/Max Health
    int newHealth;
    newHealth = eHealth - attackpwr;

    for (int e=0;e<8;e++)
    {
        if (currHealth+playerEquipment[e].vampirism < maxHealth)
        {
            currHealth += playerEquipment[e].vampirism;
        }
        else
        {
            currHealth = maxHealth;
        }
    }

    return newHealth;

}

void Player::Equip(Item equipment)
{
    //It should unequip your stuff, too.
    attackpwr += equipment.totaldmg;
    maxHealth += equipment.totaldef;

    GenerateItemSprite(equipment,posX,posY,equipment.itemType);

    if (currHealth > maxHealth)
    {
        currHealth = maxHealth;
    }

    if (equipment.itemType == 0)
    {
        if (weaponEquipped = false)
        {
            weaponEquipped = true;
            std::cout << "Weapon Equipped." << std::endl;
            playerEquipment[0] = equipment;
            std::cout << playerEquipment[0].totaldmg << std::endl << playerEquipment[0].totaldef << std::endl;
            gearSprite[0].setTexture(equipment.texture);
            gearSprite[0].setPosition(posX*50,posY*50);
            //playerEquipment[0].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[0].totaldmg;
            maxHealth -= playerEquipment[0].totaldef;

            std::cout << "New Weapon Equipped." << std::endl;
            playerEquipment[0] = equipment;
            std::cout << playerEquipment[0].totaldmg << std::endl << playerEquipment[0].totaldef << std::endl;
            gearSprite[0].setTexture(equipment.texture);
            gearSprite[0].setPosition(posX*50,posY*50);
            //playerEquipment[0].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 1)
    {
        if (chestplateEquipped == false)
        {
            chestplateEquipped = true;
            std::cout << "Chestplate Equipped." << std::endl;

            playerEquipment[1] = equipment;
            std::cout << playerEquipment[1].totaldmg << std::endl << playerEquipment[1].totaldef << std::endl;
            gearSprite[1].setTexture(equipment.texture);
            gearSprite[1].setPosition(posX*50,posY*50);
            //playerEquipment[1].sprite.setPosition(0,0);
            //posX*50,posY*50
        }
        else
        {
            attackpwr -= playerEquipment[1].totaldmg;
            maxHealth -= playerEquipment[1].totaldef;

            std::cout << "New Chestplate Equipped." << std::endl;
            playerEquipment[1] = equipment;
            std::cout << playerEquipment[1].totaldmg << std::endl << playerEquipment[1].totaldef << std::endl;
            gearSprite[1].setTexture(equipment.texture);
            gearSprite[1].setPosition(posX*50,posY*50);
            //playerEquipment[1].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 2)
    {
        if (greavesEquipped == false)
        {
            greavesEquipped = true;
            std::cout << "Greaves Equipped." << std::endl;
            playerEquipment[2] = equipment;
            std::cout << playerEquipment[2].totaldmg << std::endl << playerEquipment[2].totaldef << std::endl;
            gearSprite[2].setTexture(equipment.texture);
            gearSprite[2].setPosition(posX*50,posY*50);
            //playerEquipment[2].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[2].totaldmg;
            maxHealth -= playerEquipment[2].totaldef;

            std::cout << "New Greaves Equipped." << std::endl;
            playerEquipment[2] = equipment;
            std::cout << playerEquipment[2].totaldmg << std::endl << playerEquipment[2].totaldef << std::endl;
            gearSprite[2].setTexture(equipment.texture);
            gearSprite[2].setPosition(posX*50,posY*50);
            //playerEquipment[2].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 3)
    {
        if (chestplateEquipped == false)
        {
            bootsEquipped = true;
            std::cout << "Boots Equipped." << std::endl;
            playerEquipment[3] = equipment;
            std::cout << playerEquipment[3].totaldmg << std::endl << playerEquipment[3].totaldef << std::endl;
            gearSprite[3].setTexture(equipment.texture);
            gearSprite[3].setPosition(posX*50,posY*50);
            //playerEquipment[3].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[3].totaldmg;
            maxHealth -= playerEquipment[3].totaldef;

            std::cout << "New Boots Equipped." << std::endl;
            playerEquipment[3] = equipment;
            std::cout << playerEquipment[3].totaldmg << std::endl << playerEquipment[3].totaldef << std::endl;
            gearSprite[3].setTexture(equipment.texture);
            gearSprite[3].setPosition(posX*50,posY*50);
            //playerEquipment[3].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 4)
    {
        if (gauntletEquipped == false)
        {
            gauntletEquipped = true;
            std::cout << "Gauntlet Equipped." << std::endl;
            playerEquipment[4] = equipment;
            std::cout << playerEquipment[4].totaldmg << std::endl << playerEquipment[4].totaldef << std::endl;
            gearSprite[4].setTexture(equipment.texture);
            gearSprite[4].setPosition(posX*50,posY*50);
            //playerEquipment[4].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[4].totaldmg;
            maxHealth -= playerEquipment[4].totaldef;

            std::cout << "New Gauntlet Equipped." << std::endl;
            playerEquipment[4] = equipment;
            std::cout << playerEquipment[4].totaldmg << std::endl << playerEquipment[4].totaldef << std::endl;
            gearSprite[4].setTexture(equipment.texture);
            gearSprite[4].setPosition(posX*50,posY*50);
            //playerEquipment[4].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 5)
    {
        if (ringEquipped == false)
        {
            ringEquipped = true;
            std::cout << "Ring Equipped." << std::endl;
            playerEquipment[5] = equipment;
            std::cout << playerEquipment[5].totaldmg << std::endl << playerEquipment[5].totaldef << std::endl;
            gearSprite[5].setTexture(equipment.texture);
            gearSprite[5].setPosition(posX*50,posY*50);
            //playerEquipment[5].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[5].totaldmg;
            maxHealth -= playerEquipment[5].totaldef;

            std::cout << "New Ring Equipped." << std::endl;
            playerEquipment[5] = equipment;
            std::cout << playerEquipment[5].totaldmg << std::endl << playerEquipment[5].totaldef << std::endl;
            gearSprite[5].setTexture(equipment.texture);
            gearSprite[5].setPosition(posX*50,posY*50);
            //playerEquipment[5].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 6)
    {
        if (necklaceEquipped == false)
        {
            necklaceEquipped = true;
            std::cout << "Necklace Equipped." << std::endl;
            playerEquipment[8] = equipment;
            std::cout << playerEquipment[8].totaldmg << std::endl << playerEquipment[8].totaldef << std::endl;
            gearSprite[8].setTexture(equipment.texture);
            gearSprite[8].setPosition(posX*50,posY*50);
            //playerEquipment[6].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[8].totaldmg;
            maxHealth -= playerEquipment[8].totaldef;

            std::cout << "New Necklace Equipped." << std::endl;
            playerEquipment[8] = equipment;
            std::cout << playerEquipment[8].totaldmg << std::endl << playerEquipment[8].totaldef << std::endl;
            gearSprite[8].setTexture(equipment.texture);
            gearSprite[8].setPosition(posX*50,posY*50);
            //playerEquipment[6].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 7)
    {
        if (shieldEquipped == false)
        {
            shieldEquipped = true;
            std::cout << "Shield Equipped." << std::endl;
            playerEquipment[7] = equipment;
            std::cout << playerEquipment[7].totaldmg << std::endl << playerEquipment[7].totaldef << std::endl;
            gearSprite[7].setTexture(equipment.texture);
            gearSprite[7].setPosition(posX*50,posY*50);
            //playerEquipment[7].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[7].totaldmg;
            maxHealth -= playerEquipment[7].totaldef;

            std::cout << "New Shield Equipped." << std::endl;
            playerEquipment[7] = equipment;
            std::cout << playerEquipment[7].totaldmg << std::endl << playerEquipment[7].totaldef << std::endl;
            gearSprite[7].setTexture(equipment.texture);
            gearSprite[7].setPosition(posX*50,posY*50);
            //playerEquipment[7].sprite.setPosition(0,0);
        }
    }
    else if (equipment.itemType == 8)
    {
        if (helmetEquipped == false)
        {
            helmetEquipped = true;
            std::cout << "New Helmet Equipped." << std::endl;
            playerEquipment[6] = equipment;
            std::cout << playerEquipment[6].totaldmg << std::endl << playerEquipment[6].totaldef << std::endl;
            gearSprite[6].setTexture(equipment.texture);
            gearSprite[6].setPosition(posX*50,posY*50);
            //playerEquipment[8].sprite.setPosition(0,0);
        }
        else
        {
            attackpwr -= playerEquipment[6].totaldmg;
            maxHealth -= playerEquipment[6].totaldef;

            std::cout << "New Helmet Equipped." << std::endl;
            playerEquipment[6] = equipment;
            std::cout << playerEquipment[6].totaldmg << std::endl << playerEquipment[6].totaldef << std::endl;
            gearSprite[6].setTexture(equipment.texture);
            gearSprite[6].setPosition(posX*50,posY*50);
            //Value swapped with necklace because necklace doesn't have a sprite.
            //playerEquipment[8].sprite.setPosition(0,0);
        }
    }
}

void Player::GenerateItemSprite(Item equipment,int xpos, int ypos,int itemnum)
{
    if (equipment.itemType == 0)
    {
        if (equipment.itemSprite == 0)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon1.png");
            std::cout << "Weapon1 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 1)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon2.png");
            std::cout << "Weapon2 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 2)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon3.png");
            std::cout << "Weapon3 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 3)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon4.png");
            std::cout << "Weapon4 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 4)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon5.png");
            std::cout << "Weapon5 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 5)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon6.png");
            std::cout << "Weapon6 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 6)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/weapon7.png");
            std::cout << "Weapon7 Loaded" << std::endl;
        }

    }
    else if (equipment.itemType == 1)
    {
        if (equipment.itemSprite == 0)
        {
           equipment.texture.loadFromFile("sprites/player_sprites/chestplate1.png");
            std::cout << "Chestplate1 Loaded" << std::endl;

        }
        else if (equipment.itemSprite == 1)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/chestplate1.png");
            std::cout << "Chestplate2 Loaded" << std::endl;

        }
        else if (equipment.itemSprite == 2)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/chestplate1.png");
            std::cout << "Chestplate3 Loaded" << std::endl;
        }

    }
    else if (equipment.itemType == 2)
    {
        if (equipment.itemSprite == 0)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/greaves1.png");
            std::cout << "Greaves1 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 1)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/greaves2.png");
            std::cout << "Greaves2 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 2)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/greaves3.png");
            std::cout << "Greaves3 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 3)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/greaves4.png");
            std::cout << "Greaves4 Loaded" << std::endl;
        }

    }
    else if (equipment.itemType == 3)
    {
        if (equipment.itemSprite == 0)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/boots1.png");
            std::cout << "Boots1 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 1)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/boots2.png");
            std::cout << "Boots2 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 2)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/boots3.png");
            std::cout << "Boots3 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 3)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/boots4.png");
            std::cout << "Boots4 Loaded" << std::endl;
        }

    }
    else if (equipment.itemType == 4 or equipment.itemType == 5 or equipment.itemType == 6)
    {
        equipment.texture.loadFromFile("sprites/player_sprites/nosprite.png");
        std::cout << "Invisible Sprite Loaded" << std::endl;
    }
    else if (equipment.itemType == 7)
    {
        if (equipment.itemSprite == 0)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/shield1.png");
            std::cout << "Shield1 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 1)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/shield2.png");
            std::cout << "Shield2 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 2)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/shield3.png");
            std::cout << "Shield3 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 3)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/shield4.png");
            std::cout << "Shield4 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 4)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/shield5.png");
            std::cout << "Shield5 Loaded" << std::endl;
        }

    }
    else if (equipment.itemType == 8)
    {
        if (equipment.itemSprite == 0)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/helmet1.png");
            std::cout << "Helmet1 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 1)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/helmet2.png");
            std::cout << "Helmet2 Loaded" << std::endl;
        }
        else if (equipment.itemSprite == 2)
        {
            equipment.texture.loadFromFile("sprites/player_sprites/helmet3.png");
            std::cout << "Helmet3 Loaded" << std::endl;
        }
    }
    equipment.sprite.setTexture(equipment.texture);
    std::cout << "Texture attached" << std::endl;
    equipment.sprite.setPosition(xpos*50,ypos*50);
    std::cout << "XPos: " << xpos << " YPos: " << ypos << std::endl;

    /*if (itemnum == 8)
    {
        gearSprite[6].setTexture(equipment.texture);
        gearSprite[6].setPosition(xpos*50,ypos*50);
    }
    else if (itemnum == 6)
    {
        gearSprite[8].setTexture(equipment.texture);
        gearSprite[8].setPosition(xpos*50,ypos*50);
    }
    else
    {
        gearSprite[itemnum].setTexture(equipment.texture);
        gearSprite[itemnum].setPosition(xpos*50,ypos*50);
    }*/
}
