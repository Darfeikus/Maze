#include "Player.h"

int main()
{
    int x = 0;
    int y = 0;
    int size = 60;
    int x1 = size-1;
    int y1 = size-1;

    struct Tablero *board = getTablero(size, x, y, x1, y1, 1000);
    struct Tile *goal = (struct Tile*)malloc(sizeof(struct Tile));
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));
    
    goal = *(board->grid) + (x1 + y1 * size);
    
    player->pos = *(board->grid) + (x + y * size);
    
    printf("You took %d moves\n", autoGame(player,x,y,goal,board));
}
