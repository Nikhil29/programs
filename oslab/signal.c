#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
void fun(int x)
{

	if(x==SIGINT)
	{
		printf("\nProcess cannot be aborted\n");
		while(1)
			{
				printf("program running\n");
				sleep(1);
			}
		sleep(10);
	}
	if(x==SIGCHLD)
	{  
		int i,s;
		i=wait(&s);
		printf("\n child process %d of parent process %d destroyed with status %d \n",i,getpid(),WEXITSTATUS(s));
	}
	if(x==SIGTSTP)
	{
		printf("\nProcess cannot be stopped\n");
	}
	if(x==SIGTERM)
	{
		printf("process can,t be stopped\n");
	}
}


int main(int argc,char* argv[])
{
	signal(SIGINT,fun);
	signal(SIGCHLD,fun);
	signal(SIGTSTP,fun);
	signal(SIGTERM,fun);
	sigset(SIGTERM,SIG_IGN);
	int pid;
	pid=fork();
	int x;
	if(pid==0)
	{
		int j;
		printf("\nI am a child process %d of parent process %d \n",getpid(),getppid());
		for(j=atoi(argv[1]);j<=atoi(argv[2]);j++)
		{
			printf("%d\n",j);
			fflush(stdout);
			sleep(2);	
		}
		sleep(10);
	}

	else if(pid>0)
	{
		printf("\nI am a parent-process %d of child process %d \n",getpid(),pid);
		x=wait(NULL);
		printf("%d is the pid of died child in parent\n",x);
		sleep(10);
	}
	else
	{		
		printf("\nerror\n");
	}

	if(pid)
		return 4;
	else
		return 0;

}
