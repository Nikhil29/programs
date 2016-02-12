#include<stdio.h>
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
	FILE *input=fopen("schedulinginput","r");
	FILE *waitoutput=fopen("waitoutput","w");
	FILE *turnoutput=fopen("turnoutput","w");
	FILE *startoutput=fopen("startoutput","w");
	int arrival[10002],service[10002],i,n,j,wait[10002],turnaround[10002],start[10002],flag[10002],currtime,minjob,minjobindex,x;
	for(i=0;;i++)
	{
		x=fscanf(input,"%d%d",&arrival[i],&service[i]);
		if(x==-1)
			break;
	}
	n=i;
	currtime=0;
	for(i=0;i<n;i++)
		flag[i]=0;
	for(i=0;i<n;i++)
	{
		minjob=1000000005;
		minjobindex=-1;
		for(j=0;j<n;j++)
		{
			if(flag[j]==-1)
				continue;
			if(arrival[j]>currtime)
				break;
			if(service[j]<minjob)
			{
				minjob=service[j];
				minjobindex=j;
			}
		}
		if(minjobindex!=-1)
		{
			start[minjobindex]=currtime;
			flag[minjobindex]=-1;
			currtime=currtime+service[minjobindex];
		}
		else
		{
			for(j;j<n;j++)
			{
				if(flag[j]==-1)
					continue;
				else
					break;
			}
			start[j]=arrival[j];
			flag[j]=-1;
			currtime=arrival[j]+service[j];
		}
	}
	waitingtime(arrival,start,n,wait);
	turnaroundtime(arrival,start,service,n,turnaround);
	print(wait,n,waitoutput);
	print(turnaround,n,turnoutput);
	print(start,n,startoutput);
	return 0;
}
