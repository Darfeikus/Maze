#include "Player.h"

int main()
{
    int x = 2;
    int y = 3;
    int x1 = 34;
    int y1 = 34;
    int size = 40;

    struct Tablero *board = getTablero(size, x, y, x1, y1, 1000);
    struct Tile *goal = *(board->grid) + (x1 + y1 * size);
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));

    printf("You took %d moves", game(player,x,y,goal,board));
    free(player);
    free(goal);
    free(board);
}
