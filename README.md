# HeightMapGenerator
A simple height map generator.

#### TODO
- Allow merging of heightmaps.
- Implement a function to get a stream of heightmaps based on the previous heightmap, this can be done through the merging talked about above.
- Should be able to save memory by using the png24 format instead of png32, furthermore we could exclude using grid_t and directly using the png24/32 buffer instead.

#### COMPILING
gcc -c *.c && gcc *.o -o [binary file name]

#### USAGE
- [binary file name] [output file name] [width] [height [blur radius] [blur iterations] [seed]

![Example of 2D heightmap](https://github.com/isubasinghe/HeightMapGenerator/raw/master/heightmap.png)

![Example of 3D terrain](https://github.com/isubasinghe/HeightMapGenerator/raw/master/image.png)

These can be blurred more or less, depending on your desired "flatness"
