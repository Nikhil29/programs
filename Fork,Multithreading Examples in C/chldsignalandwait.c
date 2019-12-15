#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void fun(int num)
{
	printf("sigcld signal received\n");
	sleep(15);
	int x=wait(NULL);
	printf("%d child killed in signal block\n",x);
	sleep(15);
}
int main()
{
	signal(SIGCHLD,fun);
	printf("hello\n");
	int i=fork();
	if(i==0)
	{
		printf("in child\n");
		sleep(5);
		return 0;
	}
	else
	{
		printf("in parent\n");
		int x=wait(NULL);
		printf("%d child killed in parent\n",x);
	}
	return 0;
}
