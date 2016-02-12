#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	int pid;
	pid=fork();
	if(pid==0)
	{
 		printf("\nI am a child-process(%d) of (%d).\n",getpid(),getppid());
 		sleep(50);
	}
	else if(pid>0)
	{
 		printf("\nI am a parent-process(%d) of child process(%d).\n",getpid(),pid);
 		wait(NULL);
	}
	else
	{
		printf("\nError\n");
	}
	return 0;
}
