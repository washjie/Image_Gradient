#define ARRAY_TYPE unsigned char
#define PI 3.14159265

typedef struct image_data{
	int width, height, max_gray;
	ARRAY_TYPE ** image_arr;
} image_info;