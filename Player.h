#include "Tablero.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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
    return movements;
}

int calcularPath(struct Tile* chuckee, struct Tile* goal, struct Queue** stack)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));

    if (chuckee == goal) {
        tmp->dir='e';
        iatb(stack, tmp);
        chuckee -> val = 0;
        return 1;
    }

    chuckee -> val = 2;

    if (chuckee->right != NULL && chuckee->right->val == 0)
        if( calcularPath(chuckee->right,goal, stack))
        {
            tmp->dir='d';
            iatb(stack, tmp);
            chuckee -> val = 0;
            return 1;
        }

    if (chuckee->down != NULL && chuckee->down->val == 0)
        if( calcularPath(chuckee->down,goal, stack))
        {
            tmp->dir='s';
            iatb(stack, tmp);
            chuckee -> val = 0;
            return 1;
        }

    if (chuckee->left != NULL && chuckee->left->val == 0)
        if( calcularPath(chuckee->left,goal, stack))
        {
            tmp->dir='a';
            iatb(stack, tmp);
            chuckee -> val = 0;
            return 1;
        }
    
    if (chuckee->up != NULL && chuckee->up->val == 0)
        if( calcularPath(chuckee->up,goal, stack))
        {
            tmp->dir='w';
            iatb(stack, tmp);
            chuckee -> val = 0;
            return 1;
        }

    chuckee -> val = 0;
    return 0;
}

int autoGame(struct Player* player,int x, int y,struct Tile* goal,struct Tablero* board){
    player->pos = *(board->grid) + (x + y * size);
    int movements = -1;
    int cont = 1;
    struct Queue* stack = calloc(1,sizeof(struct Queue));

    
    calcularPath(player->pos, goal, &stack);

    while (player->pos != goal && cont)
    {
        movements++;
        printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y,goal->self->x,goal->self->y);
        system("cls");
        printTile(player->pos,goal);
        char c = get(&stack)->dir;

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
    system("cls");
    printGridBinaryFile(board->grid, player->pos->self->x, player->pos->self->y,goal->self->x,goal->self->y);
    printTile(player->pos,goal);
    return movements;
}