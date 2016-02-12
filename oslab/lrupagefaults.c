#include<stdio.h>
int searchpage(int w[],int size,int page)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		if(w[i]==page)
		{
			for(j=i+1;j<size;j++)
			{
				w[j-1]=w[j];
			}
			w[j-1]=page;
			return 1;
		}
	}
	return 0;
}
int addpage(int w[],int size,int page)
{
	int i,j;
	for(i=1;i<size;i++)
	{
		w[i-1]=w[i];
	}
	w[i-1]=page;
	return 0;
}
int initialisewindow(int w[],int size,int a[])
{
	int i;
	for(i=0;i<size;i++)
	{
		w[i]=a[i];
	}
}
int main()
{
	int i,n,w[10000],size,a[10000],hit,miss,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&size);
	if(size>n)
		hit=n;
	else
		hit=size;
		miss=0;
	initialisewindow(w,size,a);
	for(i=size;i<n;i++)
	{
		temp=searchpage(w,size,a[i]);
		//printf("%d\n",temp );
		if(temp==1)
			hit++;
		else
		{
			miss++;
			addpage(w,size,a[i]);
		}
	}
	printf("hits:%d\nmiss:%d\n",hit,miss);
	return 0;
}