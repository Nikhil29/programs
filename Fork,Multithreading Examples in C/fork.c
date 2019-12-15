# include <sys/types.h>
#include<stdio.h>
int main( )
{
printf ( "Before Forking\n" ) ;
fork() ;
printf ( "After Forking\n" ) ;
}
