struct coord{
    int x,y;
};

/*
    0 free
    1 occupied
    2 player
    3 goal
*/

struct Tile
{
    int val;
    struct coord* self;
    struct Tile* up;
    struct Tile* down;
    struct Tile* left;
    struct Tile* right;
};

struct Tablero{
    int height;
    int width;
    struct Tile* start;
    struct Tile* goal;
    struct Tile** grid;
};

struct Player
{
    struct coord* pos;
};

