# include <sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main( )
{
int pid ;
pid = fork( ) ;
if ( pid == 0 )
{
printf ( "In child process\n" ) ;
/* code to play animated GIF file */
	/*while(1)
	{
	printf("animation\n");
	}*/
}
else
{
execl("/bin/ls","/etc","-al",NULL);
printf ( "In parent process\n" ) ;
/* code to copy file */
	/*while(1)
	{
	printf("copying\n");
	}*/
}
}
