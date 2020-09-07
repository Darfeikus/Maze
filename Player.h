#include "Tablero.h"

int game(struct Player* player,int x, int y,struct Tile* goal,struct Tablero* board){
    player->pos = *(board->grid) + (x + y * size);
    int movements = -1;
    int cont = 1;
    while (player->pos != goal && cont)
    {
        movements++;
        printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y,goal->self->x,goal->self->y);
        // system("clear");
        printTile(player->pos,goal);
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
            printf("You Lose\n");
            cont = 0;
            break;
        default:
            break;
        }
    }
    // system("clear");
    printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y,goal->self->x,goal->self->y);
    return movements/2;
}

char seleccionarLetra(struct Tile* chuckee, struct Tile* goal)
{
    if (chuckee == goal)
        return 'e';

    if (chuckee->right != NULL && chuckee->right->val == 0)
        if( seleccionarLetra(chuckee->right,goal))
            return 'd';

    if (chuckee->down != NULL && chuckee->down->val == 0)
        if( seleccionarLetra(chuckee->down,goal))
            return 's';

    if (chuckee->left != NULL && chuckee->left->val == 0)
        if( seleccionarLetra(chuckee->left,goal))
            return 'a';
    
    if (chuckee->up != NULL && chuckee->up->val == 0)
        if( seleccionarLetra(chuckee->up,goal))
            return 'w';

    return 'e';
}

int autoGame(struct Player* player,int x, int y,struct Tile* goal,struct Tablero* board){
    player->pos = *(board->grid) + (x + y * size);
    int movements = -1;
    int cont = 1;

    while (player->pos != goal && cont)
    {
        movements++;
        printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y,goal->self->x,goal->self->y);
        //system("cls");
        printTile(player->pos,goal);
        char c = seleccionarLetra(player->pos,goal);

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
            printf("You Lose\n");
            cont = 0;
            break;
        default:
            break;
        }
        sleep(1);
    }
    //system("cls");
    printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y,goal->self->x,goal->self->y);
    return movements/2;
}