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
	int arrival[10002],service[10002],i,n,j,wait[10002],turnaround[10002],start[10002],flag[10002],currtime,maxrrindex,x;
	float maxrr;
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
		maxrr=-1;
		maxrrindex=-1;
		for(j=0;j<n;j++)
		{
			if(flag[j]==-1)
				continue;
			if(arrival[j]>currtime)
				break;
			if((((float)service[j]+currtime-arrival[j])/service[j])>maxrr)
			{
				maxrr=((float)service[j]+currtime-arrival[j])/service[j];
				maxrrindex=j;
			}
		}
		if(maxrrindex!=-1)
		{
			start[maxrrindex]=currtime;
			flag[maxrrindex]=-1;
			currtime=currtime+service[maxrrindex];
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
