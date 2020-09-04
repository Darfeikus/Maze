#include "Tablero.h"

int game(struct Player* player,int x, int y,struct Tile* goal,struct Tablero* board){
    player->pos = *(board->grid) + (x + y * size);
    int movements = -1;
    int cont = 1;
    while (player->pos != goal && cont)
    {
        movements++;
        printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y);
        system("clear");
        printTile(player->pos);
        char c;
        scanf("%c", &c);

        switch (c)
        {
        case 'w':
            if (player->pos->up != NULL)
            {
                if (player->pos->up->val != 1)
                {
                    player->pos = player->pos->up;
                    break;
                }
            }
            break;
        case 'a':
            if (player->pos->left != NULL)
            {
                if (player->pos->left->val != 1)
                {
                    player->pos = player->pos->left;
                    break;
                }
            }
            break;
        case 's':
            if (player->pos->down != NULL)
            {
                if (player->pos->down->val != 1)
                {
                    player->pos = player->pos->down;
                    break;
                }
            }
            break;
        case 'd':
            if (player->pos->right != NULL)
            {
                if (player->pos->right->val != 1)
                {
                    player->pos = player->pos->right;
                    break;
                }
            }
            break;
        case 'e':
            printf("You Lose");
            cont = 0;
            break;
        default:
            break;
        }
    }
    system("clear");
    printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y);
}