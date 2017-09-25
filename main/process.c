#include "process.h"
#include "image_io.h"

#include <stdlib.h>
#include <math.h>

/*
This function calculates the gradient map for the original image. 
Direction is determined by the char string parameter, 
which could have the form: g1g2, g2g0, g1, g7g8, g9...
*/
void image_routine(image_info image, char* direction){
	int i, j;
	double val = 180.0 / PI;
	image_info new_image;

	new_image.image_arr = image_arr_allocate(image.width, image.height);
	new_image.width = image.width;
	new_image.height = image.height;
	new_image.max_gray = image.max_gray;

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
			

			double first = fabs(45 - degree);
			double second = fabs(225 - degree);
			if(first < 40)
				new_image.image_arr[i][j] = 0;
			else if (second < 40)
				new_image.image_arr[i][j] = 255;
			else
				new_image.image_arr[i][j] = 128;
		}
	}

	write_image("test(1&5).pgm", new_image);
}
