#include<stdio.h>
int main()
{ int n,i;
  printf("enter no. of processes");
  scanf("%d",&n);
  int arr[n],arr1[n], wt[n];
  float ta[n];
  int dummy[n];
  for(i=0;i<n;i++)
  {
      dummy[i]=0;
  }
  for(i=0;i<n;i++)
  {
  printf("enter arrival time nd service time of %d process",i+1);
  scanf("%d%d",&arr[i],&arr1[i]);
  }
  int k=0;
  int x=arr1[0];
   printf("process p1 runs from %d to %d",0,x);
  printf("\n");
  for(i=0;i<n;i++)
  {   
      if(arr[i+1]<x);
      {
      dummy[i+1]=arr1[i+1];
      }
      int j=min();
      int sum1=x;
      x=arr1[j]+x;
     printf("process p%d runs from %d to %d",i+1,sum1,x);
     printf("\n");
  }
  
  int min()
  {
   int min=dummy[0];
   for(i=0;i<n;i++)
   {
     if(dummy[i]<min)
     min=dummy[i];
     int k=i;
     return k;
   }
  }
    
 }   
    
    
    
    
    
  
  printf("waiting time for process p%d is %d ",i+1,wt[i]);
  printf("\n");
  printf("turn around time for process p%d is %f",i+1,ta[i]);
  printf("\n");
  

