#include <stdio.h>
#include <stdlib.h>


#include "lodepng.h"
#include "grid.h"
#include "procgen.h"



int main(int argc, char * argv[]) {
    if(argc != 7) {
    	printf("usage: %s <filename: string> <width: int> <height: int> <blur_radius: int> <blur_iter: int> <seed: int>\n", argv[0]);
        return 1;
    }

    char * fname = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int blur_radius = atoi(argv[4]);
    int do_blur = 1;
    int blur_iter = atoi(argv[5]);
    int seed = atoi(argv[6]);
    
    grid_t * grid = create_grid(width, height);
    srand(seed);
 rand();
    init_rand(grid);

    int i = 0;
    if(do_blur) {
    	for(; i < blur_iter; i++) {
    		blur_grid(grid, blur_radius);
    	}
    }
    
    save_grid_as_png(grid, fname);

    free_grid(grid);

    return 0;
}