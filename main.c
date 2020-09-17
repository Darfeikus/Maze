#include "Player.h"
#include "lib_myscanner.h"
#include "new_board.h"

int main() {   
    struct scanner s = scan();
    int x = getHorizontalStart(s);
    int y = getVerticalStart(s);
    int x1 = getHorizontalEnd(s);
    int y1 = getVerticalEnd(s);
    int size = s.size;

    struct Tablero *board = getTablero(size, x, y, x1, y1, 1);
    board->grid = changeTablero(board->grid, s);
    struct Tile *goal = *(board->grid) + (x1 + y1 * size);
    struct Player *player = (struct Player *)malloc(sizeof(struct Player));

    printf("You took %d moves", game(player,x,y,goal,board));
    free(player);
    free(goal);
    free(board);
}
