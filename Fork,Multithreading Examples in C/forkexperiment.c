# include <sys/types.h>
#include<stdio.h>
int main( )
{
pid_t pid;
int x=0;
printf ( "Before Forking" ) ;
//sleep(5);
for(x=0;x<1000000000;x++)
{
	x=x+1;
}
pid=fork() ;
scanf("%d",&x);
printf ( "After Forking %d %d\n",pid,x ) ;
}
