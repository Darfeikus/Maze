#include "Player.h"

int main()
{
    int x = 2;
    int y = 3;
    int x1 = 10;
    int y1 = 13;
    int size = 15;

    struct Tablero *board = getTablero(size, x, y, x1, y1);
    struct Tile *goal = *(board->grid) + (x1 + y1 * size);
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));

    printf("You took %d moves", game(player,x,y,goal,board));
    free(player);
    free(goal);
    free(board);
}