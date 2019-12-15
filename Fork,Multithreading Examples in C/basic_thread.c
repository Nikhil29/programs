#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>

typedef long long unsigned lint;
lint x_limit,y_limit;

/*  A program to display the use and share of variables in threads*/

void print_error(char *message){
	fprintf(stderr, "%s\n",message);
	exit(EXIT_FAILURE);
}


void *increment_x(void *x_void_ptr)
{

	lint *x_ptr = (lint *)x_void_ptr;
	while(++(*x_ptr) < x_limit);

	printf("X incremented in thread\n");

	pthread_exit(NULL);											//Return to the calling thread
}


int main(int argc,char **argv)
{
	if (argc<3)
		print_error("Args >=2 ");

	lint x = 0, y = 0;
	x_limit=atoll(argv[1]);
	y_limit=atoll(argv[2]);

	printf("Initial  x: %lld, y: %lld\n", x, y);

	pthread_t tid;											//Create a thread identifier	

	if(pthread_create(&tid, NULL, increment_x, &x))			//Create the thread which runs in the background.
		print_error("Error creating thread");

	// while(++x< x_limit);
	// 	printf("X incremented\n");

	while(++y < y_limit);									//Main thread continues execution
		printf("Y incremented\n");

	if(pthread_join(tid, NULL)) 			//make calling thread wait for the called thread .analogous to waitpid() in processes
		print_error("Error joining thread");

	printf("Thread Over\n");
	printf("Final x: %lld, y: %lld\n", x, y);
	return 0;
}