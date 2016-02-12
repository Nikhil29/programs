#include<stdio.h>
#include<unistd.h>
void waitingtime(int arrival[],int start[],int index,int wait[])
{
	int i;
	for(i=0;i<index;i++)
	{
		wait[i]=start[i]-arrival[i];
	}
}
void turnaroundtime(int arrival[],int start[],int service[],int index,int turnaround[])
{
	int i;
	for(i=0;i<index;i++)
	{
		turnaround[i]=start[i]-arrival[i]+service[i];
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
	FILE *input;
	input=fopen("schedulinginput","r");
	FILE *waitoutput=fopen("waitoutput","w");
	FILE *turnoutput=fopen("turnoutput","w");
	FILE *startoutput=fopen("startoutput","w");
	int a,b,i,arrival[10000],service[10000],index,x,start[10000],currtime,wait[10000],turnaround[10000];
	index=0;
	while(1)
	{
		x=fscanf(input,"%d%d",&a,&b);
		if(x==-1)
			break;
		arrival[index]=a;
		service[index]=b;
		index++;
	}
	currtime=0;
	for(i=0;i<index;i++)
	{
		if(currtime>=arrival[i])
		{
			start[i]=currtime;
			currtime=currtime+service[i];
		}
		else
		{
			start[i]=arrival[i];
			currtime=arrival[i]+service[i];
		}
	}
	waitingtime(arrival,start,index,wait);
	turnaroundtime(arrival,start,service,index,turnaround);
	print(wait,index,waitoutput);
	print(turnaround,index,turnoutput);
	print(start,index,startoutput);
	return 0;
}
