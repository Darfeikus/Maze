#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t t;
int size;

void clean(struct Tile** pointer_grid){
    *pointer_grid = (struct Tile*)malloc(sizeof(struct Tile)*size*size);
    struct Tile* c= *pointer_grid;
    for(int i = 0; i < size*size; i++){
        (c+i)->self = (struct coord*)malloc(sizeof(struct coord));
        (c+i)->self->x=i%size;
        (c+i)->self->y=i/size;
        (c+i)->val = 1;
    }
    for(int i = 0; i < size*size; i++){
        (c+i)->up = (struct Tile*)malloc(sizeof(struct Tile));
        (c+i)->left = (struct Tile*)malloc(sizeof(struct Tile));
        (c+i)->down = (struct Tile*)malloc(sizeof(struct Tile));
        (c+i)->right = (struct Tile*)malloc(sizeof(struct Tile));
        
        (c+i)->up = i-size>=0 ? ((c+i)-size):NULL;
        (c+i)->down = i+size<size*size ? ((c+i)+size):NULL;
        (c+i)->left = i%size!=0 && i-1>0 ? ((c+i)-1):NULL;
        (c+i)->right = NULL;
        (c+i)->right = (i+1)%size!=0 && i+1<size*size ? ((c+i)+1):NULL;
    }
        
}

void printGrid(struct Tile** grid){;
    for(int i = 0; i < size*size; i++){
        if(i%size==0 && i!=0)
            printf("\n");
        printf("(%d,%d) | %d\t",((*grid)+i)->self->x,((*grid)+i)->self->y,((*grid)+i)->val);
    }
    printf("\n");
}

void createPath(struct Tablero* board, struct Tile* start, struct Tile* goal){
    
}

struct Tablero* getTablero(int s,int x1, int y1, int x2, int y2){
    size = s;
    //Create board
    struct Tablero* board = (struct Tablero*)malloc(sizeof(struct Tablero));
    board->height=size;
    board->width=size;
    
    //establish grid size
    board->grid = (struct Tile**)malloc(sizeof(struct Tile)*size*size);
    clean(board->grid);

    struct Tile* start = *(board->grid)+(x1+y1*size);
    struct Tile* goal = *(board->grid)+(x2+y2*size);
    start->val = 0;
    goal->val = 4;
    
    printGrid(board->grid);
    createPath(board,start,goal);
    return board;
}


