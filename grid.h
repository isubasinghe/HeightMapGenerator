#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct {
    int width;
    int height;
    unsigned char ** mat;
} grid_t;

static double rand_2()
{
    return rand() % 256;
}

grid_t * create_grid(int width, int height) {
    grid_t * grid = malloc(sizeof(grid_t));
    grid->width = width;
    grid->height = height;
    grid->mat = malloc(height*sizeof(unsigned char *));
    int i = 0;
    for(; i < height; i++){
        grid->mat[i] = malloc(width*sizeof(unsigned char));
    }
    return grid;
}

grid_t * clone_grid(grid_t * grid) {
    grid_t * clone = create_grid(grid->width, grid->height);
    int i = 0;
    for(; i < clone->height; i++){
        int j = 0;
        for(; j < clone->width; j++){
            clone->mat[i][j] = grid->mat[i][j];
        }
    }
    return clone;
}

void init_rand(grid_t * grid) {
    int i = 0;
    for(; i < grid->height; i++) {
        int j = 0;
        for(; j < grid->width; j++) {
            grid->mat[i][j] = rand_2();
        }
    }
}


void free_grid(grid_t * grid) {
    int i = 0;
    for(; i < grid->height; i++) {
        free(grid->mat[i]);
    }
    free(grid->mat);
}

#endif // GRID_H