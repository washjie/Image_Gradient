#include "image_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Allocate memory for image_arr, which will have the type ARRAY_TYPE(unsigned char) **.
So image_arr will be a two  dimensional array.
Size of memory allocated should be: sizeof(ARRAY_TYPQ) * width * height.
*/
ARRAY_TYPE ** image_arr_allocate( int width, int height){
	int i;
	ARRAY_TYPE ** image_arr;

	image_arr = (ARRAY_TYPE **) malloc(sizeof(ARRAY_TYPE *) * (height));
	for(i = 0; i < height; i++)
		image_arr[i] = (ARRAY_TYPE *) malloc(sizeof(ARRAY_TYPE) * (width));
	
	return image_arr;
}

/*
This function write the image array to a pgm file.
Since I didn't handle the filename, filename shuold contain ".pgm".
ex. "output1.pgm"
I will update this function later.
*/
void write_image(const image_info image){
	int i;
	FILE * image_out = fopen(image.filename, "wb");
	
	if(image_out){
		fprintf(image_out, "P5\n%d %d\n%d\n", image.width, image.height, image.max_gray);
		for (i = 0; i < image.height; i++)
			fwrite(image.image_arr[i], sizeof(ARRAY_TYPE), image.width * sizeof(ARRAY_TYPE), image_out);
	}
	fclose(image_out);
}

/*
In the pgm file, the format is like:

P5				//The magic number for identifying the file type.
700 465			//The width, height of the picture
255				//The maximum gray value
byte data...	// image data started here

So we first read the first three lines,(fscanf)
allocate memory for the image array,(image_arr_allocate)
then read the picture data byte by byte.(fread)
*/
image_info read_image(char * image_file){
	image_info image;
	FILE * image_file_ptr = fopen(image_file, "r");
	
	if(image_file_ptr){
		int i; char pgm_type[10];
		fscanf(image_file_ptr, "%s \n%d %d %d ", pgm_type, &(image.width), &(image.height), &(image.max_gray));
		image.image_arr = image_arr_allocate( image.width, image.height);
		
		char * token;
		token = strtok(image_file, " ,./");
		char prev_token[100];

		while(token != NULL){

			strcpy(prev_token, token);
			token = strtok(NULL, " ,./");
			if(token){
				if(strcmp(token, "pgm") == 0){
					strcpy(image.filename, prev_token);
				}
			}
			
		}

		for(i = 0; i < image.height; i++)
			fread(image.image_arr[i], sizeof(ARRAY_TYPE), image.width, image_file_ptr);
	}
	fclose(image_file_ptr);
	return image;
}
