struct Tile** changeTablero(struct Tile **grid, struct scanner s) {
    struct Tile **newGrid = grid;
    for(int i=0; i<s.size*s.size; i++) {
        if(s.maze[i] == '*') {
            ((*grid)+i)->val = 1;
        } else {
            ((*grid)+i)->val = 0;
        }
    }
    return newGrid;
}

int getHorizontalStart(struct scanner s) {
    int start = 0;
    for(int i=0; i<s.size*s.size; i++) {
        if(s.maze[i] == '1') {
            start = i;
        }
    }
    int row = start/s.size;
    start = start - (row*s.size);

    return start;
}

int getVerticalStart(struct scanner s) {
    int end = 0;
    for(int i=0; i<s.size*s.size; i++) {
        if(s.maze[i] == '1') {
            end = i;
        }
    }
    end = end/s.size;

    return end;
}


int getHorizontalEnd(struct scanner s) {
    int start = 0;
    for(int i=0; i<s.size*s.size; i++) {
        if(s.maze[i] == '2') {
            start = i;
        }
    }
    int row = start/s.size;
    start = start - (row*s.size);

    return start;
}

int getVerticalEnd(struct scanner s) {
    int end = 0;
    for(int i=0; i<s.size*s.size; i++) {
        if(s.maze[i] == '2') {
            end = i;
        }
    }
    end = end/s.size;

    return end;
}