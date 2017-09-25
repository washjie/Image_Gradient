#include <stdio.h>
#include "image_io.h"
#include "process.h"

int main(int argc, char* argv[]){
	
	if(argc == 3){
		image_info image = read_image(argv[1]);	
		image_routine(image, argv[2]);
	}
	else{
		printf("No arguments.");
	}

	return 0;
}
