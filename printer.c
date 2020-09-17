#include <stdio.h>
#include <stdlib.h>

struct coord{
    int x,y;
};

/*
    0 free
    1 occupied
    2 player
    3 goal
*/

struct Tile
{
    int val;
    struct coord* self;
    struct Tile* up;
    struct Tile* down;
    struct Tile* left;
    struct Tile* right;
};

struct Tablero{
    int height;
    int width;
    struct Tile* start;
    struct Tile* goal;
    struct Tile** grid;
};

struct Player
{
    struct Tile* pos;
};

void printGridBinaryFile(struct Tile** grid, int x, int y, int x1, int y1, int size){
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
        else if(x1+y1*size == i)
            fprintf(fp,"x");
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

