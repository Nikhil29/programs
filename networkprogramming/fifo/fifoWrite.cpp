// the data will be written by this process to fifo
// the write end of the fifo must be opened after the read end is opened
// thus first execute read process and then this one

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Enter the name of the fifo to write data\n");
		exit(EXIT_FAILURE);
	}

	char buffer[100];
	// open the fifo file to write data
	FILE *myfile=fopen(argv[1], "w");
	if(myfile==NULL){
		printf("unable to open fifo file\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the data to be sent: \n");
	fgets(buffer, 100, stdin);
	fputs(buffer, myfile);
	printf("Data sent.\n");

	fclose(myfile);
	return 0;
}