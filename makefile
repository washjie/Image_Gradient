
test: ./main/image_io.c ./main/process.c ./main/main.c
	gcc -o test ./main/image_io.c ./main/process.c ./main/main.c -I.
