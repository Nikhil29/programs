#include<bits/stdc++.h>
using namespace std;
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<unistd.h>

int main(){
	sem_t *semAddress;
	int i;

	// A semaphore is created with name as "hai" and initial value of resources as 1
	semAddress=sem_open("hai", O_CREAT, 0777, 1);
	if(semAddress==NULL){
		perror("Error while opening semaphore");
		return -1;
	}

	// write to the file when semaphore is free
	for(i=0;i<2;i++){
		sem_wait(semAddress);
		FILE *input = fopen("input", "a");
		fprintf(input, "Process 1 writing %d\n",i);
		sem_post(semAddress);
	}

	return 0;
}