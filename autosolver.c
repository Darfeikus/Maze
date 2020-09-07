#include "Player.h"

int main()
{
    int x = 2;
    int y = 3;
    int size = 25;
    int x1 = size-1;
    int y1 = size-1;

    struct Tablero *board = getTablero(size, x, y, x1, y1, 1000);
    struct Tile *goal = (struct Tile*)malloc(sizeof(struct Tile));
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));
    
    goal = *(board->grid) + (x1 + y1 * size);
    
    player->pos = *(board->grid) + (x + y * size);
    
    printf("You took %d moves", autoGame(player,x,y,goal,board));
    
    free(player);
    free(goal);
    free(board);
}
