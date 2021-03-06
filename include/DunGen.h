#ifndef DUNGEN_H
#define DUNGEN_H
#include <SFML/Graphics.hpp>


class DunGen
{
    public:
        DunGen(int xCap,int yCap,int difficulty);
        //Is, for the most part, useless. Just runs Generate  down there.
        //But if I don't have it run something when it starts, it breaks on me.
        void Generate(int xCap,int yCap,int difficulty);
        //This one just runs Tunnels and Rooms to generate the level.
        void Tunnels(int xCap,int yCap,int difficulty,int roomType);
        //Creats the tunnel. Well, I probably shouldn't have made it plural.
        //Remember! 3 is standard, 1 is bonus! Bonus is canned.
        void Rooms(int xCap,int yCap,int difficulty,int roomType);
        //Creates the rooms. Plurality is totally okay here.
        //Remember, 4 is standard, 2 is bonus! Er, it would be, but bonus got canned.
        void PlaceChest(int difficulty);
        //Places chests around the map

        void ResetLevel();
        //Sets every part of the level to 0.

        void Load(int xCap, int yCap);
        //Need to load the level

        void TunUp();
        void TunRight();
        void TunDown();
        void TunLeft();
        //Makes the tunnel. These might require adjustment for the bonus levels, specifically, so that the room check isn't
        //for just 3. The decision on what it should check for is up for debate (0? If it's lower?)
        void RoomBoundsCheck(int xCap,int yCap);
        //Checks if the room is in the bounds of the level.
        void SpriteGenerate();

        int level[100][100];
        sf::Vertex level_sprite[40000];
        //sf::Sprite sprite[100][100];
        bool levelOccupied[100][100];
        //Checks if there is a mobile entity at that location.
        bool chestOccupied[100][100];
        //Checks if there is a chest in that location.

        int levelXCap,levelYCap;
        //Sets the caps on the level

        int startStairX,startStairY;
        //Player start position
        int endStairX,endStairY;
        //Position to exit the level
        /*bool chest0Created = false;
        bool chest1Created = false;
        bool chest2Created = false;
        bool chest3Created = false;
        bool chest4Created = false;*/
        int chestsActive = 0;
        int chestLocX[4],chestLocY[4];
        sf::Texture chestTexture[4];
        sf::Sprite chestSprite[4];
    protected:
    private:
        int lineLength;
        //Chooses the Length of the tunnel
        int tunX;
        //Tunnel's X position
        int tunY;
        //Tunnel's Y position
        int direction;
        //Gets the direction of the line
        int prevDir = 5;
        //gets the previous direction
        int altDir;
        //Sets alternate directions.
        int tunCount = 0;
        //Counts how many 3s there are in the area.
        int firstTunX,firstTunY,lastTunX,lastTunY;
        //Gets the first position and last position of the tunnel for room generation.
        int tunLocX[255],tunLocY[255];
        //Grabs the location of the tunnels

        int roomTotal;
        //Counts how many rooms there are.
        int roomFX,roomFY;
        //Designates the upper left corner of the room. F stands for "First"
        int roomLX,roomLY;
        //Designates the lower right corner of the room. L stands for "Last"
        int rWidth,rHeight;
        //Designates the room's width and height. r stands for rooms
        int startXDist,startYDist;
        //Figures out the distance between the tunnel and the upper left position.


        int firstRoomULX,firstRoomULY,firstRoomLRX,firstRoomLRY,lastRoomULX,lastRoomULY,lastRoomLRX,lastRoomLRY;
        //Gets the Upper left and lower right position of the first and last rooms.
        //This is going to be useful later to place the spawn point and stairs.
        int roomXInv,roomYInv;

        int levelSize = 0;
        //Makes the size of the room
        //sf::Texture lvlTexture;
        //sf::Texture stairTexture;
        //sf::Texture blankTexture;


};

#endif // DUNGEN_H
