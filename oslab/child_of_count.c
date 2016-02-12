#include<stdio.h>

int main(int argc,char* argv[])
{
 int n=atoi(argv[1]);
 int m=atoi(argv[2]);
 int i;
 for(i=n;i<=m;i++)
 { 
 sleep(1);
 printf("%d \n",i);
 fflush(stdout);
 }
}
