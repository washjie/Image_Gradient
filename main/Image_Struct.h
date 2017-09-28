#define ARRAY_TYPE unsigned char
#define PI 3.14159265

/*
Image file structure definition
Since we use <picture>.pgm file as our material
The array type for storing every pixel is unsigned char

width: the width of the image file.
height: the height of the image file.
max_gray: maximum gray value.
image_arr: where the image data is stored.
filename: the name of this image data.
*/

typedef struct image_data{
	int width;
	int height; 
	int max_gray;
	ARRAY_TYPE ** image_arr;
	char filename[100];
} image_info;
