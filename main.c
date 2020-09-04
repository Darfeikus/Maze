#include "Tablero.h"
#include "conio.h"

int main()
{
    int x = 2;
    int y = 3;
    int x1 = 14;
    int y1 = 14;
    int size = 15;

    struct Tablero *board = getTablero(size, x, y, 14, 14);
    printf("\n");
    struct Tile *goal = *(board->grid) + (x1 + y1 * size);

    struct Player *player = (struct Player *)malloc(sizeof(struct Player));

    player->pos = *(board->grid) + (x + y * size);
    int movements = -1;
    int cont  = 1;
    while (player->pos != goal && cont)
    {
        movements++;
        printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y);
        system("clear");
        printTile(player->pos);
        char c;
        scanf("%c",&c);
        
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
                cont=0;
                break;
            default:
                break;
            }
        
    }
    printf("You took %d moves", movements);
    free(player);
    free(board);
}