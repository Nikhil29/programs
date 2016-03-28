// this makes the fifo file which can be used for communication by other processes

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Enter the name of the fifo to be made\n");
		exit(EXIT_FAILURE);
	}

	// make fifo
	if(mkfifo(argv[1], 0777)==-1){
		printf("unable to make fifo\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}