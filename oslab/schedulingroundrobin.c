#include<stdio.h>
#define sizequeue 10002
void enque(int process[],int *rear,int id)
{
	*rear++;
	if(*rear==sizequeue-1)
		*rear=0;
	process[*rear]=id;
}
int deque(int process[],int *front,int *rear)
{
	if(*front==*rear+1)
	{
		return -1;
	}
	int x=*front;
	*front++;
	if(*front==sizequeue-1)
		*front=0;
	return process[x];
}
void turnaroundtime(int arrival[],int end[],int index,int turnaround[])
{
	int i;
	for(i=0;i<index;i++)
	{
		turnaround[i]=end[i]-arrival[i];
	}
}
void print(int x[],int index,FILE *output)
{
	int i;
	for(i=0;i<index;i++)
	{
		fprintf(output,"%d %d\n",i,x[i]);
	}
}
int main()
{
	FILE *input=fopen("schedulinginput","r");
	FILE *waitoutput=fopen("waitoutput","w");
	FILE *turnoutput=fopen("turnoutput","w");
	FILE *endoutput=fopen("endoutput","w");
	int i,n,arrival[10002],service[10002],wait[10002],turnaround[10002],end[10002],currtime,x,timeslice,temp,pending,index;
	int process[10002];
	int front=0,rear=-1;
	fscanf(input,"%d",&timeslice);
	for(i=0;;i++)
	{
		x=fscanf(input,"%d%d",&arrival[i],&service[i]);
		if(x==-1)
			break;
	}
	n=i;
	currtime=0;
	index=0;
	pending=-1;
	while(1)
	{
		if(pending!=-1)
		{
			enque(process,&rear,pending);
		}
		if(front==rear+1)
			break;
		temp=deque(process,&front,&rear);
		if(temp!=-1)
		{
			if(service[temp]>timeslice)
			{
				currtime=currtime+timeslice;
				service[temp]-=timeslice;
				pending=temp;
			}
			else
			{
				currtime+=service[temp];
				service[temp]=0;
				pending=-1;
				end[temp]=currtime;
			}
		}
		for(index;index<n;index++)
		{
			if(arrival[index]<=currtime)
			{
				enque(process,&rear,index);
			}
		}
	}
	turnaroundtime(arrival,end,n,turnaround);
	print(turnaround,n,turnoutput);
	print(end,n,endoutput);
	return 0;
}
