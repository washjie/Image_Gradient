#include "image_io.h"
/*
The function dose the following things:
1. It calculates gradience of every pixel.
2. It then determines what direction these pixels are in.
3. Then the function colors the pixel in the new image array based on pixel angle in the old image.
4. Output the new image file.

There are 8 direction: 0(g0), 45(g1), 90(g2), 135(g3), 180(g4), 225(g5), 270(g6), 315(g7), 360(g8).
If degree of a pixel is 39.6, it will be classified as g1.(Since 39.6 degree is closer to 45 degree than the others.)
*/
void image_routine(image_info image);
