# include <sys/types.h>
#include<stdio.h>
int main( )
{
int pid ;
pid = fork( ) ;
if ( pid == 0 )
{
printf ( "Child : Hello I am the child process\n" ) ;
printf ( "Child : Child’s PID: %d\n", getpid( ) ) ;
printf ( "Child : Parent’s PID: %d\n", getppid( ) ) ;
//scanf("%d");
}
else
{
printf ( "Parent : Hello I am the parent process\n" ) ;
printf ( "Parent : Parent’s PID: %d\n", getpid( ) ) ;
printf ( "Parent : Child’s PID: %d\n", pid ) ;
//scanf("%d");
}
}
