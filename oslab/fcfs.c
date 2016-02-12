#include<stdio.h>
int main()
{ int n,i;
  printf("enter no. of processes");
  scanf("%d",&n);
  int arr[n],arr1[n], wt[n];
  float ta[n];
  for(i=0;i<n;i++)
  {
  printf("enter arrival time nd service time of %d process",i+1);
  scanf("%d%d",&arr[i],&arr1[i]);
  }
  int sum=0;
  for(i=0;i<n;i++)
  {   int sum1=sum;
      sum=arr1[i]+sum;
      wt[i]=sum1-arr[i];
      ta[i]=(wt[i]+arr1[i])/arr1[i];
  printf("process p%d runs from %d to %d",i+1,sum1,sum);
  printf("\n");
  printf("waiting time for process p%d is %d ",i+1,wt[i]);
  printf("\n");
  printf("turn around time for process p%d is %f",i+1,ta[i]);
  printf("\n");
  
  }
  
  
  
  
  
  
  
}
