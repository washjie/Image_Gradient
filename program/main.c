#include "image_io.h"
#include "process.h"

/* started here */
int main(int argc, char* argv[]){
	
	if(argc == 2){
		image_info image = read_image(argv[1]);	
		image_routine(image);
	}

	return 0;
}
