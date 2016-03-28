// send message from parent to child using pipe

#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
	// 1 argument i.e. message to be sent to child
	if(argc!=2){
		printf("1 argument is required.\n");
		exit(EXIT_FAILURE);
	}

	int pipefd[2];
	pid_t cpid;
	char buf;

	if(pipe(pipefd)!=-1){
		// pipe successful

		cpid=fork();
		if(cpid==-1){
			// fork failed
			printf("fork failed\n");
			exit(EXIT_FAILURE);
		}
		
		if(cpid==0){
			// child process
			// close the write descriptor in the child process
			close(pipefd[1]);
			printf("Message received from parent: ");
			while(read(pipefd[0], &buf, 1)){
				printf("%c",buf);
			}
			printf("\n");
			printf("Child exiting\n");
			return 0;
		}
		else{
			// parent process
			// close the read descriptor in the parent process
			close(pipefd[0]);
			printf("Message sent to child: %s\n", argv[1]);
			write(pipefd[1], argv[1], strlen(argv[1]));
			close(pipefd[1]);
			wait(NULL);
			printf("Parent exiting\n");
			return 0;
		}
	}
	else{
		// pipe failure
		printf("Pipe failed\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}