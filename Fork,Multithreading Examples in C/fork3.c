# include <unistd.h>
# include <sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main( )
{
unsigned int i = 0 ;
int pid, status ;
pid = fork( ) ;
if ( pid == 0 )
{
/*while ( i < 1294967295U )
i++ ;*/
sleep(3);
printf ( "The child is now terminating\n" ) ;
}
else
{
waitpid ( pid, &status, 0 ) ;
printf("status:%d\n",status);
if ( WIFEXITED(status) )
printf ( "Parent: Child terminated normally\n" ) ;
else
printf ( "Parent: Child terminated abnormally\n" ) ;
}
return 0 ;
}
