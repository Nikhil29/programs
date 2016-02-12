#include<stdio.h>
int searchpage(int window[],int window_size,int page)
{
	int i;
	for(i=0;i<window_size;i++)
	{
		if(window[i]==page)
		{
			return 1;
		}
	}
	return 0;
}
void initialisewindow(int window[],int window_size,int *window_front,int *window_rear,int pages[])
{
	int i;
	for (i = 0; i < window_size; ++i)
	{
		window[i]=pages[i];
	}
	*window_front=0;
	*window_rear=window_size-1;
}
void addpage(int window[],int window_size,int *window_front,int *window_rear,int page)
{
	(*window_front)++;
	if(*window_front==window_size)
		*window_front=0;
	(*window_rear)++;
	if(*window_rear==window_size)
		*window_rear=0;
	window[*window_rear]=page;

}
int main(int argc, char const *argv[])
{
	int i,no_of_pages,pages_required[1001],window[101],window_size,window_rear,window_front,no_of_hits,no_of_miss,temp;
	scanf("%d",&no_of_pages);
	for(i=0;i<no_of_pages;i++)
	{
		scanf("%d",&pages_required[i]);
	}
	scanf("%d",&window_size);
	if(window_size>no_of_pages)
		no_of_hits=no_of_pages;
	else
		no_of_hits=window_size;
	no_of_miss=0;
	initialisewindow(window,window_size,&window_front,&window_rear,pages_required);
	for(i=window_size;i<no_of_pages;i++)
	{
		temp=searchpage(window,window_size,pages_required[i]);
		if(temp==0)
		{
			addpage(window,window_size,&window_front,&window_rear,pages_required[i]);
			no_of_miss++;
		}
		else
		{
			no_of_hits++;
		}
	}
	printf("no of hits=%d\nno of miss=%d\n",no_of_hits,no_of_miss );
	return 0;
}