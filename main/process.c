#include "process.h"
#include "image_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int direction_check(char * g_direct, double *angle1, double *angle2){
	if(!g_direct)
		return -1;

	int l = (unsigned)strlen(g_direct);
	if(l == 2){
		*angle1 = g_direct[1]-48;
		return 1;
	}
	else if(l == 4){
		*angle1 = g_direct[1]-48;
		*angle2 = g_direct[3]-48;
		return 2;
	}
	else{
		printf("illegal input.\n");
		return -1;
	}

	return -1;
}

/*
This function calculates the gradient map for the original image. 
Direction is determined by the char string parameter, 
which could have the form: g1g2, g2g0, g1, g7g8, g9...
*/
void image_routine(image_info image, char* direction){
	int i, j;
	double val = 180.0 / PI;
	image_info new_image = { .width = image.width, .height = image.height, .max_gray = image.max_gray };

	new_image.image_arr = image_arr_allocate(image.width, image.height);
	
	double angle1;
	double angle2;
	int mode = direction_check(direction, &angle1, &angle2);
	double first, second;
	
	for(i = 1; i < image.height - 1; ++i){
		for(j = 1; j < image.width - 1; ++j){
			/* calculate the gadient */
			double x = image.image_arr[i][j+1] - image.image_arr[i][j-1];
			double y = image.image_arr[i-1][j] - image.image_arr[i+1][j];
			
			if((fabs(x) < 1) && (fabs(y) < 1)){
				new_image.image_arr[i][j] = 128;
				continue;
			}

			if (y == 0)
				y = 0.001;

			double degree = atan(x/y) * val;
			
			if ((x < 0) && (y > 0)){
				degree = 180 + degree;
			}
			else if ((x < 0) && (y < 0)){
				degree = 180 + degree;
			}
			else if ((x > 0) && (y < 0)){
				degree = 360 + degree;
			}
			else {
				;
			}

			if(mode == 2){
				first = fabs(angle1 * 45 - degree);
				second = fabs(angle2 * 45 - degree);
				if(first < 40)
					new_image.image_arr[i][j] = 0;
				else if (second < 40)
					new_image.image_arr[i][j] = 255;
				else
					new_image.image_arr[i][j] = 128;
			}
			else if(mode == 1){
				double first = fabs(angle1 * 45 - degree);
				if(first < 40)
					new_image.image_arr[i][j] = 0;
				else
					new_image.image_arr[i][j] = 128;
			}
			else{
				;
			}
		}
	}
	strcpy(new_image.filename, image.filename);
	strcat(new_image.filename, "_");
	strcat(new_image.filename, direction);
	strcat(new_image.filename, ".pgm");

	write_image(new_image);
}
