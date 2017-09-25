#include "image_io.h"
#include <stdio.h>
#include <stdlib.h>

ARRAY_TYPE ** image_arr_allocate( int width, int height){
	int i;
	ARRAY_TYPE ** image_arr;

	image_arr = (ARRAY_TYPE **) malloc(sizeof(ARRAY_TYPE *) * (height));
	for(i = 0; i < height; i++)
		image_arr[i] = (ARRAY_TYPE *) malloc(sizeof(ARRAY_TYPE) * (width));
	
	return image_arr;
}

void write_image(const char * filename, image_info image){
	int i;
	FILE * image_out = fopen(filename, "wb");

	if(image_out){
		fprintf(image_out, "P5\n%d %d\n%d\n", image.width, image.height, image.max_gray);
		/* write the image array */
		for (i = 0; i < image.height; i++)
			fwrite(image.image_arr[i], sizeof(ARRAY_TYPE), image.width * sizeof(ARRAY_TYPE), image_out);
	}
	/* close the file */
	fclose(image_out);
}

image_info read_image(const char * image_file){
	image_info image;

	FILE * image_file_ptr = fopen(image_file, "r");
	/* check file opened */
	if(image_file_ptr){
		int i; char pgm_type[10];
		
		/* read magic number and picture's info */
		fscanf(image_file_ptr, "%s \n%d %d %d ", pgm_type, &(image.width), &(image.height), &(image.max_gray));
		printf("%s, %d, %d, %d\n",  pgm_type, image.width, image.height, image.max_gray);
		/* allocate memory for image array */
		image.image_arr = image_arr_allocate( image.width, image.height);	
		
		/* read image byte by byte */
		for(i = 0; i < image.height; i++)
			fread(image.image_arr[i], 1, image.width, image_file_ptr);
	}
	/* close the file */
	fclose(image_file_ptr);
	return image;
}