#ifndef Image_InOut
#define Image_InOut

#include "Image_Struct.h"

ARRAY_TYPE ** image_arr_allocate( int width, int height);

void write_image(const char * filename, image_info image);

image_info read_image(const char * image_file);

#endif