#include<stdio.h>
#include<unistd.h>
int fact(int i)
{
	if(i==0)
		return 0;
	int j,l;
	char a[10],b[10];
	printf("%d %u\n",i,(unsigned int)clock());
	i--;
	l=i;
	j=0;
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
	fact(l);
}
int main(int argc,char *argv[])
{
	int i=atoi(argv[1]);
	fact(i);
	printf("%d %u\n",i,(unsigned int)clock());
	return 0;
}
