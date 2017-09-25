#ifndef Image_InOut
#define Image_InOut

#include "Image_Struct.h"

/*
Function for allocating memory space to the image array, which has the array type ARR_TYPE**.
*/
ARRAY_TYPE ** image_arr_allocate( int width, int height);

/*
this function writes image to file, which has the file extension ".pgm" and is in format P5.
*/
void write_image(const char * filename, image_info image);

/*
This function reads the image file which has the ".pgm" file extension and in P5 format.
*/
image_info read_image(const char * image_file);

#endif
