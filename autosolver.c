#include "Player.h"

int main()
{
    int x = 2;
    int y = 3;
    int x1 = 14;
    int y1 = 14;
    int size = 15;

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
