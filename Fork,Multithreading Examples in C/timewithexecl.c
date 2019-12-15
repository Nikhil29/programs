#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	int i=atoi(argv[1]),j=0;
	if(i==0)
		return 0;
	char a[10],b[10];
	printf("%d %u\n",i,(unsigned int)clock());
	i--;
	while(i!=0)
	{
		a[j]=i%10+48;
		i=i/10;
		j++;
	}
	for(i=0;i<j;i++)
	{
		b[i]=a[j-i-1];
	}
	b[i]='\0';
	execl("/home/nike/c_linux/a.out","abc",b,NULL);
	return 0;
}
