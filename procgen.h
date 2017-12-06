#ifndef PROCGEN_H
#define PROCGEN_H

#include <assert.h>
#include "grid.h"
#include "lodepng.h"

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

void blur_grid(grid_t * grid, int radius) {
	printf("blurring...");
	grid_t * clone = clone_grid(grid);
	int i, j, x, y;
	for(i = 0; i < grid->height; i++) {
		int x_min = MAX(0, i-radius), x_max = MIN(clone->height, i+radius);
		for(j = 0; j < grid->width; j++) {
			int y_min = MAX(0, j-radius), y_max = MIN(clone->width, j+radius);
			double sum = 0;
			int count = 0;
			for(x = x_min; x < x_max; x++){
				for(y = y_min; y < y_max; y++){
					sum += clone->mat[x][y];
					count++;
				}
			}
			grid->mat[i][j] = sum / count;
		}
	}
    printf("blurred\n");
	free_grid(clone);
}

void save_grid_as_png(grid_t * grid, const char * fname) {
    unsigned char * data = malloc(sizeof(unsigned char)*(grid->width*(grid->height+1)+1)*4);
    for(int y = 0; y < grid->height; y++) {
        for(int x = 0; x < grid->width; x++) {
            for(int chan = 0; chan < 3; chan++) {
                data[4*y*grid->width + 4*x + chan] = grid->mat[y][x];
            }
            data[4*y*grid->width + 4*x + 3] = 255;
        }
    }

    lodepng_encode32_file(fname, data, grid->width, grid->height);
}



#endif // PERLIN_H