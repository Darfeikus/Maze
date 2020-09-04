#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t t;
int size;
int uncrossed; //boolean that tells when the two paths have crossed

void printTile(struct Tile* tile){
    if(tile->up!=NULL){
        if (tile->up->val)
            printf("x■x\n");
        else
            printf("x x\n");
    }
    else
        printf("■■■\n");

    if(tile->left!=NULL){
        if (tile->left->val)
            printf("■");
        else
            printf(" ");
    }
    else
        printf("■");

    printf("o");

    if(tile->right!=NULL){
        if (tile->right->val)
            printf("■\n");
        else
            printf(" \n");
    }
    else
        printf("■\n");

    if(tile->down!=NULL){
        if (tile->down->val)
            printf("x■x\n");
        else
            printf("x x\n");
    }
    else
        printf("■■■\n");
}

void clean(struct Tile** pointer_grid){
    *pointer_grid = (struct Tile*)malloc(sizeof(struct Tile)*size*size);
    struct Tile* c= *pointer_grid;
    for(int i = 0; i < size*size; i++){
        (c+i)->self = (struct coord*)malloc(sizeof(struct coord));
        (c+i)->self->x=i%size;
        (c+i)->self->y=i/size;
        (c+i)->val = 0;
        (c+i)->up = i-size>=0 ? ((c+i)-size):NULL;
        (c+i)->down = i+size<size*size ? ((c+i)+size):NULL;
        (c+i)->left = i%size!=0 && i-1>0 ? ((c+i)-1):NULL;
        (c+i)->right = (i+1)%size!=0 && i+1<size*size ? ((c+i)+1):NULL;
    }   
}

int cleanGrid(struct Tile** pointer_grid){
    int o = 0;
    struct Tile* c= *pointer_grid;
    for(int i = 0; i < size*size; i++)
        if((c+i)->val==5 || (c+i)->val==4){
            (c+i)->val = 0;
            o++;
        }
        else if((c+i)->val==7 || (c+i)->val==8)
            (c+i)->val = 1;
        else
            (c+i)->val = 1;
    if(size>10){
        int r = 0;
        for(int i = 0; i < size*size; i++)
            if((c+i)->val==1){
                r = rand()%3;
                (c+i)->val = r<1 ? 0:1;
            }
    }
    return o;
}

void printGrid(struct Tile** grid){;
    for(int i = 0; i < size*size; i++){
        if(i%size==0 && i!=0)
            printf("\n");
        printf("(%d,%d) | %d\t",((*grid)+i)->self->x,((*grid)+i)->self->y,((*grid)+i)->val);
    }
    printf("\n");
}

void printGridBinary(struct Tile** grid, int x, int y){;
    for(int i = 0; i < size+1; i++)
        printf("■");
    for(int i = 0; i < size*size; i++){
        if(i%size==0){
            printf("■");
            printf("\n");
            printf("■");
        }
        if(x+y*size == i)
            printf("o");
        else
            printf("%s",((*grid)+i)->val ? "■":" ");
    }
    printf("\n");
    for(int i = 0; i < size+2; i++)
        printf("■");
    printf("\n");
}

void printGridBinaryFile(struct Tile** grid, int x, int y){;
    FILE * fp;
    fp = fopen("out","w");
    for(int i = 0; i < size+1; i++)
        fprintf(fp,"■");
    for(int i = 0; i < size*size; i++){
        if(i%size==0){
            fprintf(fp,"■");
            fprintf(fp,"\n");
            fprintf(fp,"■");
        }
        if(x+y*size == i)
            fprintf(fp,"o");
        else
            fprintf(fp,"%s",((*grid)+i)->val ? "■":" ");
    }
    fprintf(fp,"■");
    fprintf(fp,"\n");
    for(int i = 0; i < size+2; i++)
        fprintf(fp,"■");
    fprintf(fp,"\n");
    fclose(fp);
}

void printGridNormal(struct Tile** grid){;
    for(int i = 0; i < size*size; i++){
        if(i%size==0 && i!=0)
            printf("\n");
        printf("%d\t",((*grid)+i)->val);
    }
    printf("\n\n");
}

struct Tile* draw(struct Tile* t, int direction,int move){
    int val = t->val;
    switch (direction){
        case 0://Up
            if(t->up==NULL)
                draw(t,direction+1,move);
            while(t->up!=NULL && move>0){ //keep moving up and change values
                t=t->up;
                move--;
                if(abs(t->val-val)==1){//They crossed
                    uncrossed = 0;
                    return t;
                }
                if(t->val != val && t->val>3)
                    return t->down;
                t->val=val;
            }
            return t;
            break;
        case 1://Down
            if(t->down==NULL)
                draw(t,direction+1,move);
            while(t->down!=NULL && move>0){ //keep moving down and change values
                t=t->down;
                if(t->val != val && t->val>3)
                    return t->up;
                move--;
                if(abs(t->val-val)==1){//They crossed
                    uncrossed = 0;
                    return t;
                }
                t->val=val;
            }
            return t;
            break;
        case 2://Left
            if(t->left==NULL)
                draw(t,direction+1,move);
            while(t->left!=NULL && move>0){ //keep moving left and change values
                t=t->left;
                if(t->val != val && t->val>3)
                    return t->right;
                move--;             
                if(abs(t->val-val)==1){//They crossed
                    uncrossed = 0;
                    return t;
                }
                t->val=val;
            }
            return t;
            break;
        case 3://Right
            if(t->right==NULL)
                draw(t,0,move);
            while(t->right!=NULL && move>0){ //keep moving right and change values
                t=t->right;
                if(t->val != val && t->val>3)
                    return t->left;
                move--;             
                if(abs(t->val-val)==1){//They crossed
                    uncrossed = 0;
                    return t;
                }
                t->val=val;
            }
            return t;
            break;
    }
}


int createPath(struct Tablero* board){
    srand((unsigned) time(&t));
    int MAX_PATH_SIZE = size/5>=2 ? size/5:2;
    struct Tile* start = board->start;
    struct Tile* goal = board->goal;
    
    struct Tile* p1 = start;
    struct Tile* p2 = goal;
    struct Tile* p3 = *(board->grid)+rand()%(size*size);
    struct Tile* p4 = *(board->grid)+rand()%(size*size);

    while(p3==p1 || p3==p2){
        p3 = *(board->grid)+rand()%(size*size);
    }
    while(p4==p1 || p4==p2){
        p4 = *(board->grid)+rand()%(size*size);
    }

    p3->val = 7;
    p4->val = 8;
    
    int dir1,dir2,hv1,hv2;
    dir1=0;
    dir2=0;
    hv1=0;
    hv2=0;
    uncrossed = 1;

    while(uncrossed){ //Generate principal path
        hv1 = dir1 < 2 ? hv1+2:hv1-2;//Go vertical or horizontl next move
        hv2 = dir2 < 2 ? hv2+2:hv2-2;
        dir1=rand()%2+hv1;
        p1=draw(p1,dir1,rand()%MAX_PATH_SIZE+2);
        
        dir2=rand()%2+hv2;
        p2=draw(p2,dir2,rand()%MAX_PATH_SIZE+2);
    }

    uncrossed = 1;
    int stop = 200;

    while(uncrossed && stop>0){ //Generate principal path
        stop--;
        hv1 = dir1 < 2 ? hv1+2:hv1-2;//Go vertical or horizontl next move
        hv2 = dir2 < 2 ? hv2+2:hv2-2;
        dir1=rand()%2+hv1;
        p3=draw(p3,dir1,rand()%MAX_PATH_SIZE+2);
        
        dir2=rand()%2+hv2;
        p4=draw(p4,dir2,rand()%MAX_PATH_SIZE+2);
    }
    return cleanGrid(board->grid);
}

struct Tablero* getTablero(int s,int x1, int y1, int x2, int y2){
    size = s;
    //Create board
    struct Tablero* board = (struct Tablero*)malloc(sizeof(struct Tablero));
    struct Tablero* bestBoard = (struct Tablero*)malloc(sizeof(struct Tablero));
    
    int time_s = 100000;
    int o = size*size;
    int areaof_error = size/2;
    int min_o = o;

    while(o>areaof_error && time_s>0){
        board->height=size;
        board->width=size;
        //establish grid size
        board->grid = (struct Tile**)malloc(sizeof(struct Tile)*size*size);
        clean(board->grid);
        board->start = *(board->grid)+(x1+y1*size);
        board->goal = *(board->grid)+(x2+y2*size);
        board->start->val = 5;
        board->goal->val = 4;
        time_s--;
        o = createPath(board); // get amount of 0's when creating path
        if(min_o>o){
            min_o = o;
            free(bestBoard);
            bestBoard = board;
            board = (struct Tablero*)malloc(sizeof(struct Tablero));
        }
    }
    return bestBoard;
}


