// the data will be read by this process from fifo
// the read end of the fifo must be opened before the write end is opened
// thus first execute read process and then write process

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Enter the name of the fifo to read data\n");
		exit(EXIT_FAILURE);
	}

	char buffer[100];
	// open the fifo file to read data
	FILE *myfile=fopen(argv[1], "r");
	if(myfile==NULL){
		printf("unable to open fifo file\n");
		exit(EXIT_FAILURE);
	}

	fscanf(myfile, "%s", buffer);
	printf("Data received: %s\n",buffer);

	fclose(myfile);
	return 0;
}