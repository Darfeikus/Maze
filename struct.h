struct coord{
    int x,y;
};

struct Tile
{
    int val;
    coord* self;
    coord* up;
    coord* down;
    coord* left;
    coord* right;
};

struct Tablero{
    int height;
    int length;
    Tile** tablero;
};

struct Player
{
    coord* pos;
};

