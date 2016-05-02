#include<bits/stdc++.h>
using namespace std;
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>

int main(){
	sem_t *semAddress;
	int i;

	semAddress=sem_open("hai", O_EXCL);
	if(semAddress==NULL){
		printf("Error while opening semaphore %d\n",errno);
		return -1;
	}

	// write to file when semaphore is free
	for(i=0;i<2;i++){
		sem_wait(semAddress);
		FILE *input = fopen("input", "a");
		fprintf(input, "Process 2 writing %d\n",i);
		sem_post(semAddress);
	}
	
	return 0;
}