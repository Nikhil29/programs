#include<stdio.h>
int i,t,k;
static int q=1;
  int adm[10],st[10],st1[10],queue[10], wt[10];
  float ta[10];
int function1(int t,int n)
{   t=t+1;
  for(i=0;i<n;i++)
     { 
        if(adm[i+1]<=t)
        {queue[i+1]=i+2;
         st1[i+1]=st[i+1];   
        }
   }
  int min;
     min=(st[0]-st1[0]);
    //  printf("min is %d",min);
   for(i=0;i<n;i++)
   {
      if((st[i]-st1[i])<=min)
      {  
          min=(st[i]-st1[i]);
          k=i;
      }  
   }  
   printf("%d",k);
   return k;
   
}
int main()
{
   int n;
   int sum=0;
  printf("enter no. of processes");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
  printf("enter arrival time nd service time of %d process",i+1);
  scanf("%d%d",&adm[i],&st[i]);
  }
  
  
   for(i=0;i<n;i++)
     { st1[i]=0;
   }  
 
  t=adm[0];
     queue[0]=1;
        printf("process %d runs from %d to %d",queue[0],t,t+1);
        st1[0]=st[0]-1;
        t++;
   for(i=0;i<n;i++)
  {
      sum=sum+st[i];
  }
        
    while(t<sum)
    {   int x;
          x=function1(t,n); 
    
   printf("process %d runs from %d to %d\n",queue[x],t,t+1);
   t++;
     }
     
   
  
  }
