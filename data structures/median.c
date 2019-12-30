#include<stdio.h>
int median(int *a,int n)
    {
    int i,j,k;
     for(i=0;i<n;i++)
         {
         for(j=i+1;j<n;j++)
             {
             if(a[i]>a[j])
                 {
                 k=a[i];
                 a[i]=a[j];
                 a[j]=k;
             }
         }
     }
    return a[n/2];
}
int main()
    {
    int n,*a,i,med;
    printf("enter the no. of integers in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    med=median(a,n);
    printf("the median is %d\n",med);
    return 0;
}