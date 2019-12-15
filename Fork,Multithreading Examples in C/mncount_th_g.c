#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>

typedef long long unsigned lint;
lint global_sum=0;

/*  A program to print the sum of a numbers given using command line arguments
	using separate threads and display the final result. Compare with normal methods.
*/

typedef struct thread_info{
	pthread_t thread_id;
	int thread_no;
	void *argument;
}thread;

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* thread_sum(void *x){

	global_sum=0;
	lint y=*(lint *)x;
	for(lint i=1; i<=y; i++){

		global_sum+=i;
	}
	printf("Returned: %lld",global_sum);
	pthread_exit(NULL);
}

void print_error(char *message){
	fprintf(stderr, "%s\n",message);
	exit(EXIT_FAILURE);
}

int main(int argc,char **argv)
{
	int s;
	if(argc<2)
		print_error("Arguments !> 2");

	pthread_attr_t attr;											//Set of attribites for our own thread structure
	s=pthread_attr_init(&attr);										//initialise the attributes for the thread stack
		assert(s==0);

	thread *tid=(thread *)calloc(argc-1,sizeof(thread));						//Allocate memory for threads
	if(tid==NULL)
		print_error("Couldn't Allocate Memory");

	for(int i=0; i<argc-1; i++){

		lint arg=atoll(argv[i+1]);
		tid[i].argument=&arg;													//Set the argument as the input
		tid[i].thread_no=i+1;

		s=pthread_create(&tid[i].thread_id,&attr,thread_sum,tid[i].argument);	//Create the thread in background
		assert (s==0);
	}

	s=pthread_attr_destroy(&attr);				//We don't need the attributes now as the threads are up and running.
	assert(s==0);	

	for(int i=0; i<argc-1; i++){
		s=pthread_join(tid[i].thread_id,NULL);							//make calling thread wait for the called thread
																		//analogous to waitpid() in processes	
		printf("Thread %d finished. \n",tid[i].thread_no );
	}

	return 0;
}
