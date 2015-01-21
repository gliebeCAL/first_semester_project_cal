#include <iostream>
#include <DunGen.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Melee_Enemy.h"

/*
Need to adjust how enemies are removed

Okay, so! List of things to do:

Change levels
    -Need to erase the sprites, then remake and replace.

Add inventory
    -Might cut to just "DO YOU WANT TO REPLACE CURRENT ITEM"

Add Equipment
    -Enchantments, at least for raw stats, are more or less implemented.
Add spells
Add chests
Add HUD elements

Make a weapon switch button.

Bug Fixing
    -Level generation doesn't work sometimes (Overflow error)
    -Player can't move to (0,0)
    -Player can move past an enemy if an enemy just died right there.
    -Not really a bug, but the character doesn't get moved to the right place when the level re-Generates.

Would LIKE to make a save file, but running low on time.
*/


int main()
{
    bool dungeonGenerated = false;
    //Used to see if the dungeon is generated yet.
    bool playerSpawned = false;
    //Used to see if the player has been spawned yet.
    bool playerMoved = false;

    int difficulty = 1;

    int melee_Enemies = 3;

    int enemyPosX;
    int enemyPosY;
    bool enemyGenerated = false;

    DunGen dungeon(difficulty+2,difficulty+2,difficulty);
    Player pChar(50,50);

    Melee_Enemy mEnemy[50];



    //Melee_Enemy mEnemy(1,0,0,1,1,1,10,10,dungeon.level);


    sf::View camera;
    camera.setSize(800,600);
    camera.setCenter(pChar.posX,pChar.posY);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Invasion of the Ratbot King");

    int levelSize = 0;



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                //This moves the character.
                //Can't move to 0,0.
                if (event.key.code == sf::Keyboard::D)
                {
                    if (dungeon.level[pChar.posX + 1][pChar.posY] > 0 and pChar.posX < dungeon.levelXCap)
                    {
                        if (dungeon.levelOccupied[pChar.posX+1][pChar.posY] == false)
                        {
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = false;
                            pChar.MoveRight();
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = true;
                            playerMoved = true;
                        }
                        else
                        {
                            for(int m=0;m<melee_Enemies;m++)
                            {
                                if (mEnemy[m].posX == pChar.posX+1 and mEnemy[m].posY == pChar.posY)
                                {
                                    mEnemy[m].health = pChar.Attack(mEnemy[m].health);
                                    playerMoved = true;
                                    std::cout << "Enemy " << m <<" Health: " << mEnemy[m].health << std::endl;
                                }
                            }
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::A)
                {
                    if (dungeon.level[pChar.posX - 1][pChar.posY] > 0 and pChar.posX > 0)
                    {
                        if (dungeon.levelOccupied[pChar.posX-1][pChar.posY] == false)
                        {
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = false;
                            pChar.MoveLeft();
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = true;
                            playerMoved = true;
                        }
                        else
                        {
                            for(int m=0;m<melee_Enemies;m++)
                            {
                                if (mEnemy[m].posX == pChar.posX-1 and mEnemy[m].posY == pChar.posY)
                                {
                                    mEnemy[m].health = pChar.Attack(mEnemy[m].health);
                                    playerMoved = true;
                                    std::cout << "Enemy " << m <<" Health: " << mEnemy[m].health << std::endl;
                                }
                            }
                        }
                    }
                }

                if (event.key.code == sf::Keyboard::S)
                {
                    if (dungeon.level[pChar.posX][pChar.posY + 1] > 0 and pChar.posY < dungeon.levelXCap)
                    {
                        if (dungeon.levelOccupied[pChar.posX][pChar.posY+1] == false)
                        {
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = false;
                            pChar.MoveDown();
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = true;
                            playerMoved = true;
                        }
                        else
                        {
                            for(int m=0;m<melee_Enemies;m++)
                            {
                                if (mEnemy[m].posX == pChar.posX and mEnemy[m].posY == pChar.posY+1)
                                {
                                    mEnemy[m].health = pChar.Attack(mEnemy[m].health);
                                    playerMoved = true;
                                    std::cout << "Enemy " << m <<" Health: " << mEnemy[m].health << std::endl;
                                }
                            }
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    if (dungeon.level[pChar.posX][pChar.posY - 1] > 0 and pChar.posY > 0)
                    {
                        if (dungeon.levelOccupied[pChar.posX][pChar.posY-1] == false)
                        {
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = false;
                            pChar.MoveUp();
                            dungeon.levelOccupied[pChar.posX][pChar.posY] = true;
                            playerMoved = true;
                        }
                        else
                        {
                            for(int m=0;m<melee_Enemies;m++)
                            {
                                if (mEnemy[m].posX == pChar.posX and mEnemy[m].posY == pChar.posY-1)
                                {
                                    mEnemy[m].health = pChar.Attack(mEnemy[m].health);
                                    playerMoved = true;
                                    std::cout << "Enemy " << m <<" Health: " << mEnemy[m].health << std::endl;
                                }
                            }
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (pChar.posX == dungeon.endStairX and pChar.posY == dungeon.endStairY)
                    {
                        difficulty += 1;
                        dungeon.Generate((difficulty*2)+4,(difficulty*2)+4,difficulty);
                        pChar.Spawn(dungeon.startStairX,dungeon.startStairY);
                        for (int r=0;r<difficulty+2;r++)
                        {
                            while (enemyGenerated == false)
                            {
                                enemyPosX = rand() % (dungeon.levelXCap+1);
                                enemyPosY = rand() % (dungeon.levelYCap+1);

                                if (dungeon.levelOccupied[enemyPosX][enemyPosY] == false and dungeon.level[enemyPosX][enemyPosY] == 4)
                                {
                                    mEnemy[r].Create(1,enemyPosX,enemyPosY,1,1,1,10,10,dungeon.level);
                                    dungeon.levelOccupied[enemyPosX][enemyPosY] = true;
                                    enemyGenerated = true;
                                }
                            }

                            enemyGenerated = false;

                            //Find a value that isn't occupied and is a 4.
                            mEnemy[r].GenerateSprite();
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Period)
                {
                    playerMoved = true;
                }
            }
        }
        if (dungeonGenerated == false)
        {
            levelSize = 0;

            for (int m=0;m<melee_Enemies;m++)
            {
                while (enemyGenerated == false)
                {
                    enemyPosX = rand() % (dungeon.levelXCap+1);
                    enemyPosY = rand() % (dungeon.levelYCap+1);

                    if (dungeon.levelOccupied[enemyPosX][enemyPosY] == false and dungeon.level[enemyPosX][enemyPosY] == 4)
                    {
                        mEnemy[m].Create(1,enemyPosX,enemyPosY,1,1,1,10,10,dungeon.level);
                        dungeon.levelOccupied[enemyPosX][enemyPosY] = true;
                        enemyGenerated = true;
                    }
                }

                enemyGenerated = false;

                //Find a value that isn't occupied and is a 4.
                mEnemy[m].GenerateSprite();
            }

            dungeonGenerated = true;
        }
        if (playerSpawned == false)
        {
            pChar.Spawn(dungeon.startStairX,dungeon.startStairY);
            //Will later be used to place the player at the spawn location, but that's not implemented yet.
            playerSpawned = true;
        }

        for (int c=0;c<dungeon.chestsActive;c++)
        {
            //Draw active chests
            if (pChar.posX == dungeon.chestLocX[c] and pChar.posY == dungeon.chestLocY[c] and dungeon.chestOccupied[pChar.posX][pChar.posY] == true)
            {
                //Change the sprite.
                dungeon.chestTexture[c].loadFromFile("sprites/dungeon_sprites/chest_open.png");
                dungeon.chestSprite[c].setTexture(dungeon.chestTexture[c],false);
                dungeon.chestOccupied[pChar.posX][pChar.posY] = false;
                std::cout << "On a Chest" << std::endl;
                //Generate an item
                Item equipment;
                equipment.Generate(difficulty);

                pChar.Equip(equipment);

            }
        }



        camera.setCenter(pChar.posX*50,pChar.posY*50);
        window.setView(camera);

        if (playerMoved == true)
        {
            for (int mE=0;mE<melee_Enemies;mE++)
            {
                if (mEnemy[mE].enemyDeleted == true)
                {
                    //Delete the enemy's positions.
                    //The problem is that it does this EVERY loop, so that position is always cleared, so you can never
                    //fight there again. Need to fix.
                    dungeon.levelOccupied[mEnemy[mE].posX][mEnemy[mE].posY] = false;
                }
                else
                {
                    dungeon.levelOccupied[mEnemy[mE].posX][mEnemy[mE].posY] = false;
                    mEnemy[mE].AIAction(dungeon.levelOccupied,10,10,pChar.posX,pChar.posY,dungeon.level);
                    dungeon.levelOccupied[mEnemy[mE].posX][mEnemy[mE].posY] = true;
                    playerMoved = false;

                    if (mEnemy[mE].enemyCanAttack == true)
                    {
                        pChar.currHealth = mEnemy[mE].Attack(pChar.currHealth);
                        std::cout << "Player Health: " << pChar.currHealth << std::endl;
                        mEnemy[mE].enemyCanAttack = false;
                    }
                    if (mEnemy[mE].health <= 0)
                    {
                        dungeon.levelOccupied[mEnemy[mE].posX][mEnemy[mE].posY] = false;
                    }
                }
            }
        }

        //So what these do is set what opts are occupied at the end of every loop.

        window.clear();

        window.draw(dungeon.level_sprite,40000,sf::Quads);
        //Draw the Dungeon

        for (int c=0;c<dungeon.chestsActive;c++)
        {
            //Draw active chests
            window.draw(dungeon.chestSprite[c]);
        }

        window.draw(pChar.sprite);

        for (int e=0;e<9;e++)
        {
            window.draw(pChar.playerEquipment[e].sprite);
            //std::cout << "Drawing Equipment " << e << std::endl;
        }
        //Draw the player and their gear

        for (int m=0;m<melee_Enemies;m++)
        {
            //Draw the Enemy.
            window.draw(mEnemy[m].sprite);
        }
        window.display();
    }
    return 0;
}
