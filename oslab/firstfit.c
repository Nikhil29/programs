#include<stdio.h>
int main()
{  int size,i,pos,n;
   printf("enter size of m/m(array)");
   scanf("%d",&size);
   int arr[size],no=1;
   for(i=0;i<size;i++)
   {
    arr[i]=0;
   }
   while(no!=5)
   {
    printf("enter spaces filled");
    scanf("%d",&pos);
    arr[pos]=1;
    no++;
   }
   
   for(i=0;i<size;i++)
   {
    printf("%d",arr[i]);
   }
   
   printf("enter no. of spaces u want in continous");
   scanf("%d",&n);
   int k,c;
   k=0;
   for(i=0;i<size;)
   { c=0;
   while(k!=n)
     {
       if(arr[i+k]==1)
      {
        i=i+k+1;
        k=0;
       break;
      }
      else
       {
        arr[i+k]=2;
        k++;
        c++;
       }
       
     } 
     if(c==n)
        break; 
   }
   
   for(i=0;i<size;i++)
   {
    printf("%d",arr[i]);
   }
}
