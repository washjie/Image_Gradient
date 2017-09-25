#define ARRAY_TYPE unsigned char
#define PI 3.14159265

/*
Image file structure definition
Since we use <picture>.pgm file as our material
The array type for storing every pixel is unsigned char
*/

typedef struct image_data{
	int width;
	int height; 
	int max_gray;
	ARRAY_TYPE ** image_arr;
} image_info;
