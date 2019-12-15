#include<stdio.h>
#include<unistd.h>
#include<time.h>
int fact(int n,int result)
{
	result=result*n;
	if(n!=1)
	{
		char a[50],b[50],temp[50];
		n--;
		int i=0,j;
		while(n!=0)
		{
			temp[i]=n%10+48;
			n=n/10;
			i++;
		}
		for(j=0;j<i;j++)
		{
			a[j]=temp[i-1-j];
		}
		a[j]='\0';
		i=0;
		while(result!=0)
		{
			temp[i]=result%10+48;
			result=result/10;
			i++;
		}
		for(j=0;j<i;j++)
		{
			b[j]=temp[i-1-j];
		}
		b[j]='\0';
		//printf("%s %s\n",a,b);
		printf("%u\n",(unsigned int)clock());
		execl("/home/nike/c_linux/a.out","abc",a,b,NULL);
	}
	else
	{
		printf("%d\n",result);
	}
	return 0;
}
int main(int argc,char *  argv[])
{
	int n=atoi(argv[1]);
	int result=atoi(argv[2]);
	//printf("%d %d\n",n,result);
	fact(n,result);
	return 0;
}
